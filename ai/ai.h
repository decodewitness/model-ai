// (inside AI directory) "AI/AI.H" - MAIN HEADER FILE FOR AI MODEL CLASS (USED BY AI.CPP)

	// ALL DATA FILES GO IN: "AI/DATA/FILES"
	// ALL META QUERIES AND REFERENCES GO IN "AI/LIB/QUERIES"
	//
	// ***
	// Commands are in ai/system/logic/assembly/logic.cpp, logic.h, AI::Query().

#define PROGRAM "MODEL-AI"
#define VERSION "v0.1-29a"
#define WEBSITE	"https://model-ai.com"
#define AUTHOR "Author: vera lo"
#define DOWNLOADURL "https://model-ai.com/archive/model-ai.tar.gz"

#ifndef _SPLASH
#include "steering/splash.h"
#endif

#ifndef _AI_HEADER
#define _AI_HEADER

// commandos / comodos && _varaan
//#include "comodovaraan.cpp"	// already included differently

// headers
#include <cstring>
#include <iostream>
#include <string>
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

// headers and modules
// #include "func.h"
#include "al/al.cpp"
//#include "brain/nn.h"
#include "system/chk.h"
#include "lib/data.cpp"
//#include "simulation.cpp"	// already included in "ai.cpp"
//#include "fetch/curl.cpp"		(fix)
#include "lib/testing.cpp"
#include "system/gradle.h"
//#include "brain/brain.cpp"	// use "nn.cpp" instead
#include "comodo/varaan.h"
#include "chains/chain.cpp"
#include "lib/construct.cpp"
#include "tempus/tempus.cpp"
#include "patching/patch.cpp"
#include "system/protocol.cpp"
#include "entropy/b33hiv3.cpp"	// includes entropy.cpp && ltctapttclt.cpp
#include "sampler/sampler.cpp"
// #include "steering/splash.h"
#include "system/menu/menu.cpp"
#include "language/concepts.cpp"
// #include "system/audio/audio.cpp"	(fix)
#include "drum_machine/drums.cpp"
#include "data/convert/convert.cpp"
#include "data/handler/handler.cpp"
#include "system/logic/strings.cpp"
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
#include "system/modules/status/status.cpp"
//#include "system/logic/analysis/statx.cpp"	// valid functions already defined in modular_bay.h
#include "system/modules/simulation/sim.cpp"	// simulation
#include "system/modules/combine/combine.cpp"
#include "system/modules/service/service.cpp"
// #include "steering/initialize_runcheck.cpp"
#include "system/logic/analysis/interpret.cpp"
#include "system/logic/analysis/algorithms.cpp"
// #include "system/logic/transponder/references.cpp"	// build refs
#include "system/logic/transponder/transponder.cpp"
#include "system/modules/modular_bay/modular_bay.cpp"
// #include "system/security/credentials/credentials.cpp"	// already included in "ai.cpp"

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
	// ints
	int check_routine;
	int nr;
	int r10; // for storing random number <=10
	int r100; // for storing random number <=100
	int pool; // for pooling data (initialize to 0)

	// stepping
	int step;
	int element;
	int elements;

	// ai cyclus
	int bstepcount;
		int *pbstep;

	
	// references
	int rNr;	// nr for the last reference (size of references)
	
	// chars
	char ch;
	
	// bools
	bool testrun;
	bool recordat;
	bool disableAudio;
	bool access;
	bool pytubeRan;	// external software is linked

	// modules
	bool ammod;	// used for AMModule
	bool modul;	// used for Modular
	bool comb;	// used for Combine
	bool combm;	// used for CombineModule
	bool smpl;	// used for Sampler
	bool brn;	// used for Brain
	bool trans;	// used for Transponder
	bool statis;	// used for Status

	// prepared
	bool transponderIsPrepped;

	// locks on data
	bool ddLck;
	bool d1Lck;
	bool d2Lck;

	// strings
	std::string number_modules[nr_modules];	// these are all files and used to construct the virtual domain
	std::string crlurl;	// the url for the curl request to download the latest model
	std::string original_string;	// used for query string reference until being overridden by another str object

	// containers
	moduleContainer m;

	// module pointers
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
	Status *status;

	// data pipelines
	Data *dd;
	Data *d1;
	Data *d2;

public:

	// constructor
	AI(int n, int ss);

	// splash
	void splash(void);

	// help && version
	void help(int n);
	void version();

	// round init
	void init();
	void initialize_runtime_check(int x);

	// headers
	void headers();

	// brain & neural net
	void assembleBrain();
	void add_to_brain(std::string h, std::string s, std::string c);
	void add_to_cabinet(std::string d, std::string desc);
	void add_to_brain_manually();
	void add_to_cabinet_manually();
	void add_intelligence(std::string tag, std::string desc);
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
	void audioToggle() { this->disableAudio = !this->disableAudio; }

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
	
	// transponder
	void createTransponder();
	void tsp(std::string s);
	void prepTransponder(std::string s);
	// exporting transponder backlogs
	void export_backlog1();	// export backlog_queries
	void export_backlog2();	// export backlog_answers
	void export_backlogs();	// export both backlog_queries & backlog_answers

	// handle data
	void hdata();
	void hmath();

	// credentials
	void list_credentials();
	void store_new_credentials();

	// testing
	//bool testing1();
	//bool testing2();
	//bool testing3();

	// stat
	int statdir(std::string d);

	// data conversion
	void convert_data(std::string f, int l);

	// killchain
	void destroy_msg();
	void saygrace();
	void decouple();
	void killc(int x);

	// pytube
	void install_pytube();
	bool chk_pytube();
	void run_tube(std::string url);

	// menu
	void menu();

	// meta queries
	void readMetaQue();

	// ACCOUNT MGMT
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

	// SIMULATION
			// SIMULATOR
	void startSim();
	void stopSim();
	void runSim();
	void cycle(int n);
	// add delete
	void addSimEntity(int x, int y, int z, int n=1);
	void deleteSimEntity(int x);
	void addSimObject(int x, int y, int z, int n=1);
	void deleteSimObject(int x);
	// listing
	void sim_stats();
	void listEntity();
	void listObject();
	void listAllEO();
	void printEntityCount();
	void printObjectCount();

	// meta queries
	void clearQue();
	void answer(bool b);

	// learned
	void whatHaveYouGot();
	void talk(int x=0);
	
	// references
	void buildRef();
	void readRefs();
	void readLastRef();
	void readRef(int n);
	void returnRefNr();
	void storeRef(nref x);	// nref and not ref

	// testing
	void testA();
	void train_model(std::string q, std::string a);

	// analytical / category research
	void qlog(int x);	// log last queries ;; x=number (0 default ;; means only last query+response)

	// running scripts
	void runscript(std::string ss);

	// chains
	Chain & create_chain();
	void chain_id(Chain & ccc);
	void read_chain(Chain & ccc);
	void write_chain(int x, int id, Chain & ccc, std::string str);
	void view_chain(Chain & ccc,int x);
	void delete_chain(Chain & ccc);
};

#endif

// eof