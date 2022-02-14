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
    
    bool entityList[MAX_ENTITIES];
    bool objectList[MAX_OBJECTS];
    
    Entity *entity[MAX_ENTITIES];
    Object *object[MAX_OBJECTS];

public:

    Simulation();

    void createEntity(int x, int y, int z, int n);
    void createObject(int x, int y, int z, int n);

    void listEntities();
    void listObjects();
    void listAll();

    int killEntity(int n);
    int killObject(int n);

};

// eof