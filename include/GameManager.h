#pragma once
#include "UI.h"
#include "Wheel.h"
#include "Wallet.h"
#include "BetManager.h"
#include "Statistics.h"

class GameManager {
private:
    UI ui;
    Wheel wheel;
    Wallet wallet;
    BetManager betManager;
    Statistics stats;

    void playRound();
    void bettingPhase();

public:
    GameManager();
    void run();
};