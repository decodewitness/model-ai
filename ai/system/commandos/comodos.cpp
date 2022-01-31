// /AI/SYSTEM/COMMANDOS/COMODOS.CPP -- STANDALONE INTERPRETER/PARSER PROGRAM FOR "MODEL-AI" PROGRAM "RUNTIME" (INTERFACE)

#include <iostream>
#include <fstream>
#include <string>

#include "varab.h"
#include "varan.h"

// *    .    * //
//* *COMODOS* *//
// *    .    * //
// INTERPRETER //
//     &&      //
//   PARSER    //
//     &&      //
//  INTERFACE  //
//*   * . *   *//

    /*~+=+ model_a_i )(_'_>~<
  //    //       //
_/   //7*/        //*7

using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    ifstream fs;
    
    cout << std::endl << "~=::COMODOS:_'>" << VERSION[1] << endl;

    if (argc >= 2) {
        fs.open(argv[1],ios::in);
    }

    if (fs.is_open())
    {
        while(getline(fs,line))
        {
            std::cout<<line<<endl;

            // anounce
            std::cout << "\t~varan: " << std::endl << "\t";
            
            // parse commands into main program
            std::cout << commands[0] << commands[1] << commands[2]
                        << commands[3] << commands[4]  << commands[5]
                            << commands[6] << commands[7]  << commands[8]
                                << commands[9] << commands[10];
        }
    }
    fs.close();

return 0;
}

// eof