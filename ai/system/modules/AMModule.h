// "/AI/SYSTEM/MODULES/AMMODULE.H" - USED BY "/AI/SYSTEM/MODULES/AMMODULE.CPP"

#include <string>

class AMModule {

private:
    int j;
    std::string r;
    std::string s;
    std::string x;


    int k;
    int l;
    int m;
    
    int rnd;

public:
    AMModule();

    void addStringR(std::string r);
    void addStringS(std::string s);
    
    void addni(int n);
    void addnj(int n);

    void combine();
    void combinen();

    // loader for modules
    bool loader(std::string filen);

    void seedRNG10();
    void seedRNG100();

    int getRNG();

    void nrs(int max, int x, int limits); // x heavy numbers sequence
    void incrementalNrs(int max, int x); // another heavy numbers sequence

    std::string returnProduct(); // don't return into x as product that is futile
    int returnProductn(); // don't return to k as product that is futile
};