#include "Grille.h"
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, string> chars = {{0, "□"}, {1, "■"},{2,"▲"},{3,"●"}};

Grille::Grille()
{
    this->grille={{}};
}

Grille::Grille(vector<vector<Cellule>> g) : grille(g) {}
int Grille::getValue(int h, int l) const
{
    return this->grille[h][l].getEtat();
}

void Grille::setValue(int h, int l, int v)
{
    grille[h][l].setEtat(v);
}

void Grille::print() {
    for (int i=0;i<grille.size();i++){
        for (int j=0;j<grille[0].size();j++){
            cout << chars[grille[i][j].getEtat()]<<" ";
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
            if (grille[toricX][toricY].getEtat() == 1 || grille[toricX][toricY].getEtat()==3) {
                number++;
            }
        }
    }

    // Retirer la cellule elle-même si elle est vivante
    return number - grille[x][y].getEtat();
}

void Grille::run() {
    vector<vector<Cellule>> newGrid=grille;
    for (int i = 0; i < grille.size(); i++) {
        for (int j = 0; j < grille[0].size(); j++) {
            if (grille[i][j].getEtat() == 1) {
                newGrid[i][j] =Cellule(AliveNeighbors(i, j) == 2 || AliveNeighbors(i, j) == 3);
            } else if (grille[i][j].getEtat()==0) {
                newGrid[i][j] = Cellule(AliveNeighbors(i, j) == 3);
            }
        }
    }
    if (grille==newGrid){
        running=false;
    }
    grille = newGrid;
}