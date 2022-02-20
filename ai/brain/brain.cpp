// AI/BRAIN/BRAIN.CPP   -- NOT USED YET!!!
#include "brain.h"

Brain::Brain() {
// store_reference
    //int resonate iNumber
    this->resonate_index = starting_index;
    this->descriptor = false;
    this->keep_alive = false;

    this->set2 = 0;

// inside of canopy
    this->file_access(1);
};

// technicalities
void Brain::file_access(int level) {

    if (this->access_is_open == false) {
        this->access.open(store_reference_file);
    }    

    if (access.is_open() == true) {
        this->access_is_open = true;

        if (level >= 3) {
            // do logic
            this->keep_alive = true;

        } else if (level < 3 && level < 9) {
            // label descriptor;
            this->descriptor=true;
        } else if (level >= 9 && level < 99) {
            // skip step for now

        } else if (level == 99) { this->access.close(); }

        // could also keep open for duration of the program depending on the brain logic
    } else {
        std::cout << std::endl << "~::!::~ error opening file." << std::endl;
    }    
};

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
        this->set2++;
        // add trailing handles
            // need to keep into account number of lines to skip from main index (1st line)
        this->procure(max_index - this->handles);   // results in sum   // creates research "set2"

        // rebuild database catalogue
        this->research(set2);
    }

    this->handles = max_index;

    // reset file handle
    for (int i=0; i<max_index; i++) {
        // get a fix on line number

    }
};

void Brain::research(int x) {
    int nr_of_sets = x;

    // need to open files or catalogue

    for (int i=0; i< nr_of_sets; i++) {
        std::cout << "~:: researching batch number: " << (i+1) << std::endl;
        sleep(1);
    }
};

void Brain::procure(int nr=1) {
    // default (nr=1) procures 1 line back from the log

    // process data
    if (nr < 11) {
        for (int i=1; i<this->handles && i<=nr; i++) {

        }
    }

    // compare with old data

    // update this->handles
}

void Brain::useBrain() {
    // logic think
    // access cabinet with search method

    std::string logic = "logic";
    this->search(logic);
}

// access
void Brain::store_reference(int resonate_iNumber) { // handles data // resonate_index
    // inside of brain (cabinet)
    this->store_filename = store_reference_file;
    file_access(3);
};

// data
void Brain::arrange() { // arranges data in cabinet // alphabetical sequence

};

void Brain::search(std::string logic, int n) { // search cabinet    // n is default 1   // n is resonate index
    // has access cabinet
    
    // start from index in cabinet
    
    int resonate_frequency_max = n;  // last index in cabinet according to reference
};

void Brain::recall() {  // recalls events

};

void Brain::add_data() {    // adds data to a stored reference (store_reference())

};

void Brain::done_with_query() {
    this->done[0] = true;
};