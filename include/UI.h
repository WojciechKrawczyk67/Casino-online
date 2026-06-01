#pragma once
#include <string>
#include "Statistics.h"

class UI {
private:
    const std::string RESET = "\033[0m";
    const std::string RED_TEXT = "\033[31m";
    const std::string GREEN_TEXT = "\033[32m";
    const std::string YELLOW_TEXT = "\033[33m";
    const std::string CYAN_TEXT = "\033[36m";

public:
    UI();
    void clearScreen();
    void drawTable();
    int displayMenu();
    int displayBettingMenu();
    std::string getUserInput();
    void showMessage(const std::string& message, const std::string& color = "");
    void showStatistics(const Statistics& stats);
    void spinAnimation(int winningNumber);

    std::string colorizeNumber(int number);
};