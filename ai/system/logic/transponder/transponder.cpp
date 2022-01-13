// /AI/LOGIC/TRANSPONDER/TRANSPONDER.CPP - USED BY /AI/AI.H
// USED FOR LANGUAGE INTERPRETATIONS.

#include <iostream>
#include <string>

#include "transponder.h"
#include "prepare.cpp"

class Transponder {
private:
    std::string initial_sentence;

protected:
    std::string subject;
    std::string answer;
        
public:
    Transponder(std::string s);

    std::string respond();
    
    void prep() {
        prepare_ints(limit);    // limit is declared in "prepare.cpp"
    };

    void analytics();
};

Transponder::Transponder(std::string s) {
    std::cout << std::endl << "~:: transponder queries." << std::endl;
    this->initial_sentence = s;

    // fit "initial_sentence" to "question" declared in "prepare.cpp"
    aquestion = s;

    // do check if data was initialized with a library here else preprocess the data.

    // CHECK !!!! !!!! !!!!
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
