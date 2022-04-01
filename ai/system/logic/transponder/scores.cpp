#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unistd.h>

// #include <iterator>
// #include <algorithm>

std::string weights = "ai/lib/queries/weights";

int scores(std::string s) {
    std::ifstream scores;
    std::string x = s;
    std::string word;
    std::string wrd;

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
                if (word.compare(s) == true) {
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

    return score;
};
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