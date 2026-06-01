#pragma once
#include "UI.h"
#include "Wheel.h"
#include "Wallet.h"
#include "BetManager.h"

class GameManager {
private:
    UI ui;
    Wheel wheel;
    Wallet wallet;
    BetManager betManager;
    void playRound();

public:
    GameManager();
    void run();
};