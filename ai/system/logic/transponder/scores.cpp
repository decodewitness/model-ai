#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <algorithm>


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
    std::vector<size_t> vec;
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
        conversation.push_back(a);  // works in conjunction with "vector<int> record" // PROBABLY NOT YET !!!
        std::cout << std::endl << "pushed back <<< " << a << std::endl;
    }

    // vec_rec =

return score;
};

void listConvo() {
    std::cout << std::endl;
    std::cout << "having convo?" << std::endl;
    std::cout << std::endl;

    for (auto que : conversation) {
        std::cout << ":: " << que << std::endl;
    }
}
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