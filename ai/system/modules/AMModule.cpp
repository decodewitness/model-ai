// AMMODULE.CPP - IS USED BY "/AI/SYSTEM/MODULES/MODULAR.CPP"

#include "AMModule.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

AMModule::AMModule() {
    this->l = 3;
};

void AMModule::addStringR(std::string r) {
    this->r = r;
};

void AMModule::addStringS(std::string s) {
    this->s = s;
};

void AMModule::combine() {
    this->x = r + s;
};

std::string AMModule::returnProduct() {
    return this->x;
}

void AMModule::addni(int n) {
    this->k = n;
}

void AMModule::addnj(int n) {
    this->l = n;
};

void AMModule::combinen() {
    this->m = this->k + this->l;
};

int AMModule::returnProductn() {
    return this->m;
}

bool AMModule::loader(std::string filen) {

    // load module here next

    // open file
    // need array for data or better structure like pointers
        // modular container

    return 1;
};

void AMModule::seedRNG10() {
    std::cout << "~:: seeding random number generator. (<=10)" << std::endl;
    srand (time(NULL));
    this->rnd = rand() % 10 + 1;
};

void AMModule::seedRNG100() {
    std::cout << "~:: seeding random number generator. (<=100)" << std::endl;
    srand (time(NULL));
    this->rnd = rand() % 100 + 1;
};

int AMModule::getRNG() {
    std::cout << "~:: pseudo random number (" << this->rnd << ")" << std::endl;
    return this->rnd;
};

void AMModule::nrs(int max, int x, int limits) {
    
    std::cout << "~:: running numbers sequence to compare between upper/lower bounds." << std::endl;

    // compares between bounds
    int boundLow = x;
    int boundHigh = max;

    std::cout << "\t- (" << boundLow << ") <<< BOUNDS >>> (" << boundHigh << ")" << std::endl;

    int boundsLow[max]; // not implemented yet
    int boundsHigh[max];

    for (int i=1; i<limits; i++) {
        if (i>boundLow && i<boundHigh) {
            // take action
            std::cout << "\t:number (" << i << ")" << std::endl;
        }
    }
};

void incrementalNrs(int max, int x) {

    int boundsLow[max];
    int boundsHigh[max];

    for (int i=1; i<max; i++) {
        if (i<boundsLow[i] && i<boundsHigh[i]) {
            // take action
        }
    }
};