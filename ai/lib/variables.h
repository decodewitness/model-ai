// AI/DATA/FILES/VARIABLES.H    -   USED BY "AI/AI.H"

#include <string>

// queries
std::string query_string;   // gets used from Transponder class // when inserting logic into the device

// meta limits
const int meta_queries = 128;
const int meta_query_length = 256;

// meta queries (primary)
std::string meta_query; // meta_query is not used yet
std::string meta_sequence; // meta_sequence is used to store the "meta sequence" :: intvars int_occurences[]    // prepare.cpp

// meta queries (fast)
std::string meta_1; // meta_1 is not used yet
std::string meta_2; // meta_2 is not used yet
std::string meta_3; // meta_3 is not used yet
std::string meta_4; // meta_4 is not used yet
std::string meta_5; // meta_5 is not used yet

// meta queries (triviary)
char metas[meta_queries][meta_query_length];    // [128] meta queries in char format of length [256]

// eof