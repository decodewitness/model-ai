#include "forest.h"

class Forest {

private:
    int nr_of_trees;
    Tree *tree;
    Tree *trees[16];
    std::string label;
public:
    Forest();
    ~Forest();
};

Forest::Forest() {  // constructor
    std::cout << "\t\t-:: forest constructor." << std::endl;
    this->label = "\t\tforest type I (label)";
    std::cout << "\t\t-:: forest " << this->label << " was created." << std::endl;

    this->nr_of_trees=0;

    for (int i=0; i<maximum_trees; i++) {
        // plant additional trees
        this->trees[i] = new Tree(this->label);
        this->nr_of_trees++;
        std::cout << "\t.: plants " << this->nr_of_trees << " trees. trees labeled " << this->label << "." << std::endl;
    }
}

Forest::~Forest() { // destructor
    std::cout << "\t-:: deleting tree." << std::endl;
    for (int i=0; i<maximum_trees; i++) {
        //delete this->trees[i];
    }
}
