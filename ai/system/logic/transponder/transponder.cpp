// AI/LOGIC/TRANSPONDER/TRANSPONDER.CPP - USED BY "/AI/AI.H" // USED FOR LANGUAGE INTERPRETATION.

#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <sstream>
#include <fstream>

#include "prepare.cpp"
#include "transponder.h"

Transponder::Transponder(std::string s) {
    std::cout << std::endl << "~:: transponder queries." << std::endl;
    sleep(2);
    // setting both "this->initial_sentence" && "this->subject" here to parameter string, which is the sentence queried to the Transponder
    this->initial_sentence = s;
    
    // initial value
    this->subject = s;

    this->analytical = true;   // also redundant

    // fit "initial_sentence" to "question" declared in "prepare.cpp"
    aquestion = s;
    
    // respond
    this->respond(this->analytical);
};

std::string Transponder::respond(bool b) {
    
    // skip line and respond from mechanism
    std::cout << std::endl;
    std::cout << "\tTRANSPONDER::responding:" << std::endl;
    std::cout << "\t-----" << std::endl;

    // std::string x;

    // do logic here to determine if analytics are required.

    if (b == true) {
        // x = this->subject;
        this->analytics(this->subject);
    } else {
        // debug messages
        std::cout << std::endl << "~::(skipping analytics)" << std::endl;
    }

    // EDIT THIS!!!
    // should use transponder together with NLP processing
    // instead of just relaying the answer.
        // use logic here
    this->response = "~:: tr :: message was relayed from transponder -- response().";

    // return the answer to the question or statement/pragma/sequence/expression
    return this->response;
};

void Transponder::analytics(std::string s) {
    // unsigned int countWords(char *str);

    // variables for analytics 
    int wordcount=0;      // number of words in string
    int noun=0;
    int consonant=0;
    int number=0;
    int special=0;
    int unknown=0;

    // length for analytics
    int len = s.length();   // length of string
    
    // debugging output
    std::cout << "\t~:: (DEBUG) performing analytics() in {transponder}." << std::endl;

    for (int i=0; i<len; i++) {
        
        if (s.at(i) == 32 || s.at(i) == '\n') {    // checks to see if char is a 'space' (32) or newline character (enter) '\n'
            wordcount++;
        }

        switch (s.at(i)) {
            // nouns
            case 'a':
            case 'e':
            case 'i':
            case 'u':
            case 'o':
                noun++;
                break;
            // consonants
            case 'z':
            case 'x':
            case 'c':
            case 'v':
            case 'b':
            case 'n':
            case 'm':
            case 's':
            case 'd':
            case 'f':
            case 'g':
            case 'h':
            case 'j':
            case 'k':
            case 'l':
            case 'q':
            case 'w':
            case 'r':
            case 't':
            case 'y':
            case 'p':
                consonant++;
                break;
            // numbers
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                number++;
                break;
            // special characters
            case '!':
            case '@':
            case '#':
            case '$':
            case '%':
            case '^':
            case '&':
            case '*':
            case '(':
            case ')':
            case '_':
            case '=':
            case '-':
            case '+':
            case '[':
            case ']':
            case '{':
            case '}':
            case '|':
            case '\\':
            case '.':
            case ',':
            case '<':
            case '>':
            case '/':
            case '?':
            case '\'':
            case '"':
            case ';':
            case ':':
            case '`':
            case '~':
            case (32):
            case '\n':
            case '\r':
                special++;
                break;
            
            default:    // unknown characters
                unknown++;
                break;
        };
    }

    // analytics function output
    std::cout << "\t::- analytics -::" << std::endl;
    std::cout << std::endl << "\t-----------------" << std::endl;
    std::cout << std::endl;

    // out put analytics data
    std::cout << "\t\t* words no_#: " << (wordcount + 1) << std::endl;
    std::cout << "\t\t* length: " << len << std::endl;
    std::cout << "\t\t* vowels: " << noun << std::endl;
    std::cout << "\t\t* consonants: " << consonant << std::endl;
    std::cout << "\t\t* numbers: " << number << std::endl;
    std::cout << "\t\t* special chars: " << special << std::endl;
    std::cout << "\t\t* unknown chars: " << unknown << std::endl;

    // skip line
    std::cout << std::endl;

    // process answers in "this->answer()"
    
    std::cout << std::endl << "(debug) answer." << std::endl;
    this->response = this->answer(s);
    
    sleep(1);
    
    // answer the question
    std::cout << std::endl << "~:: transponder -> answer()" << std::endl;
    std::cout << std::endl << "+query :: (" << this->subject << ")" << std::endl;
    std::cout << std::endl;
    std::cout << "-- answer:" << std::endl << "\t" << this->response << std::endl;
    std::cout << std::endl;
};

void Transponder::prep(std::string s) { // 's' is the input sentence from "query_string"
    //int indexes = 1;
    //bool bNo = true;    // initial word check

    int nrOfWords = 0;
    int counter = 0;

    std::string extrapolated;
    std::string word;

    std::vector<std::string> userString(max_sentence_length);
    std::istringstream iss(s);

    for (decltype(userString.size()) i=0; i<userString.size(); ++i) {
        // split words in sentence
        while (iss >> word) {

            if (word.back() == '.' || word.back() == ',' || word.back() == '!' || word.back() == '?' || word.back() == ':' || word.back() == ';' ) {
                word.pop_back();
            }

            std::cout << "(debug) word :: " << word << std::endl;
            nrOfWords++;
            // at the same time counting words in sentence
            strncpy(wordsFromSentence[counter++], word.c_str(), word.length());
        }
    }

    std::cout << std::endl;
    std::cout << "~:: (debug)::nrOfWords = " << nrOfWords << "." << std::endl;
    std::cout << "~:: (debug)::counter = " << counter << "." << std::endl;
    std::cout << std::endl;


    // prepare_ints() prepares the dictionaries
    // dictionaries(true);
    std::cout << "(debug) calling prepare_ints() (from) -> \"" << s << "\"." << std::endl;

    // PREPARE DICTIONARIES IN THIS FUNCTION
    dictionaries(alimit, counter);  // A1: limit dictionary A2: limit sentence
    //prepare_ints(alimit, counter);  // arg1: limit dictionary, arg2: limit length of filled elements in "wordsFromSentence"
    //prepare_occurrences(alimit, counter);   // prepares_occurrences array with place in the dictionary for the wordsFromSentence
};

std::string Transponder::retVal() {
    return this->initial_sentence;
};

std::string Transponder::answer(std::string s) {
    int answers_processed = 0;

    std::string query = s;
    std::string x;
    std::ifstream filen;
    
    std::string used_file ="trivia_logic.txt";  // AI/DATA/FILES/TRIVIA_LOGIC.TXT
    std::string used_file_ar[64] = { "trivia_logic", "question_answers" };  // max. file name length    // AI/DATA/FILES/TRIVIA_LOGIC.TXT   // AI/DATA/FILES/QUESTION_ANSWERS.TXT

    // question, normal, or exclamation
    bool isDot = false;
    bool isQuestion = false;
    bool isExclamation = false;
    // interpunction
    bool isComma = false;
    bool isSemicolon = false;
    bool isColon = false;
    // query needs followed up statement for logic
    bool isFollowUp = false;

    // open the correct file
    if (query.back() == '?') {  // open "question_answers"
        isQuestion = true;
        used_file = question_answers;
        query.pop_back();
    } else if (query.back() == '!') {   // open "trivia_logic"
        isExclamation = true;
        used_file = trivia_logic;
        query.pop_back();
    } else if (query.back() == '.') {   // open "trivia_logic"
        isDot = true;
        used_file = trivia_logic;
        query.pop_back();
    } else if (query.back() == ',') {   // open "trivia_logic"
        isComma = true;
        isFollowUp = true;
        used_file = trivia_logic;
        // follow_up check here
        query.pop_back();
    } else if (query.back() == ';') {   // open "trivia_logic"
        isSemicolon = true;
        isFollowUp = true;
        used_file = trivia_logic;
        // follow up check here
        query.pop_back();
    } else if (query.back() == ':') {   // open "trivia_logic"
        isColon = true;
        isFollowUp = true;
        used_file = trivia_logic;
        // follow up check here
        query.pop_back();
    }

    filen.open(used_file);

    if (filen.is_open() == true) {
        while (getline (filen,x)) {
            answers_processed += 1;
            // convert this logic first!!!!!!!!
            // process answers into NEW!! ARRAY!!!!!!!!
            // calculate score
            std::cout << std::endl << "(score): " << this->rank_score(query, x) << std::endl;
        }
    } else {
        std::cout << std::endl << "~::!::~ error opening file (Transponder::answer()): \"" << used_file << "\"" << std::endl << std::endl;
    }

    std::cout << std::endl;

    if (isDot == true) {
        std::cout << "~:: (debug) query was normal: ('.')" << std::endl;
    } else if (isQuestion == true) {
        std::cout << "~:: (debug) query was question: ('?')" << std::endl;
    } else if (isComma == true || isColon == true || isSemicolon == true) {
        std::cout << "~:: (debug) query gets follow up: (','|':'|';')" << std::endl;
    } else if (isExclamation == true) {
        std::cout << "~:: (debug) query was exclamation: ('!')" << std::endl;
    } else {
        std::cout << "~:: (debug) -- (!) -- abnormal query!" << std::endl;
    }

    std::cout << std::endl << "~:: (debug) - answers processed: " << answers_processed << std::endl;

    // return answer to Transponder::analytics(std::string)
    return x;
};

int Transponder::rank_score(std::string q, std::string a) { // parameters: q:query, a:answer
    int score = 0;

    // split words in query
    // compare occurences in q -&- a
    // add score and return it

    // then compare score inside 

return score;
};

    // char strP[256][wordsize][words];
    // char *strP2;


    // for (int i=0, indexPrev=0, indexNext=0; i<s.length(); i++) {
    //     if (s.at(i) == 32 || s.at(i) == '\n') {    // checks to see if char is a 'space' (32) or newline character (enter) '\n'
    //         extrapolated  = s.substr(indexPrev, (i));

    //         std::cout << std::endl << "(debug) added word (" << extrapolated << ") to extrapolated." << std::endl;
    //         sleep(1);   // debug

    //         nrOfWords++;
    //         indexPrev=i;

    //         strncpy(wordsFromSentence[++counter], extrapolated.c_str(), wordsize);

    //         // check if next char is also '\n' or (32)
    //         do { indexNext = i+indexes++; i=indexNext; std::cout << "(debug)[skipped char] * (" << indexes << ")." << std::endl; } while (s.at(i) == 32 || s.at(i) == '\n');
    //     } else if (i > 0 && bNo == true) {  // adjust nrOfWords (counter)
    //         nrOfWords += 1;
    //         bNo = false;
    //     }
    // }
   
    // for (int i=0, indexPrev=0, indexNext=0; i<s.length(); i++) {
    //     if (s.at(i) == 32 || s.at(i) == '\n') {    // checks to see if char is a 'space' (32) or newline character (enter) '\n'
    //         extrapolated = s.substr(indexPrev, (i-1));
    //         nrOfWords++;
    //         indexPrev=i;

    //         // check if next char is also '\n' or (32)
    //         do { indexNext = i+indexes++; i=indexNext; std::cout << "(debug)[skipped char] x (" << indexes << ")." << std::endl; } while (s.at(i) == 32 || s.at(i) == '\n');
    //     }
    // }
    
    //    nrOfWordsInSentence = counter;
    //    prepare_ints(alimit);    // limit is declared in "prepare.cpp"

    // set "nrOfWordsInSentence" to "counter" to get the correct number of words in the "prepare_ints()" function.
//};

