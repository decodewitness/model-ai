//  "AI/LOGIC/INTERPRET.CPP" - INTERPRETS TEXT MODEL FOR THE AI CLASS MODEL - USED BY "AI/AI.H"
#include "interpret.h"

// interprets
std::string sos; // start of sentence
std::string eos; // end of sentence
std::string eot; // end of transmission

// language construct
std::string language_construct;

// temporary containers
std::string tempA;
std::string tempB;

// result container
std::string result;

// grammar rules
std::string subject;
std::string vowels;
std::string provowels;
std::string adjective;
std::string numerical;
