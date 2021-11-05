// /AI/LOGIC/ASSEMBLY/LOGIC.CPP: USED BY /AI/LOGIC/ASSEMBLY/INPUT.H

#include <string>
#include <iostream>
#include "logic.h"

void commands(int x, std::string param) {
    // list attributes of string
    std::cout << "\t[ ";
    switch(x) {
        case 1: // param length
            std::cout << "len: " << param.length();
            break;
        
        case 2: // param attributes
            std::cout << "attr: ";
            std::cout << "len(" << param.length() << ")";
            break;

        case 3: // computations for x coordinate
            std::cout << "computation: ";
            break;

        default:
            std::cout << "-:: was not supplied as function :: (NOP)";
            break;
    };
    std::cout << " ]" << std::endl;
};