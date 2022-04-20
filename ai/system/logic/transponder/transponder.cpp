// AI/LOGIC/TRANSPONDER/TRANSPONDER.CPP - USED BY "/AI/AI.H" // USED FOR LANGUAGE INTERPRETATION.

#include "transponder.h"

// #include "scores.cpp"

extern std::string aquestion;

Transponder::Transponder() {
    std::cout << std::endl << "~:: transponder queries." << std::endl;
    sleep(1);
    this->init();
    this->points = 0;
    this->default_response = "can't relate to query.";
    this->capsize= false;
};

void Transponder::init() {
    std::cout << std::endl << "\t~:: transponder->init()." << std::endl;

    if (this->scores.is_open() == false) {
        this->scores.open(weights);
        if (this->scores.is_open() == true) {
            std::cout << "\t\t~:: successfully opened: \"" << weights << "\"." << std::endl;
        } else {
            std::cout << std::endl << "~:!:~ (error): opening \"" << weights <<"\"." << std::endl;
        }
    }

    if (this->syno.is_open() == false) {
        this->syno.open(synonym);
        if (this->syno.is_open() == true) {
            std::cout << "\t\t~:: successfully opened: \"" << synonym << "\"." << std::endl;
        } else {
            std::cout << std::endl << "~:!:~ (error): opening \"" << synonym <<"\"." << std::endl;
        }        
    }
};

void Transponder::decouple() {
    std::cout << std::endl << "~:: decoupling transponder." << std::endl;

    if (this->scores.is_open() == true) {
        this->scores.close();
        std::cout << "\t~:: closed \"" << weights << "\" transponder file access." << std::endl;
    }

    if (this->syno.is_open() == true) {
        this->syno.close();
        std::cout << "\t~:: closed \"" << synonym << "\" transponder file access." << std::endl;
    }
};

void Transponder::prepTr(std::string s) { // preparation of Transponder object
    this->initial_sentence = s;
    
    // initial value
    this->subject = s;
    this->analytical = true;   // also redundant

    // fit "initial_sentence" to "question" declared in "prepare.cpp"
    this->waquestion = s;
};

// Transponder::Transponder(std::string s) {
//     std::cout << std::endl << "~:: transponder queries." << std::endl;
//     sleep(2);
//     // setting both "this->initial_sentence" && "this->subject" here to parameter string, which is the sentence queried to the Transponder
//     this->initial_sentence = s;
    
//     // initial value
//     this->subject = s;

//     this->analytical = true;   // also redundant

//     // fit "initial_sentence" to "question" declared in "prepare.cpp"
//     aquestion = s;
    
//     // respond
//     this->respond(this->analytical);
// };

void Transponder::setSubject(std::string s) {
    this->subject = s;
    std::cout << std::endl << "~:: set subject to: \"" << this->subject << "\"." << std::endl;
};

std::string Transponder::respond(bool b) {
    std::string syn_res;
    
    // skip line and respond from mechanism
    std::cout << std::endl;
    std::cout << "\tTRANSPONDER::responding:" << std::endl;
    std::cout << "\t-----" << std::endl;

    // std::string x;
    // do logic here to determine if analytics are required.

    if (b == true) {
        // x = this->subject;
        this->analytics(this->subject);
        // syn_res = synonyms(this->subject);

    } else {
        // debug messages
        std::cout << std::endl << "~::(skipping analytics)" << std::endl;
    }

    // EDIT THIS!!!
    // should use transponder together with NLP processing
    // instead of just relaying the answer.
        // use logic here
    this->response = "~:: tr :: message was relayed by transponder -- response()."; // gets changed somewhere else, in: *void Transponder::analytics(std::string s)*

    // return the answer to the question or statement/pragma/sequence/expression
    return this->response;
};

void Transponder::analytics(std::string s) {    // function that performs the analytics
    // metas
    int meta;

    // variables for analytics 
    int wordcount=0;      // number of words in string
    int noun=0;
    int consonant=0;
    int number=0;
    int special=0;
    int unknown=0;
    // unsigned int countWords(char *str);

    // variables for query position
    int pos;
    bool queryAssigned = false;
    // int pos1, pos2;

    // strings
    std::string query;

    std::string syn_res;
    // std::string syn_res1;
    // std::string syn_res2;

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

    // output analytical data
    std::cout << "\t\t* words no_#: " << (wordcount + 1) << std::endl;
    std::cout << "\t\t* length: " << len << std::endl;
    std::cout << "\t\t* vowels: " << noun << std::endl;
    std::cout << "\t\t* consonants: " << consonant << std::endl;
    std::cout << "\t\t* numbers: " << number << std::endl;
    std::cout << "\t\t* special chars: " << special << std::endl;
    std::cout << "\t\t* unknown chars: " << unknown << std::endl;

    // skip line
    std::cout << std::endl;

    // RESPONSE GETS SET HERE
    // process answers in "this->answer()"
    std::cout << std::endl << "(debug) answer." << std::endl;
    this->response = this->answer(s);
    
    std::cout << std::endl;
    std::cout << "----- ----- -----" << std::endl;
    //std::cout << "(debug) response : " << this->response << std::endl;
    std::cout << "(debug) result : " << this->result << std::endl;

    
    
    //syn_res1 = synonyms(this->response);
    // syn_res2 = synonyms(this->result);



    sleep(1);
    
    // answer the question
    std::cout << std::endl << "~:: transponder -> answer()" << std::endl;
    
    // ANSWER / RESPONSE
    if (this->result.length() > 0) {
        std::cout << std::endl << "~:: pushing back queries." << std::endl;

        // push back query
        this->backlog_queries.push_back(this->subject);
        this->backlog_answers.push_back(this->result);
        
        // strip line number from transponder query and store it in relations
        if (this->used == 1 || this->used == 2) {
            std::cout << std::endl << "~:: stripping (result)." << std::endl;
            // use strip() to get the line number
            this->line = this->strip(this->result);
            // store line number in relations
            this->relations.push_back(this->line);
            
            std::cout << std::endl << "- pushing back : " << this->line << std::endl;
            
            // reset this->used and this->line ;; this->used indicates the file that was used ;; 1=trivia_logic ;; 2=questions_answers
            this->used = 0;
            this->line = "0";
        }

        // store your relations
        this->store_relations();    // stores the relations through store_relations() function
        // flush relations
        this->flush_relations();

        syn_res = synonyms(this->subject);

        // filter response
        // if (this->result.length() >= 1) {
        //     // query
            
        //     pos = this->result.find_first_of("\";") - 2;
        //     query = this->result.substr(this->result.find("\",\"") + 3, pos);
            
        //     // pos2 = this->result.find_last_of("\";");
        //     // query = this->result.substr(pos1, pos2-1);

        //     if (query.length() > 0) {
        //         queryAssigned = true;
        //     }
        // }

        // std::cout << std::endl;
        // std::cout << ((queryAssigned) ? "-assigned query;" : "-query was not assigned;");
        // std::cout << std::endl;

        // metas
        std::string word;
        istringstream iss(this->subject);
        
        while (iss >> word) {
            meta = singleMeta(word);
            this->vec.push_back(meta);
        }

        // handle storing of the meta queries in "vec"
        nref xl;
        xl.nr = "1000";
        xl.rel1 = this->result;
        xl.description = this->subject;
        std::cout << std::endl;
        
        for (int i=0; i<vec.size(); i++) {
            std::cout << "\t~:: pushing back query : " << std::endl;
            xl.rel.push_back(std::to_string(vec.at(i)));
        }
        
        std::cout << "\t~:: storing nref." << std::endl;
        store_nref(xl);

        // OUTPUT

        // output MAIN RESPONSE in all certain events
        std::cout << std::endl;
        std::cout << "+query :: (" << this->subject << ")" << std::endl;
        // std::cout << "[RESPONSE] : " << ((queryAssigned) ? query : "-query was not assigned-") << std::endl; // query was just made here above
        std::cout << "[RESPONSE] : " << this->result << std::endl;
        sleep(3);

        // reset points
        this->points = 0;   // this keeps track of the highest score for results
        // reset result
        this->result = "missing";   // redundant
        // clear vector with metas
        this->vec.clear();
    } else {
        // secondary output // DEFAULT RESPONSE // Not used in the most cases
        std::cout << std::endl;
        std::cout << "+query :: (" << this->subject << ")" << std::endl;
        std::cout << "[RESPONSE] : " << this->default_response << std::endl;
        sleep(3);
    }
    // std::cout << std::endl << "-- answer:" << std::endl << "\t" << this->response << std::endl;
    std::cout << std::endl;
};

void Transponder::prep(std::string s) { // 's' is the input sentence from "query_string"
    //int indexes = 1;
    //bool bNo = true;    // initial word check

    int nrOfWords = 0;
    int counter = 0;

    std::string extrapolated;
    std::string word;

    this->setSubject(s);

    std::vector<std::string> userString(max_sentence_length);
    std::istringstream iss(s);

    for (int i=0; i<max_sentence_length; i++) {
        memset(wordsFromSentence[i],'\0', wordsize);
    }

    for (decltype(userString.size()) i=0; i<userString.size(); ++i) {
        // split words in sentence
        while (iss >> word) {

            if (word.back() == '.' || word.back() == '\'' || word.back() == ',' || word.back() == '!' || word.back() == '?' || word.back() == ':' || word.back() == ';' ) {
                word.pop_back();
            }

            std::cout << "(debug) word :: " << word << std::endl;
            nrOfWords++;
            // at the same time counting words in sentence
            // THIS WILL OMIT THE SPACE
                // NEEDS FIX
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
    // std::cout << "(debug) query_string = \"" << query_string << "\"" << std::endl;

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
    int rank;
    int count;
    int biggest=0;
    int inc=0;
    int b=0;
    int pos1, pos2;

    std::string x;
    std::string tp; // initially chosen returned query
    std::string query = s;
    std::string query2;
    std::string used_file = "ai/data/files/trivia_logic.txt";  // AI/DATA/FILES/TRIVIA_LOGIC.TXT
    std::string used_file_ar[64] = { "trivia_logic", "question_answers" };  // max. file name length    // AI/DATA/FILES/TRIVIA_LOGIC.TXT   // AI/DATA/FILES/QUESTION_ANSWERS.TXT

    std::ifstream filen;

    conversation.push_back(s);  // should work
    
    // debugging information
    // std::cout << "->>> pushed back ->>> " << s << std::endl;

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
        this->used = 2; // 1=trivia_logic; 2=questions_answers
    } else if (query.back() == '!') {   // open "trivia_logic"
        isExclamation = true;
        used_file = trivia_logic;
        query.pop_back();
        this->used = 1;
    } else if (query.back() == '.') {   // open "trivia_logic"
        isDot = true;
        used_file = trivia_logic;
        query.pop_back();
        this->used = 1;
    } else if (query.back() == ',') {   // open "trivia_logic"
        isComma = true;
        isFollowUp = true;
        used_file = trivia_logic;
        // follow_up check here
        query.pop_back();
        this->used = 1;
    } else if (query.back() == ';') {   // open "trivia_logic"
        isSemicolon = true;
        isFollowUp = true;
        used_file = trivia_logic;
        // follow up check here
        query.pop_back();
        this->used = 1;
    } else if (query.back() == ':') {   // open "trivia_logic"
        isColon = true;
        isFollowUp = true;
        used_file = trivia_logic;
        // follow up check here
        query.pop_back();
        this->used = 1;
    } else {
        this->used = 1;
    }

    filen.open(used_file);  // trivia_logic // questions_ansewers

    if (filen.is_open() == true) {  // trivia logic // questions_answers
        while (getline(filen,x)) {
            answers_processed += 1;

            // convert this logic first!!!!!!!!
                // rank score
                    // x = transponder queries  // query = user input query
            // debug

            // TRANSFORM TRANSPONDER QUERY
            std::cout << "(debug) : " << std::endl;
            pos1 = query.find_last_of(",");
            pos2 = query.find_last_of(";");
            std::cout << "\t" << pos2;
            std::cout << std::endl;
            query2 = query.substr(pos1+1, pos2-2);
            std::cout << "\t" << query2 << std::endl;
            std::cout << std::endl;

            rank = this->rank_score(query2, x);  // calculate score
            
            // debugging information
            // std::cout << std::endl << "(transponder query): " << x << std::endl;            
            // std::cout << "(rank): " << rank << std::endl;

            this->ints.push_back(rank);
            // process answers into NEW!! ARRAY!!!!!!!!

            // this part is redundant
            if (rank > 0) {
                if (rank > b) {
                    b=rank;
                    tp = x;
                }
            }
        }
        // rewind file
        filen.seekg(SEEK_SET);
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
        std::cout << "~:: (debug) -- normal query!" << std::endl;
    }

    std::cout << "~:: (debug) -- answers processed: " << answers_processed << std::endl;

    // return answer to Transponder::analytics(std::string)

    int noted=0;

    for (size_t i : this->ints) {
        inc++;
        if (i>biggest) { biggest = i; noted = inc; }
    }

    std::cout << std::endl;
    std::cout << "(debug)" << std::endl;
    std::cout << "noted : " << noted << std::endl;
    std::cout << "biggest : " << biggest << std::endl;
    std::cout << std::endl;

    // for (size_t i : ints) {
    //     if (i == biggest) {
    //     }
    // }
    std::cout << std::endl;
    std::cout << "labelled biggest faculty : " << biggest << std::endl;
    
    // if (noted > 0) {    // ANSWER THE QUERY WITH listConvos()
    // // <---> OVER HERE TRANSPONDER QUERIES <--->
    //     std::cout << std::endl << "[CONVOS] :" << std::endl;
    //     this->listConvos(0);    // also lists synonyms ;; and stores relations
    // }
    std::cout << std::endl;    

return x;
};

int Transponder::rank_score(std::string q, std::string a) { // parameters: q:query, a:answer
    int score = this->scored(q,a);
    // std::vector<std::string> result;
return score;
};

int Transponder::scored(std::string q, std::string tq) {
    // std::string x = tq;  // is the transponder queries from "trivia_logic" or "question_answer"
    std::string word;
    std::string wrd;
    std::string str;
    std::vector<size_t> vec;
    std::vector<std::string> words;
    std::vector<std::string> result;
    int score=0;

    // stringstream s_stream(a); //create string stream from the string
    // char delimeter = ' ';
    // size_t pos = 0;

    std::cout << std::endl;
    std::cout << "~:: scored() : " << std::endl;

    // this->scores.open(weights);

    if (this->scores.is_open() == true) {
        // std::cout << "\t~:: successfully opened: \"" << weights << "\"." << std::endl;
        std::istringstream iss(q);

        std::cout << std::endl;
        // std::cout << "~:: results :" << std::endl;
        while (iss >> wrd) {
            // iss >> wrd;
            words.push_back(wrd);   // contains the query from the transponder
            std::cout <<  "\t~:: pushing back ---> " << wrd << std::endl;
        }


        // DEBUG HERE


        for (const auto& s : words){
            while (this->scores >> word) {
                if (word.compare(s) == false) {
                    std::cout << "- found: " << word << std::endl;
                    score += 1;
                    sleep(1);
                }
            }
            scores.seekg(0,std::ios::beg);
        }

        std::cout << std::endl;
    } else {
        std::cout << "~:!:~ (error) -> file: \"" << weights << "\" is not available." << std::endl;
    }

    for (const auto &str : words) {
        std::cout << "\t- " << str; // prints the query words one by one
        std::cout << "\t~:: matching occurences." << std::endl;
        
        // conversation.push_back(str);  // should work
        // std::cout << "->>> pushed back ->>> " << str << std::endl;

        // Get the first occurrence
        std::cout << std::endl;
        size_t pos = tq.find(str);
        // Repeat till end is reached

        while( pos != std::string::npos) {
            // Add position to the vector
            vec.push_back(pos);
            // Get the next occurrence from the current position
            pos = q.find(tq, pos + tq.size());
        }
    }

    std::cout << std::endl << "incremental size function : " << vec.size() << std::endl;
    score = vec.size();
    vec.clear();

    // debugging output (1)
    std::cout << std::endl;
    std::cout << "[RESULT] : ";

    if (score > this->points) { // rate score
        // debugging output (2)
        std::cout << "~:: score(" << score << ") got rated." << std::endl;
        std::cout << tq << endl;
        this->points = score;
        this->result = tq;
    }

    words.clear();

return score;
};

    // if (vec.size() > 0) {   // let's have a conversation :)
    //     std::stringstream s_stream(a); //create string stream from the query string
    //     while(s_stream.good()) {
    //         std::string substr;
    //         std::getline(s_stream, substr, ','); //get first string delimited by comma
            
    //         substr = substr.substr(1, substr.size() - 2);   // erase the ' " ' in the front and back of the string
    //         // substr.erase(0,1);
    //         // substr.erase(substr.size() - 1);

    //         result.push_back(substr);
    //     }

    //     for(int i = 0; i<result.size(); i++) {    //print all splitted strings
    //         str = result.at(i);
    //         if (i == 2) {
    //             str.pop_back();
    //         }
    //         std::cout << std::endl << "RESULT: " << i << ") : " << str << std::endl;
    //     }

    //     // conversation.push_back(result.at(2));  // should work
    //     // std::cout << std::endl << "->>> pushed back ->>> " << result.at(2) << std::endl;
    // }

    // // Get the first occurrence
    // size_t pos = a.find(q);
    // // Repeat till end is reached
    // std::cout << std::endl << "\t~:: matching occurences." << std::endl;
    // while( pos != std::string::npos) {
    //     // Add position to the vector
    //     vec.push_back(pos);
    //     // Get the next occurrence from the current position
    //     pos=a.find(q, pos + q.size());
    // }
    

void Transponder::listConvos(size_t max_history_length) {  // list conversation, and also list synonyms
    // vars
    int iter=0;
    std::string q;
    std::string syno;
    std::string line;
    
    // vectors
    std::vector<std::string> results;
    std::vector<std::string> results2;

    // query user
    std::cout << std::endl;
    std::cout << "[CONVOS]" << std::endl;
    std::cout << std::endl;
    std::cout << "~:: listConvos() :" << std::endl;
    std::cout << std::endl;
    std::cout << "\t\% having convos?" << std::endl;
    std::cout << std::endl;

    int count=0;

    // list conversation    ;;  conversation is found in: vector<std::string> conversation
    for (auto &que : conversation) {
        iter++;
        // display transponder query and list synonyms
        std::cout << "\t:: " << que << std::endl;
        if (answers.size() < count) { std::cout << "\t:: " << answers.at(count++) << std::endl; }
        
        if (max_history_length != 0 && iter == max_history_length) {
            // maybe should also put flush device here ...
            break;  // break out of loop on max length for conversation history
        }
    }    
    
    if (backlog_answers.size() > 0) {
        for (auto &que : backlog_answers) {
            std::cout << std::endl;
            std::cout << "\t:>>>: " << que << std::endl;
        }
    }

    this->list_relations(); // list the relations
    // this->store_relations();    // then stores the relations through store_relations() function
    
    // End Of Transmission
    std::cout << std::endl;
    std::cout << "(EOT)" << std::endl;
};
    // append comma again to split correctly
//     for (auto que : conversation) {
//         std::stringstream s_stream(que); //create string stream from the string
    
//         // get synonyms from s_stream var
//         while(s_stream.good()) {
//             std::string substri;
//             std::getline(s_stream, substri, ' '); //get first string delimited by comma
//             results.push_back(substri);
            
//             // substr.pop_back();  // remove ' " ' char
//             // substri.pop_back();  // remove ' . ' char

//             while (substri.back() == '"' ||  substri.back() == '\'' || substri.back() == '.' || substri.back() == '?' || substri.back() == '!' || substri.back() == ',' || substri.back() == ';' || substri.back() == ':') {
//                     substri.pop_back();
//             }
            
//             std::cout << std::endl << "->>> pushing ->>> " << substri << std::endl;
//             sleep(1);   // DEBUG DEBUG!

//             // get the synonyms and pop the comma at the end and add a dot.
//             for (auto res : results) {
//                 std::string tmp = res;

//                 // syno = synonyms(substri);   // look up every que synonym
//                 while (tmp.back() == '"' || tmp.back() == '\'' || tmp.back() == '.' || tmp.back() == '?' || tmp.back() == '!' || tmp.back() == ',' || tmp.back() == ';' || tmp.back() == ':') {
//                     tmp.pop_back();
//                 }

//                 if (res.back() == ';') {
//                     res.pop_back();
//                 }

// //                std::cout << std::endl << "(debug) res : \"" << res << "\"" << std::endl;

//                 // syno = synonyms(tmp);   // look up every que synonym
//                 syno = synonyms(substri);   // look up every que synonym

//                 // DEBUGGING INFORMATION
//                 // std::cout << std::endl;
//                 // std::cout << "(debug) res: " << res << std::endl;
//                 // std::cout << "(debug) syno: " << syno << std::endl;
//                 // std::cout << "(debug) substri: " << substri << std::endl;
//                 // std::cout << std::endl;
                
//                 // syno.pop_back();    // remove comma to display correctly

//                 std::stringstream s_stream(syno); //create string stream from the string
        
//                 // get synonyms from s_stream var
//                 while(s_stream.good()) {
//                     std::string sub;

//                     // DEBUGGING INFORMATION
//                     // std::cout << std::endl << "SUB SUB SUB SUB::::::" << sub << std::endl;
//                     std::getline(s_stream, sub, ','); //get first string delimited by comma
//                     results2.push_back(sub);
//                 }

//                 // print categories of synonyms
//                 std::cout << "\t:: (synonyms) : " << syno << std::endl;
//             }
//         }
//     }

std::string Transponder::synonyms(std::string q) {    // q is term for looking up synonyms thereof
    int meta;    
    
    std::string term;
    std::string line;
    std::string word;
    std::string word1, word2, word3, word4, word5;
    vector<std::string> ourwords;

    bool match1=false;
    bool match2=false;
    bool match3=false;
    bool match4=false;
    bool match5=false;

    istringstream iss(q);

    std::cout << std::endl << "~:: --- synonyms() ---:" << std::endl;
    
    // process query first
    // while (iss >> word) {
    //     ourwords.push_back(word);
    //     meta = singleMeta(word);
    //     std::cout << std::endl << "~:: meta : " << meta << std::endl;
    // }

    for (size_t i=0; i<ourwords.size(); i++) {
        if (this->syno.is_open() == true) {
            while (getline(this->syno, line)) {
                // debugging output
                // std::cout << line << std::endl;
                std::istringstream iss (line);
                iss >> word1 >> std::skipws >> word2 >> std::skipws >> word3 >> std::skipws >> word4 >> std::skipws >> word5;
                            
                if (word1.length() != 0) {
                    word1[0] = tolower(word1[0]);
                    if (word1.compare(word) == false) {
                        // this->oursyns.push_back(word1);
                        std::cout << "success 1" << std::endl;
                        std::cout << std::endl << "word1 : " << word1 << " // q : " << q << std::endl;
                        match1=true;
                        break;
                    }
                }

                if (word2.length() != 0) {
                    word2[0] = tolower(word2[0]);
                    if (word2.compare(word) == false) {
                        // this->oursyns.push_back(word2);
                        std::cout << "success 2" << std::endl;
                        std::cout << std::endl << "word2 : " << word1 << " // q : " << q << std::endl;
                        match2=true;
                        break;
                    }
                }

                if (word3.length() != 0) {
                    word3[0] = tolower(word3[0]);
                    if (word3.compare(word) == false) {
                        // this->oursyns.push_back(word3);
                        std::cout << "success 3" << std::endl;
                        std::cout << std::endl << "word3 : " << word1 << " // q : " << q << std::endl;
                        match3=true;
                        break;
                    }
                }

                if (word4.length() != 0) {
                    word4[0] = tolower(word4[0]);
                    if (word4.compare(word) == false) {
                        // this->oursyns.push_back(word4);
                        std::cout << "success 4" << std::endl;
                        std::cout << std::endl << "word4 : " << word1 << " // q : " << q << std::endl;
                        match4=true;
                        break;
                    }
                }

                if (word5.length() != 0) {
                    word5[0] = tolower(word5[0]);
                    if (word5.compare(word) == false) {
                        this->oursyns.push_back(word5);
                        std::cout << "success 5" << std::endl;
                        std::cout << std::endl << "word5 : " << word1 << " // q : " << q << std::endl;
                        match5=true;
                        break;
                    }
                }
            }

            if (match1 || match2 || match3 || match4 || match5) {
                std::cout << "\t~:: match ::~" << std::endl;
                if (match1 == true) {
                    std::cout << "\t\tmatch -1-" << std::endl;
                }
                if (match2 == true) {
                    std::cout << "\t\tmatch -2-" << std::endl;
                }
                if (match3 == true) {
                    std::cout << "\t\tmatch -3-" << std::endl;
                }
                if (match4 == true) {
                    std::cout << "\t\tmatch -4-" << std::endl;
                }
                if (match5 == true) {
                    std::cout << "\t\tmatch -5-" << std::endl;
                }

                if (match1 || match2 || match3 || match4 || match5) {
                    std::cout << std::endl;
                    std::cout << "- pushing:" << std::endl;

                    if (word1.length() > 0) {
                        this->oursyns.push_back(word1);
                    }
                    if (word2.length() > 0) {
                        this->oursyns.push_back(word2);
                    }
                    if (word3.length() > 0) {
                        this->oursyns.push_back(word3);
                    }
                    if (word4.length() > 0) {
                        this->oursyns.push_back(word4);
                    }
                    if (word5.length() > 0) {
                        this->oursyns.push_back(word5);
                    }
                }

                // this->oursyns.push_back(word2);
                // this->oursyns.push_back(word3);
                // this->oursyns.push_back(word4);
                // this->oursyns.push_back(word5);

                // OUTPUT SYNONYMS
                std::cout << std::endl;
                for (size_t i=0; i<this->oursyns.size(); i++) {
                    this->oursyns.at(i).front() = tolower(this->oursyns.at(i).front()); // to lower
                    std::cout << "- synonym : " << this->oursyns.at(i) << std::endl;
                }
            }
                
                // DEBUGGING OUTPUT
                // for (size_t i=0; i < this->oursyns.size(); i++) {
                //     std::cout << " :: " << this->oursyns.at(i);
                // }

                // std::cout << std::endl;
        } else {
            std::cout << std::endl << "~:!:~ (error) - \"syno\" is not open." << std::endl;
        }
    }

    // measure synonyms
    if (this->oursyns.size() > 0) {
        if (this->oursyns.at(0).length() > 0) {
            term = this->oursyns.at(0);
            std::cout << std::endl;
            std::cout << "\t- assigned term : " << term << std::endl;
        }
    } else {
        term = "<none assigned>";
    }

return term;
};

void Transponder::export_backlog(int n=2) {

    ofstream out_queries;
    ofstream out_answers;

    std::cout << std::endl;
    std::cout << "export_backlog() : " << std::endl;

    switch (n) {
        case 0:
            std::cout << std::endl;
            std::cout << "\t~:: exporting backlog <queries> to: \"ai/log/backlog_queries.txt\"" << std::endl;
            std::cout << std::endl;

            out_queries.open(backlog_query);
            if (out_queries.is_open() == true) {
                for (size_t i=0; i<backlog_queries.size(); i++) {
                    out_queries << backlog_queries.at(i) << std::endl;
                }
                out_queries.close();
                std::cout << "\t~:: exported." << std::endl;
            }            
            break;

        case 1:
            std::cout << std::endl;
            std::cout << "\t~:: exporting backlog <answers> to: \"ai/log/backlog_answers.txt\"" << std::endl;
            std::cout << std::endl;

            out_answers.open(backlog_answer);
            
            if (out_answers.is_open() == true) {
                for (size_t i=0; i<backlog_answers.size(); i++) {
                    out_answers << backlog_answers.at(i) << std::endl;
                }
                out_answers.close();
                std::cout << "\t~:: exported." << std::endl;
            }
            break;

        case 2:
            std::cout << std::endl;
            std::cout << "\t~:: exporting backlogs - <backlog_queries> & <backlog_answers> to: \"ai/log/backlog_queries.txt\" && to \"ai/log/backlog_answers.txt\"" << std::endl;
            std::cout << std::endl;

            out_queries.open(backlog_query);
            if (out_queries.is_open() == true) {
                for (size_t i=0; i<backlog_queries.size(); i++) {
                    out_queries << backlog_queries.at(i) << std::endl;
                }
                out_queries.close();
                std::cout << "\t~:: exported <backlog_queries>." << std::endl;
            }
            
            out_answers.open(backlog_answer);
            if (out_answers.is_open() == true) {
                for (size_t i=0; i<backlog_answers.size(); i++) {
                    out_answers << backlog_answers.at(i) << std::endl;
                }
                out_answers.close();
                std::cout << "\t~:: exported <backlog_answers>." << std::endl;
            }
            break;

        default:
            std::cout << std::endl << "~:!:~ (error) - export_backlog() - unknown parameter given." << std::endl;
            break;
    };
    
    std::cout << std::endl;
    std::cout << "~:: done." << std::endl;
    std::cout << std::endl;
};

std::string Transponder::strip(std::string tq) {
	int pos, pos2;
	std::cout << std::endl << "~:: strip()" << std::endl;

	pos = tq.find_first_of("\"");
	pos2 = tq.find_first_of(",");

	std::string result = tq.substr(pos+1, pos2-2);

	// std::cout << "\tpos : " << pos << " pos2 : " << pos2 << std::endl;
	//std::cout << "\t(nr. of query) : " << result << std::endl;

return result;
};

void Transponder::list_relations() {    // lists the relations from this->relations <vector>
    std::string tmp = "relatives : ";

    if (this->relations.size() > 0) {
        std::cout << std::endl << "~:: list_relations() :" << std::endl;
        
        for (size_t i=0; i<this->relations.size(); i++) {
            // std::cout << "\"" << this->relations.at(i) << "\",";
            tmp.append("\"");
            tmp.append(this->relations.at(i));
            tmp.append("\",");
        }

        tmp.pop_back(); // remove the last comma
        tmp.append(".");    // add a dot
        
        // output
        std::cout << tmp << std::endl;
        std::cout << std::endl;
    }
    // this->store_relations(); // already stores relations in list_convos()
};

void Transponder::store_relations() {   // stores the relations from this->relations <vector>
    std::cout << "\t~:: store_relations()." << std::endl;

    if ((this->relations.size() > 0) && (this->relate.is_open() == false)) {
        std::cout << std::endl << "~:: storing relations ::~" << std::endl;
        std::cout << "\t~:: opening : \"" << relatives << "\"." << std::endl;
        this->relate.open(relatives, ios::app);
    }

    if (this->relate.is_open() == true) {
        std::cout << "\t\t+/+ relations :" << std::endl;
        std::cout << "\t\t";
        for (size_t i=0; i<this->relations.size(); i++) {
            this->relate << this->relations.at(i);
            this->relate << ((i<this->relations.size()-1) ? " " : ";") << std::endl;
            std::cout << ".";   // a dot for every relation
        }
        if (this->relate.is_open() == true) {
            std::cout << std::endl;
            std::cout << "~:: closing file." << std::endl;
            this->relate.close();
        }
    }
    std::cout << std::endl;
};

void Transponder::flush_relations() {
    this->relations.clear();
};

void Transponder::logQueries(int x) {    // log x number of queries + answers (n*2)
    bool io = false;
    ofstream file_io;

    file_io.open(logfile, std::ios::app);
    std::cout << "\t- logging queries." << std::endl;

    // BUILD IN support for several queries!
    if (x == 0) {
        if (this->capsize == true) {
            file_io << std::endl;
        }
        
        if (this->subject.length() > 0) {
            file_io << this->subject << std::endl;
        }

        if (this->result.length() > 0) {
            file_io << this->result << std::endl;
        }
        
        if (this->capsize == true) {
            file_io << std::endl;
        }

        std::cout << "\t-> stored related queries." << std::endl;
    }

    if (file_io.is_open() == true)  {
        file_io.close();
    }
};

void Transponder::cappedsize() {
    std::cout << std::endl;
    std::cout << "~:: toggle (b) capsize." << std::endl;
    this->capsize=true;
    std::cout << "\t~:: done." << std::endl;
    std::cout << std::endl;
};
    // // variables
    // int nr_of_synonyms; // the number of actual synonyms for term
    // // bools
    // bool hitCorrectChar=false, hitTerm=false;
    // // strings
    // std::string line;   // line from synonyms file
    // std::string one, two, three, four, five;  // number of possible synonyms for the 1st term (one should equal q)
    // std::string term, nop="0";
    // std::string str1;
    // std::string str2;
    // std::string str3;
    
    // // vectors
    // std::vector<std::string> result;

    // // file streams
    // // std::ifstream syno;
    // // syno.open(synonym);

    // if (this->syno.is_open() == true) {
    //     std::cout << std::endl << "~:: iterating synonyms for: \"" << q << "\"" << std::endl;
        
    //     while (getline(this->syno, line)) {
    //         str1 = line;
    //         str2 = q;

    //         //str1.append("\t");

    //         // DEBUGGING OUTPUT
    //         std::cout << "(debug) str1 :" << std::endl;
    //         std::cout << str1 << std::endl;
    //         std::cout << std::endl;

    //         std::string syn;
    //         //std::cout << "(debug) str1 : " << str1 << std::endl;

    //         std::stringstream s_stream(str1); //create string stream from the string
            
    //         while(s_stream.good()) {
    //             std::string substr;
    //             std::getline(s_stream, substr, '\t'); //get first string delimited by comma
    //             result.push_back(substr);
    //         }
            
    //         for(int i = 0; i<result.size(); i++) {    //print all splitted strings
    //             // DEBUGGING INFORMATION
    //             //std::cout << result.at(i) << std::endl;
                
    //             str3 = result.at(i);
    //             // str3[0] = tolower(str3[0]);
                
    //             // transform char to lower case
    //             str2[0] = tolower(str2[0]); // q
    //             str3[0] = tolower(str3[0]); // result.at(i)
    //             line[0] = tolower(line[0]); // line from syno=synonyms (.txt)

    //             // // DEBUGGING OUTPUT
    //             // std::cout << "(debug) str3 :" << std::endl;
    //             // std::cout << str3 << std::endl;
    //             // std::cout << std::endl;

    //             if (str2.compare(str3) == 0) {
    //                 std::cout << std::endl << "HiT!" << std::endl;
    //                 hitTerm = true;

    //                 std::cout << std::endl;
    //                 std::cout << "2: " << str2 << std::endl;
    //                 std::cout << "3: " << str3 << std::endl;
    //             }

    //                 // DEBUGGING INFORMATION
    //                 // if (hitTerm == true) {
    //                 //     std::cout << std::endl;
    //                 //     std::cout << "\thit term in db : ";
    //                 //     std::cout << std::endl;
    //                 //     std::cout << "\t" << str1 << std::endl << str2 << std::endl << str3 << std::endl;
    //                 //     sleep(2);
    //                 //     break;
    //                 // }
                
    //             if (hitTerm == true) {
    //                     break;
    //             }
    //         }
            
    //         if (hitTerm == true) {  // break out of 2nd loop if hit correct term in syno
    //             break;
    //         }

    //         // break even
    //         if (hitCorrectChar == true && (line.front() != q.front())) {
    //             hitCorrectChar = false;
    //             // if (this->syno.is_open() == true) {
    //             //     this->syno.close();
    //             // }
    //             break;
    //         }
    //     }

    //     // combine synonyms into one string for return statement
    //     if (hitTerm == true) {
    //         term = str1;
    //         hitTerm = false;
    //     } else {
    //         term = nop;
    //         hitTerm=false;
    //     }
    // } else {
    //     std::cout << std::endl << "~:!:~ (error) synonyms is still closed." << std::endl;
    // }

    // // if (this->syno.is_open() == true) {
    // //     this->syno.close();
    // // }

    // std::cout << std::endl << "(debug) term : \"" << term << "\"." << std::endl;

/*  // DEBUGGING INFORMATION IN THIS COMMENT
 *      // clutters display
 *  std::cout << std::endl << "- rank_score(q,a) :" << std::endl;
 *  std::cout << "Q : " << q << std::endl;
 *  std::cout << "A : " << a << std::endl;
 */
    // split words in query
    // compare occurences in q -&- a
    // add score and return it
    // then compare score inside
    // if (a.length() >= 1) {
    //     std::cout << a.find_first_of("\"1\",");
    // }



// NNNNNNNEEEEEED TO FIX THIS
    // if (q.length() >= 1 && a.find(q)) {
    //     std::cout << std::endl << "ANSWER : " << a << std::endl;
    //     std::cout << std::endl;
    // }



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

