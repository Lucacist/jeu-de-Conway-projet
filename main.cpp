#include <filesystem> // Pour gérer les fichiers
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Grille.h"

using namespace std;
namespace fs = std::filesystem; 
const int cellSize = 20;

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

void deletePreviousFiles(const string& prefix) {
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().string().find(prefix) != string::npos) {
            fs::remove(entry.path());
        }
    }
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
        string outputDirectory = "./Output";
        while (true) {
            cout << "Combien d'itérations voulez-vous générer ? ";
            int iterations;
            cin >> iterations;

            if (iterations <= 0) {
                cout << "Nombre d'itérations invalide. Arrêt du programme." << endl;
                break;
            }

            deletePreviousFiles("Grille_Etat_");

            for (int i = 0; i < iterations; i++) {
                grille.print();
                cout << "---" << endl;

                stringstream filename;
                filename << "Input_out" << i << ".txt"; 
                ofstream outputFile(filename.str());
                if (!outputFile) {
                    cerr << "Erreur lors de la création du fichier !" << endl;
                    return 1;
                }

                const auto& grid = grille.getGrid();
                for (const auto& row : grid) {
                    for (int cell : row) {
                        outputFile << cell << " ";
                    }
                    outputFile << endl;
                }
                outputFile.close();

                grille.run();
            }
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
