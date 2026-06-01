#include "BetManager.h"

Bet::Bet(double amount, int multiplier) : amount(amount), payoutMultiplier(multiplier) {}

double Bet::resolveBet(int winningNumber) const {
    if (isWinning(winningNumber)) return amount * payoutMultiplier;
    return 0.0;
}

ParityBet::ParityBet(double amount, bool even) : Bet(amount, 2), betOnEven(even) {}
bool ParityBet::isWinning(int winningNumber) const {
    if (winningNumber == 0) return false;
    return betOnEven ? (winningNumber % 2 == 0) : (winningNumber % 2 != 0);
}

HalfBet::HalfBet(double amount, bool low) : Bet(amount, 2), betOnLow(low) {}
bool HalfBet::isWinning(int winningNumber) const {
    if (winningNumber == 0) return false;
    return betOnLow ? (winningNumber >= 1 && winningNumber <= 18) : (winningNumber >= 19 && winningNumber <= 36);
}

ColorBet::ColorBet(double amount, bool red) : Bet(amount, 2), betOnRed(red) {}
bool ColorBet::isWinning(int winningNumber) const {
    if (winningNumber == 0) return false;
    int redNumbers[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
    for (int n : redNumbers) {
        if (winningNumber == n) return betOnRed;
    }
    return !betOnRed;
}

StraightBet::StraightBet(double amount, int number) : Bet(amount, 36), chosenNumber(number) {}
bool StraightBet::isWinning(int winningNumber) const { return winningNumber == chosenNumber; }

DozenBet::DozenBet(double amount, int dozen) : Bet(amount, 3), dozen(dozen) {}
bool DozenBet::isWinning(int winningNumber) const {
    if (winningNumber == 0) return false;
    if (dozen == 1) return winningNumber >= 1 && winningNumber <= 12;
    if (dozen == 2) return winningNumber >= 13 && winningNumber <= 24;
    if (dozen == 3) return winningNumber >= 25 && winningNumber <= 36;
    return false;
}

ColumnBet::ColumnBet(double amount, int column) : Bet(amount, 3), column(column) {}
bool ColumnBet::isWinning(int winningNumber) const {
    if (winningNumber == 0) return false;
    if (column == 1 && winningNumber % 3 == 1) return true;
    if (column == 2 && winningNumber % 3 == 2) return true;
    if (column == 3 && winningNumber % 3 == 0) return true;
    return false;
}

SplitBet::SplitBet(double amount, int num1, int num2) : Bet(amount, 18), num1(num1), num2(num2) {}
bool SplitBet::isWinning(int winningNumber) const {
    return winningNumber == num1 || winningNumber == num2;
}

StreetBet::StreetBet(double amount, int startNumber) : Bet(amount, 12), startNumber(startNumber) {}
bool StreetBet::isWinning(int winningNumber) const {
    if (winningNumber == 0) return false;
    return winningNumber >= startNumber && winningNumber <= startNumber + 2;
}

CornerBet::CornerBet(double amount, int topLeftNumber) : Bet(amount, 9), topLeftNumber(topLeftNumber) {}
bool CornerBet::isWinning(int winningNumber) const {
    if (winningNumber == 0) return false;
    return winningNumber == topLeftNumber || winningNumber == topLeftNumber + 1 || winningNumber == topLeftNumber + 3 || winningNumber == topLeftNumber + 4;
}

SixLineBet::SixLineBet(double amount, int startNumber) : Bet(amount, 6), startNumber(startNumber) {}
bool SixLineBet::isWinning(int winningNumber) const {
    if (winningNumber == 0) return false;
    return winningNumber >= startNumber && winningNumber <= startNumber + 5;
}

BetManager::BetManager() {}

void BetManager::addParityBet(double amount, bool even) { activeBets.push_back(std::make_unique<ParityBet>(amount, even)); }
void BetManager::addHalfBet(double amount, bool low) { activeBets.push_back(std::make_unique<HalfBet>(amount, low)); }
void BetManager::addColorBet(double amount, bool red) { activeBets.push_back(std::make_unique<ColorBet>(amount, red)); }
void BetManager::addStraightBet(double amount, int number) { activeBets.push_back(std::make_unique<StraightBet>(amount, number)); }
void BetManager::addDozenBet(double amount, int dozen) { activeBets.push_back(std::make_unique<DozenBet>(amount, dozen)); }
void BetManager::addColumnBet(double amount, int column) { activeBets.push_back(std::make_unique<ColumnBet>(amount, column)); }
void BetManager::addSplitBet(double amount, int num1, int num2) { activeBets.push_back(std::make_unique<SplitBet>(amount, num1, num2)); }
void BetManager::addStreetBet(double amount, int startNumber) { activeBets.push_back(std::make_unique<StreetBet>(amount, startNumber)); }
void BetManager::addCornerBet(double amount, int topLeftNumber) { activeBets.push_back(std::make_unique<CornerBet>(amount, topLeftNumber)); }
void BetManager::addSixLineBet(double amount, int startNumber) { activeBets.push_back(std::make_unique<SixLineBet>(amount, startNumber)); }

bool BetManager::hasBets() const { return !activeBets.empty(); }

double BetManager::getTotalActiveBetsAmount() const {
    double total = 0.0;
    for (const auto& bet : activeBets) {
        total += bet->getAmount();
    }
    return total;
}

double BetManager::resolveAllBets(int winningNumber) {
    double totalPayout = 0.0;
    for (const auto& bet : activeBets) {
        totalPayout += bet->resolveBet(winningNumber);
    }
    clearBets();
    return totalPayout;
}

void BetManager::clearBets() { activeBets.clear(); }