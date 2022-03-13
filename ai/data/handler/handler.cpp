// "AI/DATA/HANDLER/HANDLER.CPP" USED BY "AI/AI.H" 

#include <iostream>
#include <string>
#include <fstream>

#include "filter.cpp"

std::string INPUTFILE = "ai/data/cab";      // file containing (unfiltered) input data
std::string DATA_IN = "ai/data/in/pipeline"; // file containing input data that needs to get processed
std::string MATH_IN = "ai/data/in/expression";   // file containing math expressions or to write new expressions into

// FUNCTION TO HANDLE MATH DATA INPUT
void math_handler() {    // handles math expressions by using "matrix"  // called from math_filter()
    // file stream
    std::ifstream indata;

    // variables
    std::string expr = "0";
    std::string myvar = "this is a temporary variable and data container";

    std::cout << std::endl << "~:: math handler" << std::endl;

    indata.open(MATH_IN);
    
    if (indata.is_open() == true) {
        while (indata >> myvar) {
            // handle any math expression here
            math_filter(myvar);
        }            
    }

    indata.close();
};

// FUNCTION TO HANDLE DATA INPUT STREAMS
void data_handler() {   // handles data expressions // called from data_filter()
    // file stream
    std::ifstream indata;

    // variables
    std::string expr = "0";
    std::string myvar = "this is a temporary variable and data container";

    std::cout << std::endl << "~:: data handler" << std::endl;
    
    indata.open(DATA_IN);

    if (indata.is_open() == true) {
        while (indata >> myvar) {
            // convert myvar data from "out" variable (usually "DATA_IN" variable holding a filename)
            // handle data here
            data_filter(myvar);
        }
    }

    indata.close();
};

// eof