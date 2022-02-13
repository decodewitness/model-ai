#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include "entity.cpp"
#include "object.cpp"

#define MAX_ENTITIES 100
#define MAX_OBJECTS 100

class Simulation {
private:
    int x;
    int y;
    int z;

    int coordinates[3];

    int registered_entities[MAX_ENTITIES];
    int entity_focus_area;
    int entity_count;

    int objects;
    
    Entity *entity[MAX_ENTITIES];
    Object *object[MAX_OBJECTS];

public:

    Simulation();

    void createEntity(int x, int y, int z, int n) { if (n>0 && n<MAX_ENTITIES) this->entity[n] = new Entity; }
    void createObject(int x, int y, int z, int n) { if (n>0 && n<MAX_ENTITIES) this->object[n] = new Object; }

    int killEntity(int n) { if (n>0 && n<MAX_ENTITIES) delete this->entity[n]; }   // put in bounds checks
    int killObject(int n) { if (n>0 && n<MAX_ENTITIES) delete this->object[n]; }

};

// eof