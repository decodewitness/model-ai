// MAIN.CPP - YOUR MAIN FILE CARRYING THE MAIN FUNCTION FOR YOUR AI MODEL
// MAIN FILE FOR HEADER.H

// including all headers
#include "main.h"

// namespaces
using namespace std;

// main function
int main(int argc, char *argv[]) {

	std::string arguments;

	if (argc > 1) {
		for (int i=1; i<argc; i++) {
			arguments.append(argv[i]);
			arguments.append(",");
		}
		std::cout << std::endl << "ARG: " << arguments << std::endl << std::endl;
	}

	//initialize_runtime_check();	// checks for file integrity
	steering(1);	// steers the AI (class) code 
	//steering(2);
return 0;
}

// old main function
// int main(int argc, char *argv[]) {

// 	int loopvar=0; 	// use loopvar in recounting xl[1024]
// 	char * xl[1024];

// 	if (logging_is_enabled==true) {
// 		cout << std::endl << "-:: enabled logging." << std::endl;
// 	}

// 	// arguments
// 	for (int i=0, loopvar=0; i<argc && i<1024; i++, loopvar++) {
// 		xl[i] = *(argv+i); 	// use loopvar in recounting xl[1024]
// 		std::cout << std::endl << "_ARGV(debug): " << argv[i] << " -- " << xl[i] << std::endl << std::endl;
// 	}

// 	// splash AI model
// 	splash();

// 	// pass arguments here

// 	// class instances
// 	AI ai(argc);

// 	// rollouts
// 	ai.rollout(9);	// rollout comodos
// 	ai.rollout(1);

// 	// health
// 	chk();
	
// 	// auto patch
// 	ai.auto_patch();

// 	// checking AI functions
// 	//ai.check_functions();

// 	//ai modules
// 	ai.mod();

// 	// hash function checks file hashes
// 	ai.hashtype("my string"); // checking integrity
	
// 	// logical kill chain (uncomment next line)
// 	//ai.kill(9);

// 	// stepping engine
// 	ai.stepping();
	
// 	bool crc32=true;
// 	// check bool conditional
// 	if (crc32 == true) {
// 		cout << endl;
		
// 		// starting AI
// 		ai.sample();
		
// 		// test run (NEXT LINE IS BETA TESTING)
// 		// ai.test_run(runtime_testing);	// 1001 = All modules (module: 1-5)
// 	} else {
// 		exit(1);
// 	}

// 	// curl attempt site "curled_url" [std::string]
// 	int x = ai.curl("https://model-ai.com");
	
	
// 	// stage down and decouple logic (graceful shutdown)
// 	ai.decouple();

// return 0;
// }	
	
// 	//cout << "Working Directory: ";
// 	//system("pwd");
// 	//cout << endl;

// 	// start artificial life
// 	//HAL hal;	// will automatically start living
	
// 	// ltctap
// 	// cout << endl << endl;
// 	// cout << "-:: tap the ltctap." << endl;

// 	// for (int i=0; i<10; i++) {
// 	// 	entropyr();		// cognitive pattern
// 	// 	entropyw();		// tl "more lorem ipsum"
// 	// 	cout << "\t-:: -:: psht -:: <tap>" << endl;
// 	// 	fcltaptaptap();	// hussle
// 	// 	cout << "::- insert the tam tam reading -::" << endl;


// 	// 	lt1tlt1();
// 	// 	t1tl();
// 	// 	tl();
// 	// 	t1();
// 	// 	cout << "-:: swapping sequence." << endl << endl;
// 	// }

// // void lt1tlt1() {std::cout << "holy";}
// // void t1tl() {std::cout << "taplc";}
// // void tl() { std::cout << "ltct";}
// // int t1() { std::cout << "tapsh";}
// // // trousers
// // void lt1tlt1(int t) {std::cout << "tap";}
// // void tlt1(int t) {std::cout << "tap";}
// // int t1(int t) {std::cout << "tap";}

// 	// closing program
	
// 	// grace routine in decouple() - kill off any AI functions and unloading modules

// //return 0;
// //}

// // eof

