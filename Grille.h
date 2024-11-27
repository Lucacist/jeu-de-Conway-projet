#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <iostream>

class Grille {
private:
    std::vector<std::vector<int>> grid;

public:
    Grille(const std::vector<std::vector<int>>& g) : grid(g) {}

    int AliveNeighbors(int x, int y);

    void run();

    void print() const;

    // Accesseur pour la grille (nécessaire pour le rendu graphique)
    const std::vector<std::vector<int>>& getGrid() const {
        return grid;
    }
};

#endif
