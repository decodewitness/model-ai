// AI/SYSTEM/MENU/MENU.H    -   USED BY "AI/SYSTEM/MENU/MENU.CPP"

// headers
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

// variable context
// change this when adding or deleting from menuOption[]
unsigned int menuSize = 5;

// the options for the menu
const char menuOption[][32] = {
    "(N)ew file",
    "(L)oad file",
    "(S)earch files",
    "(D)elete file",
    "(Q)uit"
};