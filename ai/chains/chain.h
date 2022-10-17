#include <iostream>
#include <string>
#include <vector>
#include <fstream>

const std::string chainfile = "ai/chains/chain";

// length of chain "descriptor" or content.
const int strlimit = 1024; // length of char sequence

// utilize nr of chains // e.g. 5 (or 500, 47, etc.)
const int maxchains = 1;

// length of stored chain refs.
const int climit = 2; // e.g. 10 (or 5, or 100)

// nr of referrals to sequences in seq_1 to seq_5
const int seq_ref = 1;  // must be smaller or the same as climit!!!

// Main Chain structure.
struct Chain {
    // stats is measured (work on this!!!)
    int id;         // id of single chain

    // chain stats
    int nrOfChains; // nr of chains  // ((( could fluctuate ;; needs implementation)))
    int activeChain;    // the active chain number (passive/active ##)

    // current nominal chain sequences
        // from 1 -> ... -> 5
    int seq_1[climit];
    int seq_2[climit];
    int seq_3[climit];
    int seq_4[climit];
    int seq_5[climit];

    // chain data
    int chain[maxchains][climit];
    char chains[maxchains][strlimit];

    // reference to sequences inside chain
    int seq_no[5][seq_ref];

    // total pooled data
    std::vector<std::string> pool;
};

// need to implement stringing mechanism to process this pool back and forth into stringed {} metadata.
// the pool fills up with data.
// string references are tied to definitions.
// pool empties in random order.
// sort of swap