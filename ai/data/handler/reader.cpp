// AI/DATA/HANDLER/READER.CPP - USED BY MODEL-AI (NOT USED YET!!!)

#include <string>
#include <iostream>
#include <fstream>

class Reader {
private:
    std::string filename;

public:

    Reader() {}
    Reader(std::string s) {}
    
    bool dataIsText();
    bool dataIsMath();

    void caller(std::string f);
};


bool Reader::dataIsText() { // returns true or false if data is text
    // insert conditions here
    
    return true;
}

bool Reader::dataIsMath() { // returns true or false if data is math
    // insert conditions here
    
    return true;
}

void caller(std::string f) { // f = this->filename
    
    std::string line;
    std::ifstream myfile;

    myfile.open(f);

    if (myfile.is_open()) {
        std::cout << "~:: caller() function -- reading data." << std::endl;
        while (getline (myfile,line)) {
            std::cout << line << std::endl;
        }
        myfile.close();
    } else {
        std::cout << "~:: caller() function -- Unable to open file." << std::endl;
    }
}