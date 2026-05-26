
#ifndef FOLDERNPGWOJCIECHKRAWCZYK_WHEEL_H
#define FOLDERNPGWOJCIECHKRAWCZYK_WHEEL_H

#pragma once
#include <random>

class Wheel {
public:
    Wheel() {}

    int spin() { 
        std::random_device rd; 
        std::mt19937 gen(rd()); 
        std::uniform_int_distribution<> distrib(0, 36);
        
        return distrib(gen);
    }
};

#endif