// MAIN.CPP - YOUR MAIN FILE CARRYING THE MAIN FUNCTION FOR YOUR AI MODEL

// including all headers
#include "header.h"

// namespaces
using namespace std;

// main function
int main(int argc, char *argv[]) {

	// splash AI model
	splash();
	
	// class instances
	AI ai(argc);

	// checking AI functions
	ai.check_functions();

	// hash function checks file hashes
	ai.hash("my string"); // checking integrity

	// logical kill chain (uncomment next line)
	//ai.kill(9);

	// health
	chk();
	
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
	ai.decouple();

return 0;
}

// eof