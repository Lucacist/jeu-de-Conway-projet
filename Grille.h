#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
using namespace std;

class Grille{
    vector<vector<int>> grille;
    public:
    Grille();
    Grille(vector<vector<int>> g);
    int getValue(int h,int l);
    int AliveNeighbors(int x,int y);
    void run();
    void print();
};

#endif