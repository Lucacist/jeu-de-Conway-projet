#ifndef CELLULE_H
#define CELLULE_H

/**
 * @brief Représente une cellule du jeu de la vie
 * 
 */
class Cellule
{
    /**
     * @brief 0 : Morte, 1 : Vivante, 2 : Obstacle Morte, 3 : Obstacle Vivante
     * 
     */
    int etat;

public:
    Cellule();
    Cellule(int etat);
    /**
     * @brief Défini le nouvel état de la cellule
     * 
     * @param etat le nouvel etat
     */
    void setEtat(int etat);
    /**
     * @brief Renvoie l'état de la cellule
     * 
     * @return int
     */
    int getEtat() const;
    /**
     * @brief Compare l'état de 2 cellules
     * 
     * @param other 
     * @return true
     * @return false 
     */
    bool operator==(const Cellule &other) const;
};

#endif