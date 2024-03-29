// /AI/LOGIC/ASSEMBLY/LOGIC.CPP: USED BY /AI/LOGIC/ASSEMBLY/INPUT.H

#include <stdio.h>
#include <iostream>
#include <string>

#include "logic.h"

void commands(int x, std::string param) {

    void compare_query_str(std::string str);

    // used in x computation
    int consonants=0;
    int vowels=0;
    int special=0;

    // list attributes of string
    std::cout << "\t[ ";
    
    switch(x) {
        case 1: // param length
            std::cout << "len: " << param.length();
            break;
        
        case 2: // param attributes
            std::cout << "attr: ";
            std::cout << "len(" << param.length() << ")";
            break;

        case 3: // computations for x coordinate
            std::cout << "simple x computation: ";
            
            // formulate x computations
            for (int i=0, j=0; i<param.length(); i++) {
                if (param[i] == 'a' || param[i] == 'i' || param[i] == 'e' || param[i] == 'o' || param[i] == 'u') {
                    consonants++;
                } else if (param[i] != '!' && param[i] != '@' && param[i] != '#' && param[i] != '$' && param[i] != '%' && param[i] != '^' && param[i] != '&' && param[i] != '*' && param[i] != '(' && param[i] != ')' && param[i] != '-' && param[i] != '_' && param[i] != '+' && param[i] != '=' && param[i] != '\\' && param[i] != '/' && param[i] != '?' && param[i] != '\'' && param[i] != '"' && param[i] != ';' && param[i] != ':' && param[i] != '[' && param[i] != ']' && param[i] != '}' && param[i] != '{' && param[i] != '|' && param[i] != '>' && param[i] != '<' && param[i] != ',' && param[i] != '.' && param[i] != '~' && param[i] != '`') {
                    vowels++;
                } else {
                    special++;
                }
            }
            
            // draw x computation here
            std::cout << "type:[char]: len:" << param.length() << " ";
            std::cout << "vowels:" << vowels << " ";
            std::cout << "consonants:" << consonants << " ";
            std::cout << "special:" << special << " ";

            //std::cout << " " << std::endl;
            compare_query_str(param);
            break;

        default:
            std::cout << "-:: was not supplied as function :: (NOP)";
            break;
    };
    std::cout << " ]" << std::endl;

    // do logic

};

// find these commands in logic.h and the query() function in ai.cpp..!!!
    // logic.h, logic.cpp, ai/ai.cpp ;
void compare_query_str(std::string str) {   // handles the commands for the logic input
    if (str.compare("/test") == false) {
        std::cout << std::endl << "~:: testing parameters request: test()." << std::endl;
        isTest = true;
    } else if (str.compare("/testA") == false || str.compare("/testa") == false) {
        std::cout << std::endl << "~:: testing parameters: testA()." << std::endl;
        isTestA = true;   // triggers testing function (AI::testA)
    } else if (str.compare("/testB") == false || str.compare("/testb") == false) {
        std::cout << std::endl << "~:: testing parameters: testB()." << std::endl;
        isTestB = true;   // triggers testing function (AI::testB)
    } else if (str.compare("/sim") == false || str.compare("/simulation") == false) {
        std::cout << std::endl << "~:: parameter request: simulation()." << std::endl;
        isSim = true;   // triggers Simulation in AI/AI.CPP
    } else if (str.compare("/convert") == false) {
        std::cout << std::endl << "~:: parameter request: converter EURO()." << std::endl;
        isConvert = true;   // triggers converter EURO -> USD in AI/AI.CPP
    } else if (str.compare("/convertd") == false) {
        std::cout << std::endl << "~:: parameter request: converter USD()." << std::endl;
        isConvertUSD = true;   // triggers converter from USD -> EURO in AI/AI.CPP
    } else if (str.compare("/hash") == false) {
        std::cout << std::endl << "~:: parameter request: hash()." << std::endl;
        isHash = true;   // triggers hashing function in AI/AI.CPP
    } else if (str.compare("/killc") == false) {
        std::cout << std::endl << "~:: parameter request: kill_chain()." << std::endl;
        isKill = true;   // triggers kill chain in AI/AI.CPP
    } else if (str.compare("/stepping") == false) {
        std::cout << std::endl << "~:: parameter request: stepping_engine()." << std::endl;
        isStepping = true;   // triggers stepping() engine in AI/AI.CPP
    } else if (str.compare("/rollout") == false) {
        std::cout << std::endl << "~:: parameter request: rollout()." << std::endl;
        isRollout = true;   // triggers rollout function in AI/AI.CPP
    } else if (str.compare("/curl") == false) {
        std::cout << std::endl << "~:: parameter request: curl()." << std::endl;
        isCurl = true;   // curl website (input URL)
    } else if (str.compare("/bank") == false) {
        std::cout << std::endl << "~:: parameter request: track_account()." << std::endl;
        isBank = true;   // triggers accounting features
    } else if (str.compare("/table") == false) {
        std::cout << std::endl << "~:: parameter request: table()." << std::endl;
        isTable = true;   // displays math table of #
    } else if (str.compare("/tableto") == false) {
        std::cout << std::endl << "~:: parameter request: tableTo()." << std::endl;
        isTableTo = true;   // displays math table of # to #max
    } else if (str.compare("/dice") == false) {
        std::cout << std::endl << "~:: parameter request: dice_pr()." << std::endl;
        isDice = true;   // prints dice numbers
    } else if (str.compare("/dice2") == false) {
        std::cout << std::endl << "~:: parameter request: dice_npr()." << std::endl;
        isDice2 = true;   // prints dice numbers
    } else if (str.compare("/stat") == false) {
        std::cout << std::endl << "~:: parameter request: stat_dir()." << std::endl;
        isStat = true;   // triggers stat function for files/directories
    } else if (str.compare("/rm") == false) {
        std::cout << std::endl << "~:: parameter request: rm()." << std::endl;
        isRm = true;   // triggers remove function for files in the system hierarchy
    } else if (str.compare("/cp") == false) {
        std::cout << std::endl << "~:: parameter request: cp()." << std::endl;
        isCp = true;   // triggers copy function for files in the system hierarchy
    } else if (str.compare("/+") == false) {
        std::cout << std::endl << "~:: parameter request: add()." << std::endl;
        isAdd = true;   // adds parameters
    } else if (str.compare("/-") == false) {
        std::cout << std::endl << "~:: parameter request: subtract()." << std::endl;
        isSubtract = true;   // subtracts parameters
    } else if (str.compare("/*") == false) {
        std::cout << std::endl << "~:: parameter request: multiply()." << std::endl;
        isMultiply = true;   // multiplies parameters
    } else if (str.compare("//") == false) {
        std::cout << std::endl << "~:: parameter request: divide()." << std::endl;
        isDivide = true;   // divides parameters
    } else if (str.compare("/pow") == false) {
        std::cout << std::endl << "~:: parameter request: power()." << std::endl;
        isPower = true;   // calculates power
    } else if (str.compare("/playf") == false) {
        std::cout << std::endl << "~:: parameter request: play_audio_file()." << std::endl;
        isPlayAudio = true;   // triggers play audio file
    } else if (str.compare("/punch") == false) {
        std::cout << std::endl << "~:: parameter request: return_punch()." << std::endl;
        isReturnPunch = true;   // triggers return punch calculator
    } else if (str.compare("/prpunch") == false) {
        std::cout << std::endl << "~:: parameter request: print_punch()." << std::endl;
        isPrintPunch = true;   // triggers print/punch calculator
    } else if (str.compare("/help") == false) {
        std::cout << std::endl << "~:: parameter request: help()." << std::endl;
        isHelp = true;   // triggers displaying help text
    } else if (str.compare("/version") == false) {
        std::cout << std::endl << "~:: parameter request: version()." << std::endl;
        isVersion = true;   // triggers displaying version
    } else if (str.compare("/add_data") == false) {
        std::cout << std::endl << "~:: parameter request: add_data()." << std::endl;
        isAddData = true;   // triggers the add_data_to_brain_manually method
    } else if (str.front() != '/') {
        std::cout << "]" << std::endl << std::endl;
        std::cout << "[ -- you're asking my input --";
        isLogic = true;
    } else if (str.compare("/convert_data") == false) {
        std::cout << std::endl << "~:: parameter request: convert_data()." << std::endl;
        isConvertData = true;   // triggers the convert_datas function
    } else if (str.compare("/run_tube") == false) {
        std::cout << std::endl << "~:: parameter request: run_tube()." << std::endl;
        isRunPytube = true;     // triggers the AI::run_tube() method
    } else if (str.compare("/audio_toggle") == false) {
        std::cout << std::endl << "~:: parameter request: toggle_audio()." << std::endl;
        isToggleAudio = true;
    } else if (str.compare("/passwd") == false) {
        std::cout << std::endl << "~:: parameter request: store_new_credentials()." << std::endl;
        isNewCred = true;
    } else if (str.compare("/list_cred") == false) {
        std::cout << std::endl << "~:: parameter request: list_credentials()." << std::endl;
        isListCred = true;
    } else if (str.compare("/menu") == false) {
        std::cout << std::endl << "~:: parameter request: menu()." << std::endl;
        isMenu = true;
    } else if (str.compare("/clear metas") == false) {
        std::cout << std::endl << "~:: parameter request: clear_que()." << std::endl;
        isClearQue = true;
    } else if (str.compare("/learned") == false) {
        std::cout << std::endl << "~:: parameter request: whatHaveYouGot()." << std::endl;
        isWhatHave = true;
    } else if (str.compare("/what") == false) {
        std::cout << std::endl << "~:: parameter request: whatHaveYouGot()." << std::endl;
        isWhatHave = true;
    } else if (str.compare("/answer") == false) {
        std::cout << std::endl << "~:: parameter request: answer()." << std::endl;
        isAnswer = true;
    } else if (str.compare("/list") == false) {
        std::cout << std::endl << "~:: parameter request: listConvos()." << std::endl;
        isTalk = true;
    } else if (str.compare("/export_backlog1") == false) {
        std::cout << std::endl << "~:: parameter request: export_backlogs(1)." << std::endl;
        isExportBL = true;
        isExportBL1 = true;
    } else if (str.compare("/export_backlog2") == false) {
        std::cout << std::endl << "~:: parameter request: export_backlogs(2)." << std::endl;
        isExportBL = true;
        isExportBL2 = true;
    } else if (str.compare("/export_backlogs") == false) {
        std::cout << std::endl << "~:: parameter request: export_backlogs(both)." << std::endl;
        isExportBL = true;
        isExportBL1 = true;
        isExportBL2 = true;
    } else if (str.compare("/buildref") == false) {
        std::cout << std::endl << "~:: parameter request: buildRef()." << std::endl;
        isBuildRef = true;
    } else if (str.compare("/readref") == false) {
        std::cout << std::endl << "~:: parameter request: readRef(n)." << std::endl;
        isReadRef = true;
    } else if (str.compare("/readrefs") == false) {
        std::cout << std::endl << "~:: parameter request: readRefs()." << std::endl;
        isReadRefs = true;
    } else if (str.compare("/lastref") == false) {
        std::cout << std::endl << "~:: parameter request: readLastRef()." << std::endl;
        isReadLastRef = true;
    } else if (str.compare("/refnumber") == false) {
        std::cout << std::endl << "~:: parameter request: export_backlogs()." << std::endl;
        isReturnRefNr = true;
    } else if (str.compare("/log") == false) {
        std::cout << std::endl << "~:: parameter request: qlog()." << std::endl;
        isQLog = true;
    }
};

std::string chain(std::string s) {
    std::string c;
// still building this funnction

    return c;
}

// eof