#ifndef FICHIER_H
#define FICHIER_H

#include <string>
#include "Grille.h"
using namespace std;

/**
 * @brief Classe permettant de gérer les fichiers stockant les grilles du jeu
 *
 */
class Fichier
{
    string chemin = "";
    int hauteur = 0;
    int largueur = 0;

public:
    Fichier();
    Fichier(string c);
    /**
     * @brief Renvoie les dimensions de la grille stockés dans le fichier
     *
     * @return pair<int, int>
     */
    pair<int, int> getDims();
    /**
     * @brief Recupère les données du fichier pour créer une grille
     *
     * @return Grille
     */
    Grille versGrille();
    /**
     * @brief Génère une grille de cellules aléatoires et la stocke dans un fichier
     *
     * @param chemin
     * @param hauteur
     * @param largeur
     */
    void genererFichierAleatoire(const string &chemin, int hauteur, int largeur);
    /**
     * @brief Sauvegarde la grille à une itération donnée dans le chemin
     *
     * @param grille
     * @param cheminDossier
     * @param iteration
     */
    void sauvegarderEtat(Grille &grille, const string &cheminDossier, int iteration);
};

#endif
