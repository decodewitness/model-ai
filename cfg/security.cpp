#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>

int security_level = 1;
std::string passcode = "ai";
const std::string model_ai = "model-ai";

void check_passcode(std::string pass) {
    //std::string environment_var = getenv(model_ai.c_str());

    if (/*environment_var.compare("setenv-aok") == false || */pass.compare(passcode) == false) {
        std::cout << "-:: ACCESS GRANTED" << std::endl;
        setenv("_MODEL_AI_AG", "Y", 1);
        std::string x = getenv("_MODEL_AI_AG");
    } else {
        std::cout << "-:: ACCESS IS DENIED!" << std::endl;
        exit(0);
    }
}