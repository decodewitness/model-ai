// SYSTEM/MEM/DISK.H	-	USED BY "AL.H" IN ORDER TO EXPAND AI

#include <iostream>

#include "forest.cpp"

const int MAX_LEAFS_SIZE = 100;     // 1000 = 10MiB
const int MAX_FILES = 10;
const int MAX_NODES = 1;    // amount of artificial life instances run

int forest_randomness = 0; // randomness of trees (max 100)
int max_trees_in_forest = 1;
int random_trees_in_forest = (max_trees_in_forest/1);
int total_leafs = 0;

int counti = 0;

// calculate disk free here

// directory
const char directory[16] = "bin/forest";
// file hierarchy
const char hierarchy[8] = "forest";
// forest entities
const char entities[8] = "trees";
// tree nodes
const char prune[8] = "leaves";
// leaf nodes per tree
const int leaf = 100;  // 1 node is 1KiB

// create trees in "bin/forest"

void create() {
    std::cout << "\t\t-::" << " (" << counti++ << ") :- generate " << entities << " and pruning " << prune << " dependencies." << std::endl;

    // create forest class entity here
    Forest forest;
    
}

void populate() {
    int node1 = MAX_NODES;  // total mount of nodes
    std::cout << "\t-:: max nodes (" << node1 << ")" << std::endl;

    int x = MAX_LEAFS_SIZE / leaf;  // total amount of leafs

    std::cout << "\t(" << x << " " << entities << " in " << hierarchy << ")" << std::endl;
    std::cout << "\t-:: calculating size dependencies" << std::endl;

    // calculate size dependencies
    //1 leaf = 1 kb
    int calc=maximum_leafs*1024;
    std::cout << "\t-:: max. leafs (" << maximum_leafs << ") ";
    std::cout << "\t :: max. trees (" << maximum_trees << ") ";

    std::cout << std::endl << std::endl;
    std::cout << "\t-:: populating random " << hierarchy << "." << std::endl;

    // calculate dependencies
    std::cout << "\t-:: calculating dependencies." << std::endl;
    std::cout << "\t\t-:: max. trees: " << max_trees_in_forest << " * max. leafs: " << maximum_leafs << std::endl;
    std::cout << "\t\t-:: total amount:" << max_trees_in_forest*maximum_leafs << "kB." << std::endl;
    std::cout << std::endl;

    // create forests
    for (int i=0; i<node1; i++) // fork these nodes
        std::cout << "\t-:: creating forest." << std::endl;
        create();   // creating forest node
};

