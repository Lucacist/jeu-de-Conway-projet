#ifndef FICHIER_H
#define FICHIER_H

#include <string>
#include <vector>
#include "Grille.h"
using namespace std;

class Fichier{
    string chemin="";
    int hauteur=0;
    int largueur=0;
    public:
    Fichier(string c);
    pair<int, int> getDims();
    Grille versGrille();
};

#endif