// AI/CHAIN/CHAIN.CPP -- (NOT USED YET!!!)
# include "chain.h"

    // Need to use CHAIN.H to build chain dynamics in architecture.


/*
struct Chain {
    int id;    // id
    int nrOfChains; // nr   // ((( could fluctuate ;; needs implementation)))
    int activeChain;    // the active chain number (passive/active ##)

    // current nominal chain sequences
        // from 1 -> ... -> 5
    int sequence_one[limits];
    int sequence_two[limits];
    int sequence_three[limits];
    int sequence_four[limits];
    int sequence_five[limits];

    // data or reference
    int chain[maxchains][limits];
    char chains[maxchains][strlimit];

    // total pooled data
    std::vector<std::string> pool;
}

// Functions
    int reportStatID(Chain c)
    int reportStatChains(Chain c)
    int reportActiveChain(Chain c)

*/

Chain & chainCreate() {
    Chain *c = new Chain;
    return *c;
}

void deleteChain(Chain &c) {
    delete &c;
}

void readChain(Chain c) {
    // enumerate chain
}

void writeChain(int x, int id, Chain &c, std::string str) {   // x=chain, id=chain.id, str=data written to chain
    int counter=0;
    bool wrote = false;
    int lng=str.length();   // length of chain

    // write to chain
    if (id == c.id) {
        // correct Chain!
        std::cout << "+chain:" << x << std::endl;
        if (lng > 0 && x < c.nrOfChains) {
            for (int i=0; i<strlimit; i++) {
                if (i<lng) {
                    c.chains[x][i] = str[i];
                    wrote = true;
                    counter++;
                }
                else {
                    break;
                }
            }
        }
        if (wrote == true) {
            std::cout << "~:: (wrote) chain data (" << counter << ")." << std::endl;
        }
    } else {
        //
        std::cout << "~::!::~ did not match chain number! aborts write." << std::endl;
    }
}

// checks for double chain ID nrs.
void chainID(Chain c) {
    std::cout << "\tChain ID\t:\t";
    std::cout << reportStatID(c);
    std::cout << "Active Chain\t:\t";
    std::cout << reportActiveChain(c);
    std::cout << "Nr. of Chains\t:\t";
    std::cout << reportStatChains(c);
}

void chainData(int x, Chain &c) { // x = chain number
    if (x < c.nrOfChains) {
        std::cout << "~:: (*)[chain][" << x << "]->(\"" << c.chains[x] << "\")." << std::endl;
    } else {
        std::cout << "~::!::~ (error) - assigned wrong chain nr (max: " << c.nrOfChains << ")." << std::endl;
    }
}

// eof