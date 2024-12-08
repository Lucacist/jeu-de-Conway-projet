#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vue.h"

using namespace std;

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
