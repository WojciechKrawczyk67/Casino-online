#include "Statistics.h"

Statistics::Statistics() : roundsPlayed(0), betsWon(0), betsLost(0), totalWagered(0.0), totalWon(0.0), highestWin(0.0) {}

void Statistics::addRound() { 
    roundsPlayed++; 
}

void Statistics::recordBet(double amount) { 
    totalWagered += amount; 
}

void Statistics::recordWin(double amount) {
    betsWon++;
    totalWon += amount;
    if (amount > highestWin) {
        highestWin = amount;
    }
}

void Statistics::recordLoss() { 
    betsLost++; 
}

int Statistics::getRoundsPlayed() const { return roundsPlayed; }
int Statistics::getBetsWon() const { return betsWon; }
int Statistics::getBetsLost() const { return betsLost; }
double Statistics::getTotalWagered() const { return totalWagered; }
double Statistics::getTotalWon() const { return totalWon; }
double Statistics::getHighestWin() const { return highestWin; }