#include "Grille.h"
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, string> chars = {{0, "□"}, {1, "■"}, {2, "▲"}, {3, "●"}};

Grille::Grille()
{
    this->grille = {{}};
}

Grille::Grille(vector<vector<Cellule>> g) : grille(g) {}
int Grille::getValue(int h, int l)
{
    return this->grille[h][l].getEtat();
}

void Grille::setValue(int h, int l, int v)
{
    grille[h][l].setEtat(v);
}

void Grille::print()
{
    for (int i = 0; i < grille.size(); i++)
    {
        for (int j = 0; j < grille[0].size(); j++)
        {
            cout << chars[grille[i][j].getEtat()] << " ";
        }
        cout << endl;
    }
};

// Parcourt les 9 cases autour de coordonnées (x,y) données et renvoie le nombre de voisins vivants
int Grille::AliveNeighbors(int x, int y)
{
    int number = 0;
    int rows = grille.size();
    int cols = grille[0].size();

    for (int i = x - 1; i <= x + 1; i++)
    { // Double boucle pour parcourir les deux dimensions
        for (int j = y - 1; j <= y + 1; j++)
        {
            int toricX = (i + rows) % rows; // Utilisation de modulo pour rendre la grille torique
            int toricY = (j + cols) % cols; // Ex: x=101 pour une grille de 100 devient x=1

            if (grille[toricX][toricY].getEtat() == 1 || grille[toricX][toricY].getEtat() == 3)
            {
                number++; // Incrémente le compteur pour chaque voisins vivants ou obstacles vivants
            }
        }
    }

    return number - grille[x][y].getEtat(); // Renvoie le compteur en soustrayant l'état de la Cellule (x,y)
}

int Grille::getHauteur()
{
    return this->grille.size();
}

int Grille::getLargeur()
{
    return this->grille[0].size();
}

bool Grille::isRunning()
{
    return this->running;
}

// Parcourt la grille et applique les règles du jeu de la vie pour génerer la nouvelle itération
void Grille::run()
{
    vector<vector<Cellule>> newGrid = grille;
    for (int i = 0; i < grille.size(); i++)
    {
        for (int j = 0; j < grille[0].size(); j++)
        {
            if (grille[i][j].getEtat() == 1)
            {
                newGrid[i][j] = Cellule(AliveNeighbors(i, j) == 2 || AliveNeighbors(i, j) == 3);
            }
            else if (grille[i][j].getEtat() == 0)
            {
                newGrid[i][j] = Cellule(AliveNeighbors(i, j) == 3);
            }
        }
    }
    if (grille == newGrid)
    {
        running = false; // Si la nouvelle grille est identique à la première, la grille devient figée et le jeu s'arrêtera
    }
    grille = newGrid; // La grille actuelle est remplacée par la nouvelle
}