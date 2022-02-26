// AI/SYSTEM/MODULES/SIMULATION/SIM.CPP -- USED BY "AI/SIMULATION.CPP"

#include <iostream>
//#include "sim.h"  // already included in "AI/AI.H"

Simulation::Simulation() {
    std::cout << "\t~:: sim construct()" << std::endl;
    this->init();
};

void Simulation::init() {
    std::cout << "\t~:: initializing simulation run." << std::endl;
	
    // this->max_x = MAX_X;
    // this->max_y = MAX_Y;
    // this->max_z = MAX_Z;

    this->x=0;
    this->y=0;
    this->z=0;

    // statistics counters for end of sim
    this->cycle_round=0;    
    this->max_entities=0;
    this->max_objects=0;
    //this->run_time_simulation=0;

    //this->entities=0;
    this->entity_focus_area=1;

    // counters in sim
    this->entity_count = 0;
    this->object_count = 0;

    for (int i=0; i<MAX_ENTITIES; i++) {
        this->entityList[i] = false;
    }

    for (int i=0; i<MAX_ENTITIES; i++) {
        this->objectList[i] = false;
    }

    std::cout << "\t\t~:: ready | initialized sim." << std::endl;
}

void Simulation::createEntity(double x, double y, double z, int n) {
    if (n>=0 && n<MAX_ENTITIES) {
        if (x<=MAX_X && y<=MAX_Y && z<=MAX_Z) {
            this->entity[n] = new Entity(n);
            entityList[n] = true;

            this->entityVertex[n] = new Vertex(x,y,z);
            this->entity_count += 1;
            this->max_entities += 1;
        }
    }
    std::cout << "\t\t~:: added sim {entity}(" << n << ")" << std::endl;
};
    
void Simulation::createObject(double x, double y, double z, int n) {
    if (n>=0 && n<MAX_ENTITIES) {
        if (x<=MAX_X && y<=MAX_Y && z<=MAX_Z) {
            this->object[n] = new Object(n);
            objectList[n] = true;

            this->objectVertex[n] = new Vertex(x,y,z);
            this->object_count += 1;
            this->max_objects += 1;
        }
    }
    std::cout << "\t\t~:: added sim {object}(" << n << ")"  << std::endl;
};

int Simulation::killEntity(int n) {
    if (n>=0 && n<MAX_ENTITIES) {
        //delete this->entity[n];
        entityList[n] = false;

        //delete this->entityVertex[n];
        this->entityVertexList[n] = false;
        this->entity_count -= 1;
    } else {
        std::cout << "~::!::~ error! out of bounds." << std::endl;
    }

    std::cout << "\t~:: deleted sim {entity}(" << n << ")"  << std::endl;
    return 0;
};

int Simulation::killObject(int n) {
    if (n>=0 && n<MAX_ENTITIES) {
        //delete this->object[n];
        objectList[n] = false;

        //delete this->entityVertex[n];
        this->objectVertexList[n] = false;
        this->object_count -= 1;
    } else {
        std::cout << "~::!::~ error! out of bounds." << std::endl;
    }

    std::cout << "\t~:: deleted sim {object}(" << n << ")"  << std::endl;
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
            std::cout << "entity(" << i << ") (";
            this->entityVertex[i]->getXYZ();
            std::cout <<") {" << this->entity[i]->getLabel() << "} ";
        }
    }

    std::cout << std::endl << "\t- ";

    for (int i=0; i<MAX_OBJECTS; i++) {
        if (objectList[i] == true) {
            std::cout << "obj(" << i << ") (";
            this->objectVertex[i]->getXYZ();
            std::cout << ") {" << this->object[i]->getLabel() << "}";
        }
    }
    std::cout << std::endl << std::endl;
}

void Simulation::cycle(int n) {

    std::cout << std::endl;

    using std::chrono::duration_cast;
    using std::chrono::nanoseconds;
    typedef std::chrono::high_resolution_clock clock;

    auto start = clock::now();
        
    // add starting time here
        // STARTING TIME
    //time_t endtime;
    //time_t timer = time(NULL);

    // auto start = clock::now();
    // std::cout << std::endl << "~:: simulation starting @ START TIME: " << start << std::endl;

    for (int i=1; i<=n; i++) {
        std::cout << "\t~:: sim::entering cycle -" << i << "-." << std::endl;
        this->cycle_round = i;

        // reduces lifetime expectancy
        this->mortality(1);
    }

    // add end time here
        // ENDING TIME
    //endtime = time(NULL);

    //this->run_time_simulation = endtime;

    //std::cout << std::endl << "~:: simulation @ END TIME: " << endtime << std::endl;

    auto end = clock::now();
    
    this->run_time_simulation = duration_cast<nanoseconds>(end-start).count();
    
    std::cout << duration_cast<nanoseconds>(end-start).count() << "ns\n";
};

void Simulation::mortality(int n) { // n is not used yet
    int entityCount=0;
    int objectCount=0;

    // this will increment age for entities and objects
    for (int i=0; i<MAX_OBJECTS; i++) {
        if (objectList[i] == true) {
            this->object[i]->incrementAge(n);
            if (this->object[i]->getMortality() == true) {
                this->killObject(i);
                std::cout << "- {Object}(" << i << ") reached mortality." << std::endl;
                objectCount++;
            }
        }
    }

    for (int i=0; i<MAX_ENTITIES; i++) {
        if (entityList[i] == true) {
            this->entity[i]->incrementAge(n);
            if (this->entity[i]->getMortality() == true) {
                this->killEntity(i);
                std::cout << "- {Entity}(" << i << ") reached mortality." << std::endl;
                entityCount++;
            }
        }
    }

    if (objectCount>0 || entityCount>0) {
        std::cout << std::endl;
    }

    // this will show when more than 0 entities died that round of cycle
    if (entityCount>0) {
        std::cout << "#" << entityCount << " entities perished." << std::endl;
    }
    
    if (objectCount>0) {
        std::cout << "#" << objectCount << " objects got destroyed." << std::endl;
    }

    if (objectCount>0 || entityCount>0) {
        std::cout << std::endl;
    }
};

void Simulation::statistics() {
    std::cout << std::endl << "STATISTICS :: SIMULATION RUN:" << std::endl
                << "-----" << std::endl;
    
    std::cout << "- simulation # cycles: " << this->cycle_round << std::endl;
    std::cout << "- number of entities: " << this->max_entities << std::endl;
    std::cout << "- number of objects: " << this->max_objects << std::endl;
    std::cout << "- total time simulation run (nano seconds): " << this->run_time_simulation << " ns." << std::endl;

    std::cout << std::endl;
};
// eof