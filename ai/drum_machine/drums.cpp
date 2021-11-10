// "/AI/DRUM_MACHINE/DRUMS.CPP" - USED BY "/AI/AI.H" FOR (MODEL-AI) PROJECT

#include <iostream>
#include <functional>
#include <string.h>

#include "drums.h"

void filter(int &x);

DrumMachine::DrumMachine() {    // cycle_###[] are either drum_cycle_one, drum_cycle_two, or drum_cycle_three
    std::cout << std::endl << "-::: DRUMS MACHINE OF THE DRUMS :::-" << std::endl << std::endl;

    // set pose time for when to start track sample
    this->pose = Tstart;    // (default = 00:00:02 seconds)
    
    // set start time # in all measures
    this->s1 = 0;
    this->s2 = 0;

    // set intervals A&B # of time
    this->setIntervalA();
    this->setIntervalB();

    // set recurring beat on every measure / set recurring silence after every measure
    this->beatEveryMeasure = beat_rpm;
    this->measureEveryBeat = 1.0;

    // set the drum cycle
    this->cycle_one[0] = drum_cycle_two;
    this->cycle_one[1] = drum_cycle_one;
    this->cycle_two[0] = drum_cycle_one;
    this->cycle_two[1] = drum_cycle_two;

    // show status for the drum cycles
    this->status();
};

DrumMachine::DrumMachine(int z, int x, int y) { // PARAMS: ((cycle 1 or 2), (cycle #1 measure), (cycle #2 measure))
    
    switch (z){
        case 1:
            this->cycle_one[0] = x;
            this->cycle_one[1] = y; // need to build in switch in this function
            break;

        case 2:
            this->cycle_two[0] = x;
            this->cycle_two[1] = y;
            break;

        default:
            // do nothing but show a warning
            std::cout << "!=> invalid loop selected (" << z << ")" << std::endl;
            break;
    };

    // show status
    this->status();
};

void DrumMachine::reverse() {   // reverse the drum cycles in both measures
    int x[2];

    std::cout << "-:: reversing drum" << std::endl;
    std::cout << "\t- ((L)(R)<->(R)(L))" << std::endl;
    
    std::cout << "~:: reversing:";

    // use x label in redundancy
    x[0] = this->cycle_one[0];
    x[1] = this->cycle_one[1];

    std::cout << "\t\t((1 ";
    this->cycle_one[0] = x[1];
    this->cycle_one[1] = x[0];
    std::cout << this->cycle_one[0] << " " << this->cycle_one[1];

    // use x label in redundancy
    x[0] = this->cycle_two[0];
    x[1] = this->cycle_two[1];

    std::cout << "\t\t((2";
    this->cycle_two[0] = x[1];
    this->cycle_two[1] = x[0];

    std::cout << this->cycle_two[0] << " " << this->cycle_two[1] << std::endl << std::endl;
    
    // xor the values of 'x' to [0,0] to release memory 
    filter(*x);

    this->status();
};

void DrumMachine::reverseA() {   // reverse the drum cycles in both measures
    int x[2];

    std::cout << "-:: reversing drum" << std::endl;
    std::cout << "\t- ((L)(R)<->(R)(L))" << std::endl;
    
    std::cout << "~:: reversing:";

    // use x label in redundancy
    x[0] = this->cycle_one[0];
    x[1] = this->cycle_one[1];

    std::cout << "\t\t((1 ";
    this->cycle_one[0] = x[1];
    this->cycle_one[1] = x[0];
    std::cout << this->cycle_one[0] << " " << this->cycle_one[1];

    // xor the values of 'x' to [0,0] to release memory 
    filter(*x);

    this->status();
};

void DrumMachine::reverseB() {   // reverse the drum cycles in both measures
    int x[2];

    std::cout << "-:: reversing drum" << std::endl;
    std::cout << "\t- ((L)(R)<->(R)(L))" << std::endl;
    
    std::cout << "~:: reversing (B):";

    // use x label in redundancy
    x[0] = this->cycle_two[0];
    x[1] = this->cycle_two[1];

    std::cout << "\t\t((2";
    this->cycle_two[0] = x[1];
    this->cycle_two[1] = x[0];

    std::cout << this->cycle_two[0] << " " << this->cycle_two[1] << std::endl << std::endl;
    
    // xor the values of 'x' to [0,0] to release memory 
    filter(*x);
    
    this->status();
};

void filter(int &x) {
    // xors &x array of [2]
    memset(&x, 0, 2*sizeof(&x));
}

void DrumMachine::start() {
    // increase time in measure to about 00:00:10 seconds (total time in sample=time_in_seconds + any time leftover in DrumMachine)
    double time_in_seconds = 10.0;  // seconds

    // TIME_H
    // TIME_H
    // TIME_H
    // TIME_H
    // TIME_H
}

void DrumMachine::reset() {
    // set timer starters to 0 seconds
    this->s1 = this->s2 = 0.00;
}

void DrumMachine::setStartStatus() {
    this->s1 = 1.0 + startA;    // setStartStatus initializes to startA|startB and adds 1 second
    this->s2 = 1.0 + startB;
}

void DrumMachine::setStartA() {
    this->s1 = startA;  // make A start at the # startA time
};

void DrumMachine::setStartB() {
    this->s2 = startB;  // make B start at the # startB time
};

void DrumMachine::setStartAB() {
    this->s1 = this->s2 = startAB;  // make A+B start at the same time
};

void DrumMachine::setIntervalA() {
    this->intervalA = chronotrigger;    // sets intervalA to 0.75 as default (slower measure but faster than default)
};

void DrumMachine::setIntervalB() {
    this->intervalB = chronotrigger / 2;    // sets intervalB to 0.375 as default (faster measure)
};

void DrumMachine::status() {    // broadcast status message

    // status
    std::cout << "~::--::-( status of drum kits )-::--::~" << std::endl;
    
    // cycles
    std::cout << "-:: cycle 1: m( " << this->cycle_one[0] << " m( " << this->cycle_one[1] << std::endl;
    std::cout << "\t-:: cycle 2: m( " << this->cycle_two[0] << " m( " << this->cycle_two[1] << std::endl;
    std::cout << std::endl;

    // intervals
    std::cout << "{{ +pose ( " << this->pose << " ) }} :: ";
    std::cout << "{{ -intervalA ( " << this->intervalA << " ) }} ";
    std::cout << "{{ -intervalB ( " << this->intervalB << " ) " << "}}" << std::endl;

    // status
    std::cout << "~::--::(status of drum kits)::--::~" << std::endl << std::endl;
};