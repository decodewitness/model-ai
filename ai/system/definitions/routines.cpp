// (inside AI directory) AI/ROUTINES.CPP - GRAMMAR ROUTINES FOR AI MODEL (USED BY SAYING.CPP & INTERPRET.H)
// handle interpunctions and line carries

#include <iostream>
#include <cstring>

// newline character
void carry() { std::cout << std::endl; }

// skip a line
void skipline() { std::cout << std::endl << std::endl; }	// 1x "skip()" is the same as two times: "carry(); carry();"

// space
void space() { std::cout << (32); }

// interpunction
void dot() { std::cout << "."; }

// comma and space
void comma() { std::cout << ","; }

// question 
void question() { std::cout << "?"; }

// exclamation
void exclaim() { std::cout << "!"; }

// eof