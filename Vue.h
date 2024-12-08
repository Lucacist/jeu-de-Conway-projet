#ifndef VUE_H
#define VUE_H

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

class Vue
{
    vector<sf::Text> texts;

public:
    void renderGrid(sf::RenderWindow &window, Grille &grille);
    sf::RenderWindow *initWindow(int hauteur, int largueur);
    void renderInterface(sf::RenderWindow &window, int hauteur, int largueur, int delai, Grille &grille, bool pause);
    void afficherConsole(Grille &grille);
};

#endif