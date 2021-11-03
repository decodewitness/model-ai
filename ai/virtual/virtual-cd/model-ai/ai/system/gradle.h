// GRADLE.H - MAIN GRADLE FILE WILL GLUE ALL FUNCTIONS AND CLASSES - USED BY "AI/AI.H"

#include <iostream>

int gradle() {

	std::cout << "::- loading gradle -::" << std::endl << std::endl;

	// functions
	bool check_gradle_components(int comp);
	
	// component to start with and limit of components
	int component = 1;
	int limiter = 5;
	
	// actually check the gradle functioning inside the next function
	check_gradle_components(component);
	
return 1;
};

bool check_gradle_components(int comp=0) { // check functioning of gradle

	std::cout << "\t-:: checking for gradle modules." << std::endl;
	
	switch (comp) {

		case 0:
			std::cout << "\t! -:: no active components available." << std::endl;
			break;
		case 1:	// speech
			std::cout << "\t-:: checking gradle module 1." << std::endl;
			break;
		case 2:	// methods
			std::cout << "\t-:: checking gradle module 2." << std::endl;
			break;
		case 3:	// routines
			std::cout << "\t-:: checking gradle module 3." << std::endl;
			break;
		case 4: // catalogue
			std::cout << "\t-:: checking gradle module 4." << std::endl;
			break;
		case 5:	// recognition
			std::cout << "\t-:: checking gradle module 5." << std::endl;
			break;
		default:
			std::cout << "\t! -:: no such component is registered." << std::endl;
			break;
	};
	
	return true;
};

// eof