// AI/SYSTEM/MODULES/STATISTICS/STATUS.CPP  - USED BY (AI/AI.H)

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

    std::cout << "\t~:: stats_is_active (true)" << std::endl;
    stats_is_active = true;

    this->reported_stats = 0;
    this->measured = max_stats;

    // reporting nrs... (takes some time)
    this->definitions_nr = this->count_definitions();
    this->words_nr = this->count_words_in_definitions();
    
    // generate report
    this->status_report();    
};

int Status::ret_word_count() {  // returns the words count of definitions
    return this->words_nr;
};

int Status::ret_def_count() {   // returns the number of definitions
    return this->definitions_nr;
};

void Status::numbers() {
    std::cout << std::endl;
    std::cout << "~:: (stats / numbers) : " << std::endl;
    std::cout << "\t(++)\t d:" << this->ret_def_count() << " w:" << this->ret_word_count() << std::endl;
}

void Status::prt_nr_of_stats() {    // prints stats nr being measured  // used by this->report()
    std::cout << std::endl;
    std::cout << "\t~:: stats nr. being measured : " << this->measured << std::endl;
    std::cout << "\t\t*--stats reporting (" << this->reported_stats << ")" << std::endl;
};

void Status::prt_nr_of_words() {    // prints number of words inside definitions catalogue  // used by this->report()
    std::cout << std::endl;
    std::cout << "\t~:: nr. of words inside definitions catalogue : " << this->words_nr << std::endl;
};

int Status::count_words_in_definitions() {  // counts nr of words inside definitions catalogue
    // integers
    int count=0;
    
    // chars
    // char ch;

    // strings
    std::string ln;
    std::string word;

    // file streams
    std::ifstream fil;

    // open file
    fil.open(file_with_definitions);

    std::cout << std::endl;
    std::cout << "~:: count_words_in_definitions() :" << std::endl;

    // loop over file
    while (getline(fil, ln)) {

        if (ln.back() == '\n') {

            if (ln.length() <= 2) {
                continue;
            } else {
                ln.pop_back();

                if (ln.back() == ';' && ln.length() > 3) {  // result after function should be sequential every pure definition from the catalogue
                    ln.pop_back();
                    ln.pop_back();

                    for (int i=0; i<3; i++) {
                        size_t pos = ln.find_first_of("\"");
                        if (pos != std::string::npos) {
                            std::cout << "\% DEBUGGING!!! -> chopping( " << ln << " )" << std::endl;
                            ln.erase(0, pos);
                        }
                    }
                    int c = getchar();

                    std::istringstream ss(ln);
                    while (ss >> word) {
                        count++;
                    }

                }
            }
        }
    }

    std::cout << std::endl;
    std::cout << "\t~:: words in definitions : ( " << count << " )" << std::endl;

    // close file
    fil.close();

    // report this stat enhancement
    this->reporting();

return count;
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

    // report this stat enhancement
    this->reporting();

return count;
};

void Status::status_report() {  // reports on session / stats numbers.
    int x=0;
    
    prt_statline1();    // prints "status report" line
    std::cout << " -= SESSION =-" << std::endl;
    std::cout << "   ---------" << std::endl;

    x = this->accumulate_status_report();

    switch (x) {
        case 0:
            std::cout << "- zero logic." << std::endl;
            break;

        case 1:
            std::cout << "- definitions : " << this->definitions_nr << std::endl;
            break;

        case 2:
            std::cout << "- words (total): " << this->words_nr << std::endl;
            break;

        case 3:
            std::cout << "- definitions : " << this->definitions_nr << std::endl;
            std::cout << "- words (total) : " << this->words_nr << std::endl;
            break;

        default:
            std::cout << std::endl;
            std::cout << "~:!:~ (error) status_report() - abnormal case :: skipping logic here!" << std::endl;
            std::cout << std::endl;
            break;
    };

    // end the status report for the session
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

int Status::accumulate_status_report() {    // generates report for status (session)
    double wrd = this->words_nr;
    double def = this->definitions_nr;

    int x = 0;  // return value

    double avg = 0;    // average number of words per definition

    std::cout << std::endl;
    std::cout << "~:: accumulate_status_report()" << std::endl;
    
    if (def > 0 && wrd > 0) {
        x = 3;
        avg = wrd / def;    // calculate average
    } else if (wrd > 0) {
        x = 2;
    } else if (def > 0) {
        x = 1;
    }

    // debugging information
    std::cout << "\t~:: x(#) def:wrd {" << x << "}" << std::endl;
    
    // calculate average
        // also report this stat enhancement
    if (avg != 0) {
        std::cout << "(average) : " << avg << " number of words per definition." << std::endl;
        
        // report this stat enhancement
        this->reporting();
    }

    sleep(1);
    std::cout << std::endl;

return x;
};
// eof