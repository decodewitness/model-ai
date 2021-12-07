// MAIN.CPP - YOUR MAIN FILE CARRYING THE MAIN FUNCTION FOR YOUR AI MODEL
// MAIN FILE FOR HEADER.H
// HEADER.H - HEADER FILE FOR THE AI MODEL (USED BY /MAIN.CPP)

// C++ HEADERS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>

//#include "splash.h"

// CLASS LIBRARIES HEADERS
//#include "ai/ai.cpp"

// INCLUDE SYSTEM

// LOAD ARTIFICIAL LIFE ROUTINES
//#include "al/al.cpp"

// eof
// including all headers
//#include "main.h"

// namespaces
using namespace std;

// logging the program
bool logging_is_enabled = true;

// main function
int steering(int arc) {

	int loopvar=0; 	// use loopvar in recounting xl[1024]
	char * xl[1024];

	if (logging_is_enabled==true) {
		cout << std::endl << "-:: enabled logging." << std::endl;
	}

	// arguments
	for (int i=0, loopvar=0; i<arc && i<1024; i++, loopvar++) {

		std::cout << std::endl << "_ARC(debug): " << arc << " -- " << std::endl;
	}

	// splash AI model
	splash();

	// pass arguments here

	// class instances
	AI ai(arc);

	// (DEBUG) for hashing passcodes (DISABLE THIS)
	//ai.hashtype("ai"); // checking integrity

	// rollouts
	ai.rollout(1);
	//ai.rollout(2);	// uncomment for // rolls out "patch"
	//ai.rollout(3);	// uncomment for // rolls out "restore"
	ai.rollout(4);		// rolls out "tool"
	ai.rollout(9);	// rolls out "comodos"

	// health
	chk();
	
	// auto patch
	ai.auto_patch();

	// checking AI functions
	//ai.check_functions();

	//ai modules
	ai.mod();

	// hash function checks file hashes
	ai.hashtype("my string"); // checking integrity
	
	// logical kill chain (uncomment next line)
	//ai.kill(9);

	// stepping engine
	ai.stepping();
	
	bool crc32=true;
	// check bool conditional
	if (crc32 == true) {
		cout << endl;
		
		// starting AI
		ai.sample();
		
		// test run (NEXT LINE IS BETA TESTING)
		// ai.test_run(runtime_testing);	// 1001 = All modules (module: 1-5)
	} else {
		exit(1);
	}

	// curl attempt site "curled_url" [std::string]
	int x = ai.curl("https://model-ai.com");
	
	
	// stage down and decouple logic (graceful shutdown)
	ai.decouple();

return 0;
}	
	
	//cout << "Working Directory: ";
	//system("pwd");
	//cout << endl;

	// start artificial life
	//HAL hal;	// will automatically start living
	
	// ltctap
	// cout << endl << endl;
	// cout << "-:: tap the ltctap." << endl;

	// for (int i=0; i<10; i++) {
	// 	entropyr();		// cognitive pattern
	// 	entropyw();		// tl "more lorem ipsum"
	// 	cout << "\t-:: -:: psht -:: <tap>" << endl;
	// 	fcltaptaptap();	// hussle
	// 	cout << "::- insert the tam tam reading -::" << endl;


	// 	lt1tlt1();
	// 	t1tl();
	// 	tl();
	// 	t1();
	// 	cout << "-:: swapping sequence." << endl << endl;
	// }

// void lt1tlt1() {std::cout << "holy";}
// void t1tl() {std::cout << "taplc";}
// void tl() { std::cout << "ltct";}
// int t1() { std::cout << "tapsh";}
// // trousers
// void lt1tlt1(int t) {std::cout << "tap";}
// void tlt1(int t) {std::cout << "tap";}
// int t1(int t) {std::cout << "tap";}

	// closing program
	
	// grace routine in decouple() - kill off any AI functions and unloading modules

//return 0;
//}

// eof