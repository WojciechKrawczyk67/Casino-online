#include "UI.h"
#include <iostream>

UI::UI() {}

void UI::drawTable() {
    std::cout << "\n"
                 "==============================================================\n";
    std::cout << "|                          RULETKA                           |\n";
    std::cout << "==============================================================\n";
    std::cout << "|   | 3 | 6 | 9 | 12 | 15 | 18 | 21 | 24 | 27 | 30 | 33 | 36 |\n";
    std::cout << "| 0 |---|---|---|----|----|----|----|----|----|----|----|----|\n";
    std::cout << "|   | 2 | 5 | 8 | 11 | 14 | 17 | 20 | 23 | 26 | 29 | 32 | 35 |\n";
    std::cout << "|---|---|---|---|----|----|----|----|----|----|----|----|----|\n";
    std::cout << "|   | 1 | 4 | 7 | 10 | 13 | 16 | 19 | 22 | 25 | 28 | 31 | 34 |\n";
    std::cout << "==============================================================\n";
}

int UI::displayMenu() {
    int choice = 0;
    while (true) {
        std::cout << "\n--- KASYNO ONLINE ---\n";
        std::cout << "1. Graj\n";
        std::cout << "2. Stan konta\n";
        std::cout << "3. Statystyki\n";
        std::cout << "4. Wyjscie\n";
        std::cout << "Wybierz opcje (1-4): ";

        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 4) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "[BLAD] Nieprawidlowy wybor! Wpisz cyfre od 1 do 4.\n";
        } else {
            return choice;
        }
    }
}

std::string UI::getUserInput() {
    std::string input;
    std::cin >> input;
    return input;
}

void UI::showMessage(const std::string& message) {
    std::cout << message << std::endl;
}

void UI::showStatistics(const Statistics& stats) {
    std::cout << "\n============================================\n";
    std::cout << "|            STATYSTYKI GRACZA             |\n";
    std::cout << "============================================\n";
    std::cout << " Rozegrane rundy: " << stats.getRoundsPlayed() << "\n";
    std::cout << " Wygrane zaklady: " << stats.getBetsWon() << "\n";
    std::cout << " Przegrane zaklady: " << stats.getBetsLost() << "\n";
    std::cout << " Laczna postawiona kwota: " << stats.getTotalWagered() << " zetonow\n";
    std::cout << " Laczna wygrana kwota: " << stats.getTotalWon() << " zetonow\n";
    std::cout << " Najwyzsza jednorazowa wygrana: " << stats.getHighestWin() << " zetonow\n";

    double net = stats.getTotalWon() - stats.getTotalWagered();
    std::cout << " Bilans calkowity (Netto): ";
    if (net > 0) std::cout << "+" << net << " zetonow\n";
    else std::cout << net << " zetonow\n";
    std::cout << "============================================\n";
}