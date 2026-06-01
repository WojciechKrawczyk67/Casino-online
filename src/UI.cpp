#include "UI.h"
#include <iostream>
#include <thread>
#include <chrono>

UI::UI() {}

void UI::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

std::string UI::colorizeNumber(int number) {
    if (number == 0) return GREEN_TEXT + "0" + RESET;
    int redNumbers[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
    for (int n : redNumbers) {
        if (number == n) return RED_TEXT + std::to_string(number) + RESET;
    }
    return std::to_string(number);
}

void UI::drawTable() {
    clearScreen();
    std::cout << YELLOW_TEXT;
    std::cout << "\n==============================================================\n";
    std::cout << "|                          RULETKA                           |\n";
    std::cout << "==============================================================\n" << RESET;
    std::cout << "|   | " << RED_TEXT << "3" << RESET << " | 6 | " << RED_TEXT << "9" << RESET << " | " << RED_TEXT << "12" << RESET << " | 15 | " << RED_TEXT << "18" << RESET << " | " << RED_TEXT << "21" << RESET << " | 24 | " << RED_TEXT << "27" << RESET << " | " << RED_TEXT << "30" << RESET << " | 33 | " << RED_TEXT << "36" << RESET << " |\n";
    std::cout << "|" << GREEN_TEXT << " 0 " << RESET << "|---|---|---|----|----|----|----|----|----|----|----|----|\n";
    std::cout << "|   | 2 | " << RED_TEXT << "5" << RESET << " | 8 | 11 | " << RED_TEXT << "14" << RESET << " | 17 | 20 | " << RED_TEXT << "23" << RESET << " | 26 | 29 | " << RED_TEXT << "32" << RESET << " | 35 |\n";
    std::cout << "|---|---|---|---|----|----|----|----|----|----|----|----|----|\n";
    std::cout << "|   | " << RED_TEXT << "1" << RESET << " | 4 | " << RED_TEXT << "7" << RESET << " | 10 | 13 | " << RED_TEXT << "16" << RESET << " | " << RED_TEXT << "19" << RESET << " | 22 | " << RED_TEXT << "25" << RESET << " | 28 | 31 | " << RED_TEXT << "34" << RESET << " |\n";
    std::cout << YELLOW_TEXT << "==============================================================\n" << RESET;
}

int UI::displayMenu() {
    int choice = 0;
    while (true) {
        std::cout << CYAN_TEXT << "\n--- KASYNO ONLINE ---\n" << RESET;
        std::cout << "1. Wejdz do stolu (Graj)\n";
        std::cout << "2. Stan konta\n";
        std::cout << "3. Statystyki\n";
        std::cout << "4. Wyjscie\n";
        std::cout << "Wybierz opcje (1-4): ";

        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 4) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            showMessage("[BLAD] Nieprawidlowy wybor!", RED_TEXT);
        } else {
            return choice;
        }
    }
}

int UI::displayBettingMenu() {
    int choice = -1;
    while (true) {
        std::cout << "\n[ FAZA OBSTAWIANIA ]\n";
        std::cout << "1. Kolor (Czerwone / Czarne) [1:1]\n";
        std::cout << "2. Parzystosc (Parzyste / Nieparzyste) [1:1]\n";
        std::cout << "3. Polowki (Niskie / Wysokie) [1:1]\n";
        std::cout << "4. Konkretny numer (0-36) [35:1]\n";
        std::cout << "5. Tuzin (1-12, 13-24, 25-36) [2:1]\n";
        std::cout << "6. Kolumna (1, 2, 3) [2:1]\n";
        std::cout << "7. Split (Dwa numery obok siebie) [17:1]\n";
        std::cout << "8. Ulica (Trzy numery w rzedzie) [11:1]\n";
        std::cout << "9. Rog (Cztery numery kwadratu) [8:1]\n";
        std::cout << "10. Linia (Szesc numerow, dwa rzedy) [5:1]\n";
        std::cout << GREEN_TEXT << "0. ZAKONCZ OBSTAWIANIE I ZAKREC KOLEM!\n" << RESET;
        std::cout << "Wybor: ";

        std::cin >> choice;

        if (std::cin.fail() || choice < 0 || choice > 10) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            showMessage("[BLAD] Nieprawidlowy wybor! Podaj cyfre 0-10.", RED_TEXT);
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

void UI::showMessage(const std::string& message, const std::string& color) {
    if (!color.empty()) std::cout << color;
    std::cout << message;
    if (!color.empty()) std::cout << RESET;
    std::cout << std::endl;
}

void UI::spinAnimation(int winningNumber) {
    std::cout << CYAN_TEXT << "\nKrupier wprawia kolo w ruch";
    for(int i = 0; i < 4; ++i) {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "\nKuleczka skacze po numerach: ";
    for(int i = 0; i < 15; ++i) {
        int randomNum = rand() % 37;
        std::cout << randomNum << " ";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(150 + (i * 15)));
    }

    std::cout << "\n\n" << YELLOW_TEXT << "====================================\n";
    std::cout << "      WYLOSOWANO NUMER: " << colorizeNumber(winningNumber) << "\n";
    std::cout << YELLOW_TEXT << "====================================\n" << RESET;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void UI::showStatistics(const Statistics& stats) {
    clearScreen();
    std::cout << CYAN_TEXT << "\n============================================\n";
    std::cout << "|            STATYSTYKI GRACZA             |\n";
    std::cout << "============================================\n" << RESET;
    std::cout << " Rozegrane rundy: " << stats.getRoundsPlayed() << "\n";
    std::cout << " Wygrane zaklady: " << stats.getBetsWon() << "\n";
    std::cout << " Przegrane zaklady: " << stats.getBetsLost() << "\n";
    std::cout << " Laczna postawiona kwota: " << (int)stats.getTotalWagered() << " zetonow\n";
    std::cout << " Laczna wygrana kwota: " << GREEN_TEXT << (int)stats.getTotalWon() << RESET << " zetonow\n";
    std::cout << " Najwyzsza jednorazowa wygrana: " << (int)stats.getHighestWin() << " zetonow\n";

    double net = stats.getTotalWon() - stats.getTotalWagered();
    std::cout << " Bilans calkowity (Netto): ";
    if (net > 0) std::cout << GREEN_TEXT << "+" << (int)net << RESET << " zetonow\n";
    else if (net < 0) std::cout << RED_TEXT << (int)net << RESET << " zetonow\n";
    else std::cout << "0 zetonow\n";
    std::cout << CYAN_TEXT << "============================================\n\n" << RESET;
}