// AI/LOGIC/TRANSPONDER/TRANSPONDER.H - USED BY "/AI/LOGIC/TRANSPONDER/TRANSPONDER.CPP" // USED FOR LANGUAGE INTERPRETATION.

// headers
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <cstdlib>

// other headers
#include "prepare.cpp"
#include "brain/nn.h"
#include "stringcode.h"
// #include "synonyms.h"    // already included in (transponder.h / transponder.cpp)

// use stringcode to encode coded sequence to initiate or illicit response

int vec_rec;
int track_record;
std::vector<std::string> conversation;

// files
std::string question_answers = "ai/data/files/question_answers.txt";
std::string trivia_logic = "ai/data/files/trivia_logic.txt";
std::string synonym = "ai/data/files/synonyms.txt";
std::string weights = "ai/lib/queries/weights";


// Transponder  
class Transponder {
private:
    std::string initial_sentence;   // logic comparts from here
    bool analytical;    // whether to use "analytics" function
    vector<int> ints;
    vector<std::string> strings;
    std::ifstream scores;
    std::ifstream syno;
    int points; // keeps track of highest score


protected:
    std::string subject; // same as "initial_sentence" but maybe change this later
    std::string response; // the original answer, queried by the transponder and then returned
    std::string result; // the official answer of the transponder
    std::string waquestion;
    
public:
    // Transponder(std::string s); // initialize with subject
    Transponder();

    void init();    // handles file access and such
    void decouple();    // closes files and such

    // use boolean "b" to either use analytics (true) or else not use analytics (false)
    std::string respond(bool b);    // responds with logic
    std::string answer(std::string s);  // devise answer and return it as a string
    
    // process answers
    int rank_score(std::string q, std::string a);  // processes score/ranking for the answer based of similarities
    void setSubject(std::string s);
    int scored(std::string q, std::string tq);
    void listConvo(size_t max_history_length);
    std::string synonyms(std::string q);

    // analytical functions and preparation functions
    void prep(std::string s); // preps "ints"   //  needs "this->initial_sentence" or "this->subject"
    void prepTr(std::string s); // preps Transponder with query
    void analytics(std::string s);  // textual analytics function
    std::string retVal();
};

// eof