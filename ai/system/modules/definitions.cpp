
// OBSOLETE FILE - HAS BEEN MOVED TO AI.CPP

// /AI/SYSTEM/MODULES/DEFINITIONS.H - USED BY /AI/AI.H

#include <string>

#include "definitions.h"

// MODULES DEFINITIONS AND DECLARATIONS
std::string moduleName[module_limits];
std::string data[module_limits];

const int module_limits = 1024;


// INSERT MODULE IN ModuleName[] ARRAY
    // THIS SHOULD NOT BE HIGHER IN AN ARRAY THAN THE module_limits IS SET TO
std::string moduleName[0] = "--speech synthesizers--";
std::string moduleName[1] = "--      sensors      --";
std::string moduleName[2] = "--pattern recognition--";
std::string moduleName[3] = "--artificial life rtn--";
std::string moduleName[4] = "--       drums       --";
std::string moduleName[5] = "--natural language pr--";
std::string moduleName[6] = "--catalogues routines--";
std::string moduleName[7] = "--health & life cycle--";
std::string moduleName[8] = "--        ocr        --";
std::string moduleName[9] = "--image & translation--";
// LAST MODULE TO SET THE LIMIT IN ARRAY (PLEASE ALSO SPECIFY THE modulesTotal NUMBER EQUAL TO THE LAST MODULE)
std::string moduleName[10] = "--      _EOM        --"; // COUNT ON THIS AND NOT THE VARIABLE "module_limits"

int modulesTotal = 10;  // this should be equal to the index of the "EOM" module (IN THE HIGHEST INDEX OF MODULENAME / THE INDEX AFTER THE LAST MODULE)
int dataTotal = 10; // this should be equal to the number of files in the "data[]" array

// FIT DATA INTO data[] ARRAY
std::string data[0] = "speech.csv";
std::string data[1] = "sensor_reading.csv";
std::string data[2] = "pattern_recognition.csv";
std::string data[3] = "artificial_life.csv";
std::string data[4] = "drums.csv";
std::string data[5] = "natural_language_processing.csv";
std::string data[6] = "catalogues.csv";
std::string data[7] = "health_criteria.csv";
std::string data[8] = "ocr.csv";
std::string data[9] = "images_translation.csv";
// PLACEHOLDER INSIDE LAST MODULE AGAIN
std::string data[10] = "__REACHED_EOM_THE_LAST_MODULE";
