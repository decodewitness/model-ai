//  AI/ENTROPY/ENTROPY.CPP - USED BY "AI.H" FOR AI MODEL
//  "AI/ENTROPY/ENTROPY.CPP" - USED BY "LTCTAPTTCLT.CPP" FOR AI MODELS

#include <iostream>
#include <fstream>

std::fstream fs;	// written entropy data
std::fstream rs;	// resource | read stream

int entropyr() {  // read entropy from T1
    std::string tmp;
    
    //fs << " more lorem ipsum";
    
    //std::fstream fs;	// written entropy data

    // MAIN CATALYST
    fs >> tmp;
    std::cout << std::endl << std::endl << "HEREDOC:" << tmp << std::endl;
    return 1;
}

int entropyw(std::string s) {  // write entropy in TL
    //std::string tmp=" more lorem ipsum";
    
    //std::fstream rs;	// resource | read stream
    rs << s;
    return 0;
}

// eof