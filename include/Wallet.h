#pragma once

class Wallet {
private:
    double balance;
public:
    Wallet(double initial_balance = 1000.0);
    void addFunds(double amount);
    bool deductFunds(double amount);
    double getBalance() const;
};