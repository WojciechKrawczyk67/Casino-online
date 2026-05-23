//
// Created by student164 on 19.05.2026.
//

#ifndef FOLDERNPGWOJCIECHKRAWCZYK_BETMANAGER_H
#define FOLDERNPGWOJCIECHKRAWCZYK_BETMANAGER_H
#pragma once

/**
 * @class BetManager
 * @brief Odpowiada za weryfikację zakładów i rozliczanie wygranych.
 */
class BetManager {
public:
    /**
     * @brief Konstruktor domyślny.
     */
    BetManager() {}//
// Created by student164 on 19.05.2026.
//

#ifndef FOLDERNPGWOJCIECHKRAWCZYK_BETMANAGER_H
#define FOLDERNPGWOJCIECHKRAWCZYK_BETMANAGER_H
#pragma once

#include <vector>
#include <memory>
#include "Bet.h"

/**
 * @class BetManager
 * @brief Odpowiada za weryfikację zakładów i rozliczanie wygranych.
 */
class BetManager {
private:
    // Koszyk zakładów z bieżącej rundy
    std::vector<std::unique_ptr<Bet>> activeBets;

public:
    /**
     * @brief Konstruktor domyślny.
     */
    BetManager();

    /**
     * @brief Przyjmuje zakład od gracza i umieszcza w koszyku.
     * @param betType Typ zakładu (np. 1-Czerwone, 2-Czarne, 3-Parzyste, 4-Nieparzyste, 5-Niskie, 6-Wysokie)
     * @param amount Kwota zakładu.
     * @return true jeśli zakład został przyjęty pomyślnie.
     */
    bool placeBet(int betType, double amount);

    /**
     * @brief Rozlicza zakłady na podstawie wylosowanego numeru.
     * @param winningNumber Zwycięski numer z koła.
     * @return Sumaryczna kwota do wypłaty dla gracza.
     */
    double resolveBets(int winningNumber);
};

#endif //FOLDERNPGWOJCIECHKRAWCZYK_BETMANAGER_H

    /**
     * @brief Przyjmuje zakład od gracza.
     * @param betType Typ zakładu (np. kolor, numer).
     * @param amount Kwota zakładu.
     * @return true jeśli zakład został przyjęty pomyślnie.
     */
    bool placeBet(int betType, double amount) { return false; }

    /**
     * @brief Rozlicza zakłady na podstawie wylosowanego numeru.
     * @param winningNumber Zwycięski numer z koła.
     * @return Kwota do wypłaty dla gracza.
     */
    double resolveBets(int winningNumber) { return 0.0; }
};
#endif //FOLDERNPGWOJCIECHKRAWCZYK_BETMANAGER_H
