#include "leaf.h"

class Leaf {

private:
    int length;
    int color_variation;
    int neighbours;

    bool active;

public:
    Leaf();
    void neighbor(int neigh);   // neighbor object
};

Leaf::Leaf() {	// constructor for leaf objects
    int neigh=1;
    this->active=true;
    this->neighbor(neigh);
};

void Leaf::neighbor(int neigh) {    // neigh=neighbor Leaf  // should return Leaf object
    this->length=1;
    this->neighbours=neigh;
    this->color_variation=1;
};