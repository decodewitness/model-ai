// AI/SYSTEM/LOGIC/TRANSPONDER/STORE_META_QUERIES.CPP -- USED BY "AI/SYSTEM/LOGIC/TRANSPONDER/PREPARE.CPP"

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <unistd.h>
#include <sstream>
#include <vector>

std::string reverse_path_handle = "ai/data/files/20k.txt";
std::string meta_query_path = "ai/lib/queries/meta_queries";
std::string subjectsfile = "ai/lib/queries/subs";
std::string relations = "ai/lib/queries/relations";
std::string learn = "ai/lib/queries/learn";
std::string swap = "ai/lib/queries/swap";

// NEED TO MAKE THIS VARIABLE
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
bool meta_que = false;

// stores meta queries
void store_meta_queries(int a[], int size) {
    std::ofstream met;
    if (meta_que == false && met.is_open() == false) {
        met.open(meta_query_path, std::ofstream::app);
        sleep(1);
        if (met.is_open() == true) {
            meta_que = true;
        }
    }
    std::cout << std::endl;
    if (met.is_open() == true) {
        std::cout << "~:: meta queries ~:: storing meta query sequence" << std::endl;
        std::cout << "\t~::::meta::::~" << std::endl;
        std::cout <<"\t- path: \"" << meta_query_path << "\"." << std::endl;
        std::cout <<"\t- meta sequences:" << std::endl;
        for (int i=0; i<size; i++) {
            met << a[i];
            // if (i<size-1) {
            met << ",";
            // }
            std::cout << "\t\t- " << a[i];
        }
        met << std::endl;
        met.close();
    }
    sleep(1);
    std::cout << std::endl;
};

// looks up meta queries inside a[]
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
    std::cout << "~:: meta queries" << std::endl;
    std::cout << "\t~:: reverse_meta_query_lookup(\"";
    
    for (int i=0; i<size; i++) {
        std::cout << *(a+i) << ",";
    }

    // std::cout << "\b" << (32) << "\b";
    std::cout << "\")" << std::endl;
    std::cout << "~:::~" << std::endl;
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

        // store_meta_queries;
    }

    sleep(1);
};

// reads meta queries
int readMetaQueries(bool all) {
    std::string mq;
    std::string number_as_string;
    std::vector<int> numbers;
    std::ifstream openFile;

    void meta_read(std::vector<int>numbers);
    void reverse_metas(std::vector<int> numbers);

    std::cout << std::endl << "~:: readMetaQueries() :" << std::endl;

    openFile.open(meta_query_path);

    while (getline(openFile, mq, ',')) {
        // mq.pop_back();

        if (mq.front() == '\n') {
            mq = mq.substr(1, mq.size());
        }

        if(mq.size() > 0) {
            // std::cout << "mq : " << mq << std::endl;
            std::istringstream is(mq);
            while (getline(is, number_as_string, ',')) {
                numbers.push_back(std::stoi(number_as_string));
            }
        }
    }

    // std::cout << "n : " << numbers.size() << "\n";

    // for(auto&& number : numbers)
    // {
    //     std::cout << "numbers: " << number << "\n";
    // }

    if (all == true) {
        reverse_metas(numbers);
        meta_read(numbers);

    }

return numbers.size();
}

// reads ALL meta queries
int readAllMetaQueries(bool all) {
    int counter=0;
    std::string cvar;
    std::string mq;
    std::string number_as_string;
    std::vector<int> numbers;
    std::ifstream openFile;
    void reverse_metas(std::vector<int> numbers);
    void meta_read(std::vector<int>numbers);

    std::cout << std::endl << "~:: readAllMetaQueries() :" << std::endl;

    openFile.open(meta_query_path);
    // while (1) {
        // counter++;  // increase counter to amount to 3 lines read

        // read label first
        // openFile >> cvar;
        
        // GETS THE HEADER FOR EVERY META QUEUE
        // getline(openFile,cvar);
        // std::cout << "CVAR: \"" << cvar << "\"" << std::endl;

        // GETS THE NUMBERED SEQUENCE OF EVERY META QUEUE
    while (getline(openFile, mq, ',')) {

        if (mq.front() == '\n') {
            // std::cout << "readAllMetaQueries() - removing '\\n'" << std::endl;
            mq = mq.substr(1, mq.size());
        }

        // std::cout << "mq : " << mq << std::endl;
        std::istringstream is(mq);
        // numbers.push_back(std::stoi(mq));

        while (getline(is, number_as_string, ',')) {
            numbers.push_back(std::stoi(number_as_string));
        }
    }

    // std::cout << "n : " << numbers.size() << "\n";

    // for(auto&& number : numbers) {
    //     std::cout << "numbers: " << number << "\n";
    // }

    if (all == true) {
        //reverse_metas(numbers);
        meta_read(numbers);
    }
    // }

return numbers.size();
}

// read up meta sequence
void meta_read(std::vector<int>numbers) {
    std::string reverse_meta(int x);
    std::cout << "\t\t~:: meta_read() :" << std::endl << std::endl;

    std::cout << "[[[ - ";
    for(auto&& number : numbers) {
        std::cout << reverse_meta(number) << " ";
    }
    std::cout << "- ]]]" << std::endl;
}

// reverse single meta
std::string reverse_meta(int x) {
    std::ifstream dict_in;
    int line_counter;
    std::string line;

    dict_in.open(reverse_path_handle);
    
    if (dict_in.is_open() == false) {
        dict_in.open(reverse_path_handle);
    }

    // for(std::vector<int>::iterator it = std::begin(numbers); it != std::end(numbers); ++it) {
    //     int metaquery1 = *it;
    //     std::cout << "vector : " << *it << " " << metaquery1 << std::endl;

    dict_in.seekg(SEEK_SET);
    line_counter=0;
    while (std::getline (dict_in,line)) {
        line_counter++;
        if (line_counter == x) {
            //std::cout << "LINE:::" << line << std::endl << std::endl;
            break;
        }
    }
    // }

    dict_in.close();
return line;
}

// reverses meta queries
void reverse_metas(std::vector<int> numbers) { // looks up the words for the numbers of the meta queries
    std::ifstream met;
    std::string new_meta;
    std::string word;
    std::string ourword;
    std::ifstream dict_in;
    std::vector<std::string> vecA;
    std::string tmp;
    std::string line;

    int line_counter;
    int counts = 0;
    char *our_dict[20000];
    int alloca;
    int keyd = 0;
    int i=0;

    std::cout << "\t~:: reverse_metas() :" << std::endl;

    if (dict_in.is_open() == false) {
        dict_in.open(reverse_path_handle);
    }

    for(std::vector<int>::iterator it = std::begin(numbers); it != std::end(numbers); ++it) {
        int metaquery1 = *it;
        // std::cout << "vector : " << *it << " " << metaquery1 << std::endl;

        dict_in.seekg(SEEK_SET);
        line_counter=0;
        while (std::getline (dict_in,line)) {
            line_counter++;
            if (line_counter == metaquery1) {
                // std::cout << "LINE:::" << line << std::endl << std::endl;
                break;
            }
        }
    }
    dict_in.close();
};

void clear_que() {
    std::cout << "\t~:: clearing buffer." << std::endl;
    unlink(meta_query_path.c_str());
    std::cout << std::endl << "\t~:: cleared buffer / meta queries." << std::endl;
}

void whatHaveYou() {    // return what we have extracted as data
   
    void labelSynopsis(bool sy);
    std::string answer;
    std::string meta_q;
    bool nosynopsis = false;
    std::ifstream learned;
    
    // learned.open(learn);

    std::cout << "label all? (y/n) default is [no] : ";
    std::cin >> answer;

    if (answer[0] == 'y' || answer[0] == 'y') {
        std::cout << "(label) all:" << std::endl << "-----" << std::endl;
        nosynopsis = true;
    } else {
        std::cout << "(label) synopsis:" << std::endl << "-----" << std::endl;
        nosynopsis = false;
    }
    
    if (nosynopsis == true) {
        labelSynopsis(nosynopsis);
    } else {
        labelSynopsis(false);
    }
}

void labelSynopsis(bool sy) {
    // strings
    std::string hamstr;
    
    // file pointers
    std::ifstream ifstr;
    
    // functions
    std::string filtersf(std::string f);
    void relatedMetaQueries(std::string h);

    ifstr.open(learn);
    if (sy == true) {
        std::cout << "synopsis: " << std::endl << std::endl;
    } else {
        std::cout << "all:" << std::endl << std::endl;
    }

    if (ifstr.is_open() == true) {
        if (sy == false) {
            while (ifstr >> hamstr) {
                std::cout << "metasq: " << hamstr << std::endl;
            }
        } else {
            while (ifstr >> hamstr) {
                std::cout << "metasq:" << filtersf(hamstr) << std::endl;
                relatedMetaQueries(hamstr);
            }
        }
    }
}

// main filter / scrutiny
std::string filtersf(std::string f) {
    // function
    std::string subjectsf(std::string s);

    // assign subject
    std::string x = subjectsf(f);

return x;
}

// subjects filter
std::string subjectsf(std::string s) {
    std::string line = "<unassigned>";
    std::ifstream subs;

    std::cout << "~:: subjects filter :" << std::endl;

    subs.open(subjectsfile);

    if (subs.is_open() == true) {
        while (subs >> line) {
            std::cout << ":: " << line << std::endl;
            




        }
        subs.close();
    }

return line;
}

// related meta queries
void relatedMetaQueries(std::string h) {
    std::ifstream rel;
    std::string line;
    std::vector<int> vect;

    int lines=0;
    int numberOfEntries=0;

    std::cout << std::endl << "- related meta queries:" << std::endl;
    rel.open(relations);

    if (rel.is_open() == true) {
        while (rel >> line) {
            lines++;
            std::cout << "relations : " << line << std::endl;
            std::stringstream ss(line);

            for (int i; ss >> i;) {
                vect.push_back(i);    
                if (ss.peek() == ',') {
                    ss.ignore();
                }
                numberOfEntries++;
            }
        }
        rel.close();
    }

    if (numberOfEntries > 0) {
        std::cout << "lines : " << lines << std::endl;

        for (std::size_t i = 0; i < vect.size(); i++) {
            std::cout << "vect[] = " << vect[i] << std::endl;
        }

        std::cout << "~:: reversing meta topology." << std::endl;
        reverse_metas(vect);
    }
}

// stores related meta queries in to "ai/lib/queries/relations"
void store_nr_relation(int nr, int relation) {
    std::ofstream reldb;

    std::cout << std::endl << "~::store_relation()" << std::endl;
    reldb.open(relations, std::ofstream::app);

    if (reldb.is_open() == true) {
        reldb << nr << "," << relation << std::endl;
        std::cout << "\t~:: stored reference." << std::endl;
    }
}

// stores related meta queries in to "ai/lib/queries/relations" too
void store_string_relation(std::string relation) {
    std::ofstream reldb;

    std::cout << std::endl << "~::store_relation()" << std::endl;
    reldb.open(relations, std::ofstream::app);

    if (reldb.is_open() == true) {
        reldb << relation << std::endl;
        std::cout << "\t~:: stored reference." << std::endl;
    }
}

        // alloca = *it;

        // while (dict_in >> word) {
        // if (word.compare(vecA.at(i)) == 0) {
            // std::cout << "HIT ON: " << *it << std::endl;
        // }


        // std::cout << our_dict[alloca - 1];
        // }
    // }

    // dict_in.open(reverse_path_handle);
    //bool fileWasClosed = false;

//     std::cout << std::endl;

//     met.open(meta_query_path);
    
//     if (met.is_open() == true) {
//         while (met >> new_meta) {
//             std::cout << "new meta : " << new_meta << std::endl;
//         }
//     }

//     while (keyd < 20000) {
//         dict_in >> ourword;
//         vecA.push_back(ourword);    
//     }
    
//     std::cout << "word: " << word << std::endl;

//     met.close();
//     dict_in.close();
// };
    // std::fstream dict_in;
    // dict_in.open(reverse_path_handle);
    // char our_dict[20000][256];
    // int counts=0;
    // int keyd=0;
    // std::string ourword;
    // //int counter=0, actualnumber=1, limit = 20000;  // size of dictionary

    // std::cout << std::endl;
    // std::cout << "~:: meta queries ~:: reverse_meta_query_lookup(\"";
    
    // for (int i=0; i<size; i++) {
    //     std::cout << *(a+i) << ",";
    // }

    // // std::cout << "\b" << (32) << "\b";
    // std::cout << "\") ~:::~" << std::endl;
    // std::cout << std::endl;

    // //std::cout << "- (debug) *(a+i) " << std::endl;

    // // std::string word;

    // while (keyd < 20000) {
    //     dict_in >> ourword;
                
    //     // debugging output
    //     //std::cout << key << ") " << word << std::endl; 
        
    //     strncpy(our_dict[counts], ourword.c_str(), 255);

    //     //ints[key] = counter++;
    //     //std::cout << "(debug) word = \"" << word << "\" - key: (" << key << ")." << std::endl;
        
    //     counts++;
    //     keyd++;
    // }
    
    // std::cout << "~:: reverse meta query lookup: " << std::endl;

    // for (int i=0; i<size; i++) {
    //     if (*(a+i) > 0) {
    //         std::cout << "\t- " << our_dict[(*(a+i) - 1)] << "\t\t --> *(a+i) = "  << *(a+i) << " - *(a+i) - 1 = " << (*(a+i) - 1) << std::endl;
    //     } else {
    //         std::cout << "(skipped unregistered entry)" << std::endl;
    //     }

    //     // store_meta_queries;
    // }

    // sleep(3);
// };


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