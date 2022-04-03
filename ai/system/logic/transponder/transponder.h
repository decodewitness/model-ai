// AI/LOGIC/TRANSPONDER/TRANSPONDER.H - USED BY "/AI/LOGIC/TRANSPONDER/TRANSPONDER.CPP" // USED FOR LANGUAGE INTERPRETATION.

// headers
#include <string>

// use stringcode to encode coded sequence to initiate or illicit response
#include "brain/nn.h"
#include "stringcode.h"

// files
std::string question_answers = "ai/data/files/question_answers.txt";
std::string trivia_logic = "ai/data/files/trivia_logic.txt";

int track_record;

// Transponder
class Transponder {
private:
    std::string initial_sentence;   // logic comparts from here
    bool analytical;    // whether to use "analytics" function
    vector<int> ints;
    vector<std::string> strings;

protected:
    std::string subject; // same as "initial_sentence" but maybe change this later
    std::string response; // the original answer, queried by the transponder and then returned
    std::string waquestion;
    
public:
    // Transponder(std::string s); // initialize with subject
    Transponder();

    // use boolean "b" to either use analytics (true) or else not use analytics (false)
    std::string respond(bool b);    // responds with logic
    std::string answer(std::string s);  // devise answer and return it as a string
    
    // process answers
    int rank_score(std::string q, std::string a);  // processes score/ranking for the answer based of similarities
    void setSubject(std::string s);
    
    // analytical functions and preparation functions
    void prep(std::string s); // preps "ints"   //  needs "this->initial_sentence" or "this->subject"
    void prepTr(std::string s); // preps Transponder with query
    void analytics(std::string s);  // textual analytics function
    std::string retVal();
};

// eof