#include <iostream>

void table(float x) {

    std::cout << "- table of: " << x << std::endl;
    std::cout << "  -----" << std::endl;

    for (int i = 1; i<11; i++) {
        std::cout << x << " * " << i << " = " << (x*i) << std::endl;
    }

    std::cout << std::endl;
}

void tableTo(float x, float y) {

    std::cout << "- table of: " << x << std::endl;
    std::cout << "  -----" << std::endl;

    for (int i = 1; i<=y; i++) {
        std::cout << x << " * " << i << " = " << (x*i) << std::endl;
    }

    std::cout << std::endl;
}

// eof