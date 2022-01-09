// AI/DATA/HANDLER/READER.CPP - USED BY MODEL-AI (NOT USED YET!!!)

#include <string>

class Reader {
private:
    std::string filename;

public:

    Reader() {}
    Reader(std::string s) {}
    
    Readln();

    bool dataIsText();
    bool dataIsMath();

    void caller(std::string f);
};


bool Reader::dataIsText() {

return 0;
}

bool Reader::dataIsMath() {
    
return 0;
}

void caller(std::string f) { // f = this->filename


}