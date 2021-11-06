// "/AI/SECURITY.CPP" - USED BY "/AI/AI.H"

//#include <cstdio>
#include <iostream>
#include <string>
#include <stdlib.h>

int security_level = 1;
std::string passcode = "ai";
const std::string model_ai = "model-ai";

bool check_passcode(std::string pass) {
    
    std::cout << "(debug) checking passcode." << std::endl;

    if (pass.compare(passcode) == false) {
        std::cout << "-:: ACCESS GRANTED" << std::endl;

        std::cout << "\t~::exporting to environment." << std::endl;
        system("export MODELAIAC=Y");
    } else {
        std::cout << "-:: ACCESS IS DENIED!" << std::endl;
        exit(0);
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
