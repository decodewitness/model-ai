// AI/CHAIN/CHAIN.CPP -- (NOT USED YET!!!)
# include "chain.h"

/*
// Need to use CHAIN.H to build chain dynamics in architecture.

struct Chain {
    int id;    // id
    int nrOfChains; // nr   // ((( could fluctuate ;; needs implementation)))
    int activeChain;    // the active chain number (passive/active ##)

    // current nominal chain sequences
        // from 1 -> ... -> 5
    int sequence_one[climit];
    int sequence_two[climit];
    int sequence_three[climit];
    int sequence_four[climit];
    int sequence_five[climit];

    // data or reference
    int chain[maxchains][climit];
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


    int chainno = 0;
    Chain *c = new Chain;
    
    std::cout << std::endl << "~:: chainCreate()." << std::endl;
    std::cout << std::endl;

    c->id = chainno;
    c->activeChain = chainno;
    c->nrOfChains = chainno + 1;

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
    std::cout << std::endl;
    std::cout << "Chain ID\t:\t";
    std::cout << reportStatID(c);
    std::cout << std::endl;
    std::cout << "Active Chain\t:\t";
    std::cout << reportActiveChain(c);
    std::cout << std::endl;
    std::cout << "Nr. of Chains\t:\t";
    std::cout << reportStatChains(c);
    std::cout << std::endl;
}

void viewChainData(int x, Chain &c) { // x = chain number
    if (x < c.nrOfChains) {
        std::cout << "~:: (*)[chain][" << x << "]->(\"" << c.chains[x] << "\")." << std::endl;
    } else {
        std::cout << "~::!::~ (error) - assigned wrong chain nr (max: " << c.nrOfChains << ")." << std::endl;
    }
}

// eof