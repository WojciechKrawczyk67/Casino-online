#pragma once
#include <vector>
#include <memory>

class Bet {
protected:
    double amount;
    int payoutMultiplier;
public:
    Bet(double amount, int multiplier);
    virtual ~Bet() = default;
    virtual bool isWinning(int winningNumber) const = 0;
    double resolveBet(int winningNumber) const;
    double getAmount() const { return amount; }
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

class StraightBet : public Bet {
private:
    int chosenNumber;
public:
    StraightBet(double amount, int number);
    bool isWinning(int winningNumber) const override;
};

class DozenBet : public Bet {
private:
    int dozen;
public:
    DozenBet(double amount, int dozen);
    bool isWinning(int winningNumber) const override;
};

class ColumnBet : public Bet {
private:
    int column;
public:
    ColumnBet(double amount, int column);
    bool isWinning(int winningNumber) const override;
};

class SplitBet : public Bet {
private:
    int num1;
    int num2;
public:
    SplitBet(double amount, int num1, int num2);
    bool isWinning(int winningNumber) const override;
};

class StreetBet : public Bet {
private:
    int startNumber;
public:
    StreetBet(double amount, int startNumber);
    bool isWinning(int winningNumber) const override;
};

class CornerBet : public Bet {
private:
    int topLeftNumber;
public:
    CornerBet(double amount, int topLeftNumber);
    bool isWinning(int winningNumber) const override;
};

class SixLineBet : public Bet {
private:
    int startNumber;
public:
    SixLineBet(double amount, int startNumber);
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
    void addStraightBet(double amount, int number);
    void addDozenBet(double amount, int dozen);
    void addColumnBet(double amount, int column);
    void addSplitBet(double amount, int num1, int num2);
    void addStreetBet(double amount, int startNumber);
    void addCornerBet(double amount, int topLeftNumber);
    void addSixLineBet(double amount, int startNumber);

    double resolveAllBets(int winningNumber);
    void clearBets();
    bool hasBets() const;
    double getTotalActiveBetsAmount() const;
};