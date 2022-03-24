// AI/LOGIC/TRANSPONDER/TRANSPONDER.H - USED BY "/AI/LOGIC/TRANSPONDER/TRANSPONDER.CPP" // USED FOR LANGUAGE INTERPRETATION.

// headers
#include <string>

// use stringcode to encode coded sequence to initiate or illicit response
#include "stringcode.h"

// files
std::string question_answers = "data/files/question_answers.txt";
std::string trivia_logic = "data/files/trivia_logic.txt";

// Transponder
class Transponder {
private:
    std::string initial_sentence;   // logic comparts from here
    bool analytical;    // whether to use "analytics" function

protected:
    std::string subject; // same as "initial_sentence" but maybe change this later
    std::string response; // the original answer, queried by the transponder and then returned
    
public:
    // Transponder(std::string s); // initialize with subject
    Transponder();

    // use boolean "b" to either use analytics (true) or else not use analytics (false)
    std::string respond(bool b);    // responds with logic
    std::string answer(std::string s);  // devise answer and return it as a string
    
    // process answers
    int rank_score(std::string q, std::string a);  // processes score/ranking for the answer based of similarities

    // analytical functions and preparation functions
    void prep(std::string s); // preps "ints"   //  needs "this->initial_sentence" or "this->subject"
    void prepTr(std::string s); // preps Transponder with query
    void analytics(std::string s);  // textual analytics function
    std::string retVal();
};

// eof