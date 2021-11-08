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

bool check_gradle_components(int comp=1) { // check functioning of gradle

	std::cout << "\t-:: checking for gradle modules." << std::endl;
	
	switch (comp) {	// These will switch modules (for swapping in / swapping out) +/-(modules)
												// (language)(methods)(routes)(coll./database)(record) (SPC)(SPC)
		case 0: // no implementation
			std::cout << "\t-:: no &(such) implementation." << std::endl;
			std::cout << "\t\t~:: ((0))::(no module)::implementation." << std::endl;
			break;
		case 1:	// speech
			std::cout << "\t-:: checking gradle module 01." << std::endl; // 	// needs to be wired to natural language processing		(En)
			std::cout << "\t\t~:: (01)::(EN)+module)::implementation." << std::endl;
			break;
		case 2:	// methods
			std::cout << "\t-:: checking gradle module 02." << std::endl; // hook up to methods 										(Fx)
			break;
			std::cout << "\t\t~:: (02)::(FX)+module)::implementation." << std::endl;
		case 3:	// routines
			std::cout << "\t-:: checking gradle module 03." << std::endl; // routes / routines											(Rt)
			std::cout << "\t\t~:: (03)::(RT)+module)::implementation." << std::endl;
			break;
		case 4: // catalogue
			std::cout << "\t-:: checking gradle module 04." << std::endl; // catalogue / database										(CdB)
			std::cout << "\t\t~:: (04)::(CBD)+module)::implementation." << std::endl;
			break;
		case 5:	// recognition
			std::cout << "\t-:: checking gradle module 05." << std::endl; // pattern recognition / analytics							(Rec)
			std::cout << "\t\t~:: (05)::(REC)+module)::implementation." << std::endl;
			break;
		case 6: 	// SPECIAL (A)()
			std::cout << "\t-:: checking gradle module 06." << std::endl;	// SPECIAL(A)												(SPCA) LFT
			std::cout << "\t\t~:: (BMOD)::(SPC)(A)(LFT+module)::implementation." << std::endl;
			break;
		case 7:		// SPECIAL (B)()
			std::cout << "\t-:: checking gradle module 07." << std::endl;	// SPECIAL(B)												(SPCB) RGHT
			std::cout << "\t\t~:: (BMOD)::(SPC)(B)(RGHT+module)::implementation." << std::endl;
			break;
		case 8:	// speech
			std::cout << "\t-:: checking gradle module 08." << std::endl;
			std::cout << "\t\t~:: (OUT)(1-1)::(EN)+module)::implementation." << std::endl;
			break;
		case 9:	// methods
			std::cout << "\t-:: checking gradle module 09." << std::endl;
			std::cout << "\t\t~:: (OUT)(2-2)::(EN)+module)::implementation." << std::endl;
			break;

		case 10: // routines
			std::cout << "\t-:: checking gradle module 10." << std::endl;
			std::cout << "\t\t~:: (OUT)(3-3)::(FX)+module)::implementation." << std::endl;
			break;
		case 11: // catalogue
			std::cout << "\t-:: checking gradle module 11." << std::endl;
			std::cout << "\t\t~:: (OUT)(4-4)::(FX)+module)::implementation." << std::endl;
			break;

		case 12: // recognition
			std::cout << "\t-:: checking gradle module 12." << std::endl;
			std::cout << "\t\t~:: (IN)(5-5)::(RT)+module)::implementation." << std::endl;
			break;
		case 13: // speech
			std::cout << "\t-:: checking gradle module 13." << std::endl;
			std::cout << "\t\t~:: (OUT)(aux)(1)::(RT)+module)::implementation." << std::endl;
			break;

		case 14: // methods
			std::cout << "\t-:: checking gradle module 14." << std::endl;
			std::cout << "\t\t~:: (IN)(aux)(2)::(CDB)+module)::implementation." << std::endl;
			break;
		case 15: // routines
			std::cout << "\t-:: checking gradle module 15." << std::endl;
			std::cout << "\t\t~:: (OUT)(aux)(3)::(CDB)+module)::implementation." << std::endl;
			break;

		case 16: // recognition
			std::cout << "\t-:: checking gradle module 16." << std::endl;
			std::cout << "\t\t~:: (IN)(aux)(4)::(REC)+module)::implementation." << std::endl;
			break;
		case 17:	// speech
			std::cout << "\t-:: checking gradle module 17." << std::endl;
			std::cout << "\t\t~:: (OUT)(aux)(5)::(REC)+module)::implementation." << std::endl;
			break;

		case 18:	// methods
			std::cout << "\t-:: checking gradle module 18." << std::endl;
			std::cout << "\t\t~:: (IN)(aux)(I)::(EN_VAR)+module)::implementation." << std::endl;
			break;
		case 19:	// routines
			std::cout << "\t-:: checking gradle module 19." << std::endl;
			std::cout << "\t\t~:: (OUT)(aux)(II)::(EN_VAR)+module)::implementation." << std::endl;
			break;

		case 21:	// recognition
			std::cout << "\t-:: checking gradle module 20." << std::endl;
			std::cout << "\t\t~:: (OUT)(aux)(IV)::(FX_INT)+module)::implementation." << std::endl;
			break;
		case 22:	// recognition
			std::cout << "\t-:: checking gradle module 20." << std::endl;
			std::cout << "\t\t~:: (IN)(aux)(V)::(RT_O)+module)::implementation." << std::endl;
			break;
		case 23:	// recognition
			std::cout << "\t-:: checking gradle module 20." << std::endl;
			std::cout << "\t\t~:: (IN)(aux)(_A_)::(CDB_DATA)+module)::implementation." << std::endl;
			break;
		case 24:	// recognition
			std::cout << "\t-:: checking gradle module 20." << std::endl;
			std::cout << "\t\t~:: (OUT/IN)(aux)(_B_)::(REC_OPT)+module)::implementation." << std::endl;
			break;
		case 25:	// recognition
			std::cout << "\t-:: checking gradle module 20." << std::endl;
			std::cout << "\t\t~:: (IN/OUT)(aux)(__A1_B2)::(_(XL)c_)+module)::implementation." << std::endl;
			break;
				
		default:
			std::cout << "\t! -:: no such component is registered." << std::endl;
			std::cout << "\t\t(((__NIL)))" << std::endl;
			break;
	};
	
	return true;
};

// eof