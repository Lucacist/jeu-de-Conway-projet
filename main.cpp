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

using namespace std;
namespace fs = std::filesystem;

const int cellSize = 10;

void renderGrid(sf::RenderWindow &window, Grille &grille)
{
    int hauteur = grille.getHauteur();
    int largeur = grille.getLargeur();

    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (int x = 0; x < hauteur; ++x)
    {
        for (int y = 0; y < largeur; ++y)
        {
            if (grille.getValue(x, y) > 0)
            {
                cell.setFillColor(sf::Color::White);
                cell.setPosition(y * cellSize, x * cellSize);
                if (grille.getValue(x, y) == 2)
                {
                    cell.setFillColor(sf::Color::Red);
                }
                if (grille.getValue(x, y) == 3)
                {
                    cell.setFillColor(sf::Color::Green);
                }
                window.draw(cell);
            }
        }
    }
}

void nettoyerDossier(const string &cheminDossier)
{
    if (fs::exists(cheminDossier))
    {
        fs::remove_all(cheminDossier);
    }
    fs::create_directory(cheminDossier);
}

int main()
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
            grille.print();
            cout << "---" << endl;

            fichier.sauvegarderEtat(grille, dossierSortie, i);
            grille.run();
        }

        cout << "Les états ont été sauvegardés dans le dossier : " << dossierSortie << endl;
    }
    else if (choix == 2)
    {
        sf::Font font;
        if (!font.loadFromFile("Inter-Black.woff2"))
        {
            cout << "Erreur lors de l'ouverture de la police";
        }
        sf::Text textClic;
        textClic.setFont(font);
        textClic.setString("Clic gauche pour ajouter une cellule");
        textClic.setCharacterSize(16);
        textClic.setFillColor(sf::Color::Yellow);
        textClic.setPosition(10, hauteur*cellSize - 60);
        sf::Text textEspace = textClic;
        textEspace.setString("Espace pour mettre en pause");
        textEspace.setPosition(10, hauteur*cellSize - 40);
        sf::Text textFleche = textEspace;
        textFleche.setString("^/v pour modifier la vitesse");
        textFleche.setPosition(10, hauteur*cellSize - 20);
        sf::Text textVitesse = textFleche;
        textVitesse.setPosition(largueur*cellSize - 50, hauteur*cellSize - 20);
        sf::Text textPause = textVitesse;
        textPause.setString("PAUSE");
        textPause.setStyle(sf::Text::Bold);
        textPause.setPosition(largueur*cellSize / 2, hauteur*cellSize / 2 + 50);
        sf::Text textFin = textPause;
        textFin.setString("FIN");
        textFin.setPosition(largueur*cellSize / 2, hauteur*cellSize / 2);
        textFin.setFillColor(sf::Color::Red);
        sf::RenderWindow window(sf::VideoMode(largueur*cellSize, hauteur*cellSize), "Jeu de la vie - Grille");
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
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
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    int h = mousePos.y / cellSize;
                    int l = mousePos.x / cellSize;
                    if (h < grille.getHauteur() && l < grille.getLargeur())
                    {
                        grille.setValue(h, l, 1);
                    }
                }
            }
            renderGrid(window, grille);
            window.draw(textClic);
            window.draw(textEspace);
            window.draw(textFleche);
            textVitesse.setString(std::to_string(11 - delai));
            window.draw(textVitesse);
            if (grille.isRunning() && pause)
            {
                window.draw(textPause);
            }
            if (!grille.isRunning())
            {
                window.draw(textFin);
            }
            if (grille.isRunning() && !pause)
            {
                grille.run();
            }
            window.display();
            sf::sleep(sf::milliseconds(delai * 10));
        }
    }
    else
    {
        cerr << "Choix invalide." << endl;
    }

    return 0;
}
