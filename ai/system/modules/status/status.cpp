// AI/SYSTEM/MODULES/STATISTICS/STATUS.CPP  - USED BY (NOT USED YET!!!)

#include "status.h"

// cosmetical functions ;; for Statis *stt instance functions
void prt_statline1() {
    std::cout << std::endl;
    std::cout << "~:: status - status report :" << std::endl;
    std::cout << "    ----------------------" << std::endl;
};

void prt_statline2() {
    std::cout << "~:: ---------------------- :: ~" << std::endl;
    std::cout << std::endl;
};

// Status functions
void Status::init() {   // initializes Status object
    std::cout << std::endl;
    std::cout << "~:: Status init." << std::endl;

    // reporting nrs... (takes some time)
    this->definitions_nr = this->count_definitions();
    this->words_nr = this->count_words_in_definitions();
};

int Status::ret_word_count() {  // returns the words count of definitions
    return this->words_nr;
};

int Status::ret_def_count() {   // returns the number of definitions
    return this->definitions_nr;
};

void Status::prt_nr_of_stats() {    // prints stats nr being measured
    std::cout << std::endl;
    std::cout << "stats nr. being measured : " << this->measured << std::endl;
};

void Status::prt_nr_of_words() {    // prints number of words inside definitions catalogue
    std::cout << std::endl;
    std::cout << "nr. of words inside definitions catalogue : " << this->words_nr << std::endl;
};

int Status::count_words_in_definitions() {  // counts nr of words inside definitions catalogue
    // integers
    int count;

    std::ifstream fil;

    fil.open(file_with_definitions);

    // BUSY HERE






    fil.close();
};

int Status::count_definitions() {   // counts the nr of definitions.
    // ints
    int count = 0;
    
    // strings
    std::string ln;
    
    // file streams
    std::ifstream def;
    std::ofstream updated;

    // open files
    def.open(file_with_definitions);

    std::cout << std::endl;
    std::cout << "\t~:: Status::count_words() :" << std::endl;
    std::cout << "\t\t~:: counting number of definitions inside catalogue." << std::endl;
    
    // enumerate dbase with definitions
        // count lines in def (file_with_definitions)
    if (def.is_open() == true) {
        while (std::getline(def, ln)) {
            if (ln.compare("\n") == 0) {
                continue;
            }

            count++;
        }
    
        def.close();
        
        // open updated file with count of words to write updated count
        updated.open(wrds_count);
    } else {
        std::cout << std::endl;
        std::cout << "~:!:~ (error) :: Status::count_words() - file access :: def not open." << std::endl;
    }

    // close updated file with word count
    if (updated.is_open() == true) {
        updated << count << std::endl;
        updated.close();
    } else {
        std::cout << "\t~:: skipping update." << std::endl;
        std::cout << std::endl;
    }
    
    std::cout << "\t\t\t~:: updated (count) in relations (# = " << count << ")" << std::endl;

return count;
};

void Status::status_report() {  // reports on session / stats numbers.
    prt_statline1();    // prints "status report" line
    std::cout << " -= SESSION =-" << std::endl;
    std::cout << "   ---------" << std::endl;

    this->accumulate_status_report();



    prt_statline2();    // (ends status report) line
};

void Status::report() { // report on total nrs of stats being measured.
    prt_statline1();    // prints "status report" line

    // overal stats
    this->prt_nr_of_stats();
    this->prt_nr_of_words();
    
    prt_statline2();    // (ends status report) line

    // session
    this->status_report();  // reports on session
};

// eof