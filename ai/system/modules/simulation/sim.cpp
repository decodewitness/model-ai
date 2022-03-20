// AI/SYSTEM/MODULES/SIMULATION/SIM.CPP -- USED BY "AI/SIMULATION.CPP"

#include "sim.h"

    // DECLARED IN SIM.H:

    // int entity_count;
    // int object_count;
    // int session_count;
    // int active_session;
    // int sessions_with_manipulated_entities[MAX_SESSIONS];
    // int sessions_with_manipulated_objects[MAX_SESSIONS];
    // int nr_manipulated_entities_in_session[MAX_SESSIONS];
    // int nr_manipulated_objects_in_session[MAX_SESSIONS];
    // int list_of_manipulated_entities[MAX_ENTITIES];
    // int list_of_manipulated_objects[MAX_OBJECTS];
    // int e_manipulate_in_session[MAX_ENTITIES][MAX_SESSIONS];
    // int o_manipulate_in_session[MAX_OBJECTS][MAX_SESSIONS];
    // int total_manipulated_entities;
    // int total_manipulated_objects;
    // int total_manipulations;
    // bool entityList[MAX_ENTITIES];
    // bool objectList[MAX_OBJECTS];
    // bool manipulatedEntityList[MAX_MANIPULATED];
    // bool manipulatedObjectList[MAX_MANIPULATED];
    // bool entityVertexList[MAX_ENTITIES];
    // bool objectVertexList[MAX_OBJECTS];

Simulation::Simulation() {
    std::cout << "\t~:: sim construct()" << std::endl;
    this->init();
};

void Simulation::init() {
    std::cout << "\t~:: initializing simulation run." << std::endl;
	
    // this->max_x = MAX_X;
    // this->max_y = MAX_Y;
    // this->max_z = MAX_Z;

    this->end_simulation = false;

    this->x=0;
    this->y=0;
    this->z=0;

    // statistics counters for end of sim
    this->cycle_round=0;    
    this->max_entities=0;
    this->max_objects=0;
    //this->run_time_simulation=0;

    //this->entities=0;
    // this->entity_focus_area=1;

    // // session counter with max value for manipulateOn[]
    // this->eSession = 0;
    // this->oSession = 0;

    // for (int i=0; i<MAX_CYCLE; i++) {
    //     eSessions[i]=false;    // sessions to manipulate
    //     oSessions[i]=false;    // sessions to manipulate
    //     sessionsE[i]=0;    // sessions entities to manipulate
    //     sessionsO[i]=0;    // sessions objects to manipulate
    //     manipulateOnEntity[i]=0;    // values to manipulate entity in session
    //     manipulateOnObject[i]=0;    // values to manipulate objects in session
    // }

    this->entity_count = 0;
    this->object_count = 0;
    this->session_count = 0;
    this->active_cycle = 0;
    this->total_manipulated_entities = 0;
    this->total_manipulated_objects = 0;
    this->total_manipulations = 0;
    this->total_manipulated_e_sessions = 0;
    this->total_manipulated_o_sessions = 0;

    memset(this->sessions_with_manipulated_entities,'\0',MAX_SESSIONS);
    memset(this->sessions_with_manipulated_objects,'\0',MAX_SESSIONS);
    memset(this->nr_manipulated_entities_in_session,'\0',MAX_SESSIONS);
    memset(this->nr_manipulated_objects_in_session,'\0',MAX_SESSIONS);
    memset(this->list_of_manipulated_entities,'\0',MAX_ENTITIES);
    memset(this->list_of_manipulated_objects,'\0',MAX_OBJECTS);
    memset(this->session_has_entities, '\0', MAX_MANIPULATED_ENTITIES);
    memset(this->session_has_objects, '\0', MAX_MANIPULATED_OBJECTS);
    memset(this->has_entities, '\0', MAX_SESSIONS);
    memset(this->has_objects, '\0', MAX_SESSIONS);
    memset(this->list_of_manipulated_e_sessions, '\0', MAX_SESSIONS);
    memset(this->list_of_manipulated_o_sessions, '\0', MAX_SESSIONS);
    memset(this->list_of_manipulated_sessions, '\0', MAX_SESSIONS);

    for (int i=0; i<MAX_ENTITIES; i++) {
        memset(this->e_manipulate_in_session[MAX_ENTITIES], '\0', MAX_SESSIONS);
    }

    for (int i=0; i<MAX_OBJECTS; i++) {
        memset(this->o_manipulate_in_session[MAX_OBJECTS], '\0', MAX_SESSIONS);
    }

    for (int i=0; i<MAX_SESSIONS; i++) {
        memset(this->session_has_entities[i], '\0', MAX_MANIPULATED_ENTITIES);
        memset(this->session_has_objects[i], '\0', MAX_MANIPULATED_OBJECTS);
    }
    
// bool entityList[MAX_ENTITIES];
// bool objectList[MAX_OBJECTS];
// bool manipulatedEntityList[MAX_MANIPULATED];
// bool manipulatedObjectList[MAX_MANIPULATED];
// bool entityVertexList[MAX_ENTITIES];
// bool objectVertexList[MAX_OBJECTS];

    // counters in sim
    this->entity_count = 0;
    this->object_count = 0;
    // this->nr_of_manipulated_entities = 0;
    // this->nr_of_manipulated_objects = 0;

    for (int i=0; i<MAX_ENTITIES; i++) {
        this->entityList[i] = false;
    }

    for (int i=0; i<MAX_ENTITIES; i++) {
        this->objectList[i] = false;
    }

    for (int i=0; i<MAX_MANIPULATED_ENTITIES; i++) {
        this->manipulatedEntityList[i] = false;
        this->manipulatedObjectList[i] = false;
    }

    std::cout << "\t\t~:: ready | initialized sim." << std::endl;

    // for (int i=0; i<this->max_cycles; i++) {
    //     if (this->end_simulation==false) {
    //         this->run_cycle();
    //     }
    // }
}

void Simulation::setEntity(bool ar) {
    if (ar == true) {
            this->entity_count++;
            std::cout << "~:: increased entity nr." << std::endl;
    } else {
        this->entity_count--;
        std::cout << "~:: decreased entity nr." << std::endl;
    }
};    

void Simulation::setObject(bool ar) {
    if (ar == true) {
            this->object_count++;
            std::cout << "~:: increased objects nr." << std::endl;
    } else {
        this->object_count--;
        std::cout << "~:: decreased objects nr." << std::endl;
    }
};    // ar = add/rome; respectively 0 or 1


void Simulation::manipulate() {
    int x=0;
	
    std::cout << std::endl;
	std::cout << "~:: (manipulate in session #) :: ";
	std::cin >> x;	// number of sessions to manipulate
	std::cout << std::endl;
	
    this->manipulateSessions(x);
}

void Simulation::manipulateSessions(int n) {
    char ch='x';
    int z=0;
    bool notContained=true;

    this->total_manipulated_sessions += 1;

    std::cout << "~:: manipulating session: " << n << "." << std::endl;
    std::cout << "(e|o)? : ";

    std::cin >> ch;

    while (ch != 'e' && ch != 'o' && ch != 'E' && ch != 'o') {
        std::cout << "~:!:~ invalid input." << std::endl;
        std::cout << "-> valid input is 'e' or 'o'." << std::endl;

        std::cout << std::endl;
        std::cout << "(e|o)? : ";
        std::cin >> ch;
    }

    switch (ch) {
        case 'e':
        case 'E':
            std::cout << "(entity #)? : ";
            std::cin >> z;

            // debug option
            // std::cout << std::endl << "(debug) z==" << z << std::endl;

            if (z > 0) {
                this->manipulateEntity(z, n);
                
                this->total_manipulations += 1;
                // this->total_manipulated_e_sessions += 1;
                this->sessions_with_manipulated_entities[n] += 1;
                this->list_of_manipulated_entities[this->total_manipulated_entities] = z;
                this->total_manipulated_entities += 1;
                
                for (int i=0; i<MAX_SESSIONS; i++) {
                    if (list_of_manipulated_e_sessions[i] == n) {
                        notContained = false;
                    }
                }
                if (notContained == true) {
                    this->list_of_manipulated_e_sessions[this->total_manipulated_e_sessions++] = n;
                    // std::cout << std::endl << "(debug) ~:: added session to list of sessions." << std::endl;
                    // std::cout << "\t\t- total number of sessions manipulated = " << this->total_manipulated_e_sessions << std::endl;
                }
                
                std::cout << "\t~:: added to list (" << z << ")" << std::endl;
            } else {
                std::cout << "\t~:: cancelled." << std::endl;
            }
            break;

        case 'o':
        case 'O':
            std::cout << "(object #)? : ";
            std::cin >> z;
            
            if (z > 0) {
                this->manipulateObject(z, n);

                this->total_manipulations += 1;
                // this->total_manipulated_o_sessions += 1;
                this->sessions_with_manipulated_objects[n] += 1;
                this->list_of_manipulated_objects[this->total_manipulated_objects] = z;
                this->total_manipulated_objects += 1;
                
                for (int i=0; i<MAX_SESSIONS; i++) {
                    if (list_of_manipulated_o_sessions[i] == n) {
                        notContained = false;
                    }
                }
                if (notContained == true) {
                    this->list_of_manipulated_o_sessions[this->total_manipulated_o_sessions++] = n;
                    // std::cout << std::endl << "(debug) ~:: added session to list of sessions." << std::endl;
                    // std::cout << "\t\t- total number of sessions manipulated = " << this->total_manipulated_o_sessions << std::endl;
                }
                std::cout << "\t~:: added to list (" << z << ")" << std::endl;
            } else {
                std::cout << "\t~:: cancelled." << std::endl;
            }
            
            break;

        default:
            std::cout << std::endl << "~:!:~ reached default option." << std::endl;
            break;
    };

    this->stats_is_measured(n);
};
    // int x;
    // int y;
    // int z;
    // std::string s;

    // // n = number of sessions to manipulate
    // // x = session number to manipulate

    // // entities
    // // for (int i=0; i<n; i++) {
    // std::cout << std::endl;
    // // std::cout << "~:: manipulate session #: ";
    // // cin >> x;
    // std::cout << "\t~:: entity to modify in session #" << n << ": ";
    // std::cin >> y;

    // this->manipulateOnEntity[n] = y;    // n=session # / y=entities #

    // this->eSessions[n] = true;
    // this->sessionsE[this->eSession] = y;
    // this->eSession++;
    // this->nr_of_manipulated_entities = y;
    // // }

    // // objects
    // // for (int i=0; i<n; i++) {
    //     // std::cout << "~:: manipulate session #: ";
    //     // cin >> x;
    // std::cout << "\t~:: object to modify in session #" << n << ": ";
    // std::cin >> y;

    // this->manipulateOnObject[n] = y;    // x=session # / y=entities #
    
    // this->oSessions[n] = true;
    // this->sessionsO[this->oSession] = y;
    // this->oSession++;
    // this->nr_of_manipulated_objects = y;
    // // }



void Simulation::manipulateEntity(int n, int session) {
    int x;
    int y;
    int z;
    std::string s;
   
    // for (int i=0; i<n; i++) {
    std::cout << std::endl;
    // std::cout << "~:: manipulate session #: ";
    // cin >> x;
    std::cout << "\t~:: modifying entity #" << n << "." << std::endl; 
    
    this->manipulatedEntityList[session] = n;
    
    //this->stats_is_measured(n);
};

    // std::cin >> y;

    // this->manipulateOnEntity[n] = y;    // n=session # / y=entities #

    // this->eSessions[n] = true;
    // this->sessionsE[this->eSession] = y;
    // this->eSession++;
    // this->nr_of_manipulated_entities = y;

void Simulation::manipulateObject(int n, int session) {
    int x;
    int y;
    int z;
    std::string s;

    std::cout << std::endl;
    
    std::cout << "\t~:: modifying object #" << n << "." << std::endl; 
    
    this->manipulatedObjectList[session] = n;
    
    this->stats_is_measured(n);
};

    // bool manipulatedEntityList[MAX_MANIPULATED_ENTITIES];
    // bool manipulatedObjectList[MAX_MANIPULATED_OBJECTS];
    // bool session_has_entities[MAX_MANIPULATED_ENTITIES];
    // bool session_has_objects[MAX_MANIPULATED_OBJECTS];
    // int has_entities[MAX_SESSIONS];
    // int has_objects[MAX_SESSIONS];

void Simulation::checkManipulationOnCycle() {
    // if (this->has_entities[this->active_cycle] == true) {
    //     std::cout << "- session has entities: " << this->session_has_entities[this->active_cycle][0] << std::endl;
    // }

}

void Simulation::listManipulated() {

    std::cout << std::endl;

    // DEBUG OPTION
    std::cout << "(debug) manipulated eo sessions: ES:" << this->total_manipulated_e_sessions << " OS:" << this->total_manipulated_o_sessions << std::endl;

    std::cout << "~:: listing manipulated targets: " << std::endl << "\t";

    for (int i=0; i<this->total_manipulated_e_sessions; i++) {
        std::cout << "e(" << this->list_of_manipulated_entities[i] << ") ";
    }

    for (int i=0; i<this->total_manipulated_o_sessions; i++) {
        std::cout << "o(" << this->list_of_manipulated_objects[i] << ") ";
    }

    std::cout << std::endl;
}

void performManipulationEntity() {

}

void performManipulationObject() {

}

    // std::cout << "\t~:: object to modify in session #" << n << ": ";
    // std::cin >> y;

    // this->manipulateOnObject[n] = y;    // x=session # / y=entities #
    
    // this->oSessions[n] = true;
    // this->sessionsO[this->oSession] = y;
    // this->oSession++;
    // this->nr_of_manipulated_objects = y;



    // if (this->nr_of_manipulated_entities > 0) {
    //     std::cout << std::endl << "~:: manipulate on entity (end with a negative number e.g. '-9') :: #" << std::endl;

    //     for (int i=0; i<this->nr_of_manipulated_entities; i++) {
    //         std::cout << ":: ";
    //         std::cin >> z;

    //         if (z >= 0) {
    //             manipulatedEntityList[i] = z;
    //         } else {
    //             break;
    //         }
    //     }
    // }
    
    // if (this->nr_of_manipulated_objects > 0) {
    //     std::cout << std::endl << "~:: manipulate on object (end with a negative number e.g. '-9') :: (object_number_1, object_number_n, ...) #: " << std::endl;
    //     for (int i=0; i<this->nr_of_manipulated_objects; i++) {
    //         std::cout << "\t:: ";
    //         std::cin >> z;

    //         if (z >= 0) {
    //             manipulatedObjectList[i] = z;
    //         } else {
    //             break;
    //         }
    //     }
    // }

void Simulation::stats_is_measured(int n) {
    std::cout << std::endl;
    std::cout << "\t* nr of manipulating sessions : " << this->total_manipulated_sessions << std::endl;

    // entities and objects in per session
    if (this->total_manipulated_e_sessions > 0) {
        std::cout << "\t* manipulating (entities) in # session : ";
        for (int i=0; i<this->total_manipulated_e_sessions; i++) {
            std::cout << this->list_of_manipulated_e_sessions[i] << " ";
        }
        std::cout << std::endl;
    }

    if (this->total_manipulated_o_sessions > 0) {
        std::cout << "\t* manipulating (objects) in # session : ";
        for (int i=0; i<this->total_manipulated_o_sessions; i++) {
            std::cout << this->list_of_manipulated_o_sessions[i] << " ";
        }
        std::cout << std::endl;
    }

        // this->total_manipulations += 1;
        // this->sessions_with_manipulated_entities[n] += 1;
        // this->list_of_manipulated_entities[this->total_manipulated_entities] = z;
        // this->total_manipulated_entities += 1;

    if (this->total_manipulated_entities > 0) {
        std::cout << "\t* modifying entities # : " << this->total_manipulated_entities << std::endl;
    }

    if (this->total_manipulated_objects > 0) {
        std::cout << "\t* modifying objects # : " << this->total_manipulated_objects << std::endl;
    }

    std::cout << std::endl;

    if (this->total_manipulated_entities > 0) {
        std::cout << "\t* manipulated entities : ";

        for (int i=0; i<total_manipulated_entities; i++) {
            std::cout << "e(" << this->list_of_manipulated_entities[i] <<") ";
        }

        std::cout << std::endl;
    }

    if (this->total_manipulated_objects > 0) {
        std::cout << "\t* manipulated objects : ";

        for (int i=0; i<total_manipulated_objects; i++) {
            std::cout << "o(" << this->list_of_manipulated_objects[i] <<") ";
        }

        std::cout << std::endl;
    }
};

    // for (int i=0; i<this->session; i++) {
    //     std::cout << "\t- #" << i << ": " << this->manipulateOnEntity[i] << std::endl;
    // }

void Simulation::createEntity(double x, double y, double z, int n) {
    if (n>=0 && n<MAX_ENTITIES) {
        if (x<=MAX_X && y<=MAX_Y && z<=MAX_Z) {
            this->entity[n] = new Entity(n);
            entityList[n] = true;
            this->entityVertex[n] = new Vertex(x,y,z);
            this->setEntity(true);  // increments entity_count
            // this->entity_count += 1;
            // this->max_entities += 1;
        }
        
        std::cout << "\t\t~:: added sim {entity}(" << n << ")" << std::endl;
    }
};
    
void Simulation::createObject(double x, double y, double z, int n) {
    if (n>=0 && n<MAX_ENTITIES) {
        if (x<=MAX_X && y<=MAX_Y && z<=MAX_Z) {
            this->object[n] = new Object(n);
            objectList[n] = true;

            this->objectVertex[n] = new Vertex(x,y,z);
            this->setObject(true);
            // this->object_count += 1;
            // this->max_objects += 1;
        }
        
        std::cout << "\t\t~:: added sim {object}(" << n << ")"  << std::endl;
    }
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
};

void Simulation::shortList() {
    std::cout << std::endl << "[E]: ";
    for (int i=0; i<MAX_ENTITIES; i++) {
        if (entityList[i] == true) {
            std::cout << "(" << i << ") ";
        }
    }

    std::cout << std::endl << "[O]: ";
    for (int i=0; i<MAX_OBJECTS; i++) {
        if (objectList[i] == true) {
            std::cout << "(" << i << ") ";
        }
    }

    // std::cout << std::endl;
    std::cout << std::endl;

    // std::cout << "(manipulated Entity): ";
    // for (int i=0; i<MAX_MANIPULATED_ENTITIES; i++) {
    //     if (manipulatedEntityList[i] == true) {
    //         std::cout << "(" << i << ") ";
    //     }
    // }
    // std::cout << std::endl;

    // std::cout << "(manipulated Object): ";
    // for (int i=0; i<this->object_count; i++) {
    //     if (manipulatedObjectList[i] == true) {
    //         std::cout << "(" << i << ") ";
    //     }
    // }

    // std::cout << std::endl;

    // std::cout << std::endl;
    // std::cout << "(nr of manipulated entities): " << this->nr_of_manipulated_entities << std::endl;
    // std::cout << "(nr of manipulated objects): " << this->nr_of_manipulated_objects << std::endl;
    // std::cout << std::endl;
};

/*
    int eSession;    // value for manipulateOn[] value set to max sessions for entities to perform
    int oSession;
    int sessions[MAX_CYCLE];    // sessions to manipulate
    int sessionsE[MAX_CYCLE];    // sessions entities to manipulate
    int sessionsO[MAX_CYCLE];    // sessions objects to manipulate
    int manipulateOnEntity[MAX_CYCLE];    // values to manipulate entity in session
    int manipulateOnObject[MAX_CYCLE];    // values to manipulate objects in session
*/

void Simulation::checkManipulationOnEntities(int n) {
    // if (this->eSession > 0) {
    //     if (this->eSessions[this->cycle_round] == true) {
    //         std::cout << "\t\t~:: manipulating on {Entities} #(" << n << ")." << std::endl;

    //     }
    // }
};

void Simulation::checkManipulationOnObjects(int n) {
    // if (this->oSession > 0) {
    //     if (this->oSessions[this->cycle_round] == true) {
    //         std::cout << "\t\t~:: manipulating on {Objects} #(" << n << ")." << std::endl;

    //     }
    // }
};

// void Simulation::cycle(int n) {

//     std::cout << std::endl;

//     using std::chrono::duration_cast;
//     using std::chrono::nanoseconds;
//     typedef std::chrono::high_resolution_clock clock;

//     auto start = clock::now();
        
//     // add starting time here
//         // STARTING TIME
//     //time_t endtime;
//     //time_t timer = time(NULL);

//     // auto start = clock::now();
//     // std::cout << std::endl << "~:: simulation starting @ START TIME: " << start << std::endl;

//     for (int i=1; i<=n; i++) {
//         std::cout << "\t~:: sim::entering cycle -" << i << "-." << std::endl;
//         this->cycle_round = i;

//         // reduces lifetime expectancy
//         // this->mortality(1);
//         // this->checkManipulationOnEntities(1);
//         // this->checkManipulationOnObjects(1);
//     }

//     // add end time here
//         // ENDING TIME
//     //endtime = time(NULL);

//     //this->run_time_simulation = endtime;

//     //std::cout << std::endl << "~:: simulation @ END TIME: " << endtime << std::endl;

//     auto end = clock::now();
    
//     this->run_time_simulation = duration_cast<nanoseconds>(end-start).count();
    
//     std::cout << duration_cast<nanoseconds>(end-start).count() << "ns\n";
// };

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
                this->object_count -= 1;
            }
        }
    }

    for (int i=0; i<MAX_ENTITIES; i++) {
        if (entityList[i] == true) {
            this->entity[i]->incrementAge(n);
            if (this->entity[i]->getMortality() == true) {
                this->killEntity(i);
                std::cout << "- {Entity}(" << i << ") reached mortality." << std::endl;
                this->entity_count -= 1;                
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

void Simulation::run_cycle(int n) { // this happens in 1 cycle round instance

    //this->max_cycles = n;

    using std::chrono::duration_cast;
    using std::chrono::nanoseconds;
    typedef std::chrono::high_resolution_clock clock;

    auto start = clock::now();
        
    // add starting time here
        // STARTING TIME
    // time_t endtime;
    // time_t timer = time(NULL);
    // auto start = clock::now();
    // std::cout << std::endl << "~:: simulation run -- starting @ START TIME: " << start << std::endl;

    // advance to next cycle
    
    // for (int i=0; i<n; i++) {
    this->advance_cycle();  // 'true' as parameter will print the cycle_round
    this->mortality(1);

    // this->checkManipulationOnEntities(retManipE());
    // this->checkManipulationOnObjects(retManipO());

    if (this->cycle_round == this->max_cycles) {
        this->end_simulation = true;
    }
    // }
    
    // add end time here
        // ENDING TIME
   
    auto endtime = time(NULL);
    this->run_time_simulation = endtime;
    // std::cout << std::endl << "~:: simulation run -- ending @ END TIME: " << endtime << std::endl;
    auto end = clock::now();    
    this->run_time_simulation = duration_cast<nanoseconds>(end-start).count();
    std::cout << duration_cast<nanoseconds>(end-start).count() << "ns\n";
};

// eof