// (inside AI directory) "AI/AI.H" - MAIN HEADER FILE FOR AI MODEL CLASS (USED BY AI.CPP)

#ifndef _AI_HEADER
#define _AI_HEADER
#endif

#include <cstring>

// database
#include "database/db.cpp"

// asterisktab
#include "logic/ascii/asterisktab.h"

// hal
#include "al/al.cpp"

// configurations
#include "cfg/config.h"

// modules
#include "md5/md5.cpp"
#include "system/chk.h"
#include "security.cpp"
#include "fetch/curl.cpp"
#include "system/splash.h"
#include "system/gradle.h"
#include "logic/learn.cpp"
#include "drums/drums.cpp"
#include "logic/limits.cpp"
#include "entropy/b3hiv3.h"
#include "logic/interpret.cpp"
#include "system/protocol.cpp"
#include "sampler/sampler.cpp"
#include "logic/algorithms.cpp"
#include "language/concepts.cpp"
#include "logic/assembly/input.cpp"
#include "language/speech/saying.cpp"
#include "system/modules/modular.cpp"	// includes AMModule.h
#include "logic/transponder/transponder.cpp"

const int nr_modules = 18;	// equal to the number of includes in "modules" (above in this file)
const int SAMPLER_THREADS = 8;

class AI {

private:
	int nr;
	int check_routine;

	char ch;
	bool testrun;
	bool recordat;

	bool access;

	Sampler *sampler;
	std::string number_modules[nr_modules];	// thesr_oe are all files and used to construct the virtual domain

	std::string crlurl;

	Modular *mdl;

public:

	AI(int n=1);

	void init();
	void enforce_security();
	
	void openfs();
	void openrs();

	void hal();

	void closefs();
	void closers();

	void run_checks(int arg=0);
	void check_functions();
	void chk();
	
	void test(int n);
	void test_run(int flag);

	bool stepping();
	void hash(string s);
	void sample();

	void headers();

	void appliance();
	
	void decouple();
	void destroy_msg();
	void saygrace();

	void AMMod();
	void query();

	void mod();

	std::string curl_url() {
		return this->crlurl;
	}

	// curl and fetch links
	int curl(std::string f);
	int links(std::string url, int max);

	// killchain
	void kill(int x);
};

// eof