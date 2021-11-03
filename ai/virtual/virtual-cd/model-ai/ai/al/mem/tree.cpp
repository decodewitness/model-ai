#include "tree.h"

#include <iostream>
#include <cstring>

#include <sys/types.h>
#include <unistd.h>

class Tree {

private:
    int number_of_leafs;
    int propensity;

    bool anomaly;

    std::string label;

    Leaf leafs[20];

public:
    Tree(std::string label);
    ~Tree();

    int increment(int y=2);
    void grow();
    void prune();
};

Tree::Tree(std::string label) {
    this->label = label;
    this->propensity = 1;

    std::cout << "\t\t-:: 1 tree ::label-> (" << this->label << ")." << std::endl;
    std::cout << "\t\t-:: growing leafs." << std::endl;

    this->grow();
}

Tree::~Tree() {
    std::cout << "\t\t-:: tree got deleted." << std::endl;
}

int Tree::increment(int y) {
    int x=1;
    std::cout << "\t:: increment(" << (x>y?x:y) << ")" << std::endl;
    if (y<x)
        return x;
    else
        return y;
}

void Tree::prune() {
    if (this->number_of_leafs > maximum_leafs) {
        this->anomaly = true;
    } else {
    this->number_of_leafs += increment(2); // make incrementing leafs dynamic
    Leaf l;
    Leaf m;
    }
    // time function
}

void Tree::grow() {
    int x = this->propensity*2;
    this->number_of_leafs += increment(x);
    std::cout << "\t:: (" << x << " leafs) ::";
    this->prune();
}


