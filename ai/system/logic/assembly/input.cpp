// /AI/LOGIC/ASSEMBLY/INPUT.CPP: USED BY /AI/AI.H

// #include "commands.h" // already included in logic.h
#include "input.h"

void logicalQuery(std::string &x) {

    // set logic to 0 for automatic override of logic function

    // DEFAULT: (3) (PERFORM X COMPUTATION)
    int y = logic;  // is inherited from /ai/logic/assembly/logic.h
    
    // ========= DEFAULT TO NO LOGIC =========
    // uncomment the next comment for no logic
    //y = 2;
    // ========= DEFAULT TO NO LOGIC =========

    switch (y) {
        case 0: // no logic
            break;

        case 1: // readln -/- (length / NO LENGTH)
            std::cout << "-:: :logic: (read line)::-" << std::endl;
            std::cout << "\t" << x << std::endl;
            break;

        case 2: // readln +/+ (length indication)
            std::cout << "-:: :logic: (read line)::-" << std::endl;
            std::cout << "\t" << x << " (" << x.length() << ")" << std::endl;
            commands(y, x);
            break;

        case 3: // compute x computation
            std::cout << "-:: :logic: (compute x computation)::-" << std::endl;
            std::cout << "\t" << x << std::endl;
            commands(y, x);
            break;

        default: //
            std::cout << std::endl << "[NOP]" << std::endl;
            break;
    };

    finished();
}
