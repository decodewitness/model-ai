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

#define MAX_ENTITIES 2048
#define MAX_OBJECTS 2048
#define MAX_CYCLE 2048
#define MAX_MANIPULATED 2048

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
    int entity_focus_area;
    
    int entity_count;
    int object_count;
    int registered_entities[MAX_ENTITIES];

    int nr_of_manipulated_entities;
    int nr_of_manipulated_objects;
    
    bool entityList[MAX_ENTITIES];
    bool objectList[MAX_OBJECTS];
    
    bool entityVertexList[MAX_ENTITIES];
    bool objectVertexList[MAX_OBJECTS];

    bool manipulatedEntityList[MAX_MANIPULATED];
    bool manipulatedObjectList[MAX_MANIPULATED];

    Entity *entity[MAX_ENTITIES];
    Object *object[MAX_OBJECTS];

    Vertex *entityVertex[MAX_ENTITIES];
    Vertex *objectVertex[MAX_OBJECTS];

    bool end_simulation;
public:

    Simulation();

    void init();

    void createEntity(double x, double y, double z, int n);
    void createObject(double x, double y, double z, int n);

    void listEntities();
    void listObjects();
    void shortList();
    void listAll();

    int killEntity(int n);
    int killObject(int n);

    // void cycle(int n=1);
    void mortality(int n);

    int returnEntityCount() { return entity_count; }
    int returnObjectCount() { return object_count; }

    void statistics();

    void manipulateSessions(int n);
    void checkManipulationOnEntities(int n);
    void checkManipulationOnObjects(int n);

    void stats_is_measured(int n);
    
    void run_cycle(int n=25);
    void advance_cycle() { this->cycle_round++; };

    int retManipE() { return this->nr_of_manipulated_entities; };
    int retManipO() { return this->nr_of_manipulated_objects; };
};

// eof