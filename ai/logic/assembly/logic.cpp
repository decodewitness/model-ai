// /AI/LOGIC/ASSEMBLY/LOGIC.CPP: USED BY /AI/LOGIC/ASSEMBLY/INPUT.H

#include <string>
#include "logic.h"

void commands(int x, std::string param) {
    // list attributes of string
    switch(x) {
        case 1:
            std::cout << "\tlen " << param.length() << std::endl; break;
            break;
        default:
            std::cout << "(NOP)" << std::endl;
    };
};