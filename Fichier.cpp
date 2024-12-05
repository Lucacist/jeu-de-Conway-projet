#include "Fichier.h"
#include <iostream>
#include <fstream>
using namespace std;

Fichier::Fichier(string c){
    this->chemin=c;
    ifstream fichier(chemin);
    fichier>>this->hauteur>>this->largueur;
}
pair<int, int> Fichier::getDims()
{
    return pair<int, int>(hauteur,largueur);
};

Grille Fichier::versGrille()
{
    vector<vector<Cellule>> grille(this->hauteur, vector<Cellule>(this->largueur));
    ifstream fichier(chemin);
    int valeur;
    fichier.ignore();
    fichier.ignore();
    fichier.ignore();
    fichier.ignore();
    for (int i=0;i<this->hauteur;i++){
        for(int j=0;j<this->largueur;j++){
            fichier>>valeur;
            grille[i][j]=Cellule(valeur);
        }
    }
    return grille;
}