// "/AI/SYSTEM/MODULES/COMBINE.CPP" - USED IN "/AI/AI.H" FOR THE (MODEL-AI) PROGRAM.

#include <string>
#include <iostream>

class Combine {

    private:
        std::string var_1;
        std::string var_2;

        std::string c;

        bool x; // var_1 is set if true
        bool y; // var_2 is set if true
        bool z; // c is set if true

    public:
        Combine();
        
        void setB(std::string a, std::string b);
        void setOne(std::string a);
        void setTwo(std::string b);

        int add(std::string s);
        void store();
};

Combine::Combine() {
    // do nothing
}

void Combine::setB(std::string a, std::string b) {
    this->var_1 = a;
    this->var_2 = b;
    c = a + " " + b;

    this->x = true;
    this->y = true;
    this->z = true;
};

void Combine::setOne(std::string a) {
    this->var_1 = a;
    this->x = true;
};

void Combine::setTwo(std::string b) {
    this->var_2 = b;
    this->y = true;
};

int Combine::add(std::string s) {
    if (this->x==true && this->y==true) {
        std::cout << "~:: not combined: ( " << x << " )" <<std::endl;
    } else if (this->x == false) {
        this->var_1 = s;
        this->x = true;
    } else if (this->y == false) {
        this->var_2 = s;
        this->y = true;
    }

    if (this->x == true && this->y == true) {
        this->c = this->var_1 + " " + this->var_2;
        this->z = true;

        std::cout << "combined()" << std::endl;
    }

return 1;
};

void Combine::store() {
    if (this->x == true) { /* write x side of script */ }
    if (this->y == true) { /* write y side of script */ }
    if (this->z == true) { /* write combined logfile */ }
};