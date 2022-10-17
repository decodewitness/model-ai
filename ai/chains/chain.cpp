// AI/CHAIN/CHAIN.CPP -- (NOT USED YET!!!)
    // Need to use CHAIN.H to build chain dynamics in architecture.
# include "chain.h"

int reportStatID(Chain &c) {    // also used in chainID()
    return c.id;
}

int reportStatChains(Chain &c) {    // also used in chainID()
    return c.nrOfChains;
}

int reportActiveChain(Chain &c) {    // also used in chainID()
    return c.activeChain;
}

// checks for double chain ID nrs.
void chainID(Chain c) { // uses reportStatID(&c), reportStatChains(&c), and reportActiveChain(&c)
    std::cout << "~:: chainID()." << std::endl;
    std::cout << "\t~:: Chain ID\t:\t";
    std::cout << reportStatID(c);
    std::cout << std::endl;
    std::cout << "\t~:: Active Chain\t:\t";
    std::cout << reportActiveChain(c);
    std::cout << std::endl;
    std::cout << "\t!:: Nr. of Chains\t:\t";
    std::cout << reportStatChains(c);
    std::cout << std::endl;
}

Chain & chainCreate() {
    int id=0;
    int active_chain=1;
    int chainno=1;

    Chain *c = new Chain;
    std::ifstream f;

    std::cout << "~:: chainCreate()." << std::endl;
    
    f.open(chainfile);
    
    if (f.is_open() == true) {
        f >> id;
        f.close();
    
        std::cout << "\t~:: id=[" << id << "]" << std::endl;
    } else {
        std::cout << "~::!::~ (error) can't open \"chain\" file for reading!" << std::endl;
    }
    
    // std::cout << std::endl;
    // set the new Chain before returning it

    c->id = id;
    c->activeChain = active_chain;
    c->nrOfChains = chainno;

    std::ofstream o;

    o.open(chainfile);

    if (o.is_open() == true) {
        o << id++;
        std::cout << "\t~:: updated chain ref (" << id << ") in \"chain\" file." << std::endl;
        o.close();
    }
    std::cout << std::endl;

return *c;
}

void deleteChain(Chain &c) {
    std::cout << "~:: deleteChain()." << std::endl;
    std::cout << "\t~:: Chain[" << c.id << "]->(";
    delete &c;
    std::cout << "deleted)." << std::endl;
}

void readChain(Chain &c) {
    std::cout << "~:: readChain()." << std::endl;
    
    // enumerate chain
    std::cout << "\t~:: ChainID:\t" << c.id << std::endl;
    std::cout << "\t~:: Nr of Chains:\t" << c.nrOfChains << std::endl;
    std::cout << "\t~:: Active Chain:\t" << c.activeChain << std::endl;
    
    std::cout << std::endl;

    std::cout << "\t~:: Chain Data (int):" << std::endl;
    for (int i=0; i<c.nrOfChains; i++) {
        std::cout << "\t\t-" << c.chain[i][0] << std::endl;
    }
    
    std::cout << std::endl;

    std::cout << "\t~:: Chain Data (char):" << std::endl;
    for (int i=0; i<c.nrOfChains; i++) {
        std::cout << "\t\t-" << c.chains[i] << std::endl;
    }
    
    std::cout << std::endl;

    // enumerate c.pool
    std::cout << "\t~:: Chain Pool Data:" << std::endl;
    for (std::vector<std::string>::iterator t=c.pool.begin(); t!=c.pool.end(); ++t) {
        std::cout << "\t\t-" << *t << std::endl;
    }
}

void writeChain(int x, int id, Chain &c, std::string str) {   // x=chain, id=chain.id, str=data written to chain
    int xii=x;
    int counter=0;
    bool wrote = false;
    int lng=str.length();   // length of chain

    std::cout << "~:: writeChain()." << std::endl;

    // if (x == 0) {
        // std::cout << std::endl << "~::!::~ (caution) chain number was (0) ;; changed to (1)!!!" << std::endl;
        // xii += 1;
    // }

    if (xii < 0 || x > 5) {
        std::cout << std::endl << "~::!::~ (caution) chain number was smaller than (0) ;; or bigger than (5)!!!" << std::endl;
        xii = 0;
        std::cout << "\t~:: chain number #" << xii << " set to (0)!" << std::endl;
    }

    // write to chain
    if (id == c.id) {
        // correct Chain!
        std::cout << "\t~:: +chain:" << xii << " length: (" << str.length() << ")"<< std::endl;
        if (lng > 0 && xii < c.nrOfChains) {
            for (int i=0; i<strlimit-1; i++) {
                if (i<lng) {
                    c.chains[xii][i] = str.c_str()[i];
                    wrote = true;
                    counter++;
                } else {
                    break;
                }
            }
        }
        if (wrote == true) {
            std::cout << "\t~:: (wrote) chain data (" << counter << ")." << std::endl;
            c.chains[xii][counter] = '\0';
        }
    } else {
        //
        std::cout << std::endl << "~::!::~ did not match chain number! aborts write." << std::endl;
    }
}

void viewChainData(Chain &cd, int x=0) { // x = chain number
    std::cout << "~:: viewChainData()." << std::endl;
    if (x <= cd.nrOfChains) {
        std::cout << "\t~:: (*)[chain][" << cd.id << "][" << x << "]->(\"" << cd.chains[x] << "\")." << std::endl;
    } else {
        std::cout << std::endl << "~::!::~ (error) - assigned wrong chain nr (max: " << cd.nrOfChains << ")." << std::endl;
    }
}

/*
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
*/

// eof