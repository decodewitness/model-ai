#include "sim.h"

Simulation::Simulation() {

    std::cout << std::endl << "\t~:: sim construct(){}:" << std::endl;

    this->x=0;
    this->y=0;
    this->z=0;    

    //this->entities=0;
    this->entity_focus_area=1;

    //this->entity = 0;

    std::cout << "\t\t~:: initialized sim." << std::endl;
};