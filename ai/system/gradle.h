// GRADLE.H - MAIN GRADLE FILE WILL GLUE ALL FUNCTIONS AND CLASSES - USED BY "AI/AI.H"
#include <iostream>

int gradle() {

	bool check_gradle_components(int comp);

	std::cout << std::endl;
	std::cout << "::- loading gradle -::" << std::endl;

	int x = 25; // total number of modules
	int MVAR=x;	// number of times to run 1 complete set of modules (or) modules (5) + spc (2) (or) modules + spc + (aux) (25)
	int PVAR=1; // total number of cyles including 0 for 1 cycle

	std::cout << "~!~ running: " << MVAR << "(modules); (" << PVAR << ") sets of module runs or x." << std::endl;

	// component to edit/sample with and limit to n components
	int nocomponent = 0;
	int n = 5;	// limiter to components

	// functions
	for (int totalModulesRan=0; totalModulesRan<=MVAR; totalModulesRan++) {	// Prime var

		for (int nrOfSets=1; nrOfSets<=PVAR; nrOfSets++) {	// Medium var
			// calculate module size in dependencies

			// check gradle components
			// check here for module
			// checkformodule(int i)
			bool b = check_gradle_components(totalModulesRan);
		
			//log (b) true/false results here next
			if (b != true) {
				std::cout << "\t(no module was available.)" << std::endl;
			} else {
				std::cout << "\t(module was found.)" << std::endl;
			}
		}
	}
		
	// actually check the gradle functioning inside the next function
	// sample 1 module:
	//---------------------- uncomment next line --------------------------------
	bool b = check_gradle_components(nocomponent); // run nocomponent to switch off components and run without building any modules
	
return 1;
};

bool check_gradle_components(int comp=1) { // check functioning of gradle

	// NEED TO STILL LOAD THE MODULES IN THIS FUNCTION ~!!!
	///////////////////////////////////////////////////////

	bool checks = true;
	int active_module = 0;

	std::cout << "~:: checking for gradle modules." << std::endl;

	switch (comp) {	// These will switch modules (for swapping in / swapping out) +/-(modules)
												// (language)(methods)(routes)(coll./database)(record) (SPC)(SPC)
		case 0: // no implementation
			std::cout << "\t-:: no &(such) implementation." << std::endl;
			std::cout << "\t\t~:: ((0))::(no module)::implementation." << std::endl;
			active_module=0;
			checks = false;
			break;
		case 1:	// speech
			std::cout << "\t-:: checking gradle module 01." << std::endl; // 	// needs to be wired to natural language processing		(En)
			std::cout << "\t\t~:: (01)::(EN)+module)::implementation." << std::endl;
			active_module=1;
			break;
		case 2:	// methods
			std::cout << "\t-:: checking gradle module 02." << std::endl; // hook up to methods 										(Fx)
			std::cout << "\t\t~:: (02)::(FX)+module)::implementation." << std::endl;
			active_module=2;
			break;
		case 3:	// routines
			std::cout << "\t-:: checking gradle module 03." << std::endl; // routes / routines											(Rt)
			std::cout << "\t\t~:: (03)::(RT)+module)::implementation." << std::endl;
			active_module=3;
			break;
		case 4: // catalogue
			std::cout << "\t-:: checking gradle module 04." << std::endl; // catalogue / database										(CdB)
			std::cout << "\t\t~:: (04)::(CDB)+module)::implementation." << std::endl;
			active_module=4;
			break;
		case 5:	// recognition
			std::cout << "\t-:: checking gradle module 05." << std::endl; // pattern recognition / analytics							(Rec)
			std::cout << "\t\t~:: (05)::(REC)+module)::implementation." << std::endl;
			active_module=5;
			break;
		case 6: 	// SPECIAL (A)()
			std::cout << "\t-:: checking gradle module 06." << std::endl;	// SPECIAL(A)												(SPCA) LFT
			std::cout << "\t\t~:: (BMOD)::(SPC)" << std::endl;
			std::cout << "(A)(SPC/LFT+module)::implementation." << std::endl;
			active_module=6;
			break;
		case 7:		// SPECIAL (B)()
			std::cout << "\t-:: checking gradle module 07." << std::endl;	// SPECIAL(B)												(SPCB) RGHT
			std::cout << "\t\t~:: (BMOD)::(SPC)" << std::endl;
			std::cout << "(B)(SPC/RGHT+module)::implementation." << std::endl;
			active_module=7;
			break;
		case 8:	// speech
			std::cout << "\t-:: checking gradle module 08." << std::endl;
			std::cout << "\t\t~:: (OUT)(1-1)::(EN)+module)::implementation." << std::endl;
			active_module=8;
			break;
		case 9:	// methods
			std::cout << "\t-:: checking gradle module 09." << std::endl;
			std::cout << "\t\t~:: (OUT)(2-2)::(EN)+module)::implementation." << std::endl;
			active_module=9;
			break;
		case 10: // routines
			std::cout << "\t-:: checking gradle module 10." << std::endl;
			std::cout << "\t\t~:: (OUT)(3-3)::(FX)+module)::implementation." << std::endl;
			active_module=10;
			break;
		case 11: // catalogue
			std::cout << "\t-:: checking gradle module 11." << std::endl;
			std::cout << "\t\t~:: (OUT)(4-4)::(FX)+module)::implementation." << std::endl;
			active_module=11;
			break;
		case 12: // recognition
			std::cout << "\t-:: checking gradle module 12." << std::endl;
			std::cout << "\t\t~:: (IN)(5-5)::(RT)+module)::implementation." << std::endl;
			active_module=12;
			break;
		case 13: // speech
			std::cout << "\t-:: checking gradle module 13." << std::endl;
			std::cout << "\t\t~:: (OUT)(aux)(1)::(RT)+module)::implementation." << std::endl;
			active_module=13;
			break;

		case 14: // methods
			std::cout << "\t-:: checking gradle module 14." << std::endl;
			std::cout << "\t\t~:: (IN)(aux)(2)::(CDB)+module)::implementation." << std::endl;
			active_module=14;
			break;
		case 15: // routines
			std::cout << "\t-:: checking gradle module 15." << std::endl;
			std::cout << "\t\t~:: (OUT)(aux)(3)::(CDB)+module)::implementation." << std::endl;
			active_module=15;
			break;

		case 16: // recognition
			std::cout << "\t-:: checking gradle module 16." << std::endl;
			std::cout << "\t\t~:: (IN)(aux)(4)::(REC)+module)::implementation." << std::endl;
			active_module=16;
			break;
		case 17:	// speech
			std::cout << "\t-:: checking gradle module 17." << std::endl;
			std::cout << "\t\t~:: (OUT)(aux)(5)::(REC)+module)::implementation." << std::endl;
			active_module=17;
			break;

		case 18:	// methods
			std::cout << "\t-:: checking gradle module 18." << std::endl;
			std::cout << "\t\t~:: (IN)(aux)(I)::(EN_VAR)+module)::implementation." << std::endl;
			active_module=18;
			break;
		case 19:	// routines
			std::cout << "\t-:: checking gradle module 19." << std::endl;
			std::cout << "\t\t~:: (OUT)(aux)(II)::(EN_VAR)+module)::implementation." << std::endl;
			active_module=19;
			break;
		case 20:	// recognition
			std::cout << "\t-:: checking gradle module 20." << std::endl;
			std::cout << "\t\t~:: (IN)(aux)(III)::(FX_INT)+module)::implementation." << std::endl;
			active_module=20;
			break;
		case 21:	// recognition
			std::cout << "\t-:: checking gradle module 21." << std::endl;
			std::cout << "\t\t~:: (OUT)(aux)(IV)::(FX_INT)+module)::implementation." << std::endl;
			active_module=22;
			break;
		case 22:	// recognition
			std::cout << "\t-:: checking gradle module 22." << std::endl;
			std::cout << "\t\t~:: (IN)(aux)(V)::(RT_O)+module)::implementation." << std::endl;
			active_module=23;
			break;
		case 23:	// recognition
			std::cout << "\t-:: checking gradle module 23." << std::endl;
			std::cout << "\t\t~:: (IN)(aux)(_A_)::(CDB_DATA)+module)::implementation." << std::endl;
			active_module=24;
			break;
		case 24:	// recognition
			std::cout << "\t-:: checking gradle module 24." << std::endl;
			std::cout << "\t\t~:: (IN/OUT)(aux)(_B_)::(REC_OPT)+module)::implementation." << std::endl;
			active_module=25;
			break;
		case 25:	// recognition
			std::cout << "\t-:: checking gradle module 25." << std::endl;
			std::cout << "\t\t~:: (OUT/IN)(aux)(__A1_B2)::((XL)_:c)+module)::implementation." << std::endl;
			active_module=26;
			break;
		default:
			std::cout << "\t! -:: no such component is registered." << std::endl;
			std::cout << "\t\t(((__NIL)))" << std::endl;
			active_module=-1;
			checks = false;
			break;
	};
	
	return checks;
};

// eof