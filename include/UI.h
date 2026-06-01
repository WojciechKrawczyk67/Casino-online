#pragma once
#include <string>
#include "Statistics.h"

class UI {
public:
    UI();
    void drawTable();
    int displayMenu();
    std::string getUserInput();
    void showMessage(const std::string& message);
    void showStatistics(const Statistics& stats);
};