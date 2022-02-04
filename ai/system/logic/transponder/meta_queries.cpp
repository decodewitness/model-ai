// AI/SYSTEM/LOGIC/TRANSPONDER/STORE_META_QUERIES.CPP -- USED BY "AI/SYSTEM/LOGIC/TRANSPONDER/PREPARE.CPP"

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

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
        std::cout << "~:: meta queries ~:: storing meta query sequence ~:::~" << std::endl;
        std::cout <<"\t- path: \"" << meta_query_path << "\"." << std::endl;
        std::cout <<"\t\t- meta sequences:" << std::endl;
        
        for (int i=0; i<size; i++) {
            std::cout << "\t- " << a[i];
        }

        met << std::endl;

        met.close();
    }

    std::cout << std::endl;
};

void reverse_meta_query_lookup(int a[], int size) {

    std::ifstream met;
    
    std::string new_meta;
    std::string word;

    std::cout << std::endl;
    std::cout << "~:: meta queries ~:: reverse_meta_query_lookup(\"";
    
    for (int i=0; i<size; i++) {
        std::cout << a[i] << ",";
    }

    // std::cout << "\b" << (32) << "\b";
    std::cout << "\") ~:::~" << std::endl;
    std::cout << std::endl;

    met.open(reverse_path_handle);

    // loop variables along with dict_size and size -> size = size of loopvar of array
    int i=0, counter=0, iter=-1;

    std::cout << std::endl;

    // look up meta query string here...
    if (met.is_open() == true) {
        // first EXTRACT data from meta query (meta)
            // meta == #,#,#,#, (of variable size)

            // split data by ',' HERE!!!

        // lookup words in dictionary
        
        while (getline(met, word)) {
            iter++;

            //std::cout << iter << "-";

            if (counter >= dict_size) {
                i++;

                if (i >= size) {
                    break;
                }

                counter = 0;
                continue;
            }

            if (*(a+i) < 0) {
                i++;
                counter=0;
                continue;
            }

            if (counter == *(a+i)) {
                // return word
                // new_meta = new_meta + word;
                // new_meta = new_meta + ",";
                //std::cout << "~copy~ :: " << word << std::endl;

                std::cout << "A[I]: (" << i << ") " << *(a+i) << std::endl;
                strncpy(meta[i++],word.c_str(),word.length());

                //std::cout << "+word: " << word << "." << std::endl;
                counter = 0;
                continue;
            }
            counter++;
        }

        std::cout << "+meta queries:" << std::endl;

        for (int i=0; i<size; i++) {
                std::cout << "(debug) " << i << ") " << meta[i] << " :: " << word << std::endl;
        }

        // for (int i=0; i<dict_size; i++) {
            
        //     // met >> word;
        //     if (a[i] == i) {
                
        //     }
        //     // debug
        //     //std::cout << (i+1) << ")\t" << word << "." << std::endl;
        // }

        met.close();

    } else {
        std::cout << std::endl;
        std::cout << "~::!::~ error !!! (error opening file) ~:: unable to lookup this meta sequence." << std::endl;
    }

    // std::cout << "\t- " << word << std::endl;
};