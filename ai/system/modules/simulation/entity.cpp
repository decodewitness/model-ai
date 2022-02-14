#include <iostream>
#include <string>

class Entity {

private:
    int x;
    int y;
    int z;

    std::string name;
    std::string label;
public:

    Entity() {
        std::cout << "- (Entity) was created." << std::endl;
        
        this->x=0;
        this->y=0;
        this->z=0;
    
        this->name = "<empty>";
        this->label="<empty label>";
    }

    void setName(std::string n) { this->name = n; };
    void setLabel(std::string l) { this->label = l; };
    
    std::string getName() { return this->name; };
    std::string getLabel() { return this->label; };

    void printName() { std::cout << "- name = " << this->getName() << std::endl; };
    void printLabel() { std::cout << "- label = " << this->getLabel() << std::endl; };

    int getX() { return this->x; };
    int getY() { return this->y; };
    int getZ() { return this->z; };

    void setX(int n) {
        std::cout << "\t-- moving to (x:" << n << ")." << std::endl;
        this->x = n;
    };
    
    void setY(int n) {
        std::cout << "\t-- moving to (y:" << n << ")." << std::endl;
        this->y = n;
        
    };   
    
    void setZ(int n) {
        std::cout << "\t-- moving to (z:" << n << ")." << std::endl;
        this->z = n;
    };

    void setXYZ(int l, int m, int n) {
        std::cout << "\t-- setting coordinates to (x:" << l << " y:" << m << " z:" << n << ")." << std::endl;
    
        this->x = l;
        this->y = m;
        this->z = n;
    };
};

// eof