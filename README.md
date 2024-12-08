# 🚀 **Livrable Programme**

![Static Badge](https://img.shields.io/badge/fait_avec-c++-blue?logo=cplusplus)  
![Static Badge](https://img.shields.io/badge/Headers-purple?logo=c)  
![Static Badge](https://img.shields.io/badge/makefile-orange.svg?logo=data:image/svg%2bxml;base64,PHN2ZyByb2xlPSJpbWciIHZpZXdCb3g9IjAgMCAyNCAyNCIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj48dGl0bGU+QW5rZXJNYWtlPC90aXRsZT48cGF0aCBkPSJtMTIuMzUgMTAuNDYyIDMuMDc1IDMuMTIyYy4xODcuMTg3LjE4Ny40MiAwIC42MDZsLTMuMTIyIDMuMTIzYy0uMTg2LjE4Ni0uNDIuMTg2LS42MDYgMEw4LjU3NSAxNC4xOWMtLjE4Ny0uMTg2LS4xODctLjQxOSAwLS42MDZsMy4xNjktMy4xMjJjLjE4Ni0uMTg2LjQxOS0uMTg2LjYwNiAwWm0tMS41ODUtMS41ODRjLjE0LjE4Ni4xNC40MTktLjA0Ny42MDVsLTMuMTIyIDMuMTIzYy0uMTg2LjE4Ni0uNDE5LjE4Ni0uNjA2IDBsLTEuNzI0LTEuNzI0djEyLjY3NUgwVi40NDNoMi4zM2w4LjQzNSA4LjQzNVpNMjEuNzE3LjQ0M0gyNHYyMy4xMTRoLTUuMjY2VjEwLjg4MmwtMS43MjQgMS43MjRjLS4xODcuMTg2LS40Mi4xODYtLjYwNiAwbC0zLjEyMi0zLjEyM2MtLjE4Ny0uMTg2LS4xODctLjQxOSAwLS42MDVMMjEuNzE3LjQ0M1oiLz48L3N2Zz4=)

[👉 Voir le projet sur GitHub](https://github.com/Lucacist/jeu-de-Conway-projet)

# 📋 **Sommaire**

1. **[Introduction](#-1-introduction)**  
   - Présentation du projet et des objectifs.  

2. **[Principe de Fonctionnement](#%EF%B8%8F-2-principe-de-fonctionnement)**  
   - Règles d’évolution des cellules.  
   - Structure de la grille et états des cellules.  

3. **[Spécifications Techniques](#%EF%B8%8F-3-sp%C3%A9cifications-techniques)**  
   - **[Fonctionnalités de Base](#-31-fonctionnalit%C3%A9s-de-base)**  
     - Mode console.  
     - Mode graphique avec SFML.  
   - **[Extensions Réalisées](#-32-extensions-r%C3%A9alis%C3%A9es)**  
     - Grille torique.  
     - Cellules obstacles.  
   - **[Bonus](#-33-bonus)**  
     - Modification dynamique des cellules.  
     - Pause dans le mode graphique.  
     - Génération d’un fichier aléatoire.  

4. **[Implémentation en C++](#-4-impl%C3%A9mentation-en-c)**  
   - Langage et bibliothèques utilisés.  
   - Structure du projet.

5. **[Lancer le Jeu](#-5-lancer-le-jeu)**  
   - Ouvrir le terminal et accéder au dossier du projet.  
   - Compiler le projet avec `make`.  
   - Lancer le jeu avec `./main`.  
   - Suivre les consignes affichées dans le terminal.

---

   <br>  

# 📄 Document Technique : Projet POO - Le Jeu de la Vie

   <br>  

## 📝 **1. Introduction**  
Le *Jeu de la Vie* est un automate cellulaire créé par le mathématicien John Conway. Il modélise l’évolution d’une population de cellules vivantes ou mortes dans une grille bidimensionnelle, selon des règles précises. Ce projet a pour objectif de développer une simulation du Jeu de la Vie en C++ en s'appuyant sur les principes de la programmation orientée objet (POO).

   <br>  

## ⚙️ **2. Principe de Fonctionnement**  
- **Règles d’évolution des cellules :**  
  1. Une cellule morte avec exactement **trois voisines vivantes** devient vivante.  
  2. Une cellule vivante avec **deux ou trois voisines vivantes** reste vivante, sinon elle meurt.

- **États des cellules :**  
  - 1 : Vivante  
  - 0 : Morte

- **Structure :**  
  - Grille bidimensionnelle.  
  - Les cellules sont affectées par leur voisinage (8 cellules adjacentes, sauf en mode torique).

   <br>  

## 🖥️ **3. Spécifications Techniques**  
### ✨ **3.1. Fonctionnalités de Base**
1. **Mode Console :**  
   - Lecture d'un fichier d'entrer qui nous permet d'obtenir une grille et l'état initial des cellules.  
   - Simulation des états successifs pour un nombre donné d'itérations.  
   - Sauvegarde des états dans un répertoire nommé `<nom_du_fichier_dentree>_out`.

    <br>  

   <img style="width:400px;" alt="Capture d'écran 2024-12-06 143850" src="https://github.com/user-attachments/assets/30dbaa17-e091-4d56-a4ca-13f2066b3b0f">  
   <br>  

1. **Mode Graphique (avec SFML) :**  
   - Affichage de la grille et des états des cellules en temps réel.  
   - Contrôle du temps entre deux itérations avec les touches "<" et ">".  
   - Possibilité de **modifier l'état des cellules avec la souris**.
  
        <br>  

   <img width="400" alt="Capture d'écran 2024-12-06 144330" src="https://github.com/user-attachments/assets/3f1c7202-4596-4429-9ac7-7563f1d5c524">

### 🌟 **3.2. Extensions Réalisées**
1. **Grille Torique :**  
   - Les cellules des bords sont adjacentes à celles situées à l’opposé (ligne/colonne).
     
2. **Cellules obstacle :**  
   - L’état des cellules obstacles n’évolue pas au cours de l’exécution. Ces dernières possèdent un état vivant "3 ou vert" ou mort "4 ou rouge".

### 💡 **3.3. Bonus**
1. **Modification Dynamique des Cellules (Mode Graphique) :**  
   - Interaction par clic pour **ajouter/supprimer des cellules** en fonction de la position du curseur.

2. **Pause dans le Mode Graphique :**  
   - Ajout d’un système de pause pour interrompre la simulation.

3. **Fichier Aléatoire :**  
   - Génération automatique d'un fichier d’entrée aléatoire si le fichier spécifié n’existe pas.  
   - Dimensions demandées à l'utilisateur.

   <br>  

## 🔧 **4. Implémentation en C++**
- **Langage :** C++  
- **Bibliothèque graphique :** SFML.  
- **Structure du projet :**  
   - `main.cpp` : Contient le point d'entrée du programme, gère la logique principale de la simulation et l'interface utilisateur (mode console ou graphique).  
   - `Cellule.h/.cpp` : Définit la classe Cellule, avec ses états (vivant ou mort), et les méthodes pour calculer son prochain état en fonction de son voisinage.  
   - `Grille.h/.cpp` : Gère la grille de cellules.  
   - `Fichier.h/.cpp` : Contient les fonctions pour lire un fichier d'entrée contenant l'état initial des cellules et écrire les états successifs dans des fichiers de sortie.
   - `Vue.h/.cpp` : Permet d'afficher la grille dans la console, ou dans une interface graphique grâce à la bibliothèque SFML
   - `Controller.h/.cpp` : Gère les fichiers, les grilles et les choix de l'utilisateur pour éxécuter une partie  
   - `Makefile` : Script de compilation automatisé pour construire le projet, en gérant les dépendances et les règles pour produire l'exécutable.  
   - `Input.txt` : Fichier d'entrée de base, contenant la taille de la grille et l'état initial des cellules. Ce fichier est utilisé pour initialiser la simulation.  
   - `\Input.txt_out` : Dossier de sortie par défaut, où sont sauvegardés les fichiers correspondant aux états successifs de la grille à chaque itération pour le fichier d'entrée par default (Input.txt).

    <br>  

## 🚀 **5. Lancer le Jeu**

### 1. **Ouvrir le Terminal**
   - Ouvrez votre terminal (sur Linux).

### 2. **Accéder au Dossier du Projet**
   - Utilisez la commande `cd` pour naviguer dans le dossier où sont stockés les fichiers du projet. Par exemple :
     ```bash
     cd chemin/vers/le/dossier/du/projet
     ```

### 3. **Compiler le Projet avec `make`**
   - Une fois dans le dossier du projet, tapez la commande suivante pour compiler le projet en utilisant le `Makefile` :
     ```bash
     make
     ```
   - Cela générera un exécutable nommé `main`.

### 4. **Lancer le Jeu**
   - Après la compilation, vous pourrez lancer le jeu avec la commande suivante :
     ```bash
     ./main
     ```
   
### 5. **Suivre les Consignes**
   - Une fois le jeu lancé, suivez les consignes qui s'affichent dans le terminal pour interagir avec le jeu.  
     vous pourrez choisir entre les modes console ou graphique, et configurer la simulation en fonction de vos préférences.
