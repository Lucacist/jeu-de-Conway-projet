#ifndef CONTROLLER_H
#define CONTROLLER_H

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

class Controller
{
    Vue vue;

public:
    Controller(Vue vue);
    void run();
    void nettoyerDossier(const string &cheminDossier);
};

#endif