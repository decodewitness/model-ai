// "/AI/SYSTEM/MODULES/COMBINE.CPP" - USED IN "/AI/SYSTEM/MODULES/MODULAR.CPP" FOR THE (MODEL-AI) PROGRAM.

#include <string>
#include <iostream>

class Combine { // combine string class

    private:
        std::string var_1;
        std::string var_2;

        std::string c;

        bool x; // var_1 is set if true
        bool y; // var_2 is set if true
        bool z; // c is set if true

    public:
        Combine();
        
        void setB(std::string a, std::string b);
        void setOne(std::string a);
        void setTwo(std::string b);

        int add(std::string s);
        void store();
};


// CombineModule / Class to combine two moduleContainer
class CombineModule {

private:
    int sizeModule1;
    int sizeModule2;
    int sizeModules;

    std::string module1;
    std::string module2;

    moduleContainer *data;
    /* moduleContainer {
            std::string containerName;
            int containerSize;
            char *data;
        }
    */

public:

    CombineModule();
    moduleContainer combine(moduleContainer one, moduleContainer two);
    int recount(moduleContainer one, moduleContainer two);

};
