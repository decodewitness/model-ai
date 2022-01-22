// AI/SYSTEM/LOGIC/MODULES/UTILITY.CPP  - Used by "AI/AI.H"
    // instruments performing measurements.
#include "utility.h"

float converter(float x, int mode=1) {

    float denominator = 1.28;

    // look up denominator
        // denominator
    //google

    // course exchange
    if (mode == 1) {
        return x * denominator; // EURO x COURSE DOLLAR
    }

     // measure
     // data
    return x;
}

float converter(int x, int mode=1) {
    float amount = static_cast<float>(x);
    float denominator = 1.28;

    // look up denominator
        // denominator
    // google

    // course exchange
    if (mode == 1) {
        return denominator * x;
    }

    // measure
    // data

    return amount;
}