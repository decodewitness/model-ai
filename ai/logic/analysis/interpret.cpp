//  "AI/LOGIC/INTERPRET.CPP" - INTERPRET TEXT MODEL FOR THE AI CLASS MODEL - USED BY "AI/AI.H"
#include "interpret.h"

// interprets
std::string sos; // start of sentence
std::string eos; // end of sentence
std::string language_construct;

// temporary containers
std::string tempA;
std::string tempB;

// result container
std::string result;

// grammar rules
std::string subject;
std::string nouns;
std::string pronouns;
std::string adjective;
std::string numerical;