#pragma once
#include <vector>
#include <memory>

class Bet {
protected:
    double amount;
    int payoutMultiplier;
public:
    Bet(double amount, int multiplier = 2);
    virtual ~Bet() = default;
    virtual bool isWinning(int winningNumber) const = 0;
    double resolveBet(int winningNumber) const;
};

class ParityBet : public Bet {
private:
    bool betOnEven;
public:
    ParityBet(double amount, bool even);
    bool isWinning(int winningNumber) const override;
};

class HalfBet : public Bet {
private:
    bool betOnLow;
public:
    HalfBet(double amount, bool low);
    bool isWinning(int winningNumber) const override;
};

class ColorBet : public Bet {
private:
    bool betOnRed;
public:
    ColorBet(double amount, bool red);
    bool isWinning(int winningNumber) const override;
};

class BetManager {
private:
    std::vector<std::unique_ptr<Bet>> activeBets;
public:
    BetManager();
    void addParityBet(double amount, bool even);
    void addHalfBet(double amount, bool low);
    void addColorBet(double amount, bool red);
    double resolveAllBets(int winningNumber);
};