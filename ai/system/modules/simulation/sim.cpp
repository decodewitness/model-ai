#include "sim.h"

Simulation::Simulation() {

    std::cout << "\t~:: sim construct()" << std::endl;

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
    if (n>=0 && n<MAX_ENTITIES) {
        this->entity[n] = new Entity(n);
        entityList[n] = true;
    }
    std::cout << "\t\t~:: added sim {entity}(" << n << ")" << std::endl;
};
    
void Simulation::createObject(int x, int y, int z, int n) {
    if (n>=0 && n<MAX_ENTITIES) {
        this->object[n] = new Object(n);
        objectList[n] = true;
    }
    std::cout << "\t\t~:: added sim {object}(" << n << ")"  << std::endl;
};

int Simulation::killEntity(int n) {
    if (n>=0 && n<MAX_ENTITIES) {
        delete this->entity[n];
        entityList[n] = false;
    } else {
        std::cout << "~::!::~ error! out of bounds." << std::endl;
    }

    std::cout << "\t\t~:: deleted sim {entity}(" << n << ")"  << std::endl;
    return 0;
};

int Simulation::killObject(int n) {
    if (n>=0 && n<MAX_ENTITIES) {
        delete this->object[n];
        objectList[n] = false;
    } else {
        std::cout << "~::!::~ error! out of bounds." << std::endl;
    }

    std::cout << "\t\t~:: deleted sim {object}(" << n << ")"  << std::endl;
    return 0;
};

void Simulation::listEntities() {
    std::cout << std::endl << "~:: entities:" << std::endl;
    for (int i=0; i<MAX_ENTITIES; i++) {
        if (this->entityList[i] == true) {
            std::cout << "entity(" << i << ") " << this->entity[i]->getLabel() << " : ";
        }
    }
    std::cout << std::endl << std::endl;
};

void Simulation::listObjects() {
    std::cout << std::endl << "~:: objects:" << std::endl;
    for (int i=0; i<MAX_OBJECTS; i++) {
        if (this->objectList[i] == true) {
            std::cout << "object(" << i << ") " << this->object[i]->getLabel() << " : ";
        }
    }
    std::cout << std::endl << std::endl;
};

void Simulation::listAll() {
    
    std::cout << std::endl << "~:: listing entities & objects:" << std::endl;
    std::cout << "\t- ";

    for (int i=0; i<MAX_ENTITIES; i++) {
        if (entityList[i] == true) {
            std::cout << "entity(" << i << ") {" << this->entity[i]->getLabel() << "} ";
        }
    }

    std::cout << std::endl << "\t- ";

    for (int i=0; i<MAX_OBJECTS; i++) {
        if (objectList[i] == true) {
            std::cout << "obj(" << i << ")  {" << this->object[i]->getLabel() << "}";
        }
    }
    std::cout << std::endl << std::endl;
}

void Simulation::cycle(int n) {
    std::cout << std::endl;
    for (int i=1; i<=n; i++) {
        std::cout << "\t~:: sim::entering cycle -" << i << "-." << std::endl;
        
        // reduces lifetime expectancy
        this->mortality(1);
    }
};

void Simulation::mortality(int n) { // n is not used yet

    int entityCount=0;
    int objectCount=0;

    for (int i=0; i<MAX_OBJECTS; i++) {
        if (objectList[i] == true) {
            this->object[i]->incrementAge();
            if (this->object[i]->getMortality() == true) {
                this->killObject(i);
                std::cout << std::endl << "- {Object}(" << i << ") reached mortality." << std::endl;
                objectCount++;
            }
        }
    }

    for (int i=0; i<MAX_ENTITIES; i++) {
        if (entityList[i] == true) {
            this->entity[i]->incrementAge();
            if (this->entity[i]->getMortality() == true) {
                this->killEntity(i);
                std::cout << std::endl << "- {Entity}(" << i << ") reached mortality." << std::endl;

                entityCount++;
            }
        }
    }

    if (entityCount>0) {
        std::cout << "#" << entityCount << " entities perished." << std::endl;
    }
    
    if (objectCount>0) {
        std::cout << "#" << objectCount << " objects got destroyed." << std::endl;
    }
};

// eof