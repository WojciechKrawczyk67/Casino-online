#include "Wheel.h"
#include <random>

Wheel::Wheel() {}

int Wheel::spin() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 36);
    return distrib(gen);
}