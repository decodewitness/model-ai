#include <iostream>
#include <string>
#include <vector>

// length of chain "descriptor" or content.
const int strlimit = 1024; // length of char sequence

// utilize nr of chains // e.g. 5 (or 500, 47, etc.)
const int maxchains = 5;

// length of stored chain refs.
const int climit = 5; // e.g. 10 (or 5, or 100) 

// Main Chain structure.
struct Chain {
    // stats is measured (work on this!!!)
    int id;    // id of single chain
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
};
        // need to implement stringing mechanism to process this pool back and forth into stringed {} metadata.
        // the pool fills up with data.
        // string references are tied to definitions.
        // pool empties in random order.
        // sort of swap;

int reportStatID(Chain c) {
    return c.id;
}

int reportStatChains(Chain c) {
    return c.nrOfChains;
}

int reportActiveChain(Chain c) {
    return c.activeChain;
}