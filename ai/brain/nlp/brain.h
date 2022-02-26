#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;

const int starting_index = 1;
const int batch_size = 1024;

const char store_reference_file[] = "ai/brain/nlp/intelligence/cabinet_collection";
const char data_collection[] = "ai/brain/nlp/intelligence/data_collection";
const char store_file[] = "ai/brain/nlp/intelligence/store_file";

class Brain {
private:
// variables
    std::string store_filename;
    
    int set1;   // tracks research queue # of research batches
    int set2;   // number of research batches processed internally
    long int resonate_index;
    long int handles;

    bool done[batch_size];
    bool descriptor;
    bool output_is_open;
    bool access_is_open;
    bool data_is_open;
    bool keep_alive;    // keeps access open
    
    ifstream access;
    ifstream data;
    ofstream output;
    ofstream collection;

    // std::string
// references
public:
    // constructor and destructor
    Brain();
    ~Brain();

    // technicalities
    int search_catalogue_index(std::string s);  // search for 
    int procure(int nr);   // nr of lines back from the log to procure
    void file_access(int level);    // create file access to cabinet
    void intialize1(bool perm); // perm = descriptor
    void consolidate(int nr); // does heavy research
    
    // nlp
    void neural_net(std::string s, std::string h, int cumulator);  // uses string_next_logic() sequentially
    std::string string_next_logic(std::string ssh); // strings next logic
    std::string sorter(std::string st, int level);   // sorts out data catalogues by proxy
    std::string search_index_code(std::string l);   // search

    // access
    void store_reference(std::string s); // handles data // resonate_index
    void useBrain(std::string query);    // employ logic according to account reference #'s
    
    // data
    void recall(std::string s);  // recalls events
    void research(int x);   // research sets
    void arrange(); // arranges data in cabinet // alphabetical sequence
    void add_data();    // adds data to a stored reference (store_reference())
    void search(std::string logic, int n=1); // search cabinet
    // signal
    void done_with_query(); // creates done sequence in array done[]
};