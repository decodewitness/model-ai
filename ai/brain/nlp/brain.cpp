// AI/BRAIN/BRAIN.CPP   -- NOT USED YET!!!
#include "brain.h"

Brain::Brain() {
// store_reference
    //int resonate iNumber
    this->resonate_index = starting_index;
    this->descriptor = false;
    this->keep_alive = false;
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
    
    int counter;

    // std::string combined;    // used later   // see down
    std::string code;

    // s+l = word + line
    ////////////////////

    // separate code from line
    for (int i=0; i<l.length(); i++){ 
        if (l.at(i) != '[') {
            counter++;
        } else {
            break;
        }
    }

    // this should be the words between [brackets] inside "intelligence/data_collection"
    code = l.substr(counter, (l.length()-1));

    std::cout << "search_index:article :: " << code << std::endl;

    // use variable "combined" here (see above) here to actually link the refreshed article from data_collection

    return code;
}

void Brain::search(std::string logic, int n) { // search cabinet    // n is default 1   // n is resonate index
    // has access cabinet
    this->file_access(0);

    std::string search_string = logic;
    std::string line1;
    std::string line2;
    std::string search1;
    std::string search2;
    std::string empty;

    // int counter=0;
    bool not_found=true;
    int resonate_index = n;
    int resonate_index_max = n;  // last index in cabinet according to reference

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

    for (int i=0;i<resonate_index_max; i++) {
        
        if (not_found == true) {
            this->access >> search1;
            this->data >> search2;

            std::cout << "search1 : " << search1 << std::endl;
            std::cout << "search2 : " << search2 << std::endl;

            std::getline(access, line1);
            std::getline(data, line2);

            std::cout << "line1 : " << line1 << std::endl;
            std::cout << "line2 : " << line2 << std::endl;

            std::getline(access, empty);
            std::getline(data, empty);
        }

        if (search1.compare("") != 0 && search2.compare("") != 0 && search1.compare(search2) == 0) {
            std::cout << "\t~:: searches match from cabinets." << std::endl;
            resonate_index = i;
            std::cout << "\t~:: resonate_index::match found on line: " << (resonate_index+1) << std::endl;
            
            if (search1.compare(search_string) == 0) {
                std::cout << "\t~:: matches search string." << std::endl;
                not_found = false;
                break;
            }
        } else {
            // std::cout << "~::!::~ error: search does not match search / cabinet is corrupted!" << std::endl;
            not_found = true;
            continue;
        }
    }

    if (not_found == false) {
        std::cout << std::endl;
        std::cout << search_string << " is:" << std::endl;
        std::cout << line1 << std::endl;
        std::cout << std::endl;
        std::cout << line2 << std::endl;
    }
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

void Brain::recall(std::string s) {  // recalls events
    std::string h;
    
    //this->search_catalogue_index(s);
    //this->search_index_code(h);
    //this->neural_net(s, h, 1); //neural_net(std::string s, std::string h, int cumulator)
};

void Brain::add_data() {    // adds data to a stored reference (store_reference())

};

void Brain::done_with_query() {
    this->done[0] = true;
};