//
// Created by student164 on 19.05.2026.
//

#ifndef FOLDERNPGWOJCIECHKRAWCZYK_UI_H
#define FOLDERNPGWOJCIECHKRAWCZYK_UI_H

#include <iostream>
#include <string>

/**
 * @class UI
 * @brief Odpowiada za wyświetlanie danych w konsoli i interakcję z użytkownikiem.
 */
class UI {
public:
    /**
     * @brief Konstruktor domyślny.
     */
    UI() {}

    /**
     * @brief Funkcja wyświetlająca makietę stołu do ruletki (ASCII Art)
     */
    void drawTable() {
        std::cout << "\n============================================\n";
        std::cout << "|                 RULETKA                  |\n";
        std::cout << "============================================\n";
        std::cout << "|   | 3 | 6 | 9 | 12 | 15 | 18 | 21 | 24 | 27 | 30 | 33 | 36 |\n";
        std::cout << "| 0 |---|---|---|----|----|----|----|----|----|----|----|----|\n";
        std::cout << "|   | 2 | 5 | 8 | 11 | 14 | 17 | 20 | 23 | 26 | 29 | 32 | 35 |\n";
        std::cout << "|---|---|---|---|----|----|----|----|----|----|----|----|----|\n";
        std::cout << "|   | 1 | 4 | 7 | 10 | 13 | 16 | 19 | 22 | 25 | 28 | 31 | 34 |\n";
        std::cout << "============================================\n";
    }

    /**
     * @brief Wyświetla główne menu gry i pobiera poprawny wybór.
     */
    int displayMenu() {
        int choice = 0;
        while (true) {
            std::cout << "\n--- KASYNO ONLINE ---\n";
            std::cout << "1. Graj\n";
            std::cout << "2. Stan konta\n";
            std::cout << "3. Statystyki\n";
            std::cout << "4. Wyjscie\n";
            std::cout << "Wybierz opcje (1-4): ";
            
            std::cin >> choice;

            // Zabezpieczenie przed wpisaniem liter zamiast cyfr
            if (std::cin.fail() || choice < 1 || choice > 4) {
                std::cin.clear(); 
                std::cin.ignore(10000, '\n'); 
                std::cout << "[BLAD] Nieprawidlowy wybor! Wpisz cyfre od 1 do 4.\n";
            } else {
                return choice; 
            }
        }
    }

    /**
     * @brief Pobiera komendę od użytkownika.
     * @return Tekst wprowadzony przez gracza.
     */
    std::string getUserInput() { 
        std::string input;
        std::cin >> input;
        return input;
    }

    /**
     * @brief Wypisuje komunikat w konsoli.
     * @param message Komunikat do wyświetlenia.
     */
    void showMessage(const std::string& message) {
        std::cout << message << std::endl;
    }
};

#endif //FOLDERNPGWOJCIECHKRAWCZYK_UI_H
