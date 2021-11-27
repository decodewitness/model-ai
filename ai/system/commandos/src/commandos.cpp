// -- COMMANDOS SCRIPT -- AI/SYSTEM/COMMANDOS/COMMANDOS.CPP -- USED BY "<NONE>"
    // SCRIPT FOR RUNNING SHELL COMMANDS

// HEADER
#include <iostream>

const char VERSION[] = "v.0.0-1a";

using namespace std;

int main(int argc, char *argv[]) {

    // CALLS !comodo! SCRIPT which hails MODEL-AI runtime SCRIPT

    switch (argc) { // filter arguments

        case 1: // when run with no arguments parses this to comodo
            
            cout << "ai" << "!!"; // announce (should be function or version)

            system("pwd"); // prints working directory

            cout << endl << "~ :--parser:--passing arguments" << endl;
            
            // running arguments here
            system("ai/bin/commandos --version");
            system("ai/bin/comodos");
            cout << endl;
            break;
        
        case 2: // with 2 args prints the version
            cout << "Commandos_" << VERSION << endl;

        default:
            cout << "argument1"
                    << "\n"
                        << "argument2"
                            << "\n"
                                << "argument3"
                                    << "\n";
            break;
    };

return 0;
}
// EOF