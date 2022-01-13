// "/AI/LOGIC/TRANSPONDER/TRANSPONDER.H" - USED BY "/AI/LOGIC/TRANSPONDER/TRANSPONDER.CPP" // USED FOR LANGUAGE INTERPRETATION.

#include <string>

class Transponder {

private:
    std::string initial_sentence;   // logic comparts from here
    bool analytical;    // whether to use "analytics" function

protected:
    std::string subject; // same as "initial_sentence" but maybe change this later
    std::string answer; // the original answer, queried by the transponder and then returned
    
public:
    Transponder(std::string s); // initialize with subject

    // use boolean "b" to either use analytics (true) or else not use analytics (false)
    std::string respond(bool b);    // responds with logic
    
    void prep(std::string s); // preps "word2int"   //  needs "this->initial_sentence" or "this->subject"
    void analytics(std::string s);  // textual analytics function

    std::string retVal();
};

// eof