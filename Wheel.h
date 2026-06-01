#ifndef FOLDERNPGWOJCIECHKRAWCZYK_WHEEL_H
#define FOLDERNPGWOJCIECHKRAWCZYK_WHEEL_H

#include <random>

/**
 * @class Wheel
 * @brief Odpowiada za logikę koła ruletki i losowanie wyników.
 */
class Wheel {
public:
    Wheel() {}

    /**
     * @brief Losuje i zwraca wygrywający numer (0-36).
     * @return Zwycięski numer.
     */
    int spin() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, 36);
        return distrib(gen);
    }
};

#endif //FOLDERNPGWOJCIECHKRAWCZYK_WHEEL_H