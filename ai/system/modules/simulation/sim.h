#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include "vertex.h"
#include "entity.cpp"
#include "object.cpp"

#define MAX_ENTITIES 100
#define MAX_OBJECTS 100

class Simulation {
private:
    double x;
    double y;
    double z;

    double coordinates[3];

    int registered_entities[MAX_ENTITIES];
    int entity_focus_area;
    
    int entity_count;
    int object_count;
    
    bool entityList[MAX_ENTITIES];
    bool objectList[MAX_OBJECTS];
    
    bool entityVertexList[MAX_ENTITIES];
    bool objectVertexList[MAX_OBJECTS];

    Entity *entity[MAX_ENTITIES];
    Object *object[MAX_OBJECTS];

    Vertex *entityVertex[MAX_ENTITIES];
    Vertex *objectVertex[MAX_OBJECTS];

public:

    Simulation();

    void createEntity(double x, double y, double z, int n);
    void createObject(double x, double y, double z, int n);

    void listEntities();
    void listObjects();
    void listAll();

    int killEntity(int n);
    int killObject(int n);

    void cycle(int n=1);
    void mortality(int n);

    int returnEntityCount() { return entity_count; }
    int returnObjectCount() { return object_count; }
};

// eof