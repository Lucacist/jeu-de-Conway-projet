#include "Controller.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <cstdlib>
#include <ctime>
#include "Grille.h"
#include "Fichier.h"
#include "Vue.h"
#include "Controller.h"

using namespace std;
namespace fs = std::filesystem;

int main()
{
    Vue vue;
    Controller controller{vue};
    controller.run();
    return 0;
}