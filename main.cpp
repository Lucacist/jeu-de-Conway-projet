#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Grille.h"

using namespace std;

const int cellSize = 10;

void renderGrid(const Grille& grille, int cellSize, sf::RenderWindow& window) {
    const auto& grid = grille.getGrid();

    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (int x = 0; x < grid.size(); ++x) {
        for (int y = 0; y < grid[0].size(); ++y) {
            if (grid[x][y] == 1) {
                cell.setPosition(y * cellSize, x * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}

int main() {
    ifstream inputFile("Input.txt");
    if (!inputFile) {
        cerr << "Erreur lors de l'ouverture du fichier !" << endl;
        return 1;
    }

    // Lire la taille de la grille à partir de la première ligne
    int rows, cols;
    inputFile >> rows >> cols;
    inputFile.ignore();

    vector<vector<int>> matrice(rows, vector<int>(cols));
    string line;
    for (int i = 0; i < rows; ++i) {
        getline(inputFile, line);
        istringstream iss(line);
        for (int j = 0; j < cols; ++j) {
            iss >> matrice[i][j];
        }
    }
    inputFile.close();

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
            sf::sleep(sf::milliseconds(200));
            grille.run();
        }
    } else {
        cerr << "Choix invalide." << endl;
    }

    return 0;
}
