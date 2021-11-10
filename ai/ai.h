// (inside AI directory) "AI/AI.H" - MAIN HEADER FILE FOR AI MODEL CLASS (USED BY AI.CPP)

#ifndef _AI_HEADER
#define _AI_HEADER
#endif

#define URL "https://model-ai.com/ai"

#include <cstring>

// database
#include "database/db.cpp"

// asterisktab & amnesia splashing routines
#include "logic/ascii/amnesia.h"
#include "logic/ascii/asterisktab.h"

// hal
#include "al/al.cpp"

// configurations
#include "cfg/config.h"

// modules
#include "system/chk.h"
#include "fetch/curl.cpp"
#include "system/splash.h"
#include "system/gradle.h"
#include "logic/learn.cpp"
#include "logic/limits.cpp"
#include "entropy/b3hiv3.h"		// includes entropy.cpp && ltctapttclt.cpp
#include "logic/interpret.cpp"
#include "system/protocol.cpp"
#include "sampler/sampler.cpp"
#include "logic/algorithms.cpp"
#include "language/concepts.cpp"
#include "drum_machine/drums.cpp"
#include "logic/assembly/input.cpp"
#include "language/speech/saying.cpp"
#include "system/modules/modular.cpp"	// includes AMModule.h and Modular
#include "system/modules/combine.cpp"
#include "system/security/security.cpp"
#include "logic/transponder/transponder.cpp"


// DON'T MESS WITH THIS SETTING -- this setting to "true" runs the virtual appliance.
	// --- VIRTUAL APP APPLIANCE CONTROL SETTING ---
bool app = false;
// --- VIRTUAL APP APPLIANCE CONTROL SETTING ---
	// --- VIRTUAL APP APPLIANCE CONTROL SETTING ---

	
const int nr_modules = 19;	// equal to the number of includes in "modules" (above in this file)
const int SAMPLER_THREADS = 8;

class AI {

private:
	int nr;
	int check_routine;

	int r10; // for storing random number <=10
	int r100; // for storing random number <=100

	char ch;
	bool testrun;
	bool recordat;

	bool access;

	AMModule *ammodule;
	Modular *mdl;
	Combine *cmb;
	Sampler *sampler;
	
	bool ammod;
	bool modul;
	bool comb;
	bool smpl;
	

	std::string number_modules[nr_modules];	// thesr_oe are all files and used to construct the virtual domain
	std::string crlurl;

public:

	AI(int n=1);

	// round init
	void init();

	// headers
	void headers();
	
	// checking mechanisms
	void run_checks(int arg=0);
	void check_functions();
	void chk();
	void test(int n);
	void test_run(int flag);
	
	// load (load balancing is not implemented yet) (uncomment the next line to start implementing it)
		// void loadbalance();	// function that does load balancing

	// file streams		
	void openfs();
	void openrs();
	void closefs();
	void closers();
	
	// hall and functional stepping mechanism
	void hal();
	bool stepping();

	// queries, sampler & appliance
	void query();
	void sample();
	void appliance();
	
	// modules
	void AMMod();
	void mod();

	// curl and fetch links
	std::string curl_url() { return this->crlurl; }
	int curl(std::string f);
	int links(std::string url, int max);

	// hashing and security
	void enforce_security();
	std::string hashtype(std::string h); // checking integrity

	// killchain
	void destroy_msg();
	void saygrace();
	void decouple();
	void killc(int x);
};

// eof