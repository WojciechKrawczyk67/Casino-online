#include "GameManager.h"
#include <cstdlib>
#include <ctime>

int main() {
    // Inicjalizacja ziarna dla losowości animacji
    srand(static_cast<unsigned int>(time(nullptr)));

    GameManager game;
    game.run();

    system("pause");
    return 0;
}