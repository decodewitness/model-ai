#include <iostream>
#include <string>

#include "md5/md5.cpp"

// regular hash function
void hash(std::string h) {
	std::cout << "-:: hashing function." << std::endl;
	std::cout << "\t-:: hashing (\"" << h << "\")" << std::endl;
	std::cout << "\t-:: hash: " << md5(h.c_str());
};

// function returns hash string
std::string hashn(std::string h) {
	return md5(h.c_str());
};