#include <vector>
#include <iostream>
#include <algorithm>
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

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderGrid(window,grille);

        sf::sleep(sf::milliseconds(20));
        grille.run();
    }
    return 0;
}