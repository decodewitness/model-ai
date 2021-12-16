// "AI/STEERING/INITIALIZE_RUNCHECK.CPP" -- CHECKS FILES AND INTEGRITY OF MODEL-AI FILE AND OBJECTS HIERARCHY

#ifndef _TESTING
#define _TESTING
#endif

#include <iostream>

const int nrsteps=3;

bool initialize_runtime_check() { // actually should be staged and recursive / needs a parameter in that case
    std::cout << "~:: ** &initialize_runtime_check() **" << std::endl;

    for (int i=0; i<nrsteps; i++) {
        switch (i) {
            case 0: // redundant cycle
                std::cout << "\t- checking redundancy." << std::endl;
                break;
                // do logic here
            case 1: // files complete
                std::cout << "\t- file hierarchy." << std::endl;
                break;
                // do logic here
            case 2: // file integrity && hashing
                std::cout << "\t- file integrity." << std::endl;
                break;
                // do logic here
            case 3: // compensate
                std::cout << "\t- compensating measures." << std::endl;
                break;
                // do logic here
            default: // skipping step 0 (or implement) as well as any additional steps.

                // do logic here
                std::cout << "\t- (debug) skipping redundant casing." << std::endl;
                break;
        };
    }

return true;
};