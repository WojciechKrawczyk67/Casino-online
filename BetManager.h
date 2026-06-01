//
// Created by student164 on 19.05.2026.
//

#ifndef FOLDERNPGWOJCIECHKRAWCZYK_BETMANAGER_H
#define FOLDERNPGWOJCIECHKRAWCZYK_BETMANAGER_H
#pragma once

#include <vector>
#include <memory>

/**
 * @class Bet
 * @brief Klasa bazowa dla wszystkich zakładów.
 */
class Bet {
protected:
    double amount;
    int payoutMultiplier;
public:
    Bet(double amount, int multiplier = 2) : amount(amount), payoutMultiplier(multiplier) {}
    virtual ~Bet() = default;

    virtual bool isWinning(int winningNumber) const = 0;

    /**
     * @brief Oblicza wygraną.
     * @param winningNumber Zwycięski numer z koła.
     * @return Kwota do zasilenia portfela.
     */
    double resolveBet(int winningNumber) const {
        if (isWinning(winningNumber)) {
            return amount * payoutMultiplier;
        }
        return 0.0;
    }
};

/**
 * @class ParityBet
 * @brief Zakład na Parzyste/Nieparzyste.
 */
class ParityBet : public Bet {
private:
    bool betOnEven;
public:
    ParityBet(double amount, bool even) : Bet(amount), betOnEven(even) {}
    bool isWinning(int winningNumber) const override {
        if (winningNumber == 0) return false;
        return betOnEven ? (winningNumber % 2 == 0) : (winningNumber % 2 != 0);
    }
};

/**
 * @class HalfBet
 * @brief Zakład na Wysokie/Niskie (1-18 lub 19-36).
 */
class HalfBet : public Bet {
private:
    bool betOnLow;
public:
    HalfBet(double amount, bool low) : Bet(amount), betOnLow(low) {}
    bool isWinning(int winningNumber) const override {
        if (winningNumber == 0) return false;
        return betOnLow ? (winningNumber >= 1 && winningNumber <= 18) : (winningNumber >= 19 && winningNumber <= 36);
    }
};

/**
 * @class ColorBet
 * @brief Zakład na Kolor (Czerwone/Czarne).
 */
class ColorBet : public Bet {
private:
    bool betOnRed;
public:
    ColorBet(double amount, bool red) : Bet(amount), betOnRed(red) {}
    bool isWinning(int winningNumber) const override {
        if (winningNumber == 0) return false;
        int redNumbers[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
        bool isRed = false;
        for (int n : redNumbers) {
            if (winningNumber == n) {
                isRed = true;
                break;
            }
        }
        return betOnRed ? isRed : !isRed;
    }
};

/**
 * @class BetManager
 * @brief Odpowiada za weryfikację zakładów i rozliczanie wygranych.
 */
class BetManager {
private:
    std::vector<std::unique_ptr<Bet>> activeBets;
public:
    BetManager() {}

    void addParityBet(double amount, bool even) {
        activeBets.push_back(std::make_unique<ParityBet>(amount, even));
    }

    void addHalfBet(double amount, bool low) {
        activeBets.push_back(std::make_unique<HalfBet>(amount, low));
    }

    void addColorBet(double amount, bool red) {
        activeBets.push_back(std::make_unique<ColorBet>(amount, red));
    }

    /**
     * @brief Rozlicza wszystkie aktywne zakłady.
     * @param winningNumber Wylosowany numer (0-36).
     * @return Sumaryczna wygrana do dodania do obiektu Wallet.
     */
    double resolveAllBets(int winningNumber) {
        double totalPayout = 0.0;
        for (const auto& bet : activeBets) {
            totalPayout += bet->resolveBet(winningNumber);
        }
        activeBets.clear();
        return totalPayout;
    }
};
#endif //FOLDERNPGWOJCIECHKRAWCZYK_BETMANAGER_H