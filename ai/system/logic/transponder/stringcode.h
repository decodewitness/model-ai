#include <fstream>

int operationCode(std::ifstream interface) {    // reads from file interface and returns code
    int string_code;
    interface >> string_code;
return string_code;
};

std::string stringCode(const std::string &strinterface, int nlimit=4) {    // reads from file interface and returns code ending with a 0
    char ch;

    int n;  // (int) n = (char) ch
    const std::string::size_type size_string = nlimit;   // maximum length for "string_code"
    std::string string_code="00000000"; // has maximum length of "size_string"

    std::string tmpCharContainer;   // temporary container
    
    bool isLetterSm = false;
    bool isLetterBg = false;
    bool isNumber = false;
    bool isSpecial = false;
    bool excl = false;
    bool query = true;

    // legenda ///////////
        // s = small char
        // L = large char
        // n = number
        // x = exclamation
        // q = question
        // ! = special
    //////////////////////

    for (std::string::size_type i=0; i<strinterface.size() && i < size_string; i++) {

        if (strinterface[i] >= 'a' && strinterface[i] <= 'z') {
            isLetterSm = true;
            tmpCharContainer[i] = 's';
        } else if (strinterface[i] >= 'A' && strinterface[i] <= 'Z') {
            isLetterBg = true;
            tmpCharContainer[i] = 'L';
        } else if (strinterface[i] >= '1' && strinterface[i] <= '0') {
            isNumber = true;
            tmpCharContainer[i] = 'n';
        } else if (strinterface[i] == '!') {
            excl = true;
            tmpCharContainer[i] = 'x';
        } else if (strinterface[i] == '?') {
            query = true;
            tmpCharContainer[i] = 'q';
        } else {
            isSpecial = true;
            tmpCharContainer[i] = '!';
        }
    }

    // set return key after encoding string
    string_code = tmpCharContainer + "0";

return string_code;
};
    // other checks implemented on strings

        // // codify string
        // if (isLetterSm == true) {
        //     string_code += 1;
        // } else if (isLetterBg == true) {
        //     string_code += 10;
        // }
