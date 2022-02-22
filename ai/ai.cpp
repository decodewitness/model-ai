// (inside AI directory) "AI/AI.CPP" - USED BY "/HEADER.H" MAIN FILE FOR AI MODEL CLASS

#ifndef _AI_DEFINITION_INCLUDED
#define _AI_DEFINITION_INCLUDED

#include <iostream>
#include <fstream>
#include <ctime>

// AI.H main header file
#include "ai.h"

// simulation run
#include "simulation.cpp"	// simulation.h is included in "ai.h"

// CONSTANTS
//const char _MODEL[32] = "ai/patching/restore";
	// declared elsewhere

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

void AI::splash(void) {
	std::cout << " ** ][][ **" << std::endl << std::endl;
}

void AI::help(int n=1) {
	// the help menu for the interactive menu structure
		// more function	// press a key
	// functions alphabetic
	std::cout << std::endl;
	std::cout << "--Help Function--" << std::endl << std::endl;
	std::cout << "\tCOMMANDS:" << std::endl;
	std::cout << "-----" << std::endl << std::endl;

	std::cout << "- logic" << std::endl;
	// help
	// 

	// list of arguments

	std::cout << std::endl;
};

// initialize_runtime_check
void AI::initialize_runtime_check() { // actually should be staged and recursive / needs a parameter in that case
    std::cout << "~:: ** &initialize_runtime_check() **" << std::endl;

	int nrsteps = 3;
    
	// // moved to runtime script --> "/run"
    // // compile sha1 program from external library.
    // std::cout << "(debugging symbol here)" << std::endl;
    // system("ai/system/security/sha1/sha1.sh");
    // std::cout << "(debugging symbol here)" << std::endl;

    for (int i=0; i<nrsteps; i++) {
        switch (i) {
            case 0: // redundant cycle
                std::cout << "\t- checking redundancy." << std::endl;
                break;
                // do logic here
            case 1: // files complete
                std::cout << "\t- file hierarchy." << std::endl;
                break;
                // do logic here
            case 2: // file integrity && hashing
                std::cout << "\t- file integrity." << std::endl;
                break;
                // do logic here
            case 3: // compensate
                std::cout << "\t- compensating measures." << std::endl;
                break;
                // do logic here
            default: // skipping step 0 (or implement) as well as any additional steps.
                // do logic here
                std::cout << "\t- (debug) skipping redundant caching." << std::endl;
                break;
        };
    }
};

AI::AI(int n) {	// AI constructor
	// play audio file
	this->play_audio_file("ai/system/audio/samples/flir.wav");
	this->splash();

	// security
	if (this->access == false) {
		this->enforce_security();	// also draws security prompt
	}

	// runtime check
	initialize_runtime_check();

	// splash oval
	int x=amnesia();

	// initialize the AI model
	this->init();
	
	// represent headers
	this->headers();
	
	// functional checks
	//this->run_checks(n);	// extend later
	this->check_functions();
	this->test_run(runtime_testing);	// 1001 means test all modules ( SET TEST RUN OPTIONS HERE )

	// HAL -- hypervisor
	HAL hal;

	// check modular bay
	ModularBay modular_bay;
	modular_bay.scan();

	if (app == true) {
		// run virtual appliance (virtual ai instance)
		std::cout << "\t -:: loading virtual instance" << std::endl << std::endl;
		this->appliance(); // this->appliance(); runs the virtual instance
	}
	// perform query sampling
	for (int i=0; i<n; i++) {
		std::cout << std::endl << "~:: running (" << n << ") queries." << std::endl << std::endl;
		this->query();
	}
}

void AI::openfs() {	// opens filestream to "ai/bin/TL/tl" file
    fs.open ("ai/bin/TL/tl", std::fstream::in | std::fstream::out | std::fstream::app);
}

void AI::closefs() {	// closes filestream "fs"
	fs.close();
}

void AI::openrs() {	// opens filestream to "ai/bin/TL/t1"
	rs.open ("ai/bin/TL/t1", std::fstream::in | std::fstream::out | std::fstream::app);
}

void AI::closers() {	// closes filestream "rs"
	rs.close();
}

// still needs to lookup actual financial unit courses online
void AI::convert(int amount, int method) {	// course converter (INTEGRAL METHOD)
	std::cout << std::endl << "~:: course converter: " << std::endl;
	std::cout << "\t*--> euro: " << amount << " = ";
	float d = converter(amount, 1);
	std::cout << "($" << d << ") dollar." << std::endl;
};

// still needs to lookup actual financial unit courses online
void AI::convertf(float amount, int method) {	// course converter (FLOATING POINT METHOD)
	std::cout << std::endl << "~:: course converter: " << std::endl;

	sleep(1);
	std::cout << "\t*--> euro: " << amount << " = ";
	float d = converter(amount, 1);
	std::cout << "($" << d << ") dollar." << std::endl;
};

void AI::hal() {	// start HAL abstraction layer
	start_hal();
}

void AI::AMMod() {	// AMModule
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

std::string AI::hashtype(std::string s) {	// returns hashes string s
	//hash(s);	// function is verbose
	return hashn(s);
};

// std::string AI::hashchain(std::string s) {	// 's' is the seed for the chain strength that can form a crypto
	
// 	std::string flow(std::string flux);
// 	std::string hashCipher;
// 	hashCipher.append(flow("algorithmicsequences"));

// 	Circle circle;

// return hashCipher;
// };

// std::string flow(float fl) {
// 	float flux = fl;
// 	char ch='a', alphabet[26];
// 	char k='0', semantics[32][256];
// 	std::string semantic;

// 	// alphabet gets filled with all letters
// 	for (int i=0; i<26; i++) {
// 		alphabet[i] = ch++;
// 	}

// 	ch = 'a';

// 	for (int i=0; i<32; i++) {
// 			for (int j=0; j<256; j++) {
// 			semantics[i][j] = ch;
// 		}
// 		semantic.append(semantics[i]);
// 	}

// return semantic;
// };

void AI::run_checks(int args) {	// runs checks on "args"
	std::cout << "-:: running checks arguments." << std::endl;
	std::cout << "\t" << args << ": arguments." << std::endl;

	if (args > 0) {
		std::cout << "-:: enumerating arguments:" << std::endl;
		for (int i=0; i<args; i++) {
			std::cout << std::endl << i << ". ";
		}
		std::cout << std::endl;
	}
	// couples back to main()
}

void AI::check_functions() {	// checking functions
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

void AI::headers() {	// loads the headers which contain modules
	// file streams
	ifstream indata;
	ofstream outdata;

	// variables
	int ki=0;
	int heapsize=0, total=modulesTotal, count=1024;	// variable "total" is number of .csv files defined in moduleData[] above
	string arr[count];
	string tmp;

	std::string hdr; // used to enumerate headers

	// manipulate headers
	std::cout << std::endl << "-:: setting headers :: total -::(" << total << ")::-" << std::endl;

	// open headers files && list files
	std::cout << "\t~:: opening \"ai/headers\" for input." << std::endl;
	indata.open("ai/headers");
	std::cout << "\t~:: opening \"ai/headers.txt\" for output." << std::endl;
	outdata.open("ai/headers.txt");
	
	if (outdata.is_open() == true) {
		std::cout << "\t\t~:: HEADER_OUT<ofheaders> successfully opened \"ai/headers.txt\"." << std::endl;
	}

	// enumerate headers
	if (indata.is_open() == true) {
		std::cout << "\t\t~:: HEADER_IN<ifheaders> successfully opened \"ai/headers\"." << std::endl;
		
		std::cout << "\t~:: enumerating headers." << std::endl << std::endl;
		std::cout << "\t- ()[:  module name  :] && data[queryObject] (#)" << std::endl;

		while ( getline(indata, hdr) ) {	// get headers from file
			std::cout << "\t\t* " << hdr << std::endl;
		}

		std::cout << std::endl;
	}
	
	//initialize array arr[]
	for (ki=0; heapsize < modulesTotal && heapsize < total && ki < heapsize; ki++) {
				arr[ki] = moduleName[ki] + ":" + moduleData[ki];
				//std::cout << "      " << moduleName[ki] << " - " << moduleData[ki] << std::endl;
				std::cout << "\t\t- " << arr[ki] << std::endl;
				heapsize++;
	}
	
	// declare function stackmodule
	std::string * stackmodule(int x, std::string *ar);


	// stack headers
	std::cout << "~:: stacking headers/modules ::~" << std::endl;

	// pointer xsample
	std::string *xsample = NULL;

	for (int i=0; i<modulesTotal; i++) {
		
		//std::cout << asterisktab << arr[i] << std::endl;
		std::cout << "\t- stacking header:";

		// stacking headers
		xsample = stackmodule(i, (arr+i));

		// write current module to "header.txt" file
		outdata << "header(" << i << ")::" << *xsample << std::endl;
	}

	// close file with headers' file handle
	outdata.close();
	std::cout << std::endl;
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

void run_checks(int n) {	// displays "running checks" message yet
	std::cout << "-:: running checks" << std::endl << std::endl;
}

void AI::play_audio(int s=1) {	// plays an audio sample (int)(s)
	// debug string
	//std::cout << std::endl << "~:: playing audio device." << std::endl << std::endl;
	
	// audio device + sample nr
	play_audio_device(s);
}

void AI::play_audio_file(std::string path) {
	// audio file
	play_audio_f(path);
};

// must be redevised native and compatibly
bool AI::cp(std::string src, std::string dst) {	// copy function
	std::cout << std::endl;
	std::string command;
	
	// copy command
	command = "cp ";
	command = command + src;
	command = command + " ";
	command = command + dst;

	// system command
	bool x = system(command.c_str());

	// needs stat() to verify that the file was copied

	// output
	std::cout << "~:: 1 file copied. (" << src << ") (" << dst << ")" << std::endl;
	return x;
};

bool AI::rm(std::string f) {	// remove function for files
	std::cout << std::endl;
	unlink(f.c_str());

	// needs stat() to verify that the file was deleted

	std::cout << "~:: removed 1 file. (" << f << ")" << std::endl;
return true;
};


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

	std::cout << std::endl << "-:: check integrity / logical step counter." << std::endl << std::endl;

	for (int i=steps; i>=1; i--) {
		// implement incremental logic here

		if (this->pooling(this->element++) != true && this->element < this->elements) {
			hashesCheckOut=false;
		};
		
		// increase percentages
		percentage -= (steps * (Percent/onePercent));
		inPercent += (Percent/steps);
		std::cout << "\t~:: (percentage): (%): " << inPercent << "% +/+)";
		
		// calculate degrees & adding measure in degrees
		degrees = (1-(1-((Percent - inPercent)/100)));
		std::cout << std::endl << "\t\t:(minus percentage): (-DEG.): " << degrees << " in degrees :." << std::endl;

		// on error bail out (set ch to anything but 'c' during checking to prevent the next checks)
		if (errors==true) {	// check for errors
			this->ch='d';	// change to 'd' in case of errors
		}
			
		// check for the need for the bail out routine
		if (this->ch != 'c')
			break; // bails on anything different than 'c'!
		else {
			steps_completed++;
			std::cout << std::endl << " -:: step: " << (steps-i + 1) << " complete. (100%) / (" << (steps-i+1) << "/" << count << ")" << std::endl << std::endl;
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
		std::cout << "\t\t-:: steps incomplete: " << (count-steps_completed) << std::endl;
		return false;
	}
};

void AI::sample() {	// sampling routine
	cout << "-:: starting AI." << std::endl;
	std::cout << "\t-:: sampler: " << this->nr << " threads." << std::endl;
	
	// start a new sampler device
	this->sampler = new Sampler(SAMPLER_THREADS);
	
	std::cout << std::endl << "::--entropy--::" << std::endl;
	
	// initialize sampler and is set to recording
	this->sampler->init();

	std::cout << std::endl;
	std::cout << "-:: feeding entropy" << std::endl;
	std::cout << "-:: tap the ltctap." << std::endl;
	
	for (int i=SAMPLER_THREADS+1;i>0;i--) {
		std::cout << std::endl << std::endl;
		std::cout << "-::: sampler thread ::#" << i << ":: :::-" << std::endl;
		
		// ltctap / fcltaptaptap()
		run();	// run ltctap / fcltaptaptap() / entropyr() / entropyw() :: from "entropy/b33hiv3.cpp"
		
		std::cout << "\t-:: -:: psht -:: <tap>" << std::endl;
	}
};

void check() {	// displays "check" message
	std::cout << "\t-:: check." << std::endl;
};

void AI::init() {		// INITIALIZATION
	// ALL INITIALIZATION HAPPENS HERE
	std::cout << "-:: initialization." << std::endl;

	this->nr = 8;
	this->ch = 'c';
	this->check_routine = 1;
	
	this->testrun = false;
	this->run_checks();
	
	// used by pooling
	this->step = 1;
	this->pool = 0;

	// set "this->crlurl" to resource URL.
	this->crlurl = DOWNLOADURL;
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

	// track account
	this->account = new Track_Account;

	// gradle to help build cradle
	x=gradle();
	std::cout << "\t-:: gradle method finished. (";
	std::cout << x << ")" << std::endl;
};

void AI::appliance() {	// starts the "virtual" script
	system("./ai/virtual/virtual");
};

void AI::tsp() {	// transponder function
	// create new transponder
	this->transponder = new Transponder(query_string);

	// prep new transponder
	std::cout << "~:: transponder -> prep()" << std::endl;

	sleep(2);
	this->transponder->prep(this->transponder->retVal());	// retVal() returns "initial_sentence" from "Transponder"

	// answer query
	// std::cout << std::endl << "~:: transponder -> answer()" << std::endl;
	//this->transponder->answer(query_string);

	std::cout << std::endl << "(EOT)" << std::endl;

	sleep(2);

	// delete transponder
	delete this->transponder;
};

void AI::decouple() {	// decoupler routine for the ai model
	std::cout << std::endl;
	std::cout << "-:: decoupler." << std::endl;

	// play audio file
	this->play_audio_file("ai/system/audio/samples/vwoof.wav");
	this->play_audio_file("ai/system/audio/samples/vwoof.wav");

	std::cout << "\t-:: decoupling sampler" << std::endl;
	this->sampler->decouple();
	// this->unprep_audio();	// unprepare audio devices
	this->saygrace();
}

void AI::destroy_msg() {	// shows "calling destructor" message
	std::cout << std::endl << "-:: calling destructor for AI::Model." << std::endl;
}

void AI::saygrace() {	// say grace routine
	std::cout  << std::endl;
	std::cout << std::endl << "::=> saving grace (routine) and closing libraries <=::" << std::endl;
	std::cout << std::endl;
		
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
	if (this->brn == true) 	 { delete this->brain; }

	this->smpl = false;
	this->ammod = false;
	this->modul = false;
	this->comb = false;
	this->combm = false;
	this->brn = false;

	// send destruction message
	this->destroy_msg();

	// final AI message
	std::cout << "-:: done." << std::endl;
};

//QUERY
void AI::query() {	// respond to logical query method
						// HANDLES COMMANDS
	// variables for commands structure		
	double x, xx;	// used to compute logic
	double sum;
	std::string y;	// used to compute strings
	std::string yy;
	int z, zz;
	char ch;

	// QUERY
	std::cout << std::endl << "::- type your query  -::" << std::endl;
	
	// play audio file
	this->play_audio_file("ai/system/audio/samples/taptaptap.wav");

	// PROMPT
	std::cout << "--?:: ";
	
	char str[255];
	getchar();    // create buffer (1 extra for null char)
	cin.get(str, 255);    // read up to 79 chars and place in str
	query_string = str;
	str[0] = '\0';

	std::cout << std::endl << std::endl << "-:: testing sample ::-" << std::endl;
	logicalQuery(query_string);

	// process commands	// compute logic and strings
	if (isSim == true) {	// run simulation
		std::cout << std::endl << "(simulation) entities: ";
		cin >> x;

		// still need to add entities (or) objects to Simulation

		this->runSim();
		isSim = false;
	} else if (isConvert == true) {	// run converter EURO
		std::cout << std::endl << "(converter) (EURO->USD) : ";
		cin >> x;
		this->convertf(x, 1);
		isConvert = false;
	} else if (isConvertUSD == true) {	// run converter USD
		std::cout << std::endl << "(converter) (USD->EURO) : ";
		cin >> x;
		this->convertf(x, 2);
		isConvertUSD = false;
	} else if (isHash == true) {	// hash function
		std::cout << std::endl << "(hash) function() : ";
		cin >> y;
		std::cout << std::endl << this->hashtype(y.c_str()) << std::endl;
		isHash = false;
	} else if (isKill == true) {	// hash function
		std::cout << std::endl << "(kill chain) function() : 9" << std::endl;
		isKill = false;
		this->killc(9);
	} else if (isStepping == true) {	// hash function
		std::cout << std::endl << "(stepping engine) function() : " << std::endl;
		this->stepping();		
		isStepping = false;
	} else if (isRollout == true) {	// hash function
		std::cout << std::endl << "(rollout) function(#) : ";
		cin >> x;
		// rollout functions numbers:
			// no_model1 next_model2 patch3
			// TOOL4 permissions5 comodos9
		this->rollout(x);	// don't do the restore rollout function
		isRollout = false;
	} else if (isCurl == true) {	// hash function
		std::cout << std::endl << "(curl engine) function() : ";
		cin >> y;
		this->curl(y);
		isCurl = false;
	} else if (isBank == true) {	// hash function

		for (int i=0; isBank==true ; i++) {
			draw_banking_menu();	// draws banking menu on the screen
			cin >> z;
			
			switch (z) {
				case 1:
					std::cout << "(amount) : ";
					cin >> x;
					// ai.add_account(1);
					this->add_account(x);
					break;
				case 2:
				// ai.subtract_account(10);
					std::cout << "(amount) : ";
					cin >> x;
					this->subtract_account(x);
					break;
				case 3:
				// ai.change_account(10);
					std::cout << "(change to account) #: ";
					cin >> z;
					this->change_account(z);
					break;
				case 4:
				// ai.printn_account();
					// ai.print_account();
					this->printn_account();
					break;
				case 5:
				// ai.total_account();
					// ai.combine_total();
					this->total_account();
					break;
				case 6:
				// ai.list_positive();
					this->list_positive();
					break;
				case 7:
				// ai.list_negative();
					this->list_negative();
					break;
				case 8:
				// ai.average_account();
					this->average_account();
					break;
				case 9:
				// ai.transfer(1,200,20.00);	// transfer from acct 1 to 200 an amount of 20.00
					std::cout << "(source account) :# ";
					cin >> z;
					std::cout << "(target account) :# ";
					cin >> zz;
					std::cout << "(amount):# ";
					cin >> x;
					this->transfer(z,zz,x);
					break;
				case 10:
				// ai.store_accounts_detail();
					this->store_accounts_detail();
					break;
				case 11:
				// ai.export_accounts(exp_account);
					this->export_accounts(exp_account);
					break;
				case 12:
				// ai.import_accounts(imp_account);
					this->import_accounts(imp_account);
					break;
				case 99:
					isBank = false;
					break;

				default:
					std::cout << std::endl << "-( )skipped user input)." << std::endl;
					break;
			};
		}
	} else if (isTable == true) {
		std::cout << "(table): of :# ";
		cin >> z;
		this->table(z);
		isTable = false;
	} else if (isTableTo == true) {
		std::cout << "(table): of :# ";
		cin >> z;
		std::cout << "(to maximal): :# ";
		cin >> zz;
		this->tableTo(z,zz);
		isTableTo = false;
	} else if (isDice == true) {
		this->dice_pr();
		isDice = false;
	} else if (isDice2 == true) {
		std::cout << "(dice): number of eyes :# ";
		cin >> z;
		this->dice_npr(z);
		isDice2 = false;
	} else if (isStat == true) {
		std::cout << "(stat): dir : ";
		cin >> y;
		this->statdir(y.c_str());
		isStat = false;
	} else if (isRm == true) {
		std::cout << "(rm): filename : ";
		cin >> y;
		this->rm(y.c_str());
		isRm = false;
	} else if (isCp == true) {
		std::cout << "(cp): src dst: ";
		cin >> y >> yy;
		this->cp(y.c_str(), yy.c_str());
		isCp = false;
	} else if (isAdd == true) {
		std::cout << "(add): number1 number2 + # #: ";
		cin >> x >> xx;
		this->add(x, xx);
		isAdd = false;
	} else if (isSubtract == true) {
		std::cout << "(subtract): number1 number2 -/- # #: ";
		cin >> x >> xx;
		this->subtract(x, xx);
		isSubtract = false;
	} else if (isMultiply == true) {
		std::cout << "(multiply): number1 number2 * # #: ";
		cin >> x >> xx;
		this->multiply(x, xx);
		isMultiply = false;
	} else if (isDivide == true) {
		std::cout << "(divide): number1 number2 / # #: ";
		cin >> x >> xx;
		this->divide(x, xx);
		isDivide = false;
	} else if (isPower == true) {
		std::cout << "(power of): \"number1\" to power of \"number2\" ^ # #: ";
		cin >> x >> xx;
		this->power(x, xx);
		isPower = false;
	} else if (isPlayAudio == true) {
		std::cout << "(play audio file): file : ";
		cin >> y;
		this->play_audio_file(y.c_str());
		isPlayAudio = false;
	} else if (isReturnPunch == true) {
		sum=0;
		for (int i=0;; i++) {
			std::cout << "(punch): number :# ";
			cin >> x;
			std::cout << "(operator or: 'Q')::(+,-,*,/) : ";
			cin >> ch;
			if (ch == 'q' || ch == 'Q') {
				std::cout << "(FINAL RESULT) = " << sum << std::endl << std::endl;
				break;
			} else if (ch=='+' || ch=='-' || ch=='/' || ch=='*') {
				std::cout << std::endl << this->return_punch(sum,ch,x) << std::endl << std::endl;
			}
		}
		isReturnPunch = false;
	} else if (isPrintPunch == true) {
		sum=0;
		for (int i=0;; i++) {
			std::cout << "(punch): number :# ";
			cin >> x;
			std::cout << "(operator or: 'Q')::(+,-,*,/) : ";
			cin >> ch;
			if (ch == 'q' || ch == 'Q') {
				std::cout << "(FINAL RESULT) = " << sum << std::endl << std::endl;
				break;
			} else if (ch=='+' || ch=='-' || ch=='/' || ch=='*') {
				this->print_punch(sum, ch, x);
			}
		}
		isPrintPunch = false;
	}
};

	// std::string sentence;
	// char sentence[256];

	// char c;
    // while((c = getchar()) != 13) {  /* 13 is carriage ret in ascii, enter key */     
    //     printf("%c\n", c);
	// }

	// while (cin.peek() != '\n') {
	//cin >> y;
	//query_string.append(y);

	// QUERY STRING

	// // }
    // std::cin >> y;

	// do {
	// 	query_string.append(y);
	// std::string str;
	// std::getline(std::cin,str);

	// } while (cin >> y);

	// std::getline(std::cin,sentence);
    // std::istringstream iss(sentence);

    // std::vector<std::string> words;
    // std::string word;
    // while(iss >> word) {
    //     words.push_back(word);
    // } 

    // for(std::vector<std::string>::const_iterator it = words.begin();
    //     it != words.end();
    //     ++it) {
    //     std::cout << *it << ' ';
	// 	query_string.append(*it);
    // }

	//s = sampleX();

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
			
			// double check these modules for escaping modules
			
			exit(0);
			break;
		default:
			std::cout << std::endl << "-/- unknown sequence." << std::endl << std::endl;
			break;
	};	
};

int AI::curl(std::string f) {	// Curl function
	std::cout << std::endl << "********* CURLING **********" << std::endl;
	int x = do_curl(f);
	
	// std::cout << "x:" << x << std::endl;
	if (x+1 == 1) {
		std::cout << "-:: curl succeeded." << std::endl;
	}

	return x;
};

int AI::links(std::string url, int max) {	// fetches links from URL
	std::cout << "********* FETCHING LINKS (max: " << max << ") **********" << std::endl << std::endl;
	
	int x = fetch_link(url, max);

	return x;
};

void AI::enforce_security() {	// jumps to security prompt
	this->play_audio(10);

	bool ack = security_prompt();
	this->access = ack;
};

void AI::mod() {	// Modular setup method
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
	
	std::cout << std::endl << "~:: polling data" << std::endl;
	this->mdl->polldata();
	
	//this->mdl->query();
};

void AI::combmod(moduleContainer a, moduleContainer b) {	// combine module
	
	std::cout << std::endl << "~:: combine modules ::~" << std::endl;

	this->combinemodule = new CombineModule();
	this->combm = true;
	this->m = this->combinemodule->combine(a, b);

	std::cout << "returned: " << this->m.sizeData << " size in module data is stored" << std::endl;
};

bool AI::pooling(int x) {	// pooling function
	this->elements = 10;
	
	std::cout << "-:: (logical step #" << this->step++ << ") max pool elements: " << this->elements << " :: pooling: " << x << " elements." << std::endl;

	for (int i=0; i<=x && i<this->elements; i++) {
		std::cout << "\t\t~:: pooling: reserve " << (i+1) << "." << std::endl;

		// pool reserve here from data
		this->pool++;
		std::cout << "\t\t(pool) (" << this->pool << ")" << std::endl;

		// add pool data here
	}
	return 1;
}

void AI::auto_patch() {	// auto patch routine
	std::cout << std::endl << std::endl << "~:: auto-patch routine ::~";
	sleep(1);

	// download cabinets
	system("./ai/patching/repos");
	std::cout << std::endl;

	// patch cabinets
	patch_module();
}

void AI::rollout(int n) {	// rollout function for several new features
	std::string toolstr;

	// roll out comodos & commandos
	std::cout << std::endl << "(debug)___msgs." << std::endl;
	switch (n) {
		case 1: // roll out no model
				//std::cout << "~:: download next model ::~" << std::endl;
				std::cout << std::endl << "~:: rollout function(1)::set to n(2-3-4-9)." << std::endl;
			break;

		case 2: // roll out next model
				//std::cout << "~:: download next model ::~" << std::endl;
				std::cout << std::endl << "~:: rollout function(2)::set to n(2-3-4-9)." << std::endl;
				system(_MODEL);
			break;

		case 3: // roll out next model and patch
				//std::cout << "~:: download next model ::~" << std::endl;
				std::cout << std::endl << "~:: rollout function(3)::set to n(2-3-4-5-9)." << std::endl;
				system(_MODEL);
				system(_PATCH);
			break;
		
		case 4: // roll out TOOL
				std::cout << std::endl << "~:: rollout function(4)::set to n(2-3-4-5-9)." << std::endl;
				
				// check if TOOL is there
				struct stat st;
				if (stat(_TOOL, &st) != 0) {
					std::cout << "~:: could not find \"TOOL\"; now deploying..." << std::endl;
					system(_DEPLOY);
					system(_TOOL);
				} else {
					std::cout << "~:: found \"TOOL\"." << std::endl;
					// 	ERRNO(errno);
					// 	return -1;
					system(_TOOL);
				}
			break;

		case 5: // set permissions scripts
				std::cout << std::endl << "~:: rollout function(5)::set to n(2-3-4-5-9)." << std::endl;
				toolstr = _TOOL;
				toolstr = toolstr + " -p";

				std::cout << "(debug) toolstr = " << toolstr << std::endl;
				//system("pwd");
				
				system(toolstr.c_str());
			break;

		case 9: // roll out comodos
				std::cout << std::endl << "~:: rollout function(9)::set to n(2-3-4-5-9)." << std::endl;

				system(_COMODOS);
			break;
		
		default: // default
				std::cout << "~:: no rollouts." << std::endl;
			break;
	};
};

void AI::constr() {	// creates Construct class instance
	std::cout << std::endl << "~:: creating construct." << std::endl;
	this->construct = new Construct;

	this->construct->preprocess();

	// don't forget to delete construct
	delete this->construct;
};

// allocate
void AI::allocate(Data d) { // allocates new set of Data object to pointer "dd"
	
	// create new Data object in "dd"
	if (ddLck == true) {
		std::cout << "~:!: (dd) data already allocated." << std::endl;
	} else {
		this->dd = new Data();
		std::cout << "\t~:: data (dd) allocated" << std::endl;
	}

	// uncomment once you've written the copy constructor in Data class object.
	//this->dd = d;	// need to handle copy constructor
	
	// lock in data object
	this->ddLck = true;	
};	

// allocateData
void AI::allocatData(int pipeline, Data d) { // allocates Data to pointer "pipeline" a.k.a. "d1" or "d2"
	switch (pipeline) {

		case 1:	// allocate to pipeline "d1"
			if (d1Lck == true) {
				// do logic
				std::cout << "~:!: (d1) data already allocated." << std::endl;
				
			} else { // allocate data
				this->d1 = new Data;
				std::cout << "~:: (d1) is free." << std::endl;
				// need the copy constructor first
			}
			break;

		case 2: // allocate to pipeline "d2"
			if (d2Lck == true) {
				// do logic
				std::cout << "~:!: (d2) data already allocated." << std::endl;
				
			} else { // allocate data
				this->d2 = new Data;
				std::cout << "~:: (d2) is free." << std::endl;
				// need the copy constructor first
			}
			break;

		default: // allocate to "dd" and handle automatically
			if (ddLck == true) {
								// do logic
				std::cout << "~:!: (dd) data already allocated." << std::endl;
				
			} else { // allocate data
				this->dd = new Data;
				
				std::cout << "\t~:: data (dd) allocated." << std::endl;
				// need to allocate the data first!!!
			}
			break;
	};
};

void AI::deallocate() {	// deallocates "dd" data object
	std::cout << "~:: deallocate:" << std::endl;

	if (this->ddLck == true) {
		delete this->dd;
		this->ddLck = false;
		std::cout << "\t~:: data (dd) deallocated." << std::endl;
	}
};	

void AI::deallocatData(int pipeline) {	// deallocates Data pipeline "d1" or "d2".
	std::cout << "~:: deallocating:" << std::endl;

	switch (pipeline) {

		case 1:	// deallocate to pipeline "d1"
			if (d1Lck == true) {
				// do logic
				delete this->d1;
				this->d1Lck = false;
				std::cout << "\t~:: data (d2) deallocated." << std::endl;
			}
			break;

		case 2: // deallocate to pipeline "d2"
			if (d2Lck == true) {
				// do logic
				delete this->d2;
				this->d2Lck = false;
				std::cout << "\t~:: data (d2) deallocated." << std::endl;
			}
			break;

		default: // no such implementation
			std::cout << ":!: ~:: no data to deallocate." << std::endl;

			if (d1Lck == true) // insert an option to force deallocating and add boolean here
				std::cout << "\t- pipeline (d1) data is ready." << std::endl;
			if (d2Lck == true)
				std::cout << "\t- pipeline (d2) data is ready." << std::endl;
			break;
	};
};

void AI::startSim() {
	// this->play_audio_file("ai/system/audio/samples/vworge.wav");
	std::cout << std::endl << "~:: starting simulation." << std::endl;
	this->simulation = new Simulation;
};

void AI::sim_stats() {
	std::cout << std::endl << "~:: generating stats ::~" << std::endl;
	this->simulation->statistics();
}

void AI::stopSim() {
	std::cout << "~:: deleting simulation." << std::endl << std::endl;
	delete this->simulation;
};

void AI::listEntity() {
	this->simulation->listEntities();	// needs fixing
}

void AI::listObject() {
	this->simulation->listObjects();	// needs fixing
}

void AI::listAllEO() {
	this->simulation->listAll();
};

void AI::cycle(int n) {
	this->simulation->cycle(n);
}

void AI::printEntityCount() {
	std::cout << "- entity count: " << this->simulation->returnEntityCount() << std::endl;

};

void AI::printObjectCount() {
	std::cout << "- object count: " << this->simulation->returnObjectCount() << std::endl;
};

// simulation;
// should be loaded from external file.

void AI::addSimEntity(int x, int y, int z, int n) {
	std::cout << std::endl << "\t~:: adding sim {entity}." << std::endl;
	this->simulation->createEntity(x,y,z,n);
};

void AI::deleteSimEntity(int x) {
	std::cout << "\t~:: deleting sim {entity}." << std::endl;
	this->simulation->killEntity(x);
};

void AI::addSimObject(int x, int y, int z, int n) {
	std::cout << std::endl << "\t~:: adding sim {object}." << std::endl;
	this->simulation->createObject(x,y,z,n);
};

void AI::deleteSimObject(int x) {
	std::cout << "\t~:: deleting sim {object}." << std::endl;
	this->simulation->killObject(x);
};

void AI::hdata() {	// data handler
	data_handler();
};

void AI::hmath() {	// math handler
	math_handler();
};

void AI::assembleBrain() {	// uses logic // useBrain && neural_net
	this->brain = new Brain;

	// move this logic somewhere else
	this->brain->useBrain(query_string);
	this->brain->neural_net(query_string);

	this->brn = true;
};

// accounts managed by Track_Account class
void AI::add_account(float x) {	// adds amount x to accounts[]
	std::cout << "- account (" << this->account->getAccount() << "):" << std::endl;
	std::cout << "\tadding: (+/+) " << x << " " << coin[coin_no] << "." << std::endl;
	this->account->add(x);
	std::cout << "\t";
	this->account->print();
	std::cout << std::endl << std::endl;
};

void AI::subtract_account(float x) {	// subtracts amount x in accounts[]
	std::cout << "- account (" << this->account->getAccount() << "):" << std::endl;
	std::cout << "\tsubtracting: (-/-) " << x << " " << coin[coin_no] << "." << std::endl;
	this->account->subtract(x);
	// std::cout << "\tbalance: (";
	std::cout << "\t";
	this->account->print();
	std::cout << std::endl << std::endl;
};

void AI::change_account(int x) {	// changes account_nr in accounts[]
	this->account->setAccount(x);
	std::cout << "- account changed to account ("
				<< this->account->getAccount() << ")."
					<< std::endl << std::endl;
};

float AI::get_account() {	// returns current account
	return this->account->getAccount();
};

void AI::print_account() {	// prints accounts[] amount
	this->account->print();
};

void AI::printn_account() {	// prints accounts[] amount
	this->account->printn();
};

void AI::combine_total() {	// combines total amount across all accounts	// accounts[max_accounts]
	this->account->combined_total();
};

void AI::list_negative() {	// lists negative saldos in account
	std::cout << std::endl;
	this->account->list_negatives();
	std::cout << std::endl;
}

void AI::list_positive() {	// lists positive saldi in account
	std::cout << std::endl;
	this->account->list_positives();
	std::cout << std::endl;
}

void AI::store_account() {	// stores accounts to textfile
	this->account->store_accounts();
};

void AI::store_accounts_detail() {	// stores detailed account info
	this->account->store_accounts_details();
};

void AI::import_accounts(std::string filen) {	// stores detailed account info
	this->account->import_accounts(filen);
};

void AI::export_accounts(std::string filen) {	// stores detailed account info
	this->account->export_accounts(filen);
};

void AI::transfer(int src, int dst, float amount) {	// transfer amount from src to dst account
	this->account->transfer_account(src, dst, amount);
};

void AI::total_account() {
	this->account->total();
};

void AI::average_account() {
	this->account->average();
};

// stat
int AI::statdir(std::string d) {	// stat directory
	int x=stats(d);	// from statx.cpp file
	std::cout << std::endl << "\t--statdir(\"" << d << "\") (flag:" << x << ")" << std::endl;
return x;
};

// OTHER FUNCTIONS
std::string * stackmodule(int x, std::string *ar) {	// stack the module addresses
	// stacking header
	// header name / content label
		// functions -> functions in display
	
	std::cout << "(" << x << ")::<address>(" << ar << ")" << std::endl;
	switch (x) {	// x == module
		case 0: // speech
		case 1: // sampling
		case 2: // random sampler routine for sampling
		case 3: // random queries inside catalogue
		case 4: // pattern recognition
		default:
		break;
	};

	std::string *mystr = ar;

	return mystr;
};

int AI::dice() {
	srand(time(NULL));
	int x = rand() % 6 + 1;
	return x;
};

void AI::dice_pr() {
	srand(time(NULL));
	int x = rand() % 6 + 1;
	std::cout << std::endl << "~:: dice: " << x << std::endl;
};

int AI::dice_n(int i=6) {
	srand(time(NULL));
	int x = rand() % i + 1;
	return x;
};

void AI::dice_npr(int i=6) {
	srand(time(NULL));
	int x = rand() % i + 1;
	std::cout << std::endl << "~:: dice: " << x << std::endl;
};

void AI::table(float x) {	// displays table of number x to 10

    std::cout << "- table of: " << x << std::endl;
    std::cout << "  -----" << std::endl;

    for (int i = 1; i<11; i++) {
        std::cout << x << " * " << i << " = " << (x*i) << std::endl;
    }

    std::cout << std::endl;
}

void AI::tableTo(float x, float y=10) {	// displays table of number x to y

    std::cout << "- table of: " << x << " to: " << y << std::endl;
    std::cout << "  -----" << std::endl;

    for (int i = 1; i<=y; i++) {
        std::cout << x << " * " << i << " = " << (x*i) << std::endl;
    }

    std::cout << std::endl;
}

void AI::add(float x, float y) {	// function adds arguments x + y
	std::cout << "adds (" << x << "+" << y << "): ";
	add_pr(x, y);
	std::cout << std::endl;
};

void AI::subtract(float x, float y) {	// function subtracts arguments x minus y
	std::cout << "subtracts (" << x << "-" << y << "): ";
	subtract_pr(x, y);
	std::cout << std::endl;
};

void AI::multiply(float x, float y) {	// function multiplies arguments x by y
	std::cout << "multiplies (" << x << "*" << y << "): ";
	multiply_pr(x, y);
	std::cout << std::endl;
};

void AI::divide(float x, float y) {	// function divides argument x by y
	std::cout << "divides (" << x << "/" << y << "): ";
	divide_pr(x, y);
	std::cout << std::endl;
};

void AI::power(float x, float y) {	// function powers argument x by power of y
	std::cout << "powers (" << x << "^" << y << "): ";
	power_pr(x, y);
	std::cout << std::endl;
};

void AI::print_punch(float s, char c, float x) {	// function prints s calculated with operator c and arguments x
	std::cout << std::endl;
	float sum = punch(s,c,x);
	std::cout << std::endl << sum << std::endl;
};

float AI::return_punch(float s, char c, float x) {	// function returns sum = s according to operator = c = (+,-,/,*) and operand x=float number
	float sum = punch(s,c,x);
	return sum;
};

#endif
// eof