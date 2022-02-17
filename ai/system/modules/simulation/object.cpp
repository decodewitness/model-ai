// AI/SYSTEM/MODULES/SIMULATION/OBJECT.CPP -- USED BY "AI/SYSTEM/MODULES/SIMULATION/SIM.H"

#include <iostream>

#define LIMIT_XYZ 9999999
#define OBJECT_LIFESPAN 7

class Object {
private:
    double x;
    double y;
    double z;

    int nr;

    int width;
    int length;
    int height;

    int age;
    int lifespan;

    std::string name;
    std::string label;

    bool dying;

public:

    Object(int n) {
        std::cout << "- {Object} was created." << std::endl;
        this->name = "<object>";
        this->label = "<empty object>";

        this->nr = n;

        this->age = 0;
        this->lifespan = OBJECT_LIFESPAN;
        this->dying = false;
    };

    ~Object() {
        std::cout << std::endl << "- {Object} " << this->label << " got destroyed." << std::endl;
    }

    void setName(std::string n) { this->name = n; };
    void setLabel(std::string l) { this->label = l; };
    
    std::string getName() { return this->name; };
    std::string getLabel() { return this->label; };

    void printName() { std::cout << "- name = " << this->getName() << std::endl; };
    void printLabel() { std::cout << "- label = " << this->getLabel() << std::endl; };

    double getX() { return this->x; };
    double getY() { return this->y; };
    double getZ() { return this->z; };

    void setX(double n) {
        if (n <= LIMIT_XYZ) {
            std::cout << "\t-- moving to (x:" << n << ")." << std::endl;
            this->x = n;
        }
    };
    
    void setY(double n) {
        if (n <= LIMIT_XYZ) {
            std::cout << "\t-- moving to (y:" << n << ")." << std::endl;
            this->y = n;
        }
    };   
    
    void setZ(double n) {
        if (n <= LIMIT_XYZ) {
            std::cout << "\t-- moving to (z:" << n << ")." << std::endl;
            this->z = n;
        }
    };

    void setXYZ(double l, double m, double n) {
        if (n <= LIMIT_XYZ) {
            std::cout << "\t-- setting coordinates to (x:" << l << " y:" << m << " z:" << n << ")." << std::endl;
            this->x = l;
            this->y = m;
            this->z = n;
        }
    };

    void incrementAge(int n=1) {
        this->age += n;

        if (this->age == this->lifespan) {
            this->dying = true;
        }
    };

    bool getMortality() {
        return this->dying;
    }
};