// /AI/MODULAR_BAY/GLOB.CPP - USED BY /AI/MODULAR_BAY/MODULAR_BAY.H

#include <glob.h>
#include <vector>
#include <string>
#include <iostream>

inline std::vector<std::string> glob(const std::string& pat){
    using namespace std;
    glob_t glob_result;
    glob(pat.c_str(),GLOB_TILDE,NULL,&glob_result);
    vector<string> ret;

    std::cout << "\t\t   :: files in directory ::" << std::endl;
    
    for(unsigned int i=0;i<glob_result.gl_pathc;++i){
        ret.push_back(string(glob_result.gl_pathv[i]));
    
        // print results
        std::cout << "\t\t\t - " << string(glob_result.gl_pathv[i]) << std::endl;
    }
    globfree(&glob_result);
    return ret;
}