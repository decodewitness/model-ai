// AMMODULE.H - IS USED BY AI/AI.H

#include "AMModule.cpp"

#include <cstdio>
#include <cstdlib>
#include <ctime>

AMModule::AMModule() {
    this->j = 3;
};

void AMModule::addStringR(string r) {
    this->r = r;
};

void AMModule::addStringS(string s) {
    this->s = s;
};

void AMModule::combine() {
    this->x = r + s;
};

string AMModule::returnProduct() {
    return this->x;
}

void AMModule::addni(int n) {
    this->i = n;
}

void AMModule::addnj(int n) {
    this->j = n;
};

void AMModule::combinen() {
    this->k = this->i + this->j;
};

int AMModule::returnProductn() {
    return this->k;
}

void AMModule::seedRNG10() {
    srand (time(NULL));
    this->rnd = rand() % 100 + 1;
};

void AMModule::seedRNG100() {
    srand (time(NULL));
    this->rnd = rand() % 100 + 1;
};

int AMModule::getRNG() {
    return this->rnd;
};

void nrs(int max, int x, int limits) {
    // compares between bounds
    int boundLow = x;
    int boundHigh = max;

    int boundsLow[max]; // not implemented yet
    int boundsHigh[max];

    for (int i=1; i<limits; i++) {
        if (i>boundLow && i<boundHigh) {
            // take action
            cout << ":number (" << i << ")" << std::endl;
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