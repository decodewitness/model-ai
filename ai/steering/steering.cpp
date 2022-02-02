// MAIN.CPP - YOUR MAIN FILE CARRYING THE MAIN FUNCTION FOR YOUR AI MODEL
// MAIN FILE FOR HEADER.H
// HEADER.H - HEADER FILE FOR THE AI MODEL (USED BY /MAIN.CPP)

// C++ HEADERS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>

#include "splash.h"
// #include "initialize_runcheck.cpp"

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
	
	// initialize_runtime_check();

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

	// check files and such things / environment
	// need to implement this function again
	//testing1();	// testing 1

	// class instances are main function
	AI ai(arc);

	// (DEBUG) for hashing passcodes (DISABLE THIS)
	//ai.hashtype("ai"); // checking integrity

	// health	// need to implement this function again
	//chk();
	
	// audio
	// ai.initialize_audio();
	// ai.play_audio(0)

	// auto patch
	ai.auto_patch();

	// checking AI functions
	//ai.check_functions();

	// rollouts
	ai.rollout(1);
	//ai.rollout(2);	// uncomment for // rolls out "patch"
	//ai.rollout(3);	// uncomment for // rolls out "restore"
	ai.rollout(4);		// rolls out "tool"
	ai.rollout(5);		// rolls out "setting permissions scripts with tool" // already done in "run" script
	ai.rollout(9);		// rolls out "comodos"

	// handlers
	ai.hdata();	// handle data
	ai.hmath();	// handle math expressions

	// testing2();	// testing 2

	//ai modules
	ai.mod();

	// construct
	ai.constr();

	// hash function checks file hashes
	ai.hashtype("ai"); // checking integrity
	//ai.play_audio(0);
	sleep(1);
	//ai.hashchain("artificial intelligence");
	
	// play audio
	// ai.play_audio(1);

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
	int crl = ai.curl("https://model-ai.com");
	
	// testing3();	// testing 3

	// transponder prepare function
	ai.tsp();
	
	std::cout << std::endl << "(debugging) course: " << crl << std::endl;
	ai.convert(10, 1);
	ai.convertf(10.0, 1);
	
	// accounts
	// ai.add_account(15);
	// ai.subtract_account(10);
	// ai.change_account(10);
	// ai.add_account(1);
	// std::cout << std::endl;
	// std::cout << "ACCT_NR::(" << ai.get_account() << ")." << std::endl;
	// ai.print_account();
	// ai.change_account(0);
	// ai.add_account(500);
	// ai.add_account(15);
	// ai.subtract_account(5);
	// ai.print_account();
	// ai.change_account(1);

	std::cout << std::endl << "~:: accounts: " << std::endl << "    -----";
	std::cout << std::endl << std::endl;

	// ai.printn_account();
	// ai.change_account(600);
	// ai.add_account(800.12);
	// ai.subtract_account(900.13);
	//ai.print_account();
	// ai.combine_total();
	// ai.list_positive();
	// ai.list_negative();
	// ai.transfer(1,200,20.00);	// transfer from acct 1 to 200 an amount of 20.00

	ai.add_account(1.33);
	ai.add_account(44.99);
	ai.printn_account();

	ai.store_accounts_detail();

	// stat directory
	ai.statdir("./ai");

	// copy file function
	ai.cp("main.cpp", "main2.cpp.txt");

	sleep(2);

	ai.rm("main2.cpp.txt");

	sleep(1);
	
	// stage down and decouple logic (graceful shutdown)
	
	ai.export_accounts("accounts.txt");
	ai.import_accounts("accounts.txt");
	sleep(1);
	
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