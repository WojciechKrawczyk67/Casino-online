//
// Created by student164 on 19.05.2026.
//

#ifndef FOLDERNPGWOJCIECHKRAWCZYK_UI_H
#define FOLDERNPGWOJCIECHKRAWCZYK_UI_H
#pragma once
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
     * @brief Wyświetla główne menu gry.
     */
    void displayMenu() {}

    /**
     * @brief Pobiera komendę od użytkownika.
     * @return Tekst wprowadzony przez gracza.
     */
    std::string getUserInput() { return ""; }

    /**
     * @brief Wypisuje komunikat w konsoli.
     * @param message Komunikat do wyświetlenia.
     */
    void showMessage(const std::string& message) {}
};
#endif //FOLDERNPGWOJCIECHKRAWCZYK_UI_H
