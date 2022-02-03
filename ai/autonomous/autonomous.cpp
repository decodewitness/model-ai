// AI/AUTONOMOUS/AUTONOMOUS.CPP (NOT USED YET)

#include "autonomous.h"

Autonomous::Autonomous(EngineType E) {
    this->powerState = 0;
    this->powerCycle = 0;
};

void Autonomous::setControl(int x) {    // control function for artificial robot
    ControlType cx;
    
    switch (x) {
        
        case 0:
        case 1: cx=Sleep; // =1;
            break;

        case 2: cx=Waking; // =2
            break;

        case 3: cx=Awake; //=3;
            break;

        case 4: cx=SensorA; //=4,
            break;

        case 5: cx=SensorB; //=5,
            break;

        case 6: cx=Ext1; //=6,
            break;

        case 7: cx=Ext2; //=7,
            break;

        case 8: cx=Ext3; //=8,
            break;

        case 9: cx=Arm1; //=9,
            break;

        case 10: cx=Arm2; //=10,
            break;

        case 11: cx=Arm3; //=11,
            break;

        case 12: cx=Arm4; //=12,
            break;

        case 13: cx=Leg1; //=13,
            break;

        case 14: cx=Leg2; //=14,
            break;

        case 15: cx=Leg3; //=15,
            break;

        case 16: cx=Leg4; //=16,
            break;

        case 17: cx=Torso; //=17,
            break;

        case 18: cx=Hip; //=18,
            break;

        case 19: cx=BlegA; //=20,
            break;

        case 20: cx=BlegB; //=21,
            break;

        case 21: cx=FootA; //=22,
            break;

        case 22: cx=FootB; //=23,
            break;

        case 23: cx=Toe1; //=24,
            break;

        case 24: cx=Toe2; //=25,
            break;

        case 25: cx=Toe3; //=26,
            break;

        case 26: cx=Toe4; //=27,
            break;

        case 27: cx=Toe5; //=28,
            break;

        case 28: cx=Toe6; //=29,
            break;

        case 29: cx=Toe7; //=30,
            break;

        case 30: cx=Toe8; //=31,
            break;

        case 31: cx=Toe9; //=32,
            break;

        case 32: cx=Toe10; //=33,
            break;

        case 33: cx=Finger1; //=34,
            break;

        case 34: cx=Finger2; //=35,
            break;

        case 35: cx=Finger3; //=36,
            break;

        case 37: cx=Finger4; //=37,
            break;

        case 38: cx=Finger5; //=38,
            break;

        case 39: cx=Finger6; //=39,
            break;

        case 40: cx=Finger7; //=40,
            break;
            
        case 41: cx=Finger8; //=41,
            break;

        case 42: cx=Finger9; //=42,
            break;

        case 43: cx=Finger10; //=43,
            break;

        case 44: cx=Head; //=44,
            break;

        case 45: cx=Eye1; //=45,
            break;

        case 46: cx=Eye2; //=46,
            break;

        case 47: cx=Eye3; //=47
            break;

        case 48: cx=Eye4; //=48
            break;

        case 49: cx=Eyes; //=49
            break;

        case 50: cx=N_A; //=50
            break;

        default:
            cx=N_A;
        break;
    };
};

void Autonomous::setEngine(int x) { // set EngineType control functions
    EngineType ex;
    
    switch(x) {
        case 1: ex=Motor;// Motor=1
        break;

        case 2: ex=Rotor;// Rotor=2,
        break;

        case 3: ex=Combustion;// Combustion=3,
        break;

        case 4: ex=Hydraulic;// Hydraulic=4,
        break;

        case 5: ex=Turbine;// Turbine=5,
        break;

        case 6: ex=Pfaf;// Pfaf=6,
        break;

        case 7: ex=Nuclear;// Nuclear=7,
        break;

        case 8: ex=Ballot;// Ballot=8,
        break;

        case 9: ex=Electric;// Electric=9,
        break;

        case 10: ex=Floatation;// Floatation=10,
        break;

        case 11: ex=Gyro;// Gyro=11,
        break;

        case 12: ex=Gyros;// Gyros=12,
        break;

        case 13: ex=Sail;// Sail=13,
        break;

        case 14: ex=Biological;// Biological=14,
        break;

        case 15: ex=Acceleration;// Acceleration=15,
        break;

        case 16: ex=Propagation;// Propagation=16,
        break;

        case 17: ex=Unknown;// Unknown=17
        break;

        default:
            this->enginetype = ex;
        break;
    };
};

int Autonomous::getEngine() {   // gets this->enginetype
    return this->enginetype;
};

void Autonomous::setAC() { strncpy(this->acdc, "ac", 2); }; // sets power mode to AC
void Autonomous::setDC() { strncpy(this->acdc, "dc", 2); }; // sets power mode to DC
void Autonomous::setACDC() { strncpy(this->acdc, "ac/dc", 4); };    // sets power mode to AC/DC
char * Autonomous::getACDC() { return this->acdc; };    // gets power mode (AC/DC)

void Autonomous::couples(int ic) {   // couples device interface    // if = interfaces used as argument

};

void controlIC(int ic) {    // controls interface
    
};

// eof