#include "sim.h"

Simulation::Simulation() {

    std::cout << std::endl << "\t~:: sim construct(){}:" << std::endl;

    this->x=0;
    this->y=0;
    this->z=0;    

    //this->entities=0;
    this->entity_focus_area=1;

    //this->entity = 0;

    for (int i=0; i<MAX_ENTITIES; i++) {
        entityList[i] = false;
    }

    for (int i=0; i<MAX_ENTITIES; i++) {
        objectList[i] = false;
    }

    std::cout << "\t\t~:: initialized sim." << std::endl;
};

void Simulation::createEntity(int x, int y, int z, int n) {
    if (n>0 && n<MAX_ENTITIES) {
        this->entity[n] = new Entity;
    }
    std::cout << "~:: added sim {entity}(" << n << ")" << std::endl;
    entityList[n] = true;
};
    
void Simulation::createObject(int x, int y, int z, int n) {
    if (n>0 && n<MAX_ENTITIES) {
        this->object[n] = new Object;
    }
    std::cout << "~:: added sim {object}(" << n << ")"  << std::endl;
    objectList[n] = true;
};

int Simulation::killEntity(int n) {
    if (n>0 && n<MAX_ENTITIES) {
        delete this->entity[n];
    }

    std::cout << "~:: deleted sim {entity}(" << n << ")"  << std::endl;
    entityList[n] = false;

    return 0;
};   // put in bounds checks

int Simulation::killObject(int n) {
    if (n>0 && n<MAX_ENTITIES) {
        delete this->object[n];
    }
    std::cout << "~:: deleted sim {object}(" << n << ")"  << std::endl;
    objectList[n] = false;
    return 0;
};

void Simulation::listEntities() {
    std::cout << std::endl << "~:: entities:" << std::endl;
    for (int i=0; i<MAX_ENTITIES; i++) {
        if (objectList[i] == true) {
            std::cout << "entity(" << i << ") ";
        }
    }
    std::cout << std::endl << std::endl;
};

void Simulation::listObjects() {
    std::cout << std::endl << "~:: objects:" << std::endl;
    for (int i=0; i<MAX_OBJECTS; i++) {
        if (objectList[i] == true) {
            std::cout << "object(" << i << ") ";
        }
    }
    std::cout << std::endl << std::endl;
};

void Simulation::listAll() {
    
    std::cout << std::endl << "Listing entities & objects:" << std::endl;

    for (int i=0; i<MAX_ENTITIES; i++) {
        if (entityList[i] == true) {
            std::cout << "entity(" << i << ") ";
        }
    }
    std::cout << std::endl;

    for (int i=0; i<MAX_OBJECTS; i++) {
        if (objectList[i] == true) {
            std::cout << "obj(" << i << ") ";
        }
    }
    std::cout << std::endl;
}

// eof