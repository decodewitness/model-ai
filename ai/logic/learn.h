// (inside AI directory) AI/LEARN.H - USED BY "LEARN.CPP" FOR AI MODEL

#include <iostream>

class Learn {

private:
	int item;
	int items;
	int length;
	
	std::string information;

public:
	Learn(std::string i);
	
	void process();
	void assess();
};

// eof