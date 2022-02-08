// AI/SYSTEM/LOGIC/TRANSPONDER/STORE_META_QUERIES.CPP -- USED BY "AI/SYSTEM/LOGIC/TRANSPONDER/PREPARE.CPP"

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <unistd.h>

std::string reverse_path_handle = "ai/data/files/20k.txt";
std::string meta_query_path = "ai/lib/queries/meta_queries";

const int dict_size = 20000;    // size of dictionary in "AI/DATA/FILES/20K.TXT"

// meta limits
const int meta_queries = 256;
const int meta_query_length = meta_queries;

// metas numbers queries
int meta_nr[meta_queries];

// meta queries (primary)
std::string meta_query; // meta_query is not used yet
std::string meta_sequence; // meta_sequence is used to store the "meta sequence" :: intvars int_occurences[]    // prepare.cpp

// meta queries (fast)
std::string meta_1; // meta_1 is not used yet
std::string meta_2; // meta_2 is not used yet
std::string meta_3; // meta_3 is not used yet
std::string meta_4; // meta_4 is not used yet
std::string meta_5; // meta_5 is not used yet

// meta queries (triviary)
char meta[meta_queries][meta_query_length];    // [128] meta queries in char format of length [256]

void store_meta_queries(int a[], int size) {

    std::ofstream met;

    met.open(meta_query_path);

    std::cout << std::endl;

    if (met.is_open() == true) {
        std::cout << "~:: meta queries ~:: storing meta query sequence ~:::: ::::~" << std::endl;
        std::cout <<"\t- path: \"" << meta_query_path << "\"." << std::endl;
        std::cout <<"\t\t- meta sequences:" << std::endl;
        
        for (int i=0; i<size; i++) {
            std::cout << "\t- " << a[i];
        }

        met << std::endl;

        met.close();
    }

    sleep(2);
    std::cout << std::endl;
};

void reverse_meta_query_lookup(int a[], int size) { // looks up the words for the numbers of the meta queries

    //std::ifstream met;
    //std::string new_meta;
    //std::string word;
    //bool fileWasClosed = false;
    std::fstream dict_in;
    dict_in.open(reverse_path_handle);
    char our_dict[20000][256];
    int counts=0;
    int keyd=0;
    std::string ourword;
    //int counter=0, actualnumber=1, limit = 20000;  // size of dictionary

    std::cout << std::endl;
    std::cout << "~:: meta queries ~:: reverse_meta_query_lookup(\"";
    
    for (int i=0; i<size; i++) {
        std::cout << *(a+i) << ",";
    }

    // std::cout << "\b" << (32) << "\b";
    std::cout << "\") ~:::~" << std::endl;
    std::cout << std::endl;

    //std::cout << "- (debug) *(a+i) " << std::endl;

    // std::string word;

    while (keyd < 20000) {
        dict_in >> ourword;
                
        // debugging output
        //std::cout << key << ") " << word << std::endl; 
        
        strncpy(our_dict[counts], ourword.c_str(), 255);

        //ints[key] = counter++;
        //std::cout << "(debug) word = \"" << word << "\" - key: (" << key << ")." << std::endl;
        
        counts++;
        keyd++;
    }
    
    std::cout << "~:: reverse meta query lookup: " << std::endl;

    for (int i=0; i<size; i++) {
        if (*(a+i) > 0) {
            std::cout << "\t- " << our_dict[(*(a+i) - 1)] << "\t\t --> *(a+i) = "  << *(a+i) << " - *(a+i) - 1 = " << (*(a+i) - 1) << std::endl;
        } else {
            std::cout << "(skipped unregistered entry)" << std::endl;
        }
    }

    sleep(3);
};
    //met.open(reverse_path_handle);

    // loop variables along with dict_size and size -> size = size of loopvar of array
    // int i=0, counter=0, iter=-1;

    // std::cout << std::endl;
    // look up meta query string here...
    // int key;

//     //met.is_open() == true) {
//     for (int i=0, actualnumber=1; i<size; i++) {
//         for (int j=0; j<limit; j++) {
//             // met >> ourword;

//             std::cout << "our_dict::entry: " << our_dict[0] << std::endl;
                
//             if (j == *(a+i)) {
//                 std::cout << "j" << j << ":a*(" << *(a+i) << "):i" << i << std::endl;
//                 std::string test = our_dict[j];
//                 std::cout << "test:" << test << ":" << "our_dict[j]" << our_dict[j] << std::endl;
//                 //     strncpy(meta[counter++],ourword.c_str(), ourword.length());
//                 //     std::cout << "- assigned: (" << j << "): " << meta[counter - 1] << " :: " << ourword << " :: " << *(a+i) << std::endl;

//                 //     break;
//             }
//         }
//     }
// };      
    //     met.close();
    // } else {
    //     std::cout << std::endl;
    //     std::cout << "~::!::~ error !!! (error opening file) ~:: unable to lookup this meta sequence." << std::endl;
    //     fileWasClosed = true;
    // }

    // if (met.is_open() == true) {

    //     for (int i=0; i<size; i++) {
    //         for (int j=1; j<limit+1; j++) {
    //             met >> ourword;
    //             if (*(a+i) == j) {
    //                 strncpy(meta[counter++],ourword.c_str(), ourword.length());
    //                 std::cout << "- assigned: (" << j << "): " << meta[counter - 1] << " :: " << ourword << " :: " << *(a+i) << std::endl;

    //                 break;
    //             }
    //         }
    //     }
        
    //     met.close();
    // } else {
    //     std::cout << std::endl;
    //     std::cout << "~::!::~ error !!! (error opening file) ~:: unable to lookup this meta sequence." << std::endl;
    //     fileWasClosed = true;
    // }
    
    // std::cout << std::endl << "+meta queries:" << std::endl;

    // if (fileWasClosed == false) {
    //     for (int k=0; k<counter; k++) {
    //         std::cout << "(debug) " << k << ") " << meta[k] << std::endl;
    //     }
    // }
    
    // std::cout << std::endl;

    // if (met.is_open() == true) {
    //     // first EXTRACT data from meta query (meta)
    //         // meta == #,#,#,#, (of variable size)

    //         // split data by ',' HERE!!!

    //     // lookup words in dictionary
        
    //     while (getline(met, word)) {
    //         iter++;

    //         //std::cout << iter << "-";

    //         if (counter >= dict_size) {
    //             i++;

    //             if (i >= size) {
    //                 break;
    //             }

    //             counter = 0;
    //             continue;
    //         }

    //         if (*(a+i) < 0) {   // maybe for loop here
    //             i++;
    //             counter=0;
    //             continue;
    //         }

    //         if (counter == *(a+i)) {
    //             // return word
    //             // new_meta = new_meta + word;
    //             // new_meta = new_meta + ",";
    //             //std::cout << "~copy~ :: " << word << std::endl;

    //             std::cout << "A[I]:(" << counter <<")(" << i << ") " << *(a+i) << std::endl;
    //             strncpy(meta[i++],word.c_str(),word.length());

    //             //std::cout << "+word: " << word << "." << std::endl;
    //             counter = 0;
    //             break;
    //         }
    //         counter++;
    //     }

        // for (int i=0; i<dict_size; i++) {
            
        //     // met >> word;
        //     if (a[i] == i) {
                
        //     }
        //     // debug
        //     //std::cout << (i+1) << ")\t" << word << "." << std::endl;
        // }

    // std::cout << "\t- " << word << std::endl;
// };