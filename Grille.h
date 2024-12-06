#ifndef GRILLE_H
#define GRILLE_H

#include "Cellule.h"
#include <vector>
using namespace std;

class Grille{
    vector<vector<Cellule>> grille;
    public:
    bool running=true;
    Grille();
    int getHauteur() const { return grille.size(); }
    int getLargeur() const { return grille[0].size(); }
    bool isRunning() const { return running; }
    Grille(vector<vector<Cellule>> g);
    int getValue(int h, int l) const;
    void setValue(int h,int l,int v);
    int AliveNeighbors(int x,int y);
    void run();
    void print();
};

#endif