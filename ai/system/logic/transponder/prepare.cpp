// "/AI/LOGIC/TRANSPONDER/PREPARE.CPP" - USED BY "/AI/LOGIC/TRANSPONDER/TRANSPONDER.CPP" // USED FOR LANGUAGE INTERPRETATION.

#include <iostream>
#include <string.h>
#include <fstream>

// include chomp as function
#include "chomp.cpp"

// the limit of the size of the dictionaries    // if you change this you must rebuild all the tables.
const int max_sentence_length=256;  // max. length of sentence in words.
const int alimit=20000;              // limit for array elements and iterations in the loop.
const int wordsize=20;              // max. word size.

// counters
int counter=0;  // used to count total number of words processed.
int occurences=0;   // used to count the occurences of words being in the dictionary.
int wordsInSentence;    // tracks the amount of words in the sentence being queried.

// question + answer + word
std::string aquestion;
std::string answer;
std::string ourword;

// dictionaries
// char our_dict[alimit][wordsize]; // contains our words.
std::string our_dict[alimit];    // contains our words.
int dict[alimit];                // contains the ordered values of all the words from the dictionary and forms this new dictionary.

// lists for integer values of keys and words
int word2int[alimit];            // contains the int value of every word in the dictionary.
int dict2int[alimit];            // contains the int values of the keys in the dictionary.

// contains the int values for the occurences of every word.
int int_occurrences[alimit];

// char dictionaries
char wordsFromSentence[max_sentence_length][wordsize];  // contains the words from the sentence // should contain the words from the question.

// questions and answers
int questions2int[alimit];   // contains the integer values of the questions list (of training data).
int answers2int[alimit];    // contains the integer representation of the answers to the analyzed questions.

// wordlists
std::string process_data="ai/data/files/20k.txt";   // contains the data to be indexed by these functions (list of most common words).

// these still need values
std::string adictionary; // contains the location of the dictionary file with the processed (and congruent) data.
std::string awords;      // contains the location of the dictionary with all the words and their definitions.
std::string adata;       // contains the location of the dictionary with all the learned responses.

// start of sentence, end of sentence, end of transmission control characters.
std::string SOS="<SOS>", EOS="<EOS>", EOT="<EOT>";

// file pointers
std::ifstream dict_in;

// learns all positions of the words in the dictionary and generates key/index values in dict2int.
void prepare_ints(int l) {

    std::cout << std::endl << "~:: preparing ints." << std::endl << std::endl;

    int key=0;
    int counter=0;

    // the sentence gets processed one word at a time
    std::string oneword;

    dict_in.open(process_data);

    if (dict_in.is_open() == true) {
        std::cout << "\t~:: succesfully opened dictionary: " << process_data << "." << std::endl;
    } else {
        std::cout << "\t~:: failed to open dictionary: " << process_data << "." << std::endl;
        
        // DEBUG OPTION !!! DEBUG OPTION !!! DEBUG OPTION
        system("pwd");
        exit(1);
    }

    // prepare word2int containing 1 ... "alimit" (numbers)
    std::cout << "\t~:: preparing: \"word2int\"." << std::endl;

    for (int i=0; i<l; i++) {
        word2int[i] = i;
    }
    
    std::cout << std::endl << "\t~:: filled array \"word2int\" up with numbers." << std::endl;
    
    std::cout << std::endl << "\t~:: listing \"[key]) [value]\" pairs:" << std::endl;
    std::cout << std::endl;
    
    // prepare "our_dict" containing all the words in the dictionary
    while (key < l) {
        dict_in >> oneword;
        
        std::cout << key << ") " << oneword << std::endl; 
        //word2int[key] = counter++;
        
        our_dict[key] = oneword;
        
        counter++;
        key++;
    };

    std::cout << std::endl << "\t~:: filled dictionary with words." << std::endl;
    std::cout << "\t~:: (" << counter << ") <- words processed." << std::endl;

    // calculate occurences for the words in the question "wordsFromSentence"
    std::cout << "\t~:: calculate occurences from word in sentence." << std::endl;

    for (int i=0; i<max_sentence_length; i++) {
        for (int j=0; j<l; j++) {
            if (i < wordsInSentence && our_dict[j].compare(wordsFromSentence[i]) == false) {
                int_occurrences[j] += 1;
                occurences += 1;
            }
        }            
    }

    // DEBUG :: list all occurences
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "~::(debug) enumerating digest:" << std::endl;
    std::cout << std::endl;
    
    for (int i=0; i<l; i++) {
        char bword[64];
        // our_dict[i];
        strncpy(bword, our_dict[i].c_str(), 64);

        // std::cout << "(\"" << our_dict[i] << "\":#" << *(int_occurrences+i) << ") ";
        std::cout << "(\"" << chomp(bword) << "\":#" << *(int_occurrences+i) << ") ";

        // print endline after every 4 occurences
        if (i%5 < 1) {
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << std::endl << "~:: number of occurences: (" << occurences << ")." << std::endl << std::endl;

    // for (int key=0; key<l; key++) {
    //     dict2int[key] += 1;
    // }
    
// compare digest to training set here (NEEDS FIXING/ADDING !!!)

    dict_in.close();
};

// UNCOMMENT LATER !!!

// // prepares dictionary
// void prepare_dictionary(int l) {
//     for (int i=0;i<l;i++) {

//     }
// };

// // prepares wordsFromSentence
// void prepare_words(int l) {
    
//     // prepare sentence
//     for (int i=0; i<max_sentence_length; i++, counter++) {
//         strncpy(wordsFromSentence[i], ourword.c_str(), wordsize);
//     }

//     std::cout << "\t~:: (" << counter << ") words processed." << std::endl;
// };

// eof