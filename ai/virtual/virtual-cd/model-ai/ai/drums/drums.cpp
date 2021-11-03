// (in AI directory) AI/DRUMS.CPP - USED BY "AI.H" FOR MODEL AI

#include <iostream>
#include "drums.h"

void DrumMachine::cycle() {
    std::cout << "-:: cycle 1: " << this->cycle_one << std::endl;
    std::cout << "-:: cycle 2: " << this->cycle_two << std::endl;
}

DrumMachine::DrumMachine() {
    this->cycle_one = drum_cycle_one;
    this->cycle_two = drum_cycle_two;

    std::cout << "'::: DRUMS :::'" << std::endl;
    this->cycle();
};

DrumMachine::DrumMachine(int x, int y) {
    this->cycle_one = x;
    this->cycle_two = y;
};

void DrumMachine::reverse() {
    int x = this->cycle_one;
    this->cycle_one = this->cycle_two;
    this->cycle_two = x;
};