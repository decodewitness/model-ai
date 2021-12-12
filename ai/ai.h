// (inside AI directory) "AI/AI.H" - MAIN HEADER FILE FOR AI MODEL CLASS (USED BY AI.CPP)

#ifndef _AI_HEADER
#define _AI_HEADER

#define VERSION "v0.1-24"
#define DOWNLOADURL "https://model-ai.com/archive/model-ai.tar.gz"

// commandos / comodos && _varaan
//#include "comodovaraan.cpp"	// already included differently

// headers
#include <cstring>
#include <sys/stat.h>

// database
#include "database/db.cpp"

// asterisktab & amnesia splashing routines
#include "system/logic/ascii/amnesia.h"
#include "system/logic/ascii/asterisktab.h"

// configurations
#include "system/config/config.h"

// headers
#include "al/al.cpp"
#include "system/chk.h"
#include "fetch/curl.cpp"
#include "system/gradle.h"
#include "comodo/varaan.h"
#include "lib/construct.cpp"
#include "steering/splash.h"
#include "patching/patch.cpp"
#include "system/protocol.cpp"
#include "entropy/b33hiv3.cpp"	// includes entropy.cpp && ltctapttclt.cpp
#include "sampler/sampler.cpp"
#include "language/concepts.cpp"
#include "drum_machine/drums.cpp"
#include "system/logic/analysis/learn.cpp"
#include "system/logic/assembly/input.cpp"
#include "system/logic/analysis/limits.cpp"
#include "system/modules/modular.cpp"
#include "language/speech/saying.cpp"
#include "system/logic/analysis/interpret.cpp"
#include "system/security/security.cpp"
#include "system/logic/analysis/algorithms.cpp"
#include "system/definitions/encoder.cpp"
#include "system/definitions/routines.cpp"
#include "system/logic/transponder/transponder.cpp"
#include "system/modules/combine/combine.cpp"
#include "system/modules/modular_bay/modular_bay.cpp"

// linked to above modules
const int nr_modules = 24;	// equal to the number of includes in "modules" (above this)

// FOR OTHER MODULES
const int module_limits = 1024;


// DON'T MESS WITH THIS SETTING -- this setting to "true" runs the virtual appliance.
	// --- VIRTUAL APP APPLIANCE CONTROL SETTING ---
bool app = false;
// --- VIRTUAL APP APPLIANCE CONTROL SETTING ---
	// --- VIRTUAL APP APPLIANCE CONTROL SETTING ---

	
const int SAMPLER_THREADS = 8;

class AI {

private:
	int nr;
	int check_routine;

	int r10; // for storing random number <=10
	int r100; // for storing random number <=100

	int pool; // for pooling data (initialize to 0)

	char ch;
	bool testrun;
	bool recordat;

	bool access;

	AMModule *ammodule;
	Modular *mdl;
	Combine *cmb;
	CombineModule *combinemodule;
	Sampler *sampler;
	Construct *construct;
	
	bool ammod;
	bool modul;
	bool comb;
	bool combm;
	bool smpl;

	int element;
	int elements;

	std::string number_modules[nr_modules];	// these are all files and used to construct the virtual domain
	std::string crlurl;

	moduleContainer m;

public:

	AI(int n=1);

	// round init
	void init();

	// headers
	void headers();

	// rollouts
	void rollout(int n);
	
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
	bool pooling(int x=1);

	// queries, sampler & appliance
	void query();
	void sample();
	void appliance();
	
	// modules
	void AMMod();
	void mod();
	void constr();

	// patching
	void auto_patch();

	// combineModule
	void combmod(moduleContainer a, moduleContainer b);

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

#endif
// eof