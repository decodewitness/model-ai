class AMModule {

private:
    int j;
    string r;
    string s;
    string x;

    int i;
    int j;
    int k;

    int rnd;

public:
    AMModule();

    void addStringR(string r);
    void addStringS(string s);
    
    void addni(int n);
    void addnj(int n);

    void combine();
    void combinen();

    void seedRNG10();
    void seedRNG100();

    int getRNG();

    void nrs(int max, int x); // heavy numbers sequence
    void incrementalNrs(int max, int x); // another heavy numbers sequence
    
    string returnProduct(); // don't return into x as product that is futile
    int returnProductn(); // don't return to k as product that is futile
};