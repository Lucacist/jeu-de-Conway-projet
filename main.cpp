#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Grille.h"

using namespace std;
#include "Grille.h"
#include "Fichier.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

const int cellSize = 10;
const int gridHeight = 70;
const int gridWidth = 70;

void renderGrid(sf::RenderWindow &window, Grille &grille) {
    int x, y;
    
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < gridHeight; ++x) {
        for (y = 0; y < gridWidth; ++y) {
            if (grille.getValue(x,y) == 1) {
                cell.setPosition(y * cellSize, x * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");

    Fichier fichier{"Input.txt"};
    Grille grille{fichier.versMatrice()};

    Grille grille{matrice};

    cout << "Voulez-vous afficher la grille dans :\n1. Le terminal\n2. Une fenêtre graphique\n";
    int choix;
    cin >> choix;

    if (choix == 1) {
        for (int i = 0; i < 1000; i++) {
            grille.print();
            cout << "---" << endl;
            grille.run();
        }
    } else if (choix == 2) {
        sf::RenderWindow window(sf::VideoMode(cols * cellSize, rows * cellSize), "Jeu de la vie - Grille");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            renderGrid(grille, cellSize, window);
            sf::sleep(sf::milliseconds(100));
            grille.run();
        }
    } else {
        cerr << "Choix invalide." << endl;
    }

    return 0;
}
