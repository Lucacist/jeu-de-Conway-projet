#include "Cellule.h"

Cellule::Cellule()
{
    this->etat = 0;
}

Cellule::Cellule(int etat)
{
    this->etat = etat;
}

void Cellule::setEtat(int etat)
{
    this->etat = etat;
}

int Cellule::getEtat() const
{
    return this->etat;
}

bool Cellule::operator==(const Cellule &other) const
{
    return this->etat == other.etat;
}
