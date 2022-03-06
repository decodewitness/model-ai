// AI/BRAIN/BRAIN.CPP   -- NOT USED YET!!!
#include "brain.h"

Brain::Brain() {
// store_reference
    //int resonate iNumber

    // index should still get updated automatically
    this->index = 5;

    this->resonate_index = starting_index;
    this->descriptor = false;
    // this->keep_alive = false;        // obsolete
    this->set1 = 0;
    this->set2 = 0;
    this->done[0] = false;

// inside of canopy
    this->file_access(0);
};

Brain::~Brain() {
    if (this->access.is_open()) {
        this->access.close();
        this->access_is_open = false;
    }

    // flush any last data here

    if (this->output.is_open() == true) {
        this->output.close();
    }
};

// technicalities
void Brain::file_access(int level) {
    if (level == 0) {   // open references (ai/brain/intelligence/cabinet)
        if (this->access.is_open() == false) {
            this->access.open(store_reference_file);
        }
        if (this->data.is_open() == false) {
            this->data.open(data_collection);
        }
        if (this->output.is_open() == false) {
            this->output.open(store_file);
        }
    
   
        if (this->access.is_open() == true) {
            this->access_is_open = true;
        } else {
            this->access_is_open = false;
            std::cout << "~::!::~ error! could not open \"access\"." << std::endl;
        }

        if (this->data.is_open() == true) {
            this->data_is_open = true;
        } else {
            this->access_is_open = false;
            std::cout << "~::!::~ error! could not open \"data\"." << std::endl;
        }

        if (this->output.is_open() == true) {
            this->output_is_open = true;
        } else {
            this->output_is_open = false;
            std::cout << "~::!::~ error! could not open \"output\"." << std::endl;
        }
    }

    if (level == 3) {
        this->cabinet.open("ai/brain/nlp/intelligence/store_file");
        if (this->cabinet.is_open()) {
            cabinet_is_open = true;
        }
    }

    if (level == 7) {
        if (information_file.length() >= 5) { // check if file has extension
            this->information.open(information_file);
        }        
        if (this->information.is_open()) {
            this->information_is_open = true;
        }
    }

    if (level == 9) {
        // close files
        if (output.is_open()) {
            output.close();
            output_is_open = false;
        }
        if (access.is_open()) {
            access.close();
            access_is_open = false;
        }
        if (data.is_open()) {
            data.close();
            data_is_open = false;
        }
        if (cabinet.is_open()) {
            cabinet.close();
            cabinet_is_open = false;
        }
        if (information.is_open()) {
            information.close();
            information_is_open = false;
        }

        std::cout << std::endl << "~:: closed all files." << std::endl;
    }
};

// if (level == 1) {   // opens write database (ai/brain/intelligence/store)
    //     this->output.open(store_file);
    // }

    // if (level == 2) { // opens "cabinet" and "store"
    //     this->access.open(store_reference_file);
    //     this->output.open(store_file);
    // }

    // if (level == 3 || level == 0) { // opens data collection
    //     this->data.open(data_collection);
    // }


    // else if (level < 3) {
    //     // debugging option   // system("pwd");
    //     std::cout << std::endl << "~::!::~ Error :: (Brain::file_access)->" << store_file << " ~:: error opening file." << std::endl;
    // }

    // logic with "level" access here

    // if (access.is_open() == true) {
    //     this->access_is_open = true;

    //     if (level >= 3) {
    //         // do logic
    //         this->keep_alive = true;
    //     } else if (level < 3) {
    //         // label descriptor;
    //         this->descriptor=true;
    //     } else if (level >= 9 && level < 99) {
    //         // skip step for now

    //     } else if (level == 99) {
    //         this->access.close();
    //     } else if (level >= 100) {
    //         // do logic
    //     }

        // could also keep open for duration of the program depending on the brain logic
    
void Brain::intialize1(bool perm) {    // perm = descriptor
    long int max_index; // number of max entries to dig
    long int difference;    // tracks the difference off from this->handles in the max_index lines account
    bool stop = false;
    std::string line;

    // loop over indexes // later change to index reference numbers
    // first indexing the line count
    for (int i=0; stop != true; i++) {
        if (access >> line) {
            max_index++;                
        } else {
            stop = true;
        };
    }

    // reset file handle
    access.seekg(SEEK_SET);

    // now we have the number of lines in the catalogue inside max_index
    // now we need the difference from max_lines and this->handles to tell how many lines to update inside catalogue
    if (this->handles < max_index) {
        this->set1 = max_index - this->handles;

        // add trailing handles
            // need to keep into account number of lines to skip from main index (1st line)
        // this->set2 should be 0 after all procedures from this->procure        
        this->set2 = this->procure(this->set1);   // results in sum   // creates research "set2"
        
        // uncomment and work with this next line
        //this->research(this->set2);

        // rebuild database catalogue
        // this->research(this->handles);
    }

    //this->handles = max_index;
};

    // reset file handle
    // for (int i=0; i<max_index; i++) {
    //     // get a fix on line number

    // }

void Brain::research(int x) {
    int nr_of_sets = x;

    // need to open files or catalogue

    for (int i=0; i< nr_of_sets; i++) {
        std::cout << "~:: researching batch number: " << (i+1) << std::endl;
        sleep(1);
    }
};

int Brain::procure(int nr) {    // nr = this->set1
    // default (nr=1) procures 1 line back from the log
    int numberProcessed = 0;
    std::string line;

    if (this->access.is_open() == true) {
        this->access_is_open = true; 
    } else {
        this->file_access(0);
    }

    // process data // read to this->handles line number
    for (int i=0; i<this->handles; i++) {
        this->access >> line;
        std::cout << line << std::endl;
    }

    std::cout << "~:: procuring data in (" << nr << ") lines." << std::endl;

    for (int i=0; i>nr; i++) {
        this->access >> line;
        
        // disassemble query here

        // output
        std::cout << (i+1) << ") ";
        std::cout << line << std::endl;

        // logic
    }

    return 0;   // set to -1 later first fix return statement
}
    // process data
    // if (nr <= 20) {
    //     for (int i=1; i<this->handles && i<=nr; i++) {

    //     }
    // } else if (nr > 20) {
    //     std::cout << "~:: doing more research." << std::endl;
    //     this->consolidate(nr);
    // } else {

    // }

    // compare with old data

    // update this->handles


void Brain::useBrain(std::string query) {
    // logic think
    // access cabinet with search method
    std::string logic = query;
    this->neural_net(query, logic, 1);

    //this->search(logic, 3);
    //this->search_catalogue_index(logic);

    // options
        // stepping engine
        // artificial life extrapolation in numbers
        // modular filters
        // string NLP
        // machine learning
            // models linear regression
            // model classification
            // model polynomial regression
            // other machine learning modules
};

// access
void Brain::store_reference(std::string s) { // handles data // resonate_index
    // inside of brain (cabinet)
    this->store_filename = store_reference_file;
    this->file_access(0);
    
    // sanitize input here



    // store string s in temporary catalogue or vector
    output << s << std::endl;
    output.close();
};

// data
void Brain::arrange() { // arranges data in cabinet // alphabetical sequence
    // arrange here
};

std::string Brain::search_index_code(std::string l) {
    
    // counters initialized with {0}
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    
    bool stop = false;
    bool tagIsComplete = false;

    // separate code from line
    for (int i=0; i<l.length(); i++){ 
        if (l.at(i) != '[' && stop == false) {
            continue;
        } else if (stop == false && l.at(i) == '[') {
            stop=true;
            counter1=i;
        }

        if (stop == true && l.at(i) != ']') {
            counter2++;
            continue;
        } else {
            tagIsComplete = true;
            counter3=i;
            break;
        }
    }

    // this should be the words between [brackets] inside "intelligence/data_collection"
    code = l.substr(counter1);
    std::cout << "search_index_code::[article] : [ " << code << " ]." << std::endl;

    // use variable "combined" here (see above) here to actually link the refreshed article from data_collection

    return code;
}

std::string Brain::search(std::string logic, int n) { // search cabinet    // n is default 1   // n is resonate index
    // has access cabinet
    this->file_access(0);

    std::string search_string = logic;
    std::string line1;
    std::string line2;
    std::string search1;
    std::string search2;
    std::string empty;
    std::string sorted="n";
    std::string i_string;   // string with information
    std::string b_string;   // string with various tags in information_file
    std::string story;
    
    vector<std::string> story_index;
    std::vector<vector<std::string>> mystrings; // use to store weights
    
    // int counter=0;
    bool found=false;
    bool not_found=true;
    int wordCount=0;
    int resonate_index=n;
    int resonate_index_max=n;  // last index in cabinet according to reference

    // bool displayed=false;
    std::cout << std::endl;
    std::cout << "~:: searching indexes:" << std::endl;
    //std::cout << "\t::";

    if (this->data_is_open == false) {
        std::cout << "~::!::~ error! \"data\" is not open." << std::endl;
        this->file_access(0);
    } else {
        this->data.seekg(SEEK_SET);
    }
    if (this->access_is_open == false) {
        std::cout << "~::!::~ error! \"access\" is not open." << std::endl;
        this->file_access(0);
    } else {
        this->access.seekg(SEEK_SET);
    }

    for (int i=0;search1.compare(search_string) != 0 && i<resonate_index_max; i++) {
        
        if (not_found == true) {
            // getting the search terms in the cabinets
            this->access >> search1;
            this->data >> search2;

            if (search1.compare(search_string) == 0) {
                found = true;

                std::cout << "\tsearch1 : " << search1 << std::endl;
                std::cout << "\tsearch2 : " << search2 << std::endl;

                // getting the description in the cabinets
                std::getline(access, line1);
                std::getline(data, line2);

                std::cout << "\tline1 : " << line1 << std::endl;
                std::cout << "\tline2 : " << line2 << std::endl;
                
                // getting the empty lines in the cabinet
                std::getline(access, empty);
                std::getline(data, empty);

                // sorter function
                if (search2.compare(search_string) == 0) {
                    sorted = this->sorter(line2, 1);
                }
                
                // process file data
                if (sorted.compare("n") == false) {
                    this->file_access(7);
                    if (this->information_is_open == true) {
                        std::cout << std::endl << ":: information ::" << std::endl;
                        this->information >> i_string;

                        std::cout << i_string << " :::_]{ ";
                        // print at least 10 results
                        while (this->information >> b_string) {
                                // streaming information
                                std::cout << b_string << ",";
                                story_index.push_back(b_string);
                        }
                        std::cout << std::endl << "- adding (" << wordCount <<") weights." << std::endl;
                    }
                } else {
                    std::cout << "[n]" << std::endl;
                    std::cout << "- could not access the file." << std::endl;
                    std::cout << std::endl;
                }
                
                std::cout << std::endl << "[]:: " << sorted << std::endl;

                // process weights
                if (wordCount > 0) {
                    for (std::vector<std::string>::iterator it = story_index.begin() ; it != story_index.end(); ++it) {
                        std::cout << " " << *it;

                        // use weights function
                        
                        // use vvec
                    }
                    
                    // need to find numbers
                        // weights
                    // std::cout << i_string << "=" << number;

                    // for (int i=0; i<wordCount; i++) {
                        // lookup weights in story from vector instead
                            // make vector
                    // }
                } else {
                    std::cout << "- no data is available." << std::endl;
                }
            } else {
                // skipping lines in the cabinets
                std::getline(access, empty);
                std::getline(access, empty);
                // skipping empty lines in the cabinets
                std::getline(data, empty);
                std::getline(data, empty);
            }
        }

        if (search1.compare("") != 0 && search2.compare("") != 0 && search1.compare(search2) == 0 && found == true) {
            resonate_index = i;
            std::cout << "~:: resonate_index::match found on line: (" << (resonate_index+1) << ")." << std::endl;

        } else {
            // std::cout << "~::!::~ error: search does not match search / cabinet is corrupted!" << std::endl;
            not_found = true;
            continue;
        }

        if (search1.compare("eof") == 0) {
            break;
        }

        if (found == true) {
            std::cout << "~:: done." << std::endl;
        }
    }

    if (search1.compare(search_string) == 0) {
        if (search1.compare(search2)) {
            std::cout << "\t~:: matches found accross files in database." << std::endl;
        }
        std::cout << "\t~:: querymatches search string: \"" << search_string << "\"." << std::endl;
        not_found = false;
    }

    if (not_found == false) {
        std::cout << std::endl;
        std::cout << "-* " << search_string << " is:" << std::endl;
        std::cout << line1 << std::endl;
        std::cout << std::endl;
        std::cout << line2 << std::endl;
    }

    // return the broad definitions from line2
        // later return article codes
            // print article code for now...

    return line2;
};

void Brain::recall(std::string s) {  // recalls events
    std::string h;
    
    //this->search_catalogue_index(s);
    //this->search_index_code(h);
    //this->neural_net(s, h, 1); //neural_net(std::string s, std::string h, int cumulator)
};

void Brain::add_data(std::string h, std::string s, std::string c) {    // adds data to a stored reference (store_reference())
    this->file_access(0);
    this->output << h << "\t" << s << "\t[" << c << "]" << std::endl << std::endl;
    this->flush_data(1);
};

void Brain::add_cabinet(std::string d, std::string desc) {
    this->file_access(3);
    this->cabinet << d << "\t" << desc << "\t" << "+ " << this->index++ << std::endl << std::endl;
    // this->file_access(9);
    this->flush_data(2);
}

void Brain::flush_data(int n) {  // consolidates data
    this->file_access(9); // closes files
    if (n == 1) {
        system("cat ai/brain/nlp/intelligence/store_file >> ai/brain/nlp/intelligence/data_collection");
    }
    if (n == 2) {
        system("cat ai/brain/nlp/intelligence/store_file >> ai/brain/nlp/intelligence/cabinet_collection");
    }
    std::cout << std::endl << "~:: flushed and consolidated data." << std::endl;
};

void Brain::done_with_query() {
    this->done[0] = true;
};

    // if (this->access.is_open() == true) {
    //     this->access_is_open = true;
    // }
    // if (this->data.is_open() == true) {
    //     this->data_is_open = true;
    // }

    // mark search term
//     for (int i=0; i<resonate_index_max; i++) {
//         // start from index in cabinet
//         this->access.seekg(SEEK_SET);
//         this->data.seekg(SEEK_SET);

//         this->access >> search;
//         sleep(1);
//         this->data >> search2;

//         // debug
//         std::cout << "search: " << search << std::endl;
//         std::cout << "search2: " << search2 << std::endl;

//         // read rest of line here
//         std::getline(access, line);
//         std::getline(data, line2);

//         // "line" is going to hold the value from
//             // "intelligence/cabinet_collection"


//         // debug section (std::cout ;; sleep(1))
//         //std::cout << line << std::endl;
//         //sleep(1);

//         // continue
//         if (search.compare(search_string) == 0) {
//             // debug
//             // std::cout << " hit(" << i << ")";
//             counter++;

//             // do logic
//             this->store_reference(line);    // stores the line in temporary catalogue or vector

//             if (displayed == false) {
//                 // give option
//                 std::cout << line << std::endl;

//                 // search_index_code(line);
//                 //std::cout << std::endl;
//                 //std::cout << "(debug): search_index_code(line) :: " << search_index_code(line) << std::endl << std::endl;
//                 sleep(2);

//                 displayed = true;
//             }
//         } else {
//             continue;
//         }

//         if (search2.compare(search_string) == 0) {
//             // debug
//             // std::cout << " hit(" << i << ")";
//             counter++;

//             // do logic
//                 //this->store_reference(line);    // stores the line in temporary catalogue or vector

//             // give option
//             std::cout << "LINE II: " << line2 << std::endl;

//             // search_index_code(line);
//             std::cout << std::endl;
//             std::cout << "(debug): search_index_code(line2) :: " << search_index_code(line2) << std::endl << std::endl;
//             sleep(2);
//         }
//     }
// };

    // count to index resonate_frequency_max
    // for (int i=0; i<resonate_index_max; i++) {

    // }

    // std::cout << std::endl;

// eof