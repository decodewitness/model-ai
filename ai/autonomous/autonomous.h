// AI/AUTONOMOUS/AUTONOMOUS.H (USED BY AI/AUTONOMOUS/AUTONOMOUS.CPP

#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>

enum ControlType {
                Sleep=1,Waking=2,Awake=3,SensorA=4,
                SensorB=5, Ext1=6, Ext2=7, Ext3=8,
                Arm1=9, Arm2=10, Arm3=11, Arm4=12,
                Leg1=13, Leg2=14, Leg3=15, Leg4=16,
                Torso=17, Hip=18, BlegA=20, BlegB=21,
                FootA=22, FootB=23, Toe1=24, Toe2=25,
                Toe3=26,Toe4=27,Toe5=28,Toe6=29,
                Toe7=30,Toe8=31,Toe9=32,Toe10=33,
                Finger1=34,Finger2=35,Finger3=36,Finger4=37,
                Finger5=38,Finger6=39,Finger7=40,Finger8=41,
                Finger9=42,Finger10=43,Head=44,
                Eye1=45,Eye2=46,Eye3=47,Eye4=48,Eyes=49,
                N_A=50 // not available
            };

enum EngineType {
    Motor=1, Rotor=2, Combustion=3, Hydraulic=4,
    Turbine=5, Pfaf=6, Nuclear=7, Ballot=8,
    Electric=9, Floatation=10, Gyro=11, Gyros=12,
    Sail=13, Biological=14, Acceleration=15, Propagation=16,
    Unknown=17
};

class Autonomous {
private:

    int interface[2];
    int protocols;
    int powerState;
    int powerCycle;

    char acdc[5];

    EngineType enginetype;

public:

    Autonomous(EngineType E);

    void setControl(int x);

    void setEngine(int x);
    int getEngine();

    void setAC();
    void setDC();
    void setACDC();
    char * getACDC();

    void couples(int ic);   // couple interface inside this function
    void controlIC(int ic);
};

// eof