#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const char store_reference_file[] = "intelligence/cabinet";
const int starting_index = 1;

class Brain {
private:
// variables
    std::string store_filename;
    
    int set1;   // number of research batches processed internally
    int set2;   // tracks research queue # of research batches
    long int resonate_index;
    long int handles;

    bool done[512];
    bool descriptor;
    bool access_is_open;
    bool keep_alive;    // keeps access open
    
    ifstream access;

// references
public:
    Brain();

    // technicalities
    void file_access(int level);    // create file access to cabinet
    void intialize1(bool perm); // perm = descriptor
    void procure(int nr);   // nr of lines back from the log to procure

    // access
    void store_reference(int resonate_iNumber); // handles data // resonate_index
    void useBrain();    // employ logic according to account reference #'s
    
    // data
    void arrange(); // arranges data in cabinet // alphabetical sequence
    void search(std::string logic, int n=1); // search cabinet
    void recall();  // recalls events
    void add_data();    // adds data to a stored reference (store_reference())
    void research(int x);   // research sets

    // signal
    void done_with_query(); // creates done sequence in array done[]
};