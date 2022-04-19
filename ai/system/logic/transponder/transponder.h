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
#include "references.cpp"
// #include "concept.cpp"   // included in AI/AI.H
// #include "synonyms.h"    // already included in (transponder.h / transponder.cpp)

// use stringcode to encode coded sequence to initiate or illicit response

// ints
int vec_rec;
int track_record;

// convo
std::vector<std::string> conversation;
std::vector<std::string> answers;

// files
std::string question_answers = "ai/data/files/question_answers.txt";
std::string trivia_logic = "ai/data/files/trivia_logic.txt";
std::string relatives = "ai/data/files/relatives.txt";
std::string synonym = "ai/data/files/synonyms.txt";
std::string weights = "ai/lib/queries/weights";

// backlog export
std::string backlog_query = "ai/log/backlog_queries.txt";
std::string backlog_answer = "ai/log/backlog_answers.txt";

// log file for query related things / - abstract
std::string logfile = "modelai_extract.txt";

// Transponder  
class Transponder {
private:
    // integers
    int used;   // indicates which file was used: trivia_logic or questions_answers
    int points; // keeps track of highest score
    
    // booleans
    bool analytical;    // whether to use "analytics" function
    bool capsize;  // if true then put a newline character before and after every log entry for the logQueries() && the qlog() functions

    // analytical
    bool fitting; // used in case the answer is fitting else resets bool and is checked in the query
    bool notAlwaysFitting;  // used when not always fitting answer
    bool alwaysFitting;  // used when applies in every answer context

    // strings
    std::string initial_sentence;   // logic comparts from here
    std::string default_response;   // carries the default response for when there is no logic
    std::string line;   // is used to indicate the line number of the transponder queries from trivia_logic/questions_answers
    
    // vectors
    vector<int> ints;
    vector<std::string> strings;
    vector<std::string> backlog_queries;    // backlog of queries of conversation
    vector<std::string> backlog_answers;    // backlog of answers of conversation
    vector<std::string> relations;
    vector<std::string> oursyns;

    // used for meta queries
    vector<int> vec;

    // file streams
    std::ifstream scores;
    std::ifstream syno;
    std::ofstream relate;

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
    std::string synonyms(std::string q);

    // analytical functions and preparation functions
    void prep(std::string s); // preps "ints"   //  needs "this->initial_sentence" or "this->subject"
    void prepTr(std::string s); // preps Transponder with query
    void analytics(std::string s);  // textual analytics function
    std::string retVal();
    std::string strip(std::string tq);

    // export backlog and storing relations
    void export_backlog(int n);    // n=0 (backlog_queries); n=1 (backlog_answers); n=2 (both)
    void cappedsize();  // toggles "capsize" boolean to put a newline char before and after log queries in Transponder::logQueries() and AI::qlog() functions

    // relations
    void store_relations();
    void flush_relations();

    // convos
    void store_in_convo(std::string s);  // stores string in this->conversation<vector>
    void store_in_answers(std::string s);    // stores in this->answers<vector>

    // listing queries and such
    void listConvos(size_t max_history_length);
    void list_relations();
    void logQueries(int x=0);

    // numerate brain
    void enumerateBrain() { std::cout << std::endl << "- size envelope : " << enumerate().size() << std::endl; };
};

// eof