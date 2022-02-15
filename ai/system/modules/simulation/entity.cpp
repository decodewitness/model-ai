#include <iostream>
#include <string>

#define ENTITY_LIFESPAN 18

class Entity {

private:
    double x;
    double y;
    double z;

    int nr;

    int age;
    int lifespan;
    bool dying;
    
    std::string name;
    std::string label;

public:
    Entity(int n) {
        std::cout << "- (Entity) was created." << std::endl;
        
        this->x=0;
        this->y=0;
        this->z=0;

        this->nr = n;
    
        this->age=0;
        this->lifespan = ENTITY_LIFESPAN;
        this->dying = false;

        this->name = "<empty>";
        this->label="<empty label>";
    }

    ~Entity() {
        std::cout << "- {Entity} <" << this->label << "> died." << std::endl;
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
        std::cout << "\t-- moving to (x:" << n << ")." << std::endl;
        this->x = n;
    };
    
    void setY(double n) {
        std::cout << "\t-- moving to (y:" << n << ")." << std::endl;
        this->y = n;
        
    };   
    
    void setZ(double n) {
        std::cout << "\t-- moving to (z:" << n << ")." << std::endl;
        this->z = n;
    };

    void setXYZ(double l, double m, double n) {
        std::cout << "\t-- setting coordinates to (x:" << l << " y:" << m << " z:" << n << ")." << std::endl;
    
        this->x = l;
        this->y = m;
        this->z = n;
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

// eof