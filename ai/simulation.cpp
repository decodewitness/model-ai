// AI/SIMULATION.CPP - USED BY AI.H
	// MAIN FILE TO EDIT THE "SIMULATION RUN"...

#include <unistd.h>

#include "system/modules/simulation/sim.cpp"

void AI::runSim() {	// sim objects and such go here
	// start the sim	// should be 1st statement in the function "runSim()"
	// this->startSim();
	
	// play audio file -- already done in "startSim()"
	this->play_audio_file("ai/system/audio/samples/vworge.wav");
	sleep(1);
	std::cout << "\t~:: simulation is running." << std::endl;
	
	// this->addSimEntity(0,0,0,0);
	// this->addSimObject(0,0,0,0);
	this->listAllEO();
	this->printEntityCount();
	this->printObjectCount();
	sleep(3);

	// return count
	this->cycle(25);

	//this->listObject();
	//this->listEntity();

	//this->deleteSimEntity(0);
	//this->deleteSimObject(0);
	sleep(1);

	this->sim_stats();
	sleep(3);

	// this next "stopSim()" should be the last statement in this function
	this->stopSim();
};