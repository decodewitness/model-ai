#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;

const char store_reference_file[] = "ai/brain/intelligence/cabinet";
const char store_file[] = "ai/brain/intelligence/store";
const int starting_index = 1;

class Brain {
private:
// variables
    std::string store_filename;
    
    int set1;   // tracks research queue # of research batches
    int set2;   // number of research batches processed internally
    long int resonate_index;
    long int handles;

    bool done[512];
    bool descriptor;
    bool access_is_open;
    bool keep_alive;    // keeps access open
    
    ifstream access;
    ofstream outfile;
// references
public:
    Brain();
    ~Brain();

    // technicalities
    void file_access(int level);    // create file access to cabinet
    void intialize1(bool perm); // perm = descriptor
    int procure(int nr);   // nr of lines back from the log to procure
    void consolidate(int nr); // does heavy research

    // access
    void store_reference(std::string s); // handles data // resonate_index
    void useBrain(std::string query);    // employ logic according to account reference #'s
    
    // data
    void arrange(); // arranges data in cabinet // alphabetical sequence
    void search(std::string logic, int n=1); // search cabinet
    void recall();  // recalls events
    void add_data();    // adds data to a stored reference (store_reference())
    void research(int x);   // research sets

    // signal
    void done_with_query(); // creates done sequence in array done[]
};