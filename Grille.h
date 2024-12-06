#ifndef GRILLE_H
#define GRILLE_H

#include "Cellule.h"
#include <vector>
using namespace std;

/**
 * @brief Représente la grille dans le jeu de la vie
 *
 */
class Grille
{
    /**
     * @brief Vecteur à deux dimensions pour stocker les Cellules de la grille
     *
     */
    vector<vector<Cellule>> grille;
    /**
     * @brief Indique si le jeu est en cours d'exécution.
     */
    bool running = true;

public:
    Grille();
    Grille(vector<vector<Cellule>> g);
    /**
     * @brief Renvoie la hauteur de la grille
     *
     * @return int
     */
    int getHauteur();
    /**
     * @brief Renvoie la largueur de la grille
     *
     * @return int
     */
    int getLargeur();
    /**
     * @brief Renvoie si la grille évolue à la prochaine iteration ou non
     *
     * @return true
     * @return false
     */
    bool isRunning();
    /**
     * @brief Retourne l'état d'une Cellule à des coordonnées données h,l
     *
     * @param h
     * @param l
     * @return int
     */
    int getValue(int h, int l);
    /**
     * @brief Défini l'état v d'une Cellule à des coordonnées données h,l
     *
     * @param h
     * @param l
     * @param v
     */
    void setValue(int h, int l, int v);
    /**
     * @brief Retourne le nombre de voisins vivants d'une cellule à des coordonnées h,l
     *
     * @param x
     * @param y
     * @return int
     */
    int AliveNeighbors(int x, int y);
    /**
     * @brief Génère la prochaine itération de la grille en suivant les règles du jeu de la vie
     *
     */
    void run();
    /**
     * @brief Affiche la grille dans la console
     *
     */
    void print();
};

#endif