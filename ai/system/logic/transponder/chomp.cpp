#include <string>

// function chomp   // returns string minus the terminating \n \t
std::string chomp(std::string str) {
    std::string::size_type pos = str.find_last_not_of("\n \t");

    if(pos != std::string::npos) {
        str = str.substr(0, pos+1);
    }
return str;
}