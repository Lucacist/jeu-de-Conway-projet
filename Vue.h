#ifndef VUE_H
#define VUE_H

#include <SFML/Graphics.hpp>
#include "Grille.h"

/**
 * @brief Classe permettant de gérer l'affichage des deux modes
 *
 */
class Vue
{
public:
    /**
     * @brief Affiche la grille dans l'interface graphique
     *
     * @param window
     * @param grille
     */
    void renderGrid(sf::RenderWindow &window, Grille &grille);
    /**
     * @brief Ouvre une fenêtre de jeu
     *
     * @param hauteur
     * @param largueur
     * @return sf::RenderWindow*
     */
    sf::RenderWindow *initWindow(int hauteur, int largueur);
    /**
     * @brief Affiche les différents textes sur la fenêtre
     *
     * @param window
     * @param hauteur
     * @param largueur
     * @param delai
     * @param grille
     * @param pause
     */
    void renderInterface(sf::RenderWindow &window, int hauteur, int largueur, int delai, Grille &grille, bool pause);
    /**
     * @brief Affiche la grille dans la console
     *
     * @param grille
     */
    void afficherConsole(Grille &grille);
};

#endif
