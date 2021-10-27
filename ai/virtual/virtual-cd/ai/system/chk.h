// (in AI directory) AI/HEALTH.CPP - USED AS HEALTH MODULE BY "AI.H" FOR AI MODEL
    // performs checklist style health monitoring and tracking events

#include <iostream>
#include <cstring>

struct checks { // structure that contains all the checklist items
    int it; // should be the size of the arrays
    bool checklist[10];
    std::string names[10];
};

void chkconf(checks chklist) {  // checks checklist -> it needs to be set
    std::cout << "\t-:: health monitoring. (" << chklist.it << ") criteria." << std::endl;

    for (int i=0; i<chklist.it; i++) {
        std::cout << "\t-:: " << (i+1) << ". " << chklist.names[i] << ":";

        if (chklist.checklist[i] == true) {
            std::cout << "\ttrue" << std::endl;
        } else {
            std::cout << "\tfalse" << std::endl;
        }
    }    
}

checks checklist;

void chk() {
// Checks routine built in for debugging

	std::cout << std::endl << std::endl;
	std::cout << "-:: checking health criteria" << std::endl;

	checks newCheck;

	newCheck.it = 10;
	newCheck.names[0] = "one";
	newCheck.checklist[0] = true;

	newCheck.names[1] = "two";
	newCheck.checklist[1] = true;

	newCheck.names[2] = "three";
	newCheck.checklist[2] = true;

	newCheck.names[3] = "four";
	newCheck.checklist[3] = true;

	newCheck.names[4] = "five";
	newCheck.checklist[4] = false;

	newCheck.names[5] = "six";
	newCheck.checklist[5] = true;

	newCheck.names[6] = "seven";
	newCheck.checklist[6] = false;

	newCheck.names[7] = "eight";
	newCheck.checklist[7] = true;

	newCheck.names[8] = "nine";
	newCheck.checklist[8] = true;

	newCheck.names[9] = "ten";
	newCheck.checklist[9] = true;

	chkconf(newCheck);
}

// eof