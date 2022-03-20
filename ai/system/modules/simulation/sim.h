// AI/SYSTEM/MODULES/SIMULATION/SIM.H   -- USED BY "AI/AI.H"

#include <iostream>
#include <string>
#include <string.h>
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
#define MAX_SESSIONS 2048
#define MAX_MANIPULATED_ENTITIES 2048
#define MAX_MANIPULATED_OBJECTS 2048

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

    // int eSession;    // value for manipulateOn[] value set to max sessions for entities to perform
    // int oSession;
    // bool eSessions[MAX_CYCLE];    // entity sessions to manipulate
    // bool oSessions[MAX_CYCLE];    // object sessions to manipulate
    // int sessionsE[MAX_CYCLE];    // sessions entities to manipulate
    // int sessionsO[MAX_CYCLE];    // sessions objects to manipulate
    // int manipulateOnEntity[MAX_CYCLE];    // values to manipulate entity in session
    // int manipulateOnObject[MAX_CYCLE];    // values to manipulate objects in session
    // int entity_focus_area;
    
    int max_cycles;
    int entity_count;
    int object_count;
    int session_count;
    int active_session;
    int total_manipulated_sessions;
    int total_manipulated_entities;
    int total_manipulated_objects;
    int total_manipulations;

    int sessions_with_manipulated_entities[MAX_SESSIONS];
    int sessions_with_manipulated_objects[MAX_SESSIONS];

    int nr_manipulated_entities_in_session[MAX_SESSIONS];
    int nr_manipulated_objects_in_session[MAX_SESSIONS];
    
    int list_of_manipulated_entities[MAX_ENTITIES];
    int list_of_manipulated_objects[MAX_OBJECTS];

    int e_manipulate_in_session[MAX_ENTITIES][MAX_SESSIONS];
    int o_manipulate_in_session[MAX_OBJECTS][MAX_SESSIONS];

    bool entityList[MAX_ENTITIES];
    bool objectList[MAX_OBJECTS];
    
    bool manipulatedEntityList[MAX_MANIPULATED_ENTITIES];
    bool manipulatedObjectList[MAX_MANIPULATED_OBJECTS];

    bool entityVertexList[MAX_ENTITIES];
    bool objectVertexList[MAX_OBJECTS];

    Entity *entity[MAX_ENTITIES];
    Object *object[MAX_OBJECTS];

    Vertex *entityVertex[MAX_ENTITIES];
    Vertex *objectVertex[MAX_OBJECTS];

    bool end_simulation;

    // int registered_entities[MAX_ENTITIES];
    // int registered_objects[MAX_OBJECTS];

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
    void manipulateEntity(int n, int session);
    void manipulateObject(int n, int session);

    void stats_is_measured(int n);
    
    void run_cycle(int n=25);
    void set_max_cycle(int n=25) {this->max_cycles = n; }

    void advance_cycle() {
        std::cout << std::endl;
        std::cout << "- cycle round : " << (this->cycle_round + 1) << " -" << std::endl;
        this->cycle_round += 1;
        // this->cycle_round++;
        // if (this->cycle_round >= this->max_cycles) {
        //     this->end_simulation = true;
        // }
    };

    void manipulate();

    void sim_run_cycle() {
       	for (int i=0; i<this->max_cycles; i++) {
	    	this->run_cycle();
	    }
    }

    // int retManipE() { return this->nr_of_manipulated_entities; };
    // int retManipO() { return this->nr_of_manipulated_objects; };
};

// eof