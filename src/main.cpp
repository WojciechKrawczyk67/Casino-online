#include "GameManager.h"
#include <cstdlib>

int main() {
    GameManager game;
    game.run();

    // Zatrzymuje okno konsoli przed natychmiastowym zamknięciem po zakończeniu gry
    system("pause");
    return 0;
}