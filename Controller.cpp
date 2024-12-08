#include "Controller.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <cstdlib>
#include <ctime>
#include "Grille.h"
#include "Fichier.h"
#include "Vue.h"

using namespace std;
namespace fs = std::filesystem;

const int cellSize = 10;

void Controller::nettoyerDossier(const string &cheminDossier)
{
    if (fs::exists(cheminDossier))
    {
        fs::remove_all(cheminDossier);
    }
    fs::create_directory(cheminDossier);
}

Controller::Controller(Vue vue)
{
    this->vue = vue;
}

void Controller::run()
{
    string chemin;
    cout << "Entrer le chemin du fichier\n";
    cin >> chemin;

    int largueurF = 1440;
    int hauteurF = 900;
    int delai = 5;
    bool pause = false;

    if (!fs::exists(chemin))
    {
        cerr << "Erreur : fichier introuvable !" << endl;
        cout << "Création du fichier : " << chemin << endl;
        int hauteur, largeur;
        cout << "Entrez la hauteur de la grille : ";
        cin >> hauteur;
        cout << "Entrez la largeur de la grille : ";
        cin >> largeur;

        Fichier fichier;
        fichier.genererFichierAleatoire(chemin, hauteur, largeur);
    }

    Fichier fichier{chemin};
    int hauteur = fichier.getDims().first;
    int largueur = fichier.getDims().second;
    Grille grille;
    grille = fichier.versGrille();

    cout << "Voulez-vous afficher la grille dans :\n1. Le terminal avec sauvegarde\n2. Une fenêtre graphique\n";
    int choix;
    cin >> choix;

    if (choix == 1)
    {
        string dossierSortie = chemin + "_out";
        nettoyerDossier(dossierSortie);

        int n;
        cout << "Combien d'itérations voulez-vous sauvegarder ?\n";
        cin >> n;

        for (int i = 0; i < n && grille.isRunning(); ++i)
        {
            this->vue.afficherConsole(grille);

            fichier.sauvegarderEtat(grille, dossierSortie, i);
            grille.run();
        }

        cout << "Les états ont été sauvegardés dans le dossier : " << dossierSortie << endl;
    }
    else if (choix == 2)
    {
        sf::RenderWindow *window = vue.initWindow(hauteur, largueur);
        while (window->isOpen())
        {
            sf::Event event;
            while (window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window->close();
                }
                if (event.type == sf::Event::KeyPressed)
                {
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Space:
                        pause = !pause;
                        break;
                    case sf::Keyboard::Down:
                        delai = min(delai + 1, 10);
                        break;

                    case sf::Keyboard::Up:
                        delai = max(delai - 1, 1);
                        break;
                    }
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                    int h = mousePos.y / cellSize;
                    int l = mousePos.x / cellSize;
                    if (h < grille.getHauteur() && l < grille.getLargeur())
                    {
                        grille.setValue(h, l, !grille.getValue(h, l));
                    }
                }
            }
            vue.renderGrid(*window, grille);
            vue.renderInterface(*window, hauteur, largueur, delai, grille, pause);
            if (grille.isRunning() && !pause)
            {
                grille.run();
            }
            window->display();
            sf::sleep(sf::milliseconds(delai * 10));
        }
    }
    else
    {
        cerr << "Choix invalide." << endl;
    }
}
