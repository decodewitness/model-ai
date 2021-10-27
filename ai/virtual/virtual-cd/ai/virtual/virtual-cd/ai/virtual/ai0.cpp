// (inside AI directory) "AI/AI.CPP" - USED BY "/HEADER.H" MAIN FILE FOR AI MODEL CLASS

#ifndef _AI_DEFINITION_INCLUDED
#define _AI_DEFINITION_INCLUDED
#endif

#include <iostream>
#include "ai.h"

// CONDITIONS FOR RUNTIME TESTING (1001 = ALL tests; or 1, or 2, or n)
const int runtime_testing = 1001;

AI::AI(int n) {
	this->nr = 8;
	this->ch = 'c';
	this->testrun = false;
	this->check_routine = 1;
	
	// functions
	this->run_checks(n);
	this->test_run(runtime_testing);	// 1001 means test all modules ( SET TEST RUN OPTIONS HERE )

	// represent headers
	this->headers();
	HAL hal;

	// run virtual appliance (virtual ai instance)
	std::cout << "\t -:: not loading virtual instance" << std::endl << std::endl;
	//this->appliance();
}

void AI::openfs() {
    fs.open ("bin/tl", std::fstream::in | std::fstream::out | std::fstream::app);
}

void AI::closefs() {
	fs.close();
}

void AI::openrs() {
	rs.open ("bin/t1", std::fstream::in | std::fstream::out | std::fstream::app);
}

void AI::closers() {
	rs.close();
}

void AI::hal() {
	start_hal();
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

	// register headers / glob next time
	this->modules[0]  = "md5/md5.cpp";
	this->modules[1]  = "system/chk.h";
	this->modules[2]  = "../al/al.cpp";
	this->modules[3]  = "../al/header.h";
	this->modules[4]  = "system/splash.h";
	this->modules[5]  = "system/gradle.h";
	this->modules[6]  = "logic/learn.cpp";
	this->modules[7]  = "drums/drums.cpp";
	this->modules[8]  = "logic/limits.cpp";
	this->modules[9]  = "entropy/header.h";
	this->modules[10]  = "speech/saying.cpp";
	this->modules[11]  = "system/modules.cpp";
	this->modules[12] = "logic/interpret.cpp";
	this->modules[13] = "system/protocol.cpp";
	this->modules[14] = "sampler/sampler.cpp";
	this->modules[15] = "logic/algorithms.cpp";
	this->modules[16] = "language/concepts.cpp";

	// example 1: // modules
	// #include "md5/md5.cpp"
	// #include "system/chk.h"
	// #include "../al/al.cpp"
	// #include "../al/header.h"
	// #include "system/splash.h"
	// #include "system/gradle.h"
	// #include "logic/learn.cpp"
	// #include "drums/drums.cpp"
	// #include "logic/limits.cpp"
	// #include "speech/saying.cpp"
	// #include "system/modules.cpp"
	// #include "logic/interpret.cpp"
	// #include "system/protocol.cpp"
	// #include "sampler/sampler.cpp"
	// #include "logic/algorithms.cpp"
	// #include "language/concepts.cpp"

	// print out all headers as module
	std::cout << std::endl;
	std::cout << "-::output::- __ registered (" << number_of_modules << ") headers __ *:_headers_:*_" << std::endl;
	std::cout << asterisktab << this->modules[0] << std::endl;
	std::cout << asterisktab << this->modules[1] << std::endl;
	std::cout << asterisktab << this->modules[2] << std::endl;
	std::cout << asterisktab << this->modules[3] << std::endl;
	std::cout << asterisktab << this->modules[4] << std::endl;
	std::cout << asterisktab << this->modules[5] << std::endl;
	std::cout << asterisktab << this->modules[6] << std::endl;
	std::cout << asterisktab << this->modules[7] << std::endl;
	std::cout << asterisktab << this->modules[8] << std::endl;
	std::cout << asterisktab << this->modules[9] << std::endl;
	std::cout << asterisktab << this->modules[10] << std::endl;
	std::cout << asterisktab << this->modules[11] << std::endl;
	std::cout << asterisktab << this->modules[12] << std::endl;
	std::cout << asterisktab << this->modules[13] << std::endl;
	std::cout << asterisktab << this->modules[14] << std::endl;

	std::cout << "\t<->" << std::endl;
}

void AI::test(int n=0) {

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
		// ltctap
		//run();	// run ltctap here ltctap(->) :: from "entropy/header.h"
		std::cout << "\t-:: -:: psht -:: <tap>" << std::endl;

	}
};

void check() { std::cout << "\t-:: check." << std::endl; }

void AI::init() {
	// INITIALIZATION
	// ALL INITIALIZATION HAPPENS HERE
	std::cout << "-:: initialization." << std::endl;

	int x=0;

	// gradle to help build cradle
	x=gradle();

	std::cout << "\t-:: gradle method finished. (";
	std::cout << x << ")" << std::endl;

	// file streams
	std::cout << "\t-:: opening file streams." << std::endl;
	// open file streams for tl
	this->openfs();
	// open read streams for t1
	this->openrs();

	// drum machine drum machine
	std::cout << "\t-:: drum machine" << std::endl;
	DrumMachine();
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

void AI::saygrace() {
	std::cout  << std::endl << std::endl << "::=> saying grace (routine) and closing libraries <::" << std::endl;
		
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

	// final AI message
	std::cout << "-:: done." << std::endl;
};

// eof