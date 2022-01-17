// "AI/DATA/HANDLER/FILTER.CPP" -- USED BY "AI/DATA/HANDLER/HANDLER.CPP"

#include <string>

void data_filter(std::string dat) {    // filters data expressions to categorize data (later move to filter file)
    // filter data here

    std::cout << "(debug) data_filter: " << dat << std::endl;
};

void math_filter(std::string exp) {    // filters math expressions from input (later move to filter file)
    // filter math here

    std::cout << "(debug) math_filter: " << exp << std::endl;
};

// eof