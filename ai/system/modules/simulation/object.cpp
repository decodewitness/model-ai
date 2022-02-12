#include <iostream>

class Object {
private:
    int x;
    int y;
    int z;

    int width;
    int length;
    int height;

    std::string name;
    std::string label;

public:

    Object() { std::cout << "- {Object} was created." << std::endl; }
};