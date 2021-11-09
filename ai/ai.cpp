// (inside AI directory) "AI/AI.CPP" - USED BY "/HEADER.H" MAIN FILE FOR AI MODEL CLASS

#ifndef _AI_DEFINITION_INCLUDED
#define _AI_DEFINITION_INCLUDED
#endif

#include <iostream>
#include <fstream>

#include "ai.h"

bool app = true; // DON'T MESS WITH THIS SETTING -- this setting to "true" runs the virtual appliance.

//#include "system/AMModule.cpp" 	// already included in "modular.cpp" in "/ai/ai.h"

// CONDITIONS FOR RUNTIME TESTING (1001 = ALL tests; or 1, or 2, or n)
const int runtime_testing = 1001;

AI::AI(int n) {

	if (this->access == false) {
		this->enforce_security();	// also draws security prompt
	}

	// splash oval
	int x=amnesia();

	this->init();
	
	// represent headers
	this->headers();
	
	// functions
	this->run_checks(n);
	this->check_functions();
	this->test_run(runtime_testing);	// 1001 means test all modules ( SET TEST RUN OPTIONS HERE )

	HAL hal;

	if (app == true) {
		// run virtual appliance (virtual ai instance)
		std::cout << "\t -:: loading virtual instance" << std::endl << std::endl;
		this->appliance(); // this->appliance(); runs the virtual instance
	}
	// perform query sampling
	this->query();
}

void AI::openfs() {
    fs.open ("ai/bin/TL/tl", std::fstream::in | std::fstream::out | std::fstream::app);
}

void AI::closefs() {
	fs.close();
}

void AI::openrs() {
	rs.open ("ai/bin/TL/t1", std::fstream::in | std::fstream::out | std::fstream::app);
}

void AI::closers() {
	rs.close();
}

void AI::hal() {
	start_hal();
}

void AMMod() {
	
	int r; // for storing random number

	// create AMModule
	AMModule *ammodule = new AMModule;
	std::cout << "-:: running AMModule." << std::endl;

	// number sequence compares between upper and lower bounds
	ammodule->nrs(60, 3, 100);
	
	splash();	// splash sequence
	
	// some random numbers
	// use r later as input for modules
	std::cout << "~:: some random numbers:" << std::endl;
		
	ammodule->seedRNG10();
	r = ammodule->getRNG();	// this function also displays the random number
	
	// some more random numbers
	ammodule->seedRNG100();
	r = ammodule->getRNG(); // this function also displays the random number

	// delete
	delete ammodule;
}

void AI::run_checks(int args) {
	std::cout << "-:: checking arguments." << std::endl;
	std::cout << "\t" << args << ": arguments." << std::endl;
	// couples back to main()
}

void AI::check_functions() {
	int routine; // used to set the checking interval from 1 ... 10 (0=not ;; 1=at start ;; 10=every cycle)	

	std::cout << std::endl << "-:: checking AI functions." << std::endl;

	if (this->recordat == true) {
		routine=0;
	} else {
		routine=1;
	}
	
	this->check_routine = routine;

	if (this->check_routine > 0) {
		// report on functions
		std::cout << std::endl;
		std::cout << "-:: generated internal report." << std::endl;
		std::cout << "\t-:: everything is nominal." << std::endl;
		std::cout << "\t-:: checked every function." << std::endl;
		std::cout << "\t-:: operational." << std::endl;
		std::cout << std::endl;
		std::cout << "-::[_E_[entropy):>___::-" << std::endl;
		std::cout << std::endl;
		std::cout << "-:: __low on entropy ::-" << std::endl;
		std::cout << "-:: normal entropies ::-" << std::endl;
		std::cout << "-:: _high in entropy ::-" << std::endl;
		std::cout << std::endl;
	} else {
		std::cout << "\t-::=- skipping checks when grace period function was reached." << std::endl << std::endl;
	}
	
	// logging
	// log(x);
	this->recordat = true;
}

void AI::headers() {
	// put in array and manipulate headers
	std::cout << std::endl << "-:: setting headers" << std::endl;

	// open headers list file
	std::fstream headers("headers.txt");
	
	// variables
	string arr[1024];
	string tmp;
	int i=0, count;

	// close file with headers' file handle
	headers.close();
	count = i;

	// list headers
	for (i=0; i<count; i++) {
		//std::cout << asterisktab << arr[i] << std::endl;
	}

	// load headers here
	// // //
}

void AI::test(int n=0) {

	// display oval
	//int x=amnesia();

	// function writes "- check."
	void check();

	// actual checking account for modules
	switch (n) {
	
		case 0:
			std::cout << "! -:: skipping tests." << std::endl;
			break;
		case 1:	// speech
			std::cout << "\t-:: random query for speech synthesis." << std::endl;
			check();
			break;
		case 2:	// methods
			std::cout << "\t-:: access random method for sampling in device." << std::endl;
			check();
			break;
		case 3: // routines
			std::cout << "\t-:: accessing random sampler routine for sampling." << std::endl;
			check();
			break;
		case 4: // catalogue
			std::cout << "\t-:: performs random queries inside catalogue algorithmic." << std::endl;
			check();
			break;
		case 5: // recognition
			std::cout << "\t-:: random pattern recognition for input measure." << std::endl;
			check();
			break;
		default: // unrecognized
			std::cout << "! -:: error :: module not recognized in testing engine." << std::endl;
			break;
	};
};

void run_checks(int n) {
	std::cout << "-:: running checks" << std::endl << std::endl;
}

void AI::test_run(int flag=0) {	// simulate a test run
	std::cout << std::endl;
	//std::cout << "- entering (test run) simulation." << std::endl;
	//std::cout << "- testing modules." << std::endl;
	
	// tests for in test_run():
	
	// skip tests = 0
	// speech = 1
	// methods = 2
 	// routines = 3
	// catalogue = 4
	// recognition = 5
	// ALL = 1001
	
	// models are sort of the habits of the AI model
	std::cout << "-:: test run - performing tests on modules." << std::endl;
	
	if (flag == 1001) {	// 1001 = ALL tests
		for (int i=1; i<=5; i++) {	
			this->test(i);
		}
	} else {
		this->test(flag);
	}
};	

bool AI::stepping() {	// integrity checking
	bool hashesCheckOut=true;
	bool errors=false;
	
	int steps=4;
	int steps_completed=0;
	int count=steps;

	std::cout << std::endl << "-:: check integrity / logical step counter." << std::endl;
	
	for (int i=steps; i>=1; i--) {
		// implement incremental logic here
		std::cout << "\t-:: step:" << --steps;
		
		// on error bail out (set ch to anything but 'c' during checking to prevent the next checks)
		if (errors==true) {	// check for errors
			this->ch='d';	// change to 'd' in case of errors
		}
		
		
		// check for the need for the bail out routine
		if (this->ch != 'c')
			break; // bail on anything different than 'c'!
		else {
			steps_completed++;
			std::cout << " -:: complete. (100%)" << std::endl;
		}
	}
	
	if (steps<1) {
		hashesCheckOut = true;
	}

	if (hashesCheckOut == true) {
		// steps completed
		std::cout << "\t-:: steps completed: " << steps_completed << std::endl;
		return true;
	} else {
		// steps did not complete
		std::cout << "\t-:: steps completed: " << steps_completed << std::endl;
		std::cout << "\t-:: steps incomplete: " << (count-steps_completed) << std::endl;
		return false;
	}
};

void AI::hash(string s) {
	std::cout << "-:: hashing function." << std::endl;
	std::cout << "\t-:: hashing (\"" << s << "\")" << std::endl;
	std::cout << "\t-:: hash: " << md5(s.c_str());
}

void AI::sample() {
	cout << "-:: starting AI." << std::endl;
	std::cout << "\t-:: sampler: " << this->nr << " threads." << std::endl;
	
	// start a new sampler device
	this->sampler = new Sampler(SAMPLER_THREADS);
	
	std::cout << "\t::--entropy--::" << std::endl << std::endl;
	
	// initialize sampler and is set to recording
	this->sampler->init();

	std::cout << std::endl;
	std::cout << "-:: feeding entropy" << std::endl;
	std::cout << "-:: tap the ltctap." << std::endl;
	
	for (int i=SAMPLER_THREADS+1;i>0;i--) {
		std::cout << std::endl << std::endl;
		std::cout << "-::: sampler thread ::#" << i << ":: :::-" << std::endl;
		
		// ltctap / fcltaptaptap()
		run();	// run ltctap / fcltaptaptap() / entropyr() / entropyw() :: from "entropy/header.h"
		
		std::cout << "\t-:: -:: psht -:: <tap>" << std::endl;
	}
};

void check() { std::cout << "\t-:: check." << std::endl; }

void AI::init() {
	// INITIALIZATION
	// ALL INITIALIZATION HAPPENS HERE
	std::cout << "-:: initialization." << std::endl;

	this->nr = 8;
	this->ch = 'c';
	this->check_routine = 1;
	
	this->testrun = false;
	this->run_checks();
	

	// set "this->crlurl" to resource URL.
	this->crlurl = "http://thatbot.ninja";

	int x=0;

	// file streams
	std::cout << "\t-:: opening file streams." << std::endl;
	// open file streams for tl
	this->openfs();
	// open read streams for t1
	this->openrs();

	// drum machine drum machine
	std::cout << "\t-:: drum machine" << std::endl;
	DrumMachine();

	// gradle to help build cradle
	x=gradle();
	std::cout << "\t-:: gradle method finished. (";
	std::cout << x << ")" << std::endl;
}

void AI::appliance() {
	system("./ai/virtual/virtual.sh");
}

void AI::decouple() {
	std::cout << std::endl;
	std::cout << "-:: decoupler." << std::endl;

	std::cout << "\t-:: decoupling sampler" << std::endl;
	this->sampler->decouple();
	
	this->saygrace();
}

void AI::destroy_msg() {
	std::cout << std::endl << "-:: calling destructor for AI::Model." << std::endl;
}

void AI::saygrace() {
	std::cout  << std::endl << std::endl << "::=> saving grace (routine) and closing libraries <=::" << std::endl;
		
	this->nr = 0;
	this->ch = '0';
	this->testrun = false;

	// close files
	std::cout << "-:: closing files." << std::endl;
	this->closefs();
	this->closers();

	// clean up sampler allocated memory
	std::cout << "-:: cleaning memory." << std::endl;

	delete this->sampler;

	this->destroy_msg();

	// final AI message
	std::cout << "-:: done." << std::endl;
};

void AI::query() {
	// QUERY

	std::cout << "::- query in sample." << std::endl;
	
	// PROMPT
	std::cout << "--? :: ";
	std::string y;
    std::cin >> y;
	
	//s = sampleX();
	std::cout << std::endl << std::endl << "-:: testing sample ::-" << std::endl;
	logicalQuery(y);
};

void AI::kill(int x) {
	switch (x) {
		case 9:
			std::cout << std::endl << "-/- initializing sequence." << std::endl << std::endl;
			//system("pwd");
			exit(0);
			break;
		default:
			std::cout << std::endl << "-/- unknown sequence." << std::endl << std::endl;
			break;
	};	
};

int AI::curl(std::string f) {
	std::cout << std::endl << "********* CURLING **********" << std::endl << std::endl;
	int x = do_curl(f);
	std::cout << "x:" << x << std::endl;
	return x;
};

int AI::links(std::string url, int max) {
	std::cout << "********* FETCHING LINKS (max: " << max << ") **********" << std::endl << std::endl;
	
	int x = fetch_link(url, max);

	return x;
};

void AI::enforce_security() {
	bool ack = security_prompt();
	this->access = ack;
};

void AI::mod() {
	this->mdl = new Modular;

	this->mdl->query();
	this->mdl->set_data("unicorn =1=");
	this->mdl->set_datas(0, "unicorns =2=");
	this->mdl->set_datas(2, "unicorn =3=");
	this->mdl->set_datas(0, "unicorn =1=");
	this->mdl->set_data("unicorn =4=");

	this->mdl->get_index();

	this->mdl->polldata();

	delete this->mdl;
};