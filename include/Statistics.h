#pragma once

class Statistics {
private:
    int roundsPlayed;
    int betsWon;
    int betsLost;
    double totalWagered;
    double totalWon;
    double highestWin;

public:
    Statistics();
    
    void addRound();
    void recordBet(double amount);
    void recordWin(double amount);
    void recordLoss();

    int getRoundsPlayed() const;
    int getBetsWon() const;
    int getBetsLost() const;
    double getTotalWagered() const;
    double getTotalWon() const;
    double getHighestWin() const;
};