#include <string>

const int sizeOfIndexes = 2048;     // the number of countable indexes inside moduleContainer.data

struct moduleContainer {
    std::string containerName;
    int sizeData;
    char *data;
    int indexes[sizeOfIndexes];
};