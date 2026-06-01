#ifndef FOLDERNPGWOJCIECHKRAWCZYK_GAMEMANAGER_H
#define FOLDERNPGWOJCIECHKRAWCZYK_GAMEMANAGER_H

#include "UI.h"
#include "Wheel.h"
#include "Wallet.h"
#include "BetManager.h"
#include <string>

/**
 * @class GameManager
 * @brief Zarządza główną pętlą gry i koordynuje pracę pozostałych klas.
 */
class GameManager {
private:
    UI ui;
    Wheel wheel;
    Wallet wallet;
    BetManager betManager;

public:
    GameManager() : wallet(1000.0) {} // Startowy balans: 1000

    /**
     * @brief Uruchamia główną pętlę symulatora.
     */
    void run() {
        bool isRunning = true;
        while (isRunning) {
            int choice = ui.displayMenu();
            
            switch (choice) {
                case 1:
                    playRound();
                    break;
                case 2:
                    ui.showMessage("\nAktualny stan konta: " + std::to_string(wallet.getBalance()) + " zetonow.");
                    break;
                case 3:
                    ui.showMessage("\nStatystyki: Modul w budowie.");
                    break;
                case 4:
                    ui.showMessage("\nDziekujemy za gre!");
                    isRunning = false;
                    break;
            }
        }
    }

private:
    void playRound() {
        ui.drawTable();
        ui.showMessage("Wybierz rodzaj zakladu:");
        ui.showMessage("1. Czerwone / Czarne");
        ui.showMessage("2. Parzyste / Nieparzyste");
        ui.showMessage("3. Wysokie / Niskie");
        ui.showMessage("Wybor (1-3): ");
        
        int betType;
        try {
            betType = std::stoi(ui.getUserInput());
        } catch (...) {
            ui.showMessage("Bledne dane!");
            return;
        }

        ui.showMessage("Podaj stawke: ");
        double amount;
        try {
            amount = std::stod(ui.getUserInput());
        } catch (...) {
            ui.showMessage("Bledna stawka!");
            return;
        }

        if (!wallet.deductFunds(amount)) {
            ui.showMessage("Brak wystarczajacych srodkow lub nieprawidlowa kwota!");
            return;
        }

        if (betType == 1) {
            ui.showMessage("Wybierz: 1 - Czerwone, 0 - Czarne");
            bool isRed = (std::stoi(ui.getUserInput()) == 1);
            betManager.addColorBet(amount, isRed);
        } else if (betType == 2) {
            ui.showMessage("Wybierz: 1 - Parzyste, 0 - Nieparzyste");
            bool isEven = (std::stoi(ui.getUserInput()) == 1);
            betManager.addParityBet(amount, isEven);
        } else if (betType == 3) {
            ui.showMessage("Wybierz: 1 - Niskie (1-18), 0 - Wysokie (19-36)");
            bool isLow = (std::stoi(ui.getUserInput()) == 1);
            betManager.addHalfBet(amount, isLow);
        } else {
            ui.showMessage("Nieznany zaklad! Zwrot srodkow.");
            wallet.addFunds(amount);
            return;
        }

        ui.showMessage("\nKrecenie kolem...");
        int winningNumber = wheel.spin();
        ui.showMessage("Wylosowano numer: " + std::to_string(winningNumber));

        double winnings = betManager.resolveAllBets(winningNumber);
        
        if (winnings > 0) {
            ui.showMessage("Gratulacje! Wygrywasz: " + std::to_string(winnings) + " zetonow.");
            wallet.addFunds(winnings);
        } else {
            ui.showMessage("Niestety, tym razem przegrywasz.");
        }
    }
};

#endif //FOLDERNPGWOJCIECHKRAWCZYK_GAMEMANAGER_H