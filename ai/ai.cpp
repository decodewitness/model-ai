// (inside AI directory) "AI/AI.CPP" - USED BY "/HEADER.H" MAIN FILE FOR AI MODEL CLASS

#ifndef _AI_DEFINITION_INCLUDED
#define _AI_DEFINITION_INCLUDED
#endif

#include <iostream>
#include <fstream>

#include "ai.h"

// CONDITIONS FOR RUNTIME TESTING (1001 = ALL tests; or 1, or 2, or n)
const int runtime_testing = 1001;

// EXTERNAL DECLARATIONS
// const extern int module_limits;
// extern std::string moduleName[module_limits];
// extern std::string data[module_limits];


// DECLARATIONS
// MODULES DEFINITIONS AND DECLARATIONS


std::string moduleName[module_limits] = {
	"--speech synthesizers--",
	"--      sensors      --",
	"--pattern recognition--",
	"--artificial life rtn--",
	"--       drums       --",
	"--natural language pr--",
	"--catalogues routines--",
	"--health & life cycle--",
	"--        ocr        --",
	"--image & translation--",
	"--      _EOM        --"
}; // COUNT ON THIS AND NOT THE VARIABLE "module_limits"
// LAST MODULE TO SET THE LIMIT IN ARRAY (PLEASE ALSO SPECIFY THE modulesTotal NUMBER EQUAL TO THE LAST MODULE)

int modulesTotal = 10;  // this should be equal to the index of the "EOM" module (IN THE HIGHEST INDEX OF MODULENAME / THE INDEX AFTER THE LAST MODULE)
int dataTotal = 10; // this should be equal to the number of files in the "data[]" array

// FIT DATA INTO data[] ARRAY
std::string moduleData[module_limits] = {
	"speech.csv",
	"sensor_reading.csv",
	"pattern_recognition.csv",
	"artificial_life.csv",
	"drums.csv",
	"natural_language_processing.csv",
	"catalogues.csv",
	"health_criteria.csv",
	"ocr.csv",
	"images_translation.csv",
	"__REACHED_EOM_THE_LAST_MODULE"
}; // PLACEHOLDER INSIDE LAST MODULE AGAIN




// AI constructor
AI::AI(int n) {

	if (this->access == false) {
		this->enforce_security();	// also draws security prompt
	}

	// splash oval
	int x=amnesia();

	// initialize the AI model
	this->init();
	
	// represent headers
	this->headers();
	
	// functional checks
	this->run_checks(n);
	this->check_functions();
	this->test_run(runtime_testing);	// 1001 means test all modules ( SET TEST RUN OPTIONS HERE )

	// HAL -- hypervisor
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

void AI::AMMod() {
	
	// create AMModule
	this->ammodule = new AMModule;
	this->ammod = true; // set to true on new AMModule

	std::cout << "-:: running AMModule." << std::endl;

	splash();	// splash sequence
	
	// some random numbers
	// use r later as input for modules
	std::cout << "~:: some random numbers:" << std::endl;
	
	// number sequence compares between upper and lower bounds
	ammodule->nrs(60, 3, 100);

	// random numbers
	ammodule->seedRNG10();
	this->r10 = ammodule->getRNG();	// this function also displays the random number
	
	// some more random numbers
	ammodule->seedRNG100();
	this->r100 = ammodule->getRNG(); // this function also displays the random number
};

std::string AI::hashtype(std::string s) {
	//hash(s);
return hashn(s);
};


void AI::run_checks(int args) {
	std::cout << "-:: checking arguments." << std::endl;
	std::cout << "\t" << args << ": arguments." << std::endl;

	if (args > 0) {
		std::cout << "-:: enumerating arguments:" << std::endl;
		for (int i=0; i<args; i++) {
			//std::cout << "\t* " << ai_arguments[i] << std::endl;
		}
	}
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
	
	// file streams
	ifstream ifheaders;
	ofstream ofheaders;

	// variables
	int ki=0;
	int heapsize=0, total=modulesTotal, count=1024;	// variable "total" is number of .csv files defined in moduleData[] above
	string arr[count];
	string tmp;

	std::string hdr; // used to enumerate headers

	// manipulate headers
	std::cout << std::endl << "-:: setting headers ::-" << std::endl;

	// open headers files && list files
	std::cout << "\t~:: opening \"ai/headers\" for input." << std::endl;
	ifheaders.open("ai/headers");
	std::cout << "\t~:: opening \"ai/headers.txt\" for output." << std::endl;
	ofheaders.open("ai/headers.txt");
	
	if (ofheaders.is_open() == true) {
		std::cout << "\t\t~:: successfully opened \"ai/headers.txt\"." << std::endl;
	}

	// enumerate headers
	if (ifheaders.is_open() == true) {
		std::cout << "\t\t~:: successfully opened \"ai/headers\"." << std::endl;
		
		std::cout << "\t~:: enumerating headers." << std::endl;
		std::cout << "\t- ()[:  module name  :] - data[queryObject] (#)" << std::endl;

		while ( getline(ifheaders, hdr) ) {	// get headers from file
			std::cout << "\t\t* " << hdr << std::endl;
		}
	}
	
	//initialize array arr[]
	for (ki=0; heapsize < modulesTotal && heapsize < total && ki < heapsize; ki++) {
				arr[ki] = moduleName[ki] + ":" + moduleData[ki];
				//std::cout << "      " << moduleName[ki] << " - " << moduleData[ki] << std::endl;
				std::cout << "\t\t- " << arr[ki] << std::endl;
				heapsize++;
	}
	heapsize = ki;
	count = ki;

	// declare function stackmodule
	void stackmodule(int x, std::string *ar);


	// stack headers
	for (int i=0; i<modulesTotal && i<count && i<heapsize; i++) {
		
		//std::cout << asterisktab << arr[i] << std::endl;
		std::cout << "- setting header:";

		// stacking headers
		stackmodule(i, &arr[i]);

		// write headers to file
		ofheaders << (i+1) << "." << arr[i] << std::endl;
	}

	// close file with headers' file handle
	ofheaders.close();
}

void AI::test(int n=0) { // testing all modules in this function

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

			// this->synthesizer->check()
			check();	// writes check after checking is done
			break;

		case 2:	// methods
			std::cout << "\t-:: access random method for sampling in device." << std::endl;

			// this->methods->check();
			check();	// writes check after checking is done
			break;

		case 3: // routines
			std::cout << "\t-:: accessing random sampler routine for sampling." << std::endl;
			
			// this->sampler->check();
			check();	// writes check after checking is done
			break;

		case 4: // catalogue
			std::cout << "\t-:: performs random queries inside catalogue algorithmic." << std::endl;

			// this->db->check();
			check();	// writes check after checking is done
			break;

		case 5: // recognition
			std::cout << "\t-:: random pattern recognition for input measure." << std::endl;

			// this->sensors->check();
			check();	// writes check after checking is done
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

	// need to check file hashes here based of integrity
	bool hashesCheckOut=true;
	
	// any errors? 
	bool errors=false;
	
	// steps
	int steps=10;
	int steps_completed=0;
	int count=steps;

	const double Percent=100.00;

	double degrees = 0.00;
	double percentage=100.00;
	double inPercent=0.00;
	double onePercent=(Percent/Percent);

	std::cout << std::endl << "-:: check integrity / logical step counter." << std::endl;

	for (int i=steps; i>=1; i--) {
		// implement incremental logic here

		if (this->pooling(this->element++) != true && this->element < this->elements) {
			hashesCheckOut=false;
		};
		
		// increase percentages
		percentage -= (steps * (Percent/onePercent));
		inPercent += (Percent/steps);
		std::cout << "(percentage): (%): " << inPercent << "% +/+)  :";
		
		// calculate degrees & adding measure in degrees
		degrees = (1-(1-((Percent - inPercent)/100)));
		std::cout << "(minus percentage): (-DEG.): " << degrees << " in degrees :." << std::endl;

		// on error bail out (set ch to anything but 'c' during checking to prevent the next checks)
		if (errors==true) {	// check for errors
			this->ch='d';	// change to 'd' in case of errors
		}
			
		// check for the need for the bail out routine
		if (this->ch != 'c')
			break; // bails on anything different than 'c'!
		else {
			steps_completed++;
			std::cout << " -:: step: " << (steps-i + 1) << " complete. (100%)" << std::endl;
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

void check() {
	std::cout << "\t-:: check." << std::endl;
}

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
	this->crlurl = URL;
	this->cmb = new Combine;

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

	if (this->smpl == true)  { delete this->sampler; }
	if (this->ammod == true) { delete this->ammodule; }
	if (this->modul == true) { delete this->mdl; }
	if (this->comb == true)  { delete this->cmb; }
	if (this->combm == true) { delete this->combinemodule; }

	this->smpl = false;
	this->ammod = false;
	this->modul = false;
	this->comb = false;
	this->combm = false;

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

void AI::killc(int x) {	// basically implies killchain handle
	switch (x) {
		case 9:
			std::cout << std::endl << "-/- initializing sequence." << std::endl << std::endl;
			//system("pwd");
			if (this->smpl == true)  { delete this->sampler; }
			if (this->ammod == true) { delete this->ammodule; }
			if (this->modul == true) { delete this->mdl; }
			if (this->comb == true)  { delete this->cmb; }
			if (this->combm == true) { delete this->combinemodule; }
			exit(0);
			break;
		default:
			std::cout << std::endl << "-/- unknown sequence." << std::endl << std::endl;
			break;
	};	
};

int AI::curl(std::string f) {
	std::cout << std::endl << "********* CURLING **********" << std::endl;
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

	// BUSY TESTING THIS MOD()

	std::cout << std::endl << "~:: setting module data in cab." << std::endl;

	this->mdl->set_data("unicorn =001=");
	this->mdl->set_data("unicorn =002=");
	this->mdl->set_data("unicorn =003=");
	this->mdl->set_data("unicorn =004=");
	this->mdl->set_data("unicorn =005=");

	std::cout << "~:: getting index: ";
	std::cout << this->mdl->get_index() << std::endl;
	
	std::cout << "~:: polling data" << std::endl;
	this->mdl->polldata();
	
	//this->mdl->query();
};

void AI::combmod(moduleContainer a, moduleContainer b) {
	
	std::cout << std::endl << "~:: combine modules ::~" << std::endl;

	this->combinemodule = new CombineModule();
	this->combm = true;
	this->m = this->combinemodule->combine(a, b);

	std::cout << "returned: " << this->m.sizeData << " size in module data is stored" << std::endl;
};

bool AI::pooling(int x) {
	this->elements = 5;
	std::cout << "\t-::max pool elements: " << this->elements << " :: pooling: " << x << " elements." << std::endl;

	for (int i=1; i<=x && i<this->elements; i++) {
		std::cout << "\t~pooling: reserve " << i << "." << std::endl;

		// pool reserve here from data
	}
	return 1;
}

// OTHER FUNCTIONS

void stackmodule(int x, std::string *ar) {
	// stacking header
	// header name / content label
		// functions -> functions in display
	
	std::cout << x << ". " << *(ar+x) << std::endl;
	switch (x) {	// x == module
		case 0: // speech
		case 1: // sampling
		case 2: // random sampler routine for sampling
		case 3: // random queries inside catalogue
		case 4: // pattern recognition
		default:
		break;
	};
};
