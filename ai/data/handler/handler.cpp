// "AI/DATA/HANDLER/HANDLERS.CPP"  (USED BY "MODLE-AI") (NOT USED YET!!!)
#include <string>
#include <fstream>

#include "filter.cpp"

std::string INPUTFILE = "ai/data/cab";      // file containing (unfiltered) input data
std::string DATA_IN = "ai/data/in/pipeline"; // file containing input data that needs to get processed
std::string MATH_IN = "ai/data/in/expression";   // file containing math expressions or to write new expressions into

// FUNCTION TO HANDLE MATH DATA INPUT
void math_handler(std::string out) {    // handles math expressions by using "matrix"

    std::string expr = "0";
    std::string myvar = "this is a temporary variable and data container";

    // convert myvar data from "out" variable (usually "MATH_IN" variable holding a filename)
    
    // handle any math expression here
    math_filter(myvar);
};

// FUNCTION TO HANDLE DATA INPUT STREAMS
void data_handler(std::string out) {

    std::string expr = "0";
    std::string myvar = "this is a temporary variable and data container";

    // convert myvar data from "out" variable (usually "DATA_IN" variable holding a filename)

    // handle data here
    data_filter(myvar);
};

// eof