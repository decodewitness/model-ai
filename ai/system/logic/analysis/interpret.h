//	"AI/LOGIC/INTERPRET.H" FOR AI MODEL - USED BY "AI/LOGIC/INTERPRET.CPP"

// with the next header containing headers and so now has some basic knowledge of some basic language constructs

#include <iostream>
#include <cstring>

class Interpret {

private:
	int nr;
	std::string tmp;

public:

	void setTmp(std::string s) { tmp = s; }
	void getTmp() { std::cout << this->tmp << "."; }
};
// eof