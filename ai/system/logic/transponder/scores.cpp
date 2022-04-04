#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <algorithm>

#include "synonyms.h"

// #include <iterator>
// #include <algorithm>

std::string weights = "ai/lib/queries/weights";

std::vector<std::string> conversation;

int vec_rec;

int scores(std::string a, std::string q) {
    std::ifstream scores;
    std::string x = q;
    std::string word;
    std::string wrd;
    std::string str;
    std::vector<size_t> vec;
    std::vector<std::string> result;

    // stringstream s_stream(a); //create string stream from the string

    int score=0;

    // char delimeter = ' ';
    std::vector<std::string> words;
    // size_t pos = 0;

    std::cout << std::endl;
    std::cout << "~:: scores() - calculating scores:" << std::endl;

    scores.open(weights);

    if (scores.is_open() == true) {
        std::cout << "\t~:: successfully opened: \"" << weights << "\"." << std::endl;

        std::istringstream iss(x);

        std::cout << std::endl;
        std::cout << "~:: results :" << std::endl;

        while (iss >> wrd) {
            // iss >> wrd;
            words.push_back(wrd);
        }

        for (const auto& s : words){
            while (scores >> word) {
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

    if (scores.is_open() == true) {
        scores.close();
        std::cout << "\t~:: closed \"" << weights << "\"." << std::endl;
    }

    for (const auto &str : words) {
        std::cout << "\t- " << str << std::endl;
    }

    // Get the first occurrence
    size_t pos = a.find(q);
    // Repeat till end is reached
    while( pos != std::string::npos) {
        // Add position to the vector
        vec.push_back(pos);
        // Get the next occurrence from the current position
        pos=a.find(q, pos + q.size());
    }
    
    std::cout << std::endl << "incremental size function : " << vec.size() << std::endl;
    score = vec.size();

    if (vec.size() > 0) {   // let's have a conversation :)
        // BUSY IN THIS FUNCTION
        std::stringstream s_stream(a); //create string stream from the string
        
        while(s_stream.good()) {
            std::string substr;
            std::getline(s_stream, substr, ','); //get first string delimited by comma
            
            substr = substr.substr(1, substr.size() - 2);   // erase the ' " ' in the front and back of the string
            // substr.erase(0,1);
            // substr.erase(substr.size() - 1);

            result.push_back(substr);
        }

        for(int i = 0; i<result.size(); i++) {    //print all splitted strings
            str = result.at(i);
            if (i == 2) {
                str.pop_back();
            }
            std::cout << std::endl << "RESULT: " << i << ") : " << str << std::endl;
        }

        conversation.push_back(result.at(2));  // should work
        std::cout << std::endl << "->>> pushed back ->>> " << result.at(2) << std::endl;
    }

    // vec_rec =

return score;
};

void listConvo(size_t max_history_length) {  // list conversation, and also list synonyms
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
    std::cout << "~:: listConvo() :" << std::endl;
    std::cout << std::endl;
    std::cout << "\t\% having convos?" << std::endl;
    std::cout << std::endl;

    // conversation is found in: vector<std::string> conversation
    for (auto que : conversation) {
        iter++;
        // display transponder query and list synonyms
        std::cout << ":: " << que << std::endl;

        if (max_history_length != 0 && iter == max_history_length) {
            // maybe should also put flush device here ...
            break;  // break out of loop on max length for conversation history
        }
    }

    // append comma again to split correctly
    for (auto que : conversation) {
        std::stringstream s_stream(que); //create string stream from the string
    
        // get synonyms from s_stream var
        while(s_stream.good()) {
            std::string substri;
            std::getline(s_stream, substri, ' '); //get first string delimited by comma
            results.push_back(substri);
            
            // substr.pop_back();  // remove ' " ' char
            // substri.pop_back();  // remove ' . ' char

            while (substri.back() == '"' ||  substri.back() == '\'' || substri.back() == '.' || substri.back() == '?' || substri.back() == '!' || substri.back() == ',' || substri.back() == ';' || substri.back() == ':') {
                    substri.pop_back();
            }
            
            std::cout << std::endl << "->>> pushing ->>> " << substri << std::endl;

            // get the synonyms and pop the comma at the end and add a dot.
            for (auto res : results) {
                std::string tmp = res;

                // syno = synonyms(substri);   // look up every que synonym
                while (tmp.back() == '"' || tmp.back() == '\'' || tmp.back() == '.' || tmp.back() == '?' || tmp.back() == '!' || tmp.back() == ',' || tmp.back() == ';' || tmp.back() == ':') {
                    tmp.pop_back();
                }

                syno = synonyms(tmp);   // look up every que synonym

                // DEBUGGING INFORMATION
                // std::cout << std::endl;
                // std::cout << "(debug) res: " << res << std::endl;
                // std::cout << "(debug) syno: " << syno << std::endl;
                // std::cout << "(debug) substri: " << substri << std::endl;
                // std::cout << std::endl;
                
                // syno.pop_back();    // remove comma to display correctly

                std::stringstream s_stream(syno); //create string stream from the string
        
                // get synonyms from s_stream var
                while(s_stream.good()) {
                    std::string sub;

                    // DEBUGGING INFORMATION
                    // std::cout << std::endl << "SUB SUB SUB SUB::::::" << sub << std::endl;
                    std::getline(s_stream, sub, ','); //get first string delimited by comma
                    results2.push_back(sub);
                }

                // print categories of synonyms
                std::cout << "\t:: (synonyms) : " << syno << std::endl;
            }
        }
    }

    // End Of Transmission
    std::cout << "(EOT)" << std::endl;
    std::cout << std::endl;
}

            // loop vector : "results2"
                // for(int i = 0; i<results2.size(); i++) {    //print all splitted strings
                //     std::cout << "\t* " << results2.at(i) << std::endl;
                // }

    
            // if (words.at(i).compare(word) == false) {
            //     std::cout << "-- HIT!!! --> " << wrd << " " << words.at(i) << std::endl;
            // }
        
            // while (scores >> word) {
            //     if (wrd != "\n" && wrd != "") {
            //         std::cout << std::endl << "wrd: " << wrd << std::endl;
            //         // rewind for next iteration
            //         // std::cout << "substr: " << wrd << std::endl;

            //         // search through scores/weights
            //         // while (std::getline(scores, word)) {
            //         std::cout << std::endl << "WORD: " << word << std::endl;
            
            //         if (word.find( wrd ) != word.end()) {
            //             std::cout << "\t--> (HIT)" << std::endl;
                            
            //             // increase score
            //             score += 1;
            //             // break;
            //         }
            //         std::cout << std::endl;
            //     }
            // }   
        // }

        // while ((pos = x.find(delimeter)) != std::string::npos) {
        //     words.push_back(x.substr(0, pos));
        //     x.erase(0, pos + delimeter.length());
        // }

        // std::stringstream sstream(x);
        // while (std::getline(sstream, word, delimeter)) {
        //     word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        //     words.push_back(word);
        // }

        // std::istringstream iss(x);
        // std::copy(std::istream_iterator<std::string>(iss),
        // std::istream_iterator<std::string>(),
        // std::ostream_iterator<std::string>(std::cout, "\n"));


// eof