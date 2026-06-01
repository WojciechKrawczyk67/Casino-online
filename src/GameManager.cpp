#include "GameManager.h"
#include <iostream>
#include <thread>
#include <chrono>

GameManager::GameManager() : wallet(1000.0) {}

void GameManager::run() {
    bool isRunning = true;
    while (isRunning) {
        ui.clearScreen();
        int choice = ui.displayMenu();

        switch (choice) {
            case 1:
                playRound();
                break;
            case 2:
                ui.clearScreen();
                ui.showMessage("\n===========================");
                ui.showMessage("  Aktualny stan konta: " + std::to_string((int)wallet.getBalance()) + " zetonow.");
                ui.showMessage("===========================\n");
                std::cout << "Wcisnij Enter, aby wrocic...";
                std::cin.ignore();
                std::cin.get();
                break;
            case 3:
                ui.showStatistics(stats);
                std::cout << "Wcisnij Enter, aby wrocic...";
                std::cin.ignore();
                std::cin.get();
                break;
            case 4:
                ui.showMessage("\nDziekujemy za gre. Do zobaczenia!");
                isRunning = false;
                break;
        }
    }
}

void GameManager::playRound() {
    ui.drawTable();
    betManager.clearBets();

    bettingPhase();

    if (!betManager.hasBets()) {
        ui.showMessage("Brak zakladow. Anulowanie rundy.");
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return;
    }

    int winningNumber = wheel.spin();
    ui.spinAnimation(winningNumber);
    stats.addRound();

    double winnings = betManager.resolveAllBets(winningNumber);

    if (winnings > 0) {
        ui.showMessage("Gratulacje! Wygrywasz lacznie: " + std::to_string((int)winnings) + " zetonow.", "\033[32m");
        wallet.addFunds(winnings);
        stats.recordWin(winnings);
    } else {
        ui.showMessage("Niestety, wszystkie zaklady przegraly.", "\033[31m");
        stats.recordLoss();
    }

    std::cout << "\nWcisnij Enter, aby kontynuowac...";
    std::cin.ignore();
    std::cin.get();
}

void GameManager::bettingPhase() {
    bool isBetting = true;

    while (isBetting) {
        ui.showMessage("\nTwoj portfel: " + std::to_string((int)wallet.getBalance()) + " zetonow | Suma w grze: " + std::to_string((int)betManager.getTotalActiveBetsAmount()), "\033[33m");
        int betType = ui.displayBettingMenu();

        if (betType == 0) { // Zmienione na 0 (zakończ)
            isBetting = false;
            break;
        }

        ui.showMessage("Podaj stawke: ");
        double amount;
        try {
            amount = std::stod(ui.getUserInput());
        } catch (...) {
            ui.showMessage("Bledna stawka!", "\033[31m");
            continue;
        }

        if (!wallet.deductFunds(amount)) {
            ui.showMessage("Brak wystarczajacych srodkow!", "\033[31m");
            continue;
        }

        stats.recordBet(amount);

        try {
            switch (betType) {
                case 1: {
                    ui.showMessage("Wybierz: 1 - Czerwone, 0 - Czarne");
                    bool isRed = (std::stoi(ui.getUserInput()) == 1);
                    betManager.addColorBet(amount, isRed);
                    break;
                }
                case 2: {
                    ui.showMessage("Wybierz: 1 - Parzyste, 0 - Nieparzyste");
                    bool isEven = (std::stoi(ui.getUserInput()) == 1);
                    betManager.addParityBet(amount, isEven);
                    break;
                }
                case 3: {
                    ui.showMessage("Wybierz: 1 - Niskie (1-18), 0 - Wysokie (19-36)");
                    bool isLow = (std::stoi(ui.getUserInput()) == 1);
                    betManager.addHalfBet(amount, isLow);
                    break;
                }
                case 4: {
                    ui.showMessage("Wybierz numer (0-36):");
                    int num = std::stoi(ui.getUserInput());
                    if (num >= 0 && num <= 36) betManager.addStraightBet(amount, num);
                    else throw std::invalid_argument("out_of_range");
                    break;
                }
                case 5: {
                    ui.showMessage("Wybierz tuzin: 1 (1-12), 2 (13-24), 3 (25-36)");
                    int doz = std::stoi(ui.getUserInput());
                    if (doz >= 1 && doz <= 3) betManager.addDozenBet(amount, doz);
                    else throw std::invalid_argument("out_of_range");
                    break;
                }
                case 6: {
                    ui.showMessage("Wybierz kolumne: 1 (np. 1,4,7), 2 (np. 2,5,8), 3 (np. 3,6,9)");
                    int col = std::stoi(ui.getUserInput());
                    if (col >= 1 && col <= 3) betManager.addColumnBet(amount, col);
                    else throw std::invalid_argument("out_of_range");
                    break;
                }
                case 7: {
                    ui.showMessage("Podaj pierwszy numer do splitu (0-36):");
                    int n1 = std::stoi(ui.getUserInput());
                    ui.showMessage("Podaj drugi numer do splitu (0-36):");
                    int n2 = std::stoi(ui.getUserInput());
                    betManager.addSplitBet(amount, n1, n2);
                    break;
                }
                case 8: {
                    ui.showMessage("Podaj poczatkowy numer ulicy (np. 1, 4, 7... 34):");
                    int start = std::stoi(ui.getUserInput());
                    if (start >= 1 && start <= 34 && start % 3 == 1) betManager.addStreetBet(amount, start);
                    else throw std::invalid_argument("out_of_range");
                    break;
                }
                case 9: {
                    ui.showMessage("Podaj lewy-gorny numer rogu (np. 1 dla rogu 1-2-4-5):");
                    int tl = std::stoi(ui.getUserInput());
                    if (tl >= 1 && tl <= 32 && tl % 3 != 0) betManager.addCornerBet(amount, tl);
                    else throw std::invalid_argument("out_of_range");
                    break;
                }
                case 10: {
                    ui.showMessage("Podaj poczatkowy numer dwoch rzedow (np. 1, 4, 7... 31):");
                    int start = std::stoi(ui.getUserInput());
                    if (start >= 1 && start <= 31 && start % 3 == 1) betManager.addSixLineBet(amount, start);
                    else throw std::invalid_argument("out_of_range");
                    break;
                }
            }
            ui.showMessage("Zaklad przyjety!", "\033[32m");
        } catch (...) {
            ui.showMessage("Bledne dane! Anulowano wprowadzanie i zwrocono srodki.", "\033[31m");
            wallet.addFunds(amount);
            stats.recordWin(amount); // Zwracamy wygraną aby zbalansować zwrot w statystykach
        }
    }
}