// AI/SYSTEM/MODULES/SIMULATION/SIM.H   -- USED BY "AI/AI.H"

#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <chrono>

// #include <time.h>

#include "vertex.h"
#include "entity.cpp"
#include "object.cpp"

#define MAX_ENTITIES 100
#define MAX_OBJECTS 100
#define MAX_CYCLE 100

#define MAX_X 9999999
#define MAX_Y 9999999
#define MAX_Z 9999999

class Simulation {
private:
    double x;
    double y;
    double z;

    double max_x;
    double max_y;
    double max_z;

    // statistics
    int cycle_round;
    int max_entities;
    int max_objects;
    double run_time_simulation;

    double coordinates[3];

    int eSession;    // value for manipulateOn[] value set to max sessions for entities to perform
    int oSession;
    bool eSessions[MAX_CYCLE];    // entity sessions to manipulate
    bool oSessions[MAX_CYCLE];    // object sessions to manipulate
    int sessionsE[MAX_CYCLE];    // sessions entities to manipulate
    int sessionsO[MAX_CYCLE];    // sessions objects to manipulate
    int manipulateOnEntity[MAX_CYCLE];    // values to manipulate entity in session
    int manipulateOnObject[MAX_CYCLE];    // values to manipulate objects in session

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

    void init();

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

    void statistics();

    void manipulateSessions(int n);
    void checkManipulationOnEntity();
    void checkManipulationOnObject();
};

// eof