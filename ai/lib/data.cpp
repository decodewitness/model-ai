// "AI/LIB/DATA.CPP" - USED IN: "AI/AI.H" FOR ENCAPSULATING A DATA OBJECT.

#ifndef _DATAOBJECT
#define _DATAOBJECT

#include <string>
#include <vector>

using namespace std;

const int arraySize = 640;  // array for max size vectors and such as indexes in the 'index'-array.


// call this class with the Data(std::string s) constructor!
class Data {

private:
    int pref;       // current active reference into index.
    int wrdpref;    // actually referred to vector.
    int count;      // counts important refs.

    int total;      // total number of vectors in mystrings
    int totalpref;  // number of remembered preferred words
    int totalwrdpref;   // number of remembered word indexes

    int prefArray[arraySize];

    int index[arraySize]; // records index of the important strings.
                                // the index array size may increase later depending on max size for the vectors strings.    
    std::vector<std::string> mystrings; // contains the words inside the data
    std::vector<std::string> mymemory;  // contains the remembered words from mystrings

public:
    Data() { this->count=0; };

    // the actual object that gets called when constructor gets called instead of super.
    Data(std::string s) { 
        this->mystrings.at(0) = s;
        this->total = 1;
        Data();
    };

    // getters and setters.
    int getpref() { return this->pref; }  // referred index
    void setpref(int x) { this->pref=x; } // set referred index
    int getwrdpref() { return this->wrdpref; }    // word index
    void setwrdpref(int x) { this->wrdpref=x; }   // set word index
    
    // set a word at the latest index
    void set(std::string s) {
        this->mystrings.at(this->total - 1) = s;
        this->total++;
    }

    // get the word at the referred index.
    std::string get() {
        return this->mystrings.at(this->wrdpref);
    }

    // get the word from the last index.
    std::string last() {
        int el=mystrings.size();
        if (el < 1) {
            return "0";
        } else {
            return this->mystrings.at(el-1);
        }
    }

    // NEEDS GETTERS SETTERS FOR THE PREFERRED INDEX NUMBERS
    // 
};

#endif
// eof