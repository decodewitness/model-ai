// "/AI/SECURITY.CPP" - USED BY "/AI/AI.H"

//#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <unistd.h>

#include "privileges.cpp"

int security_level = 5; // max. is: security_level = 12;

std::string passcode = "ai";
const std::string model_ai = "model-ai";

// this decides if the function should compare the hashes (which assumably is only reasonable to both set it to "true")
bool hashed_credentials = true;    // hashes the inputted credentials
bool store_hashed_credentials = true;   // stores only hashed credentials

// credentials level of the active user
std::string level="user";

bool check_passcode(std::string pass) {
    std::cout << "(debug) checking passcode." << std::endl;
    
    // first hash passcode into hashcode
    //std::string hashcode = hashn(passcode);
    
    std::ifstream filen;

    std::cout << "~:: inside meta query." << std::endl;
    system("pwd");

    filen.open("data");

    std::string hashcode;
    filen >> hashcode;

    filen.close();

    std::cout << "(debug) hashcode: " << hashcode << " ";

    if (hashed_credentials == true) {
        std::cout << "hash: " << md5(pass) << std::endl;

        std::string usecase = md5(pass);
        if (usecase.compare(hashcode) == false) {
            std::cout << "-:: ACCESS GRANTED (level) (security_level)";
            
            // wait one second and set user access levels in the control
            sleep(1);
            level = set_privileges_user(user, check_key_privilege(pass));

            // export
            std::cout << "\t~::exporting to environment." << std::endl;
            system("export MODELAIAC=Y");

            // (optional) storing of (HASHED) credentials 
                // NEEDS CATALOGUE STILL
        } else {
            std::cout << "-:: ACCESS IS DENIED! (security_level) (" << security_level << ")" << std::endl;
            exit(0);
        }
    } else {
        if (pass.compare(passcode) == false) {
            std::cout << "-:: ACCESS GRANTED (level) (security_level)";
            
            // wait one second and set user access levels in the control
            sleep(1);
            level = set_privileges_user(user, check_key_privilege(pass));

            // export
            std::cout << "\t~::exporting to environment." << std::endl;
            system("export MODELAIAC=Y");

            // (optional) storing of credentials
                // ALSO NEEDS CATALOGUE STILL
        } else {
            std::cout << "hash: " << md5(pass) << std::endl;
            std::cout << "-:: ACCESS IS DENIED! (security_level) (" << security_level << ")" << std::endl;
            //exit(0);
        }
    }

    return true;
};

bool security_prompt() {
    
    std::string password;
    std::cout << "~:: security routine" << std::endl;
    
    //std::cout << std::endl << "ENV = " << secure_getenv("MODELAIAC") << std::endl;
    //std::cout << "MODELAIAC = " << x << std::endl;
    //std::cout << std::endl;

	std::cout << "ENTER PASSCODE: ";
    std::cin >> password;
    std::cout << std::endl;

    bool ack = check_passcode(password);

    return ack;
};
