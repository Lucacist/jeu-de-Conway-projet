#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <filesystem>
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
    window.display();
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

int main() {
    string chemin;
    cout << "Entrer le chemin du fichier\n";
    cin >> chemin;

    bool pause = false;

    Fichier fichier{chemin};
    Grille grille = fichier.versGrille();

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
        sf::RenderWindow window(sf::VideoMode(grille.getLargeur() * cellSize, grille.getHauteur() * cellSize), "Jeu de la vie - Grille");
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
            renderGrid(window, grille);
            sf::sleep(sf::milliseconds(100));
            if (grille.isRunning() && !pause) {
                grille.run();
            }
        }
    } else {
        cerr << "Choix invalide." << endl;
    }

    return 0;
}
