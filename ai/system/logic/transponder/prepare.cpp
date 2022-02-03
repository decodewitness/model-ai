// "/AI/LOGIC/TRANSPONDER/PREPARE.CPP" - USED BY "/AI/LOGIC/TRANSPONDER/TRANSPONDER.CPP" // USED FOR LANGUAGE INTERPRETATION.

#include <iostream>
#include <string.h>
#include <fstream>
#include <unistd.h>

// the limit of the size of the dictionaries    // if you change this you must rebuild all the tables.
const int max_sentence_length=256;  // max. length of sentence in words.
const int alimit=20000;              // limit for array elements and iterations in the loop.
const int wordsize=20;              // max. word size.

// counters
int counter=0;  // used to count total number of words processed.
int occurences=0;   // used to count the occurences of words being in the dictionary.
int nrOfWordsInSentence;    // tracks the amount of words in the sentence being queried.
int loopvar;    // also tracks number of words in sentence [int_occurences](int)

// question + answer + word
std::string aquestion;
std::string answer;
std::string ourword;

// dictionaries
// char our_dict[alimit][wordsize]; // contains our words.

std::string our_dict[alimit];    // contains our words.

int dict[alimit];   // contains the ordered values of all the words from the dictionary and forms this new dictionary.
// lists for integer values of keys and words
int ints[alimit];       // integers.
int word2ints[alimit];  // int values for the words 
int dict2int[alimit];   // contains the int values of the keys in the dictionary.

// contains the int values for the occurences of every word.
int int_occurrences[alimit];

int track_occurence;
bool numbersToInt[alimit];
int ints2pos[alimit];
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

void prepare_ints(int l, int arraySize) {  // "l" = "alimit"

    int key=0;
    int counter=0;
    
    std::string word;

    dict_in.open(process_data);

    if (dict_in.is_open() == true) {
        std::cout << "\t~:: succesfully opened dictionary: " << process_data << "." << std::endl;
    } else {
        std::cout << "\t~:: failed to open dictionary: " << process_data << "." << std::endl;
            
        // DEBUG OPTION !!! DEBUG OPTION !!! DEBUG OPTION
        //system("pwd");
        exit(1);
    }

    // prepare "our_dict" containing all the words in the dictionary
    while (key < l) {
        dict_in >> word;
        
        // debugging output
        //std::cout << key << ") " << word << std::endl; 
        
        //ints[key] = counter++;
        our_dict[key] = word;
        
        counter++;
        key++;
    };

    dict_in.close();

    // check positions in words2ints[] for number of occurence of the words in the sentence 'wordsFromSentence[]'
    for (int i=0; i<arraySize; i++) { // loops over the words in the sentence
        for (int j=0; j<l; j++) {   // loops over dictionary
            if (strcmp(wordsFromSentence[i], our_dict[j].c_str()) == 0) {
                // here one word matches
                word2ints[j] += 1;
                occurences++;
                // ints2pos[];

                //std::cout << "(debug) - words2ints[" << j << "]" << std::endl;
            }
        }
    }

    //  // for iterating through the dictionary
    // for (int i=0; i<l; i++) {
    //     std::cout << i << ") " << our_dict[i] << std::endl; 
    // }

    std::cout << std::endl << "~:: (debug) number of matching occurences: (" << occurences << ")." << std::endl;
    
    // debugging option
    sleep(1);
};

void prepare_occurrences(int al, int cnt) {
    int limit=al;   // limit dictionary
    int counter=cnt+1;    // limit wordsInSentence
    int int_word_occurrence[al];    // list of place of occurence
    
    loopvar=0;
    track_occurence=0;  // set number of occurences to 0
    bool match_found = false;
    int minusadded = 0; // tracks how many words are not in the dictionary and also used to assign a negative value to those words

    std::cout << std::endl << "~:: intvars int_occurences[] ::~" << std::endl;
    
    for (int i=0; i<cnt; i++) { // loops over the words in the sentence
        
        match_found=false;
        
        for (int j=0; j<al; j++) {   // loops over dictionary
            if (strcmp(wordsFromSentence[i], our_dict[j].c_str()) == 0) {
                // here one word matches
                match_found = true;
                
                // std::cout << "(debug) loopvar=" << loopvar << " j=" << j << std::endl;
                // std::cout << "\t(debug) " << wordsFromSentence[i] << " :: " << our_dict[j] << std::endl;
                
                // if (match_found == false && j == 19999) { std::cout << "(debug) " << "wordsFromSentence[j]: " << wordsFromSentence[j] << std::endl; }

                // if (j == 5) {
                //     std::cout << std::endl << "(debug) loopvar: " << loopvar << std::endl;
                //     std::cout << "i=" << i << "; int_occurrences[" << loopvar << "]: " << int_occurrences[loopvar] << std::endl;
                // }
                
                int_occurrences[loopvar++] = j;

                // j=0;
                // break;
            }
        }
        if (match_found == false) { int_occurrences[loopvar++] = --minusadded; }
        // std::cout << wordsFromSentence[i] << " :: #" << int_occurrences[i] << std::endl;
    }

    for (int i=0; i<loopvar; i++) {
        std::cout << "(debug) " << i << ") " << wordsFromSentence[i] << " :: #" << int_occurrences[i] << std::endl;
    }
};

void dictionaries(int al, int cnt) {    // PREPARES BOTH DICTIONARIES
    prepare_ints(al, cnt);
    prepare_occurrences(al, cnt);
};

// OLD CODE

// void prepare_ints(int l) {
//     std::cout << std::endl << "~:: preparing ints." << std::endl << std::endl;
//     int key=0;
//     int counter=0;
//     // the sentence gets processed one word at a time
//     std::string oneword;
//     dict_in.open(process_data);
//     if (dict_in.is_open() == true) {
//         std::cout << "\t~:: succesfully opened dictionary: " << process_data << "." << std::endl;
//     } else {
//         std::cout << "\t~:: failed to open dictionary: " << process_data << "." << std::endl;
//         // DEBUG OPTION !!! DEBUG OPTION !!! DEBUG OPTION
//         //system("pwd");
//         exit(1);
//     }
//     // prepare ints containing 1 ... "alimit" (numbers)
//     std::cout << "\t~:: preparing: \"ints\"." << std::endl;
//     for (int i=0; i<l; i++) {
//         ints[i] = i;
//     }
//     std::cout << std::endl << "\t~:: filled array \"ints\" up with numbers." << std::endl;
//     std::cout << std::endl << "\t~:: listing \"[key]) [value]\" pairs:" << std::endl;
//     std::cout << std::endl;
//     // prepare "our_dict" containing all the words in the dictionary
//     while (key < l) {
//         dict_in >> oneword;
//         std::cout << key << ") " << oneword << std::endl; 
//         //ints[key] = counter++;
//         our_dict[key] = oneword;
//         counter++;
//         key++;
//     };
//     std::cout << std::endl << "\t~:: filled dictionary with words." << std::endl;
//     std::cout << "\t~:: (" << counter << ") <- words processed." << std::endl;
//     // calculate occurences for the words in the question "wordsFromSentence"
//     std::cout << "\t~:: calculate occurences from word in sentence." << std::endl;
//     for (int i=0; i<max_sentence_length; i++) {
//         for (int j=0; j<l; j++) {
//             if (i < nrOfWordsInSentence && our_dict[j].compare(wordsFromSentence[i]) == false) {
//                 std::cout << "(debug) int_occurences[" << j << "] + 1" << std::endl;
//                 int_occurrences[j] += 1;
//                 occurences += 1;
//             }
//         }            
//     }
//     // DEBUG :: list all occurences
//     std::cout << std::endl;
//     std::cout << std::endl;
//     std::cout << "~::(debug) enumerating digest:" << std::endl;
//     std::cout << std::endl;
//     for (int i=0; i<l; i++) {
//         char bword[64];
//         // our_dict[i];
//         strncpy(bword, our_dict[i].c_str(), 64);
//         // std::cout << "(\"" << our_dict[i] << "\":#" << *(int_occurrences+i) << ") ";
//         std::cout << "(\"" << chomp(bword) << "\":#" << *(int_occurrences+i) << ") ";
//         // print endline after every 4 occurences
//         if (i%5 < 1) {
//             std::cout << std::endl;
//         }
//     }
//     std::cout << std::endl;
//     std::cout << std::endl << "~:: number of occurences: (" << occurences << ")." << std::endl << std::endl;
//     // for (int key=0; key<l; key++) {
//     //     dict2int[key] += 1;
//     // }
// // compare digest to training set here (NEEDS FIXING/ADDING !!!)
//     dict_in.close();
// };
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