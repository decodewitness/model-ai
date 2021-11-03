#include <iostream>
#include <string>

class Transponder {
    private:

    protected:
        std::string subject;
        std::string answer;
        
    public:
        Transponder(std::string s);

        std::string respond();
        void analytics();
};

Transponder::Transponder(std::string s) {
    this->subject = s;
    this->respond();
}

std::string Transponder::respond() {
    std::cout << std::endl;
    std::cout << ":responding" << std::endl;

    std::string x = this->subject;
    this->analytics();

    this->answer = "- message relayed.";
    return this->answer;
}

void Transponder::analytics() {

    unsigned countWords(char *str);

    int len = this->subject.length();
    int wordcount = 1;

    std::string subject;
    std::string nouns;
    std::string adjective;
    std::string numerical;
}
