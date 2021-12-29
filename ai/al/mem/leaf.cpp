#include "leaf.h"

class Leaf {

private:
    int length;
    int color_variation;
    int neighbours;

    bool active;

public:
    Leaf();
    void neighbor(int n);
};

Leaf::Leaf() {
    int neigh=1;
    this->active=true;
    this->neighbor(neigh);
};

void Leaf::neighbor(int neigh) {
    this->length=1;
    this->neighbours=neigh;
    this->color_variation=1;
};