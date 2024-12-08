#include "Fichier.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Fichier::Fichier()
{
    this->hauteur = 0;
    this->largueur = 0;
    this->chemin = "";
}

Fichier::Fichier(string c)
{
    this->chemin = c;
    ifstream fichier(chemin);
    if (fichier)
    {
        fichier >> this->hauteur >> this->largueur;
    }
    else
    {
        cerr << "Erreur : impossible d'ouvrir le fichier " << chemin << endl;
    }
}

pair<int, int> Fichier::getDims()
{
    return pair<int, int>(hauteur, largueur);
}

Grille Fichier::versGrille()
{
    vector<vector<Cellule>> grille(this->hauteur, vector<Cellule>(this->largueur));
    ifstream fichier(chemin);
    int valeur;
    fichier.ignore();
    fichier.ignore();
    fichier.ignore();
    fichier.ignore();
    for (int i = 0; i < this->hauteur; i++)
    {
        for (int j = 0; j < this->largueur; j++)
        {
            fichier >> valeur;
            grille[i][j] = Cellule(valeur);
        }
    }
    return grille;
}

void Fichier::genererFichierAleatoire(const string &chemin, int hauteur, int largeur)
{
    this->hauteur = hauteur;
    this->largueur = largeur;
    ofstream fichier(chemin);
    if (!fichier)
    {
        cerr << "Erreur lors de la création du fichier." << endl;
        return;
    }
    fichier << this->hauteur << " " << this->largueur << " " << endl;
    srand(time(nullptr));
    for (int i = 0; i < hauteur; ++i)
    {
        for (int j = 0; j < largeur; ++j)
        {
            fichier << rand() % 2 << " ";
        }
        fichier << endl;
    }

    fichier.close();
    cout << "Fichier généré avec succès : " << chemin << endl;
}

void Fichier::sauvegarderEtat(Grille &grille, const string &cheminDossier, int iteration)
{
    ostringstream fichierNom;
    fichierNom << cheminDossier << "/iteration_" << iteration << ".txt";

    ofstream fichier(fichierNom.str());
    if (!fichier)
    {
        cerr << "Erreur lors de la création du fichier : " << fichierNom.str() << endl;
        return;
    }

    for (int i = 0; i < grille.getHauteur(); ++i)
    {
        for (int j = 0; j < grille.getLargeur(); ++j)
        {
            fichier << grille.getValue(i, j) << " ";
        }
        fichier << endl;
    }

    fichier.close();
}
