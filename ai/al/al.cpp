// (in sub-directory) "./AL/AL.CPP" - USED BY "/AI/AI.H" FOR ARTIFICIAL LIFE PROGRAM FOR MODEL AI

#include "al.h"

// HAL
void start_hal() {
    HAL hal;
};

// ARTIFICIAL LIFE CLASS FUNCTIONS

AL::AL() { // AL constructor
	std::cout << std::endl;
	std::cout << "-:: constructing artificial life routine." << std::endl;

	std::cout << "\t-:: reserving mibs memory for virtual assimilation." << std::endl;
	this->kbuild(1024.0); // argument is in (double) bytes
};

AL::~AL() { // AL destructor
	std::cout << "-:: destructor artificial life routine was called. -:: killing abstraction layer." << std::endl;
};

void AL::kbuild(double i) {
	// reserving memory
	std::cout << "\t-:: kbuild reserving " << i << "(DEG) bytes ::- for your additional mappings." << std::endl;
	this->mem += i;
};

void AL::life() {	// artificial habits

	int counter=0;
	for (int i=0; i<=60532; i++) {
		if (i%2000) {
			counter++;
		}
		if (counter==30000 || counter==60000) { // runs 2 times
			// do action to start extending behavior
		}
	}

	this->modifies_behaviour();
	//std::cout << std::endl << "-::: result :::-" << std::endl;
};

void AL::modifies_behaviour() {
	std::cout << std::endl;
	std::cout << std::endl << "-:: extending behavior module" << std::endl;

	// extend behaviour
};

int AL::live() {
	populate();

	// if (fork() == 0) {
	// 	int counter=0;
	// 	for (int i=0; i<=605320; i++) {
	// 		if (i%2000) {
	// 			counter++;
	// 		}
	// 		if (counter==600000) {
	// 			std::cout << "-::: result :::-" << std::endl;
	// 		}
	// 	}
	// } else {
	std::cout << std::endl << "-:: living inside that function running a numbers sequence." << std::endl << std::endl;
		
	int dot=5, count=0, countdown=10;
	
	splash_al();

	int pinlabel=1000;	// used for shepard(int n) in artificial life routine


	// ARTIFICIAL LIFE ROUTINE
	for (int i=0;i<=110000;i++) {
		if (i>=99993 && countdown>0) {
			countdown -= 1;
			std::cout << countdown << std::endl;
		}
			
		if (countdown<1) {
			this->c = 'd'; // quits the loop
		}		
			
		if (!(i%5) && (i%20)) {
			std::cout << ".";
			count += 1;
			if (count==4) {
				std::cout << "\b" << (32) << "\b\b" << (32) << "\b\b\b" << (32) << "\b\b\b\b" << (32) << "\b";
				count-=4;
			}
		}

		if (i==500) {
			std::cout << std::endl << "5%" << std::endl;
		}

		if (i==1000) {
			std::cout << std::endl << "10%" << std::endl;
		}

		if (i==1500) {
			std::cout << std::endl << "15%" << std::endl;
		}

		if (i==2000) {
			std::cout << std::endl << "20%" << std::endl;
		}

		if (i==2500) {
			std::cout << std::endl << "25%" << std::endl;
		}

		if (i==3000) {
			std::cout << std::endl << "30%" << std::endl;
		}

		if (i==3500) {
			std::cout << std::endl << "35%" << std::endl;
		}

		if (i==4000) {
			std::cout << std::endl << "40%" << std::endl;
		}

		if (i==4500) {
			std::cout << std::endl << "45%" << std::endl;
		}

		if (i==5000) {
			std::cout << std::endl << "50%" << std::endl;
		}

		if (i==5500) {
			std::cout << std::endl << "55%" << std::endl;
		}

		if (i==6000) {
			std::cout << std::endl << "60%" << std::endl;
		}

		if (i==6500) {
			std::cout << std::endl << "65%" << std::endl;
		}

		if (i==7000) {
			std::cout << std::endl << "70%" << std::endl;
		}

		if (i==7500) {
			std::cout << std::endl << "75%" << std::endl;
		}

		if (i==8000) {
			std::cout << std::endl << "80%" << std::endl;
		}

		if (i==8500) {
			std::cout << std::endl << "85%" << std::endl;
		}

		if (i==9000) {
			std::cout << std::endl << "90%" << std::endl;
		}

		if (i==9500) {
			std::cout << std::endl << "95%" << std::endl;
		}

		if (i==10000) {
			std::cout << std::endl << "100%" << std::endl;
		}

		// alerts you of missing sheep at a set time 'i'
		this->shepard(pinlabel, i);
	}

	this->life();
	
return 1;
};

// ARTIFICIAL LIFE FUNCTIONS

HAL::HAL() {
	std::cout << std::endl << "-:: starting evolving mechanic life in artificial life habits." << std::endl;
	
	// first throttle c with 'c' here
	this->c = 'c';
	
	// now live!
	this->x = this->live();
};

HAL::~HAL() {
	std::cout << std::endl << "-:: aborts runtime! and clean up gracefully!" << std::endl << std::endl;
	std::cout << "-:: display ((x)->live())(?x) equaled " << this->x << "." << std::endl;
};

// eof