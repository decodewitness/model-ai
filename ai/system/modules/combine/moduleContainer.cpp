// AI/SYSTEM/MODULES/MODULECONTAINER.CPP - USED BY "AI/SYSTEM/MODULES/COMBINE.CPP"
#include <string>

const int sizeOfIndexes = 4096;     // the number of countable indexes inside moduleContainer.data

struct moduleContainer {
    std::string containerName;
    int sizeData;
    char *data;
    int indexes[sizeOfIndexes/2];
    int filledIndex;

    int intData[2];
    std::string stringData[2];
};


// NEED A FUNCTION TO FILL IN THE DATA INSIDE THE CONTAINER


void addInt(moduleContainer a, int x, bool index) {
    if (index == true) {
        a.intData[0] = x;
    } else if (index != true) {
        a.intData[1] = x;
    }
};

void addString(moduleContainer a, std::string s, bool index) {
    if (index == true) {
        a.stringData[0] = s;
    } else if (index != true) {
        a.stringData[1] = s;
    }
};

void storeModule(moduleContainer a) {
    // store data in module
    std::fstream fs("container.bin");

    std::cout << "~:: storing data container ::~" << std::endl;

    std::cout << "\t~:: recording size of data" << std::endl;
    fs << "{" << a.sizeData << "}";

    std::cout << "\t~:: recording data" << std::endl;
    fs << "{";
    for (int i=0; i<a.sizeData; i++) {
        fs >> a.data[i];
    }
    fs << "}";

    std::cout << "\t~:: recording indexes" << std::endl;
    fs << "{";
    for (int i=0; i < a.filledIndex && a.filledIndex < sizeOfIndexes; i++) {
        fs << a.indexes[i] << ",";
    }
    fs << "}";

	fs.close();
};