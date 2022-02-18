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
};

void compare_query_str(std::string str) {   // handles the commands for the logic input
    if (str.compare("simulation") == false) {
        std::cout << std::endl << "~:: parameter request: simulation()." << std::endl;
        isSim = true;   // triggers Simulation in AI/AI.CPP
    } else if (str.compare("convert") == false) {
        std::cout << std::endl << "~:: parameter request: converter EURO()." << std::endl;
        isConvert = true;   // triggers converter EURO -> USD in AI/AI.CPP
    } else if (str.compare("convertd") == false) {
        std::cout << std::endl << "~:: parameter request: converter USD()." << std::endl;
        isConvertUSD = true;   // triggers converter from USD -> EURO in AI/AI.CPP
    } else if (str.compare("hash") == false) {
        std::cout << std::endl << "~:: parameter request: hash()." << std::endl;
        isHash = true;   // triggers hashing function in AI/AI.CPP
    } else if (str.compare("killc") == false) {
        std::cout << std::endl << "~:: parameter request: kill_chain()." << std::endl;
        isKill = true;   // triggers kill chain in AI/AI.CPP
    } else if (str.compare("stepping") == false) {
        std::cout << std::endl << "~:: parameter request: stepping_engine()." << std::endl;
        isStepping = true;   // triggers stepping() engine in AI/AI.CPP
    } else if (str.compare("rollout") == false) {
        std::cout << std::endl << "~:: parameter request: rollout()." << std::endl;
        isRollout = true;   // triggers rollout function in AI/AI.CPP
    } else if (str.compare("curl") == false) {
        std::cout << std::endl << "~:: parameter request: curl()." << std::endl;
        isCurl = true;   // triggers rollout function in AI/AI.CPP
    } else if (str.compare("bank") == false) {
        std::cout << std::endl << "~:: parameter request: track_account()." << std::endl;
        isBank = true;   // triggers rollout function in AI/AI.CPP
    }
};

// eof