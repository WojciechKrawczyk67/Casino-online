#include "Wallet.h"

Wallet::Wallet(double initial_balance) : balance(initial_balance) {}

void Wallet::addFunds(double amount) {
    if (amount > 0) balance += amount;
}

bool Wallet::deductFunds(double amount) {
    if (amount <= 0 || amount > balance) return false;
    balance -= amount;
    return true;
}

double Wallet::getBalance() const {
    return balance;
}