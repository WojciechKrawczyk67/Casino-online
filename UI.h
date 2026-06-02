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
    const std::string RESET   = "\033[0m";
    const std::string RED     = "\033[1;31m"; // Pogrubiony czerwony
    const std::string GREEN   = "\033[1;32m"; // Pogrubiony zielony
    /**
     * @brief Konstruktor domyślny.
     */
    UI() {}

    /**
     * @brief Funkcja wyświetlająca makietę stołu do ruletki (ASCII Art)
     */
    void drawTable() {
        std::cout << "\n"
                     "==============================================================\n";
        std::cout << "|                          RULETKA                           |\n";
        std::cout << "==============================================================\n";
        std::cout << "|   | " << RED << "3" << RESET << " | 6 | " << RED << "9" << RESET << " | " << RED << "12" << RESET << " | 15 | " << RED << "18" << RESET << " | " << RED << "21" << RESET << " | 24 | " << RED << "27" << RESET << " | " << RED << "30" << RESET << " | 33 | " << RED << "36" << RESET << " |\n";
        std::cout << "| " << GREEN << "0" << RESET << " |---|---|---|----|----|----|----|----|----|----|----|----|\n";
        std::cout << "|   | 2 | " << RED << "5" << RESET << " | 8 | 11 | " << RED << "14" << RESET << " | 17 | 20 | " << RED << "23" << RESET << " | 26 | 29 | " << RED << "32" << RESET << " | 35 |\n";
        std::cout << "|---|---|---|---|----|----|----|----|----|----|----|----|----|\n";
        std::cout << "|   | " << RED << "1" << RESET << " | 4 | " << RED << "7" << RESET << " | 10 | 13 | " << RED << "16" << RESET << " | " << RED << "19" << RESET << " | 22 | " << RED << "25" << RESET << " | 28 | 31 | " << RED << "34" << RESET << " |\n";
        std::cout << "==============================================================\n";
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
