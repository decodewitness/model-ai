// (inside AI directory) AI/ROUTINES.CPP - GRAMMAR ROUTINES FOR AI MODEL (USED BY SAYING.CPP & INTERPRET.H)
// handle interpunctions and line carries

#include <iostream>
#include <cstring>

void carry() { std::cout << std::endl; }    // newline character
void skipline() { std::cout << std::endl << std::endl; }	// 1x "skip()" is the same as two times: "carry(); carry();"
void space() { std::cout << (32); } // space
void dot() { std::cout << "."; }    // interpunction
void comma() { std::cout << ","; }  // comma
void question() { std::cout << "?"; }   // question
void exclaim() { std::cout << "!"; }    // exclamation point

// eof