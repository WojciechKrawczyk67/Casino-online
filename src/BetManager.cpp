#include "BetManager.h"

Bet::Bet(double amount, int multiplier) : amount(amount), payoutMultiplier(multiplier) {}

double Bet::resolveBet(int winningNumber) const {
    if (isWinning(winningNumber)) {
        return amount * payoutMultiplier;
    }
    return 0.0;
}

ParityBet::ParityBet(double amount, bool even) : Bet(amount), betOnEven(even) {}

bool ParityBet::isWinning(int winningNumber) const {
    if (winningNumber == 0) return false;
    return betOnEven ? (winningNumber % 2 == 0) : (winningNumber % 2 != 0);
}

HalfBet::HalfBet(double amount, bool low) : Bet(amount), betOnLow(low) {}

bool HalfBet::isWinning(int winningNumber) const {
    if (winningNumber == 0) return false;
    return betOnLow ? (winningNumber >= 1 && winningNumber <= 18) : (winningNumber >= 19 && winningNumber <= 36);
}

ColorBet::ColorBet(double amount, bool red) : Bet(amount), betOnRed(red) {}

bool ColorBet::isWinning(int winningNumber) const {
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

BetManager::BetManager() {}

void BetManager::addParityBet(double amount, bool even) {
    activeBets.push_back(std::make_unique<ParityBet>(amount, even));
}

void BetManager::addHalfBet(double amount, bool low) {
    activeBets.push_back(std::make_unique<HalfBet>(amount, low));
}

void BetManager::addColorBet(double amount, bool red) {
    activeBets.push_back(std::make_unique<ColorBet>(amount, red));
}

double BetManager::resolveAllBets(int winningNumber) {
    double totalPayout = 0.0;
    for (const auto& bet : activeBets) {
        totalPayout += bet->resolveBet(winningNumber);
    }
    activeBets.clear();
    return totalPayout;
}