// AI/SYSTEM/MODULES/STATUS/STATUS.H    -   USED BY "AI/SYSTEM/MODULES/STATUS/STATUS.CPP"

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <sstream>

bool stats_is_active = false;   // true if there is a Status class object
int max_stats = 3;  // increase this number according to the measured number of stats   // later assign automatic by stat->reporting()

const std::string def_count = "ai/definitions/def_count";
const std::string wrds_count = "ai/definitions/wrds_count";
const std::string definitions_index = "ai/definitions/def_index";
const std::string file_with_definitions = "ai/definitions/definitions";

// Status 
class Status {
private:
    int definitions_nr;    // number of definitions.
    int words_nr;      // number of words in definitions.
    int measured;   // measured number of stats.
    int reported_stats; // stats that gave feedback.

public:
    // constructor / destructor
    Status() { this->init(); }
    ~Status() { stats_is_active = false; }

    // initialization
    void init();        // initializes Status object.
    
    // counter functions
    int count_words_in_definitions();  // counts the number of words inside "file_with_definitions".
    int count_definitions();    // counts the number of definitions.

    // efficiency
    void count() { int x = this->count_definitions(); int y = this->count_words_in_definitions(); }  // does both the counter functions.

    // reporting
    int ret_def_count();    // returns this->definitions_nr.
    int ret_word_count();   // returns "this->words".
    int accumulate_status_report(); // gathers session status info.
    void numbers(); // reports on already gathered stat count for definitions/-words numbers
    void reporting() { this->reported_stats += 1; } // returns from tracked stats (they invoke this function if they are being tracked)

    // printing stats
    void report();          // report on all statistics.
    void status_report();   // report on session/status report.
    void prt_nr_of_stats(); // prints the number of stats that is being measured.
    void prt_nr_of_words(); // prints the number of words inside the "file_with_definitions".

} *stt; // stt is used as the main object pointer for the Status class

// eof