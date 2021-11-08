// /AI/LOGIC/TRANSPONDER/TRANSPONDER.CPP - USED BY /AI/AI.H
// USED FOR LANGUAGE INTERPRETATIONS.

#include <iostream>
#include <string>

class Transponder {
private:
    std::string initial_sentence;

protected:
    std::string subject;
    std::string answer;
        
public:
    Transponder(std::string s);

    std::string respond();
    void analytics();
};

Transponder::Transponder(std::string s) {
    this->initial_sentence = s;
};

std::string Transponder::respond() {
    std::cout << std::endl;
    std::cout << ":responding" << std::endl;

    std::string x = this->subject;
    this->analytics();

    this->answer = "- message relayed.";
    return this->answer;
};

void Transponder::analytics() {
    unsigned int countWords(char *str);

    int len = this->subject.length();
    int wordcount = 1;

    this->respond();
};
