#include <iostream>
#include <string.h>
#include <fstream>

// the limit of the size of the dictionaries    // if you change this you must rebuild all the tables.
const int max_sentence_length=256;  // max. length of sentence in words.
const int alimit=20000;              // limit for array elements and iterations in the loop.
const int wordsize=20;              // max. word size.

// counters
int counter=0;  // used to count total number of words processed.
int occurences=0;   // used to count the occurences of words being in the dictionary.

// question + answer + word
std::string aquestion;
std::string answer;
std::string ourword;

// dictionaries
int word2int[alimit];            // contains the int value of every word in the dictionary.
int dict2int[alimit];            // contains the int values of the keys in the dictionary.
char our_dict[alimit][wordsize]; // contains our words.
int dict[alimit];                // contains the ordered values of all the words from the dictionary and forms this new dictionary.

// contains the int values for the occurences of every word.
int int_occurrence[alimit];

// char dictionaries
char wordsFromSentence[max_sentence_length][wordsize];  // contains the words from the sentence // should contain the words from the question.

// questions and answers
int questions2int[alimit];   // contains the integer values of the questions list (of training data).
int answers2int[alimit];    // contains the integer representation of the answers to the analyzed questions.

// these still need values
std::string adictionary; // contains the location of the dictionary file with the processed (and congruent) data.
std::string awords;      // contains the location of the dictionary with all the words and their definitions.
std::string adata;       // contains the location of the dictionary with all the learned responses.
std::string process_data="20k.txt";   // contains the data to be indexed by these functions (list of most common words).

// start of sentence, end of sentence, end of transmission control characters.
int SOS=':',
    EOS=';',
    EOT='.';

// file pointers
std::ifstream dict_in;

// learns all positions of the words in the dictionary and generates key/index values in dict2int.
void prepare_ints(int l) {

    std::cout << std::endl << "~:: preparing ints." << std::endl << std::endl;

    int key=0;
    int counter=0;
    std::string oneword;

    dict_in.open(process_data);

    if (dict_in.is_open() == true) {
        std::cout << "\t:: succesfully opened dictionary: " << process_data << "." << std::endl;
    } else {
        std::cout << "\t~:: failed to open dictionary: " << process_data << "." << std::endl;
        
        // DEBUG OPTION !!! DEBUG OPTION !!! DEBUG OPTION
        system("pwd");
        exit(1);
    }

    // prepare word2int containing 1 ... "alimit" (numbers)
    std::cout << "\t~:: preparing word2int." << std::endl;

    for (int i=0; i<l; i++) {
        word2int[i] = i;
    }
    
    std::cout << "\t~:: filled array with numbers." << std::endl;

    // prepare "our_dict" containing all the words in the dictionary
    while (key < l) {
        dict_in >> oneword;
        
        std::cout << key << ") " << oneword << std::endl; 
        //word2int[key] = counter++;
        
        strncpy(our_dict[key], oneword.c_str(), wordsize);
        
        counter++;
        key++;
    };

    std::cout << "\t ~:: filled dictionary with words." << std::endl;
    std::cout << "\t~:: (" << counter << ") number of words processed." << std::endl;

    // calculate occurences for the words in the question "wordsFromSentence"
    std::cout << "\t~:: calculate occurences from word in sentence." << std::endl;

    for (int i=0; i<max_sentence_length; i++) {
        for (int j=0; j<l; j++) {
            if (strcmp(wordsFromSentence[i], our_dict[j]) != true) {
                int_occurrence[j] += 1;
                occurences += 1;
            }
        }            
    }

    std::cout << "~::(debug) :: (" << occurences << ") occurences found." << std::endl;

    // DEBUG :: list all occurences
    std::cout << "\t~::(debug) enumerating digest:" << std::endl;
    
    for (int i=0; i<l; i++) {
        std::cout << "(" << our_dict[i] << " : #" << int_occurrence[i] << ") ";
    }

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