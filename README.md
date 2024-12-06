# Livrable Programme

https://github.com/Lucacist/jeu-de-Conway-projet

# **Document Technique : Projet POO - Le Jeu de la Vie**

## **1. Introduction**
Le *Jeu de la Vie* est un automate cellulaire créé par le mathématicien John Conway. Il modélise l’évolution d’une population de cellules vivantes ou mortes dans une grille bidimensionnelle, selon des règles précises. Ce projet a pour objectif de développer une simulation du Jeu de la Vie en C++ en s'appuyant sur les principes de la programmation orientée objet (POO).

## **2. Principe de Fonctionnement**
- **Règles d’évolution des cellules :**
  1. Une cellule morte avec exactement **trois voisines vivantes** devient vivante.
  2. Une cellule vivante avec **deux ou trois voisines vivantes** reste vivante, sinon elle meurt.

- **États des cellules :**
  - 1 : Vivante
  - 0 : Morte

- **Structure :**
  - Grille bidimensionnelle.
  - Les cellules sont affectées par leur voisinage (8 cellules adjacentes, sauf en mode torique).

## **3. Spécifications Techniques**
### **3.1. Fonctionnalités de Base**
1. **Mode Console :**
   - Lecture d'un fichier d'entrer qui nous permet d'obtenir une grille et l'état initial des cellules.
   - Simulation des états successifs pour un nombre donné d'itérations.
   - Sauvegarde des états dans un répertoire nommé `<nom_du_fichier_dentree>_out`.

2. **Mode Graphique (avec SFML) :**
   - Affichage de la grille et des états des cellules en temps réel.
   - Contrôle du temps entre deux itérations avec les touches "<" et ">".
   - Possibilité de **modifier l'état des cellules avec la souris**.

### **3.2. Extensions Réalisées**
1. **Grille Torique :**
   - Les cellules des bords sont adjacentes à celles situées à l’opposé (ligne/colonne).
     
2. **Cellules obstacle :**
   - L’état des cellules obstacles n’évolue pas au cours de l’exécution. Ces dernières possèdent un état vivant "3" ou mort "4". 

### **3.3. Bonus**
1. **Modification Dynamique des Cellules (Mode Graphique) :**
   - Interaction par clic pour **ajouter/supprimer des cellules** en fonction de la position du curseur.

2. **Pause dans le Mode Graphique :**
   - Ajout d’un système de pause pour interrompre la simulation.

3. **Fichier Aléatoire :**
   - Génération automatique d'un fichier d’entrée aléatoire si le fichier spécifié n’existe pas.
   - Dimensions demandées à l'utilisateur.

## **4. Implémentation en C++**
- **Langage :** C++
- **Bibliothèque graphique :** SFML.
- **Structure du projet :**
   - `main.cpp` : Contient le point d'entrée du programme, gère la logique principale de la simulation et l'interface utilisateur (mode console ou graphique).  
   - `Cellule.h/.cpp` : Définit la classe Cellule, avec ses états (vivant ou mort), et les méthodes pour calculer son prochain état en fonction de son voisinage.  
   - `Grille.h/.cpp` : Gère la grille de cellules. 
   - `Fichier.h/.cpp` : Contient les fonctions pour lire un fichier d'entrée contenant l'état initial des cellules et écrire les états successifs dans des fichiers de sortie.  
   - `Makefile` : Script de compilation automatisé pour construire le projet, en gérant les dépendances et les règles pour produire l'exécutable.  
   - `Input.txt` : Fichier d'entrée de base, contenant la taille de la grille et l'état initial des cellules. Ce fichier est utilisé pour initialiser la simulation.  
   - `\Input.txt_out` : Dossier de sortie par défaut, où sont sauvegardés les fichiers correspondant aux états successifs de la grille à chaque itération pour le fichier d'entrée par default (Input.txt).  
