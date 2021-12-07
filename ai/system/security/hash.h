#include <iostream>
#include <string>

#include "md5/md5.cpp"

// regular hash function
void hash(std::string h) {
	std::cout << "-:: hashing function." << std::endl;
	std::cout << "\t-:: hashing (\"" << h << "\")" << std::endl;
	std::cout << "\t-:: hash: " << md5(h.c_str());
};

// function returns hashed string h
std::string hashn(std::string h) {

	std::cout << "~:: hashing: " << h << std::endl;
	std::cout << "\t" << md5(h) << std::endl;

	return md5(h.c_str());
};