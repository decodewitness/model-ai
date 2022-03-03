// (inside AI directory) "AI/AI.H" - MAIN HEADER FILE FOR AI MODEL CLASS (USED BY AI.CPP)

#ifndef _SPLASH
#include "steering/splash.h"
#endif

#ifndef _AI_HEADER
#define _AI_HEADER

#define PROGRAM "model-Ai"
#define VERSION "v0.1-25c"

#define DOWNLOADURL "https://model-ai.com/archive/model-ai.tar.gz"

// commandos / comodos && _varaan
//#include "comodovaraan.cpp"	// already included differently

// headers
#include <cstring>
#include <sys/stat.h>
#include <filesystem>
//#include <thread>

// additional loaded variables
#include "lib/variables.h"

// database
#include "lib/database/db.cpp"

// asterisktab & amnesia splashing routines
#include "system/logic/ascii/amnesia.h"
#include "system/logic/ascii/asterisktab.h"

// configurations
#include "system/config/config.h"

// math
#include "system/logic/math/math.h"

// headers
#include "al/al.cpp"
#include "brain/nn.h"
#include "system/chk.h"
#include "lib/data.cpp"
//#include "simulation.cpp"	// already included in "ai.cpp"
#include "fetch/curl.cpp"
#include "lib/testing.cpp"
#include "system/gradle.h"
//#include "brain/brain.cpp"	// use "nn.cpp" instead
#include "comodo/varaan.h"
#include "lib/construct.cpp"
#include "patching/patch.cpp"
#include "system/protocol.cpp"
#include "entropy/b33hiv3.cpp"	// includes entropy.cpp && ltctapttclt.cpp
#include "sampler/sampler.cpp"
// #include "steering/splash.h"
#include "language/concepts.cpp"
#include "system/audio/audio.cpp"
#include "drum_machine/drums.cpp"
#include "data/handler/handler.cpp"
#include "autonomous/autonomous.cpp"
#include "system/modules/utility.cpp"
// #include "system/logic/math/tables.h"
#include "system/modules/modular.cpp"
// #include "language/speech/saying.cpp"
#include "system/security/security.cpp"
#include "system/definitions/encoder.cpp"
#include "system/logic/analysis/learn.cpp"
#include "system/logic/assembly/input.cpp"
#include "system/definitions/routines.cpp"
// #include "system/modules/simulation/sim.h"	// simulation
#include "system/logic/account/account.cpp"
#include "system/logic/analysis/limits.cpp"
//#include "system/logic/analysis/statx.cpp"	// valid functions already defined in modular_bay.h
#include "system/modules/simulation/sim.cpp"	// simulation
#include "system/modules/combine/combine.cpp"
// #include "steering/initialize_runcheck.cpp"
#include "system/logic/analysis/interpret.cpp"
#include "system/logic/analysis/algorithms.cpp"
#include "system/logic/transponder/transponder.cpp"
#include "system/modules/modular_bay/modular_bay.cpp"

// linked to the modules here above
const int nr_modules = 28;	// equal to the number of includes in "modules" (above this)

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
	Brain *brain;
	Sampler *sampler;
	Combine *cmb;
	CombineModule *combinemodule;
	Construct *construct;
	Transponder *transponder;
	Track_Account *account;
	Simulation *simulation;

	bool ddLck;
	bool d1Lck;
	bool d2Lck;

	Data *dd;
	Data *d1;
	Data *d2;

	bool ammod;
	bool modul;
	bool comb;
	bool combm;
	bool smpl;
	bool brn;

	int step;
	int element;
	int elements;

	std::string number_modules[nr_modules];	// these are all files and used to construct the virtual domain
	std::string crlurl;

	moduleContainer m;

public:
	AI(int n=1);

	// splash
	void splash(void);

	// help && version
	void help(int n);
	void version();

	// round init
	void init();
	void initialize_runtime_check();

	// headers
	void headers();

	// brain & neural net
	void assembleBrain();
	void add_to_brain(std::string h, std::string s, std::string c);
	void add_to_cabinet(std::string d, std::string desc);
	void add_to_brain_manually();
	void add_to_cabinet_manually();
	//void neural_net(std::string s, std::string h, int); 

	// print messages
	void printn(std::string n) { std::cout << n; }
	void printx(std::string x) { std::cout << x << std::endl; }
	void printy(std::string y) { std::cout << std::endl << y; }
	void printz(std::string z) { std::cout << std::endl << z << std::endl; }

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
	
	// converter
	void convert(int amount, int method);
	void convertf(float amount, int method);

	// file operations
	bool cp(std::string src, std::string dst);
	bool rm(std::string f);

	// hall and functional stepping mechanism
	void hal();
	bool stepping();
	bool pooling(int x=1);

	// queries, sampler & appliance
	// void search(std::string s);
	void query();
	void sample();
	void appliance();
	
	// modules
	void AMMod();
	void mod();
	void constr();

	// audio
	void play_audio(int s);
	void play_audio_file(std::string path);

	// patching
	void auto_patch();

	// combineModule
	void combmod(moduleContainer a, moduleContainer b);
	
	// math tables
	void table(float x);
	void tableTo(float x, float y);

	// math functions
	void add(float x, float y);
	void subtract(float x, float y);
	void multiply(float x, float y);
	void divide(float x, float y);
	void power(float x, float y);

	// random dice
	int dice();
	void dice_pr();
	int dice_n(int i);
	void dice_npr(int i);

	// math calculator
	float return_punch(float s, char c, float x);
	void print_punch(float s, char c, float x);

	// allocate && allocateData
	void allocate(Data d);	// allocates new set of Data object to pointer "dd"
	void allocatData(int pipeline, Data d);	// allocates Data to pointer "pipeline" a.k.a. "d1" or "d2".

	// deallocate && deallocateData
	void deallocate();	// deallocates "dd" data object
	void deallocatData(int pipeline);	// deallocates Data pipeline "d1" or "d2".
	
	// curl and fetch links
	std::string curl_url() { return this->crlurl; }
	int curl(std::string f);
	int links(std::string url, int max);

	// hashing and security
	void enforce_security();
	std::string hashtype(std::string h); // checking integrity
	//std::string hashchain(std::string s);
	// initialize transponder
	void tsp();

	// simulation
	void startSim();
	void stopSim();
	void runSim();
	void sim_stats();

	void addSimEntity(int x, int y, int z, int n=1);
	void deleteSimEntity(int x);

	void addSimObject(int x, int y, int z, int n=1);
	void deleteSimObject(int x);
	
	void listEntity();
	void listObject();

	void listAllEO();
	void cycle(int n);

	void printEntityCount();
	void printObjectCount();

	// handle data
	void hdata();
	void hmath();

	// testing
	//bool testing1();
	//bool testing2();
	//bool testing3();

	// account settings
	void add_account(float x);
	void subtract_account(float x);
	void print_account();
	void printn_account();
	// account;;getter and setter
	float get_account();
	void change_account(int x);
	void combine_total();
	// list pos/neg accounts
	void list_positive();
	void list_negative();
	// store accounts
	void store_account();
	void store_accounts_detail();
	void import_accounts(std::string filen);
	void export_accounts(std::string filen);
	// transfer from account
	void transfer(int src, int dst, float amount);
	void total_account();
	void average_account();

	// stat
	int statdir(std::string d);

	// killchain
	void destroy_msg();
	void saygrace();
	void decouple();
	void killc(int x);
};

#endif
// eof