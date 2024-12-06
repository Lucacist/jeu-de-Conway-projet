#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <cstdlib> // pour rand() et srand()
#include <ctime>   // pour initialiser rand()
#include "Grille.h"
#include "Fichier.h"

using namespace std;
namespace fs = std::filesystem;

const int cellSize = 10;

void renderGrid(sf::RenderWindow &window, Grille &grille) {
    int hauteur = grille.getHauteur();
    int largeur = grille.getLargeur();

    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (int x = 0; x < hauteur; ++x) {
        for (int y = 0; y < largeur; ++y) {
            if (grille.getValue(x, y) > 0) {
                cell.setFillColor(sf::Color::White);
                cell.setPosition(y * cellSize, x * cellSize);
                if (grille.getValue(x, y) == 2) { cell.setFillColor(sf::Color::Red); }
                if (grille.getValue(x, y) == 3) { cell.setFillColor(sf::Color::Green); }
                window.draw(cell);
            }
        }
    }
}

void sauvegarderEtat(const Grille &grille, const string &cheminDossier, int iteration) {
    ostringstream fichierNom;
    fichierNom << cheminDossier << "/iteration_" << iteration << ".txt";

    ofstream fichier(fichierNom.str());
    if (!fichier) {
        cerr << "Erreur lors de la création du fichier : " << fichierNom.str() << endl;
        return;
    }

    for (int i = 0; i < grille.getHauteur(); ++i) {
        for (int j = 0; j < grille.getLargeur(); ++j) {
            fichier << grille.getValue(i, j) << " ";
        }
        fichier << endl;
    }

    fichier.close();
}

void nettoyerDossier(const string &cheminDossier) {
    if (fs::exists(cheminDossier)) {
        fs::remove_all(cheminDossier);
    }
    fs::create_directory(cheminDossier);
}

void genererFichierAleatoire(const string &chemin, int hauteur, int largeur) {
    ofstream fichier(chemin);
    if (!fichier) {
        cerr << "Erreur lors de la création du fichier." << endl;
        return;
    }

    srand(time(nullptr)); // Initialisation de la graine pour rand()

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            fichier << rand() % 2 << " "; // Génère des cellules avec des états 0 ou 1
        }
        fichier << endl;
    }

    fichier.close();
    cout << "Fichier généré avec succès : " << chemin << endl;
}

void sauvegarderEtat(const Grille &grille, const string &cheminDossier, int iteration) {
    ostringstream fichierNom;
    fichierNom << cheminDossier << "/iteration_" << iteration << ".txt";

    ofstream fichier(fichierNom.str());
    if (!fichier) {
        cerr << "Erreur lors de la création du fichier : " << fichierNom.str() << endl;
        return;
    }

    for (int i = 0; i < grille.getHauteur(); ++i) {
        for (int j = 0; j < grille.getLargeur(); ++j) {
            fichier << grille.getValue(i, j) << " ";
        }
        fichier << endl;
    }

    fichier.close();
}

void nettoyerDossier(const string &cheminDossier) {
    if (fs::exists(cheminDossier)) {
        fs::remove_all(cheminDossier);
    }
    fs::create_directory(cheminDossier);
}

void genererFichierAleatoire(const string &chemin, int hauteur, int largeur) {
    ofstream fichier(chemin);
    if (!fichier) {
        cerr << "Erreur lors de la création du fichier." << endl;
        return;
    }

    srand(time(nullptr)); // Initialisation de la graine pour rand()

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            fichier << rand() % 2 << " "; // Génère des cellules avec des états 0 ou 1
        }
        fichier << endl;
    }

    fichier.close();
    cout << "Fichier généré avec succès : " << chemin << endl;
}

int main() {
    string chemin;
    cout << "Entrer le chemin du fichier\n";
    cin >> chemin;

    bool pause = false;
    Fichier fichier{chemin};
    int hauteur = fichier.getDims().first;
    int largueur = fichier.getDims().second;
    Grille grille;

    if (!fs::exists(chemin)) {
        cerr << "Erreur : fichier introuvable !" << endl;
        int hauteur, largeur;
        cout << "Entrez la hauteur de la grille : ";
        cin >> hauteur;
        cout << "Entrez la largeur de la grille : ";
        cin >> largeur;

        genererFichierAleatoire(chemin, hauteur, largeur);
        fichier = Fichier(chemin);
    }

    grille = fichier.versGrille();

    cout << "Voulez-vous afficher la grille dans :\n1. Le terminal avec sauvegarde\n2. Une fenêtre graphique\n";
    int choix;
    cin >> choix;

    if (choix == 1) {
        // Création du dossier de sortie
        string dossierSortie = chemin + "_out";
        nettoyerDossier(dossierSortie);

        // Nombre d'itérations à sauvegarder
        int n;
        cout << "Combien d'itérations voulez-vous sauvegarder ?\n";
        cin >> n;

        for (int i = 0; i < n && grille.isRunning(); ++i) {
            grille.print();
            cout << "---" << endl;

            // Sauvegarde de l'état actuel dans un fichier
            sauvegarderEtat(grille, dossierSortie, i);
            grille.run();
        }

        cout << "Les états ont été sauvegardés dans le dossier : " << dossierSortie << endl;

    } else if (choix == 2) {
        sf::Font font;
        if (!font.loadFromFile("Inter-Black.woff2")){
            cout<<"Erreur lors de l'ouverture de la police";
        }
        sf::Text textClic;
        textClic.setFont(font);
        textClic.setString("Clic gauche pour ajouter une cellule");
        textClic.setCharacterSize(16);
        textClic.setFillColor(sf::Color::White);
        textClic.setPosition(10,hauteur * cellSize-50);
        sf::Text textEspace=textClic;
        textEspace.setString("Espace pour mettre en pause");
        textEspace.setPosition(10,hauteur * cellSize-30);
        sf::Text textPause=textClic;
        textPause.setString("PAUSE");
        textPause.setStyle(sf::Text::Bold);
        textPause.setPosition(largueur*cellSize/2,hauteur * cellSize/2+50);
        sf::Text textFin=textPause;
        textFin.setString("FIN");
        textFin.setPosition(largueur*cellSize/2,hauteur * cellSize/2);
        textFin.setFillColor(sf::Color::Red);
        sf::RenderWindow window(sf::VideoMode(hauteur * cellSize, largueur * cellSize), "Jeu de la vie - Grille");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed) {
                    switch (event.key.code) {
                        case sf::Keyboard::Space:
                            pause = !pause;
                            break;
                    }
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    int h = mousePos.y / cellSize;
                    int l = mousePos.x / cellSize;
                    if (h < grille.getHauteur() && l < grille.getLargeur()) {
                        grille.setValue(h, l, 1);
                    }
                }
            }
            renderGrid(window,grille);
            window.draw(textClic);
            window.draw(textEspace);
            if (grille.running && pause){
                window.draw(textPause);
            }
            if (!grille.running){
                window.draw(textFin);
            }
            if (grille.running && !pause){
                grille.run();
            }
            window.display();
            sf::sleep(sf::milliseconds(50));
        }
    } else {
        cerr << "Choix invalide." << endl;
    }

    return 0;
}
