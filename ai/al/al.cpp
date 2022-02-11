// (in sub-directory) "./AL/AL.CPP" - USED BY "/AI/AI.H" FOR ARTIFICIAL LIFE PROGRAM FOR MODEL AI

#include "al.h"

// HAL
void start_hal() {	// constructs the hal object
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
	std::cout << std::endl << "-:: destructor artificial life routine was called. -::" << std::endl << "\tkilling abstraction layer." << std::endl;
};

void AL::kbuild(double i) {	// reserves memory for kbuild
	// reserving memory
	std::cout << "\t-:: kbuild reserving " << i << "(DEG) bytes ::- for your additional mappings." << std::endl;
	this->mem += i;
};

void AL::life() {	// artificial life habits
	int counter=0;
	for (int i=0; i<=60532; i++) {
		if (i%al_top_limit) {
			counter++;
		}
		if (counter==30000 || counter==60000) { // runs 2 times
			// do action to start extending behavior
		}
	}

	this->modifies_behaviour();
	//std::cout << std::endl << "-::: result :::-" << std::endl;
};

void AL::modifies_behaviour() {	// extend modular behavior
	std::cout << std::endl;
	std::cout << std::endl << "-:: extending modular behavior." << std::endl;

	// extend behaviour here
};

int AL::live() {	// running numbers sequence	// shephard
	std::cout << std::endl << "-:: living inside that function running a numbers sequence." << std::endl << std::endl;
	
	int dot=5, count=0, countdown=10;
	int pinlabel=1000;	// used for shepard(int n) in artificial life routine
	
	populate();
	//std::cout << std::endl;
	splash_al();

	// ARTIFICIAL LIFE ROUTINE
	for (int i=0; i<=alr_limit; i++) {
		if (i>=alr_countdown && countdown>0) {
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

		if (i==(alr_limit / 10) * 0.5) {										// 5%
			std::cout << std::endl << "5%" << std::endl;
		}

		if (i==(alr_limit / 10) * 1) {			// 10%
			std::cout << std::endl << "10%" << std::endl;
		}

		if (i==(alr_limit / 10) * 1.5) {										// 15%
			std::cout << std::endl << "15%" << std::endl;
		}

		if (i==(alr_limit / 10) * 2) {										// 20%
			std::cout << std::endl << "20%" << std::endl;
		}

		if (i==(alr_limit / 10) * 2.5) {										// 25%
			std::cout << std::endl << "25%" << std::endl;
		}

		if (i==(alr_limit / 10) * 3) {										// 30%
			std::cout << std::endl << "30%" << std::endl;
		}

		if (i==(alr_limit / 10) * 3.5) {										// 35%
			std::cout << std::endl << "35%" << std::endl;
		}

		if (i==(alr_limit / 10) * 4) {										// 40%
			std::cout << std::endl << "40%" << std::endl;
		}

		if (i==(alr_limit / 10) * 4.5) {										// 45%
			std::cout << std::endl << "45%" << std::endl;
		}

		if (i==(alr_limit / 10) * 5) {										// 50%
			std::cout << std::endl << "50%" << std::endl;
		}

		if (i==(alr_limit / 10) * 5.5) {										// 55%
			std::cout << std::endl << "55%" << std::endl;
		}

		if (i==(alr_limit / 10) * 6) {										// 60%
			std::cout << std::endl << "60%" << std::endl;
		}

		if (i==(alr_limit / 10) * 6.5) {										// 65%
			std::cout << std::endl << "65%" << std::endl;
		}

		if (i==(alr_limit / 10) * 7) {										// 70%
			std::cout << std::endl << "70%" << std::endl;
		}

		if (i==(alr_limit / 10) * 7.5) {										// 75%
			std::cout << std::endl << "75%" << std::endl;
		}

		if (i==(alr_limit / 10) * 8) {										// 80%
			std::cout << std::endl << "80%" << std::endl;
		}

		if (i==(alr_limit / 10) * 8.5) {										// 85%
			std::cout << std::endl << "85%" << std::endl;
		}

		if (i==(alr_limit / 10) * 9) {										// 90%
			std::cout << std::endl << "90%" << std::endl;
		}

		if (i==(alr_limit / 10) * 9.5) {										// 95%
			std::cout << std::endl << "95%" << std::endl;
		}

		if (i==alr_limit) {										// 100%
			std::cout << std::endl << "100%" << std::endl;
		}

		// alerts you of missing sheep at a set time 'i'
		this->shepard(pinlabel, i);
	}

	this->life();
	
return 1;
};

// ARTIFICIAL LIFE FUNCTIONS

HAL::HAL() {	// HAL constructor
	std::cout << std::endl << "-:: starting evolving mechanic life in artificial life habits." << std::endl;
	
	// first throttle c with 'c' here
	this->c = 'c';
	
	// now live!
	this->x = this->live();
};

HAL::~HAL() {	// HAL destructor
	std::cout << std::endl << "-:: aborting artificial life sequence, and clean up gracefully!" << std::endl << std::endl;
	std::cout << "-:: display ((x)->live())(?x) equaled " << this->x << "." << std::endl;
};

// eof