//
// Created by Maciej Kołtek on 22.05.2026.
//

#include "Wallet.h"
#include <stdexcept>

// Implementacja konstruktora
Wallet::Wallet(double initial_balance) {
    if (initial_balance < 0.0) {
        throw std::invalid_argument("Początkowe saldo nie może być ujemne.");
    }
    balance = initial_balance;
}

// Implementacja dodawania środków (np. wygranych)
void Wallet::addFunds(double amount) {
    // Zabezpieczenie: kwota dodawana musi być dodatnia
    if (amount <= 0.0) { 
        throw std::invalid_argument("Kwota dodawana do portfela musi być większa od zera.");
    }
    balance += amount;
}

// Implementacja pobierania środków na zakład
bool Wallet::deductFunds(double amount) {
    // Bezwzględna ochrona przed "Atakiem ujemną stawką" (Negative Stake Bug)
    if (amount <= 0.0) { 
        throw std::invalid_argument("Stawka zakładu musi być większa od zera.");
    }
    
    // Weryfikacja dostępności środków na koncie 
    if (amount > balance) {
        return false; // Transakcja przerwana - brak wystarczających funduszy 
    }
    
    balance -= amount;
    return true; // Transakcja autoryzowana pomyślnie
}

// Akcesor pobierający saldo
double Wallet::getBalance() const {
    return balance;
}