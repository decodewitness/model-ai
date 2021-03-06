// AI/ENTROPY/B33HIV3.H :: USED BY "AI/AI.H"

//1tlt1tl
//t1tl      (THE B3HIv3)
//tl
//t1

#include <iostream>
#include <fstream>

//#include "entropy.cpp"        // already included in this file
//#include "ltctapttclt.cpp"    // already included in this file


int x=42;
int y=42;
int z=42;

int t=1;
char c=x;


//  AI/ENTROPY/ENTROPY.CPP - USED BY "AI.H" FOR AI MODEL
//  "AI/ENTROPY/ENTROPY.CPP" - USED BY "LTCTAPTTCLT.CPP" FOR AI MODELS

std::fstream fs;	// written entropy data
std::fstream rs;	// resource | read stream

int entropyr() {  // read entropy from T1
    std::string tmp;
    
    //fs << " more lorem ipsum";
    
    //std::fstream fs;	// written entropy data

    // MAIN CATALYST
    fs >> tmp;
    std::cout << std::endl << std::endl << "HEREDOC:" << tmp << std::endl;
    return 1;
}

int entropyw(std::string s) {  // write entropy in TL
    //std::string tmp=" more lorem ipsum";
    
    //std::fstream rs;	// resource | read stream
    rs << s;
    return 0;
}

// eof

// std::fstream fs;	// written entropy data
// std::fstream rs;	// resource | read stream

std::string main_extrapolation_data=" more lorem ipsum";

// adaptable functions title panel
void lt1tlt1() { std::cout << "holy"; }
void t1tl() { std::cout << "tapltc"; }
void tl() { std::cout << "ltct"; }
int t1() { std::cout << "tapish"; return 1; }

// adaptable functions trousers
void lt1tlt1(int t) { std::cout << "tap"; }
void tlt1(int t) { std::cout << "tap"; }
int t1(int t) { std::cout << "tap"; return 2; }
int tl(char x) { std::cout << "ltct"; return 3;}

void fcltaptaptap() {
    
    char str[10] = "data.txt";
    
    //std::cout << "Enter the name of an existing text file: ";
    //std::cin.get (str,256);    // get c-string
    
    std::ifstream is(str);     // open file
    char c;
    
    while (is.get(c))          // loop getting single characters
        std::cout << c;
    
    is.close();                // close file
}

// adaptable functions shoe
void run() {    // runs adaptable functions in sequence
    entropyr();
    entropyw(main_extrapolation_data);
    std::cout << "\t-:: -:: psht -:: <tap>" << std::endl;

    lt1tlt1(); t1tl(); tl();
    int x=0;
    x=t1(); lt1tlt1(); tlt1(t);
    y=t1(); z=tl(c);
	std::cout << std::endl << "::- insert the tam tam reading -::" << std::endl;

    fcltaptaptap();

    std::cout << "-:: swapping sequence." << std::endl;
    std::cout << "x=" << x << "; " << "y=" << y << "; " << "z=" << z << "; " << std::endl;
    std::cout << std::endl;
}

void addData() {    // right now sets main_extrapolation_data percentage
    main_extrapolation_data=" 100\% entropy";
}

// eof