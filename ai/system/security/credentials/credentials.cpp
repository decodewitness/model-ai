#include <iostream>
#include <string>
#include <fstream>

//#include "../md5/md5.cpp";

using namespace std;

#define STORE "ai/system/security/db/db"

void AI::list_credentials() {
    std::ifstream fs;
    std::string cred;
    fs.open(STORE);
    fs >> cred;
    std::cout << std::endl << "~:(creds) list:~" << std::endl;
    std::cout << std::endl << "\t~:(1) ::\t" << cred << std::endl;
    // std::cout << "~:2: " << md5(cred) << std::endl;

    fs.close();
};

void AI::store_new_credentials() {
    std::ofstream fs;
    std::string cred;
    std::string shadow;
    std::cout << std::endl << "(creds management)" << std::endl;
    std::cout << std::endl;
    std::cout << "ENTER NEW PASS  : ";
    cin >> cred;
    std::cout << "REPEAT NEW PASS : ";
    cin >> shadow;
    if (cred.compare(shadow) == 0) {
        system("cat ai/system/security/db/db >> ai/system/security/db/db.old.creds");
        fs.open(STORE);
        fs << md5(cred);
        fs.close();
        std::cout << std::endl << "~[:] hashed & written credentials." << std::endl;
    }
};