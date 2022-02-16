// AI/SIMULATION.CPP - USED BY AI.H

#include <unistd.h>

void AI::runSim() {	// sim objects and such go here
	this->startSim();
	sleep(2);
	this->play_audio_file("ai/system/audio/samples/vworge.wav");
	std::cout << "\t~:: sim running." << std::endl;
	this->addSimEntity(0,0,0,0);
	this->addSimObject(0,0,0,0);
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
	this->stopSim();
	sleep(3);
};