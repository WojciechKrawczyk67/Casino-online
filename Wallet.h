//
// Created by student164 on 19.05.2026.
//

#ifndef FOLDERNPGWOJCIECHKRAWCZYK_WALLET_H
#define FOLDERNPGWOJCIECHKRAWCZYK_WALLET_H
#pragma once

/**
 * @class Wallet
 * @brief Zarządza funduszami gracza.
 */
class Wallet {
private:
    double balance;
public:
    /**
     * @brief Konstruktor inicjalizujący portfel.
     * @param initial_balance Początkowy stan konta.
     */
    Wallet(double initial_balance = 0.0) : balance(initial_balance) {}

    /**
     * @brief Dodaje środki do portfela.
     * @param amount Kwota do dodania.
     */
    void addFunds(double amount) {}

    /**
     * @brief Pobiera z portfela środki na zakład.
     * @param amount Kwota do pobrania.
     * @return true jeśli wystarczy środków, false w przeciwnym razie.
     */
    bool deductFunds(double amount) { return false; }

    /**
     * @brief Zwraca obecny stan konta.
     * @return Aktualny balans.
     */
    double getBalance() const { return balance; }
};
#endif //FOLDERNPGWOJCIECHKRAWCZYK_WALLET_H
