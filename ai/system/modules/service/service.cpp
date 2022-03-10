// AI/SYSTEM/MODULES/SERVICE/SERVICE.CPP    -   USED BY "AI/AI"

// headers
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>

// handle protocols
#include "communication/courtesy.cpp"

// essential bot
#include "robotica/screen.cpp"
#include "robotica/filter.cpp"

class Service {
private:
    Courtesy *courtesy;
public:
    Service();
    ~Service();

    int initiateService(int ls);
};

Service::Service() {
    // create new Courtesy object
    this->courtesy = new Courtesy;
};

Service::~Service() {

};

int Service::initiateService(int ls) {
    // this->courtesy = new Courtesy;
    this->courtesy->doHandshake("localhost");
    return 1;
};
