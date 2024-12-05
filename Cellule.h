#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
    int etat;
public:
    Cellule();
    Cellule(int etat);
    void setEtat(int etat);
    int getEtat();
    bool operator==(const Cellule &other) const; // Add this line
};

#endif