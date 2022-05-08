// AI/SYSTEM/LOGIC/STRINGS.CPP  -   USED BY "AI/AI.H"

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

bool searchterm(std::string search, std::string& str) {  // returns silent and 'true' when string query "search" is found in string "str" else returns false
    bool ret = false;
    if (str.find(search) != std::string::npos) {
        ret = true;
    }
return ret;
};

bool searchterm2(std::string search, std::string& str) {  // prints and returns 'true' when string query "search" is found in string "str" else returns false
    bool ret = false;
    if (str.find(search) != std::string::npos) {
        std::cout << "(true)";
        ret=true;
    } else {
        std::cout << "(false)";
        ret=false;
    }
return ret;
};
