#include "moduleContainer.cpp"
#include "combine.h"

Combine::Combine() {
    // do nothing
}

// this class still needs a size for the strings.

void Combine::setB(std::string a, std::string b) {
    this->var_1 = a;
    this->var_2 = b;
    c = a + b;

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
        this->c = this->var_1 + this->var_2;
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

//
//
//
///////////////////// CombineModule /////////////////
//
//
//

CombineModule::CombineModule() {
    this->module1 = "module 1";
    this->module2 = "module 2";

    this->sizeModule1 = 0;
    this->sizeModule2 = 0;
    this->sizeModules = 0;
};


moduleContainer CombineModule::combine(moduleContainer one, moduleContainer two) { // combine 2 module containers / input=container
    /* moduleContainer {
            std::string containerName;
            int sizeData;
            char *data;
        }
    */

    std::cout << "~:: combining 2 container modules: (" << one.containerName << ") (" << two.containerName << ")" << std::endl;
    moduleContainer cont;

    cont.containerName = "dataContainer";
    cont.sizeData = one.sizeData + two.sizeData;
    cont.data = new char[cont.sizeData];
    
    for (int i=0; i<one.sizeData; i++) {
        cont.data[i] = one.data[i];
    }

    for (int i=one.sizeData; i<cont.sizeData; i++) {
        cont.data[i] = two.data[i];
    }

    std::cout << "\t~:: combined data / returning container (size: " << cont.sizeData << ")" << std::endl;
    return cont;
};

int CombineModule::recount(moduleContainer one, moduleContainer two) {
    this->sizeModules = one.sizeData + two.sizeData;
    this->module1 = one.containerName;
    this->module2 = two.containerName;

    std::cout << "\t~:: recounting data in modules (" << one.containerName << ")(" << two.containerName << "); amounting to : (" << this->sizeModules << ")" << std::endl;

    return this->sizeModules;
};