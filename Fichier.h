// Fichier.h
#ifndef FICHIER_H
#define FICHIER_H

#include <string>
#include <vector>
#include "Grille.h"
using namespace std;

class Fichier {
    string chemin = "";
    int hauteur = 0;
    int largueur = 0;
public:
    Fichier();
    Fichier(string c);
    pair<int, int> getDims();
    Grille versGrille();
    void genererFichierAleatoire(const string &chemin, int hauteur, int largeur);  // Déclaration de la méthode
    void sauvegarderEtat(const Grille &grille, const string &cheminDossier, int iteration);  // Déclaration de la méthode
};

#endif
