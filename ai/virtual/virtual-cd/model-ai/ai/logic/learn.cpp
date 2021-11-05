// (inside AI directory) AI/LEARN.CPP - USED BY "AI.H"

#include "learn.h"

Learn::Learn(std::string i) {
	// read information
	this->information = i;
	this->process();
};

void Learn::process() {
	// process attributes
	this->item = this->items + 1;
	this->length = this->information.length();
	this->items++;	// actually increment items
};

void Learn::assess() {
	// asses information and next categorize
	char arr[256];
		strncpy(arr, this->information.c_str(), 255); 
//	for (int i=0; i<255; i++) {
		
//	}

};
