#include "Grille.h"
#include <iostream>
using namespace std;

Grille::Grille()
{
    this->grille={{}};
}

Grille::Grille(vector<vector<int>> g) : grille(g) {}
int Grille::getValue(int h, int l)
{
    return this->grille[h][l];
}
    
void Grille::print() {
    for (int i=0;i<grille.size();i++){
        for (int j=0;j<grille[0].size();j++){
            if (this->getValue(i,j) > 1) {
                cout << this->getValue(i,j) << endl;
            }
            grille [i][j]==1 ? cout<<"■"<<" ": cout<<"□"<<" ";
        }
        cout<<endl;
    }
};

int Grille::AliveNeighbors(int x, int y) {
    int number = 0;
    int rows = grille.size();
    int cols = grille[0].size();

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            // Calcul des coordonnées toriques
            int toricX = (i + rows) % rows;
            int toricY = (j + cols) % cols;

            // Compter les cellules vivantes
            if (grille[toricX][toricY] == 1) {
                number++;
            }
        }
    }

    // Retirer la cellule elle-même si elle est vivante
    return number - grille[x][y];
}

void Grille::run() {
    vector<vector<int>> newGrid(grille.size(), vector<int>(grille[0].size()));
    for (int i = 0; i < grille.size(); i++) {
        for (int j = 0; j < grille[0].size(); j++) {
            if (grille[i][j] == 1) {
                newGrid[i][j] = (AliveNeighbors(i, j) == 2 || AliveNeighbors(i, j) == 3) ? 1 : 0;
            } else {
                newGrid[i][j] = (AliveNeighbors(i, j) == 3) ? 1 : 0;
            }
        }
    }
    grille = newGrid;
}