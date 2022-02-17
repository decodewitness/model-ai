// // AI/SYSTEM/MODULES/SIMULATION/VERTEX.H -- USED BY "AI/SYSTEM/MODULES/SIMULATION/SIM.H"

#include <iostream>

class Vertex {

private:
    double x;
    double y;
    double z;

public:
    Vertex(double x=0.00, double y=0.00, double z=0.00) {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    void get() {
        std::cout << "- x:" << this->x
                    << " y:" << this->y
                    << " z:" << this->z
                    << std::endl;
    };

    void getX() {
        std::cout << "x:" << this->x << std::endl;
    };

    void getY() {
        std::cout << "y:" << this->y << std::endl;
    };

    void getZ() {
        std::cout << "z:" << this->z << std::endl;
    };

    void getXYZ() {
        std::cout << "x:" << this->x << " y:" << this->y << " z:" << this->z;
    }

    void setX(double x) {
        this->x = x;
        std::cout << "- set Vertex(x: " << x << ")" << std::endl;
    };

    void setY(double y) {
        this->y = y;
        std::cout << "- set Vertex(y: " << y << ")" << std::endl;
    };

    void setZ(double z) {
        this->z = z;
        std::cout << "- set Vertex(z: " << z << ")" << std::endl;
    };

    void setXYZ(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;

        std::cout << "- set Vertex(x:" << x << ",y:" << y << ",z:" << z << ")" << std::endl;
    };
};
