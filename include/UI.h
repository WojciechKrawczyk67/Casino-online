#pragma once
#include <string>

class UI {
public:
    UI();
    void drawTable();
    int displayMenu();
    std::string getUserInput();
    void showMessage(const std::string& message);
};