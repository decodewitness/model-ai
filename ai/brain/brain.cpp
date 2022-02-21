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

// inside of canopy
    this->file_access(1);
};

Brain::~Brain() {
    if (this->access.is_open()) {
        this->access.close();
        this->access_is_open = false;
    }
    if (this->outfile.is_open() == true) {
        this->outfile.close();
    }
};

// technicalities
void Brain::file_access(int level) {

    if (level == 2) {
        this->outfile.open(store_file);
    }

    if (this->access_is_open == false) {
        this->access.open(store_reference_file);
    }
    
    if (this->access.is_open()) {
        this->access_is_open = true;
    } else {
        system("pwd");
        std::cout << std::endl << "~::!::~ Error :: (Brain::file_access)->" << store_file << " ~:: error opening file." << std::endl;
    }

    // logic with "level" access here
};   

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
        this->file_access(3);
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
    this->search(logic, 3);
}

// access
void Brain::store_reference(std::string s) { // handles data // resonate_index
    // inside of brain (cabinet)
    this->store_filename = store_reference_file;
    this->file_access(2);
    
    // store string s in temporary catalogue or vector
    outfile << s << std::endl;
    outfile.close();
};

// data
void Brain::arrange() { // arranges data in cabinet // alphabetical sequence
    // arrange here
};

void Brain::search(std::string logic, int n) { // search cabinet    // n is default 1   // n is resonate index
    std::string line;
    std::string search;
    std::string search_string = logic;
    int counter=0;
    int resonate_index = 0;
    int resonate_index_max = n;  // last index in cabinet according to reference

    // has access cabinet
    if (!this->access_is_open && this->access.is_open() == false) {
        this->file_access(3);
    }

    // start from index in cabinet
    this->access.seekg(SEEK_SET);

    std::cout << std::endl;
    std::cout << "~:: searching indexes." << std::endl;
    std::cout << "\t::";

    // mark search term
    for (int i=0; i<resonate_index_max; i++) {
        this->access >> search;
        
        // read rest of line here
        std::getline(access, line);

        // continue
        if (search.compare(search_string) == 0) {
            std::cout << " hit(" << i << ")";
            counter++;

            // do logic
            this->store_reference(line);    // stores the line in temporary catalogue or vector
        }
    }

    // count to index resonate_frequency_max
    for (int i=0; i<resonate_index_max; i++) {

    }

    std::cout << std::endl;
};

void Brain::recall() {  // recalls events

};

void Brain::add_data() {    // adds data to a stored reference (store_reference())

};

void Brain::done_with_query() {
    this->done[0] = true;
};