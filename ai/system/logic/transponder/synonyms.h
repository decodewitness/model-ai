// AI/SYSTEM/LOGIC/TRANSPONDER/SYNONYMS.H -- USED BY "AI/SYSTEM/LOGIC/TRANSPONDER/TRANSPONDER.H"

// header file includes
#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

// file with the list of synonyms
std::string synonym = "ai/data/files/synonyms.txt";

std::string synonyms(std::string q) {    // que is term for looking up synonyms thereof
    
    // variables
    int nr_of_synonyms; // the number of actual synonyms for term
    // bools
    bool hitCorrectChar=false, hitTerm=false;
    // strings
    std::string line;   // line from synonyms file
    std::string one, two, three, four, five;  // number of possible synonyms for the 1st term (one should equal q)
    std::string term, nop="0";
    std::string str1;
    std::string str2;
    std::string str3;
    
    // vectors
    std::vector<std::string> result;

    // file streams
    std::ifstream syno;
    syno.open(synonym);

    if (syno.is_open() == true) {
        std::cout << std::endl << "~:: iterating synonyms for: \"" << q << "\"" << std::endl;
        
        while (getline(syno, line)) {
            str1 = line;
            str2 = q;

            str1.append("\t");

            std::string syn;
            //std::cout << "(debug) str1 : " << str1 << std::endl;

            std::stringstream s_stream(str1); //create string stream from the string
            
            while(s_stream.good()) {
                std::string substr;
                std::getline(s_stream, substr, '\t'); //get first string delimited by comma
                result.push_back(substr);
            }
            
            for(int i = 0; i<result.size(); i++) {    //print all splitted strings
                // DEBUGGING INFORMATION
                //std::cout << result.at(i) << std::endl;
                
                str3 = result.at(i);
                // transform char to lower case
                str2[0] = tolower(str2[0]);
                str3[0] = tolower(str3[0]);
                line[0] = tolower(line[0]);

                if (str2.compare(str3) == 0) {
                    std::cout << std::endl << "HiT!" << std::endl;
                    hitTerm = true;
                }

                    // DEBUGGING INFORMATION
                    // if (hitTerm == true) {
                    //     std::cout << std::endl;
                    //     std::cout << "\thit term in db : ";
                    //     std::cout << std::endl;
                    //     std::cout << "\t" << str1 << std::endl << str2 << std::endl << str3 << std::endl;
                    //     sleep(2);
                    //     break;
                    // }
                
                if (hitTerm == true) {
                        break;
                }
            }
            
            if (hitTerm == true) {  // break out of 2nd loop if hit correct term in syno
                break;
            }

            // break even
            if (hitCorrectChar == true && (line.front() != q.front())) {
                hitCorrectChar = false;
                if (syno.is_open() == true) {
                    syno.close();
                }
                break;
            }
        }

        // combine synonyms into one string for return statement
        if (hitTerm == true) {
            term = str1;
            hitTerm = false;
        } else {
            term = nop;
            hitTerm=false;
        }
    }

    if (syno.is_open() == true) {
        syno.close();
    }

return term;
}                        // syno >> two;
                        // syno >> three;
                        // syno >> four;
                        // syno >> five;
                        
                        // two = tolower(two[0]);
                        // three[0] = tolower(three[0]);
                        // four[0] = tolower(four[0]);
                        // five[0] = tolower(five[0]);

                        // std::cout << str3 << " " << two << " " << three << " " << four << " " << five;
                        // std::cout << std::endl;
// eof

