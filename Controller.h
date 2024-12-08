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
    /**
     * @brief Construis un objet Controller avec une Vue donnée
     *
     * @param vue
     */
    Controller(Vue vue);
    /**
     * @brief Éxecute une partie du jeu
     *
     */
    void run();
    /**
     * @brief Vide le dossier de tout fichiers
     *
     * @param cheminDossier
     */
    void nettoyerDossier(const string &cheminDossier);
};

#endif