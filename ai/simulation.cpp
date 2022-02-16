#include <unistd.h>

void AI::runSim() {	// sim objects and such go here
	this->startSim();
	this->play_audio_file("ai/system/audio/samples/vworge.wav");
	std::cout << "\t~:: sim running." << std::endl;
	sleep(3);
	this->addSimEntity(0,0,0,0);
	this->addSimObject(0,0,0,0);
	this->listAllEO();
	this->printEntityCount();
	this->printObjectCount();

	// return count
	this->cycle(25);
	sleep(3);

	//this->listObject();
	//this->listEntity();

	sleep(3);
	//this->deleteSimEntity(0);
	//this->deleteSimObject(0);
	this->stopSim();
	sleep(1);
};