#include "Fichier.h"
#include <iostream>
#include <fstream>
using namespace std;

Fichier::Fichier(string c){
    this->chemin=c;
    ifstream fichier(chemin);
    fichier>>this->hauteur>>this->largueur;
};

vector<vector<int>> Fichier::versMatrice()
{
    vector<vector<int>> grille(this->hauteur, vector<int>(this->largueur));
    ifstream fichier(chemin);
    fichier.ignore();
    fichier.ignore();
    fichier.ignore();
    fichier.ignore();
    for (int i=0;i<this->hauteur;i++){
        for(int j=0;j<this->largueur;j++){
            fichier>>grille[i][j];
        }
    }
    return grille;
}