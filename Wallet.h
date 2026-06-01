#ifndef FOLDERNPGWOJCIECHKRAWCZYK_WALLET_H
#define FOLDERNPGWOJCIECHKRAWCZYK_WALLET_H

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
    Wallet(double initial_balance = 1000.0) : balance(initial_balance) {}

    /**
     * @brief Dodaje środki do portfela.
     * @param amount Kwota do dodania.
     */
    void addFunds(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    /**
     * @brief Pobiera z portfela środki na zakład.
     * @param amount Kwota do pobrania.
     * @return true jeśli wystarczy środków, false w przeciwnym razie.
     */
    bool deductFunds(double amount) { 
        if (amount <= 0 || amount > balance) {
            return false;
        }
        balance -= amount;
        return true; 
    }

    /**
     * @brief Zwraca obecny stan konta.
     * @return Aktualny balans.
     */
    double getBalance() const { return balance; }
};

#endif //FOLDERNPGWOJCIECHKRAWCZYK_WALLET_H