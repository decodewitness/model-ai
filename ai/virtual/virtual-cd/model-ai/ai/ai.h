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
#include "header.h"

// AMModule
#include "system/AMModule.h"

// modules
#include "md5/md5.cpp"
#include "system/chk.h"
#include "security.cpp"
#include "fetch/fetch.h"
#include "system/splash.h"
#include "system/gradle.h"
#include "logic/learn.cpp"
#include "drums/drums.cpp"
#include "logic/limits.cpp"
#include "entropy/header.h"
#include "logic/interpret.cpp"
#include "system/protocol.cpp"
#include "sampler/sampler.cpp"
#include "logic/algorithms.cpp"
#include "language/concepts.cpp"
#include "language/speech/saying.cpp"
#include "logic/assembly/input.cpp"

const int number_of_modules = 19;	// equal to the number of include headers (above in this file)
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
	std::string modules[number_of_modules];	// these are all files and used to construct the virtual domain

	std::string crlurl;

public:

	AI(int n=1);

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
	void init();

	void appliance();
	
	void decouple();
	void saygrace();

	void AMMod();
	void query();


	std::string curl_url() {
		return this->crlurl;
	}

	int curl(std::string f);

	// killchain
	void kill(int x);
};

// eof