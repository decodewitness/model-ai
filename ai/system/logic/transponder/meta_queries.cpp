// AI/SYSTEM/LOGIC/TRANSPONDER/STORE_META_QUERIES.CPP -- USED BY "AI/SYSTEM/LOGIC/TRANSPONDER/PREPARE.CPP"


// MAKE ALL THIS LOGIC BASED ON INTS (NEXT TIME)


#include <iostream>
#include <string>
#include <fstream>

std::string reverse_path_handle = "ai/data/files/20k.txt";
std::string meta_query_path = "ai/lib/queries/meta_queries";

const int dict_size = 20000;    // size of dictionary in "AI/DATA/FILES/20K.TXT"

void store_meta_queries(std::string meta) {

    std::ofstream met;

    met.open(meta_query_path);

    std::cout << std::endl;

    if (met.is_open() == true) {
        std::cout << "~:: meta queries ~:: storing meta query sequence ~:::~" << std::endl;
        std::cout <<"\t- path: \"" << meta_query_path << "\"." << std::endl;
        std::cout <<"\t- meta sequence: \"" << meta << "\"." << std::endl;

        met << meta << std::endl;

        met.close();
    }
};

std::string reverse_meta_query_lookup(std::string meta) {

    std::ifstream met;
    std::string new_meta = "-empty_string-";
    std::string word;

    std::cout << std::endl;
    std::cout << "~:: meta queries ~:: reverse_meta_query_lookup(\"" << meta << "\") ~:::~" << std::endl;
    std::cout << std::endl;

    // look up meta query string here...

    met.open(reverse_path_handle);

    if (met.is_open() == true) {
        // first EXTRACT data from meta query (meta)
            // meta == #,#,#,# (of variable size)

            // split data by ',' HERE!!!

        // lookup words in dictionary
        for (int i=0; i<dict_size; i++) {
            
            met >> word;
            
            // debug
            //std::cout << (i+1) << ")\t" << word << "." << std::endl;
        }

        met.close();

    } else {
        std::cout << std::endl;
        std::cout << "~::!::~ error !!! (error opening file) ~:: unable to lookup this meta sequence." << std::endl;
    }

    std::cout << "\t- " << new_meta << std::endl;

return new_meta;
};