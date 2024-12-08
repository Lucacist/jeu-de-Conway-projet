#include "Vue.h"

const int cellSize = 10;

void Vue::renderGrid(sf::RenderWindow &window, Grille &grille)
{
    int hauteur = grille.getHauteur();
    int largeur = grille.getLargeur();

    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (int x = 0; x < hauteur; ++x)
    {
        for (int y = 0; y < largeur; ++y)
        {
            if (grille.getValue(x, y) > 0)
            {
                cell.setFillColor(sf::Color::White);
                cell.setPosition(y * cellSize, x * cellSize);
                if (grille.getValue(x, y) == 2)
                {
                    cell.setFillColor(sf::Color::Red);
                }
                if (grille.getValue(x, y) == 3)
                {
                    cell.setFillColor(sf::Color::Green);
                }
                window.draw(cell);
            }
        }
    }
}

sf::RenderWindow *Vue::initWindow(int hauteur, int largueur)
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(largueur * cellSize, hauteur * cellSize), "Jeu de la vie - Grille");
    return window;
}

void Vue::renderInterface(sf::RenderWindow &window, int hauteur, int largueur, int delai, Grille &grille, bool pause)
{
    sf::Font font;
    if (!font.loadFromFile("Inter-Black.woff2"))
    {
        cout << "Erreur lors de l'ouverture de la police";
    }
    sf::Text textClic;
    textClic.setFont(font);
    textClic.setString("Clic gauche pour ajouter une cellule");
    textClic.setCharacterSize(16);
    textClic.setFillColor(sf::Color::Yellow);
    textClic.setPosition(10, hauteur * cellSize - 60);
    sf::Text textEspace = textClic;
    textEspace.setString("Espace pour mettre en pause");
    textEspace.setPosition(10, hauteur * cellSize - 40);
    sf::Text textFleche = textEspace;
    textFleche.setString("^/v pour modifier la vitesse");
    textFleche.setPosition(10, hauteur * cellSize - 20);
    sf::Text textVitesse = textFleche;
    textVitesse.setPosition(largueur * cellSize - 50, hauteur * cellSize - 20);
    sf::Text textPause = textVitesse;
    textPause.setString("PAUSE");
    textPause.setStyle(sf::Text::Bold);
    textPause.setPosition(largueur * cellSize / 2, hauteur * cellSize / 2 + 50);
    sf::Text textFin = textPause;
    textFin.setString("FIN");
    textFin.setPosition(largueur * cellSize / 2, hauteur * cellSize / 2);
    textFin.setFillColor(sf::Color::Red);
    window.draw(textClic);
    window.draw(textEspace);
    window.draw(textFleche);
    textVitesse.setString(std::to_string(11 - delai));
    window.draw(textVitesse);
    if (grille.isRunning() && pause)
    {
        window.draw(textPause);
    }
    if (!grille.isRunning())
    {
        window.draw(textFin);
    }
}

void Vue::afficherConsole(Grille &grille)
{
    grille.print();
    cout << "---" << endl;
}
