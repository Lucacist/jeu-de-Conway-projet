#include "Fichier.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib> // pour rand() et srand()
#include <ctime>   // pour initialiser rand()

using namespace std;

Fichier::Fichier(string c) {
    this->chemin = c;
    ifstream fichier(chemin);
    if (fichier) {
        fichier >> this->hauteur >> this->largueur;
    } else {
        cerr << "Erreur : impossible d'ouvrir le fichier " << chemin << endl;
    }
}

pair<int, int> Fichier::getDims() {
    return pair<int, int>(hauteur, largueur);
}

Grille Fichier::versGrille() {
    vector<vector<Cellule>> grille(this->hauteur, vector<Cellule>(this->largueur));
    ifstream fichier(chemin);
    int valeur;
    fichier.ignore(); // Ignore les premières lignes si nécessaire
    fichier.ignore();
    fichier.ignore();
    fichier.ignore();
    for (int i = 0; i < this->hauteur; i++) {
        for (int j = 0; j < this->largueur; j++) {
            fichier >> valeur;
            grille[i][j] = Cellule(valeur);
        }
    }
    return grille;
}

// Définition de la méthode genererFichierAleatoire
void Fichier::genererFichierAleatoire(const string &chemin, int hauteur, int largeur) {
    ofstream fichier(chemin);
    if (!fichier) {
        cerr << "Erreur lors de la création du fichier." << endl;
        return;
    }

    srand(time(nullptr)); // Initialisation de la graine pour rand()

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            fichier << rand() % 2 << " "; // Génère des cellules avec des états 0 ou 1
        }
        fichier << endl;
    }

    fichier.close();
    cout << "Fichier généré avec succès : " << chemin << endl;
}

// Définition de la méthode sauvegarderEtat
void Fichier::sauvegarderEtat(const Grille &grille, const string &cheminDossier, int iteration) {
    ostringstream fichierNom;
    fichierNom << cheminDossier << "/iteration_" << iteration << ".txt";

    ofstream fichier(fichierNom.str());
    if (!fichier) {
        cerr << "Erreur lors de la création du fichier : " << fichierNom.str() << endl;
        return;
    }

    // Sauvegarde des données de la grille
    for (int i = 0; i < grille.getHauteur(); ++i) {
        for (int j = 0; j < grille.getLargeur(); ++j) {
            fichier << grille.getValue(i, j) << " ";
        }
        fichier << endl;
    }

    fichier.close();
}
