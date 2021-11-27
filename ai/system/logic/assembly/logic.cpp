// /AI/LOGIC/ASSEMBLY/LOGIC.CPP: USED BY /AI/LOGIC/ASSEMBLY/INPUT.H

#include <string>
#include <iostream>
#include "logic.h"

void commands(int x, std::string param) {

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
            std::cout << "x computation: ";
            
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
            std::cout << "type:char" << " len:" << param.length() << " ";
            std::cout << "vowels:" << vowels << " ";
            std::cout << "consonants:" << consonants << " ";
            std::cout << "special:" << special << " ";

            //std::cout << " " << std::endl;
            break;

        default:
            std::cout << "-:: was not supplied as function :: (NOP)";
            break;
    };
    std::cout << " ]" << std::endl;
};