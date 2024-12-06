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

void renderGrid(sf::RenderWindow &window, Grille &grille,const int &hauteur, const int &largueur) {
    int x, y;
    
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < hauteur; ++x) {
        for (y = 0; y < largueur; ++y) {
            if (grille.getValue(x,y) > 0) {
                cell.setFillColor(sf::Color::White);
                cell.setPosition(y * cellSize, x * cellSize);
                if (grille.getValue(x,y)==2){cell.setFillColor(sf::Color::Red);}
                if (grille.getValue(x,y)==3){cell.setFillColor(sf::Color::Green);}
                window.draw(cell);
            }
        }
    }
}

int main() {

    string chemin;
    cout <<"Entrer le chemin du fichier\n";
    cin>>chemin;

    bool pause=false;

    Fichier fichier{chemin};
    int hauteur = fichier.getDims().first;
    int largueur = fichier.getDims().second;
    Grille grille=fichier.versGrille();

    cout << "Voulez-vous afficher la grille dans :\n1. Le terminal\n2. Une fenêtre graphique\n";
    int choix;
    cin >> choix;

    if (choix == 1) {
        for (int i = 0; i < 10 && grille.running; i++) {
            grille.print();
            cout << "---" << endl;
            grille.run();
        }
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
                if (event.type==sf::Event::KeyPressed){
                    switch(event.key.code){
                        case sf::Keyboard::Space:
                        pause=!pause;
                        break;

                    }
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    cout << "Mouse Position: (" << mousePos.x << ", " << mousePos.y << ")" << endl;
                    grille.setValue((int)(mousePos.y/cellSize),(int)(mousePos.x/cellSize),!grille.getValue((int)(mousePos.y/cellSize),(int)(mousePos.x/cellSize)));
                }
            }
            renderGrid(window,grille,hauteur,largueur);
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
