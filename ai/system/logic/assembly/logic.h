// /AI/LOGIC/ASSEMBLY/LOGIC.H: USED BY "/AI/LOGIC/ASSEMBLY/INPUT.CPP" TO SET THE MODE OF INPUT
#include "command.h"

// LOGIC CONTENT OVERRIDE CONTENT
//  adapt yy to logic and logic to AI
//  and set yy to manually override or
//  change it to 0 to not manually override.

const int yy = 3;
const int logic = yy;

bool isSim=false;
bool isConvert=false;
bool isConvertUSD=false;
bool isHash=false;
bool isKill=false;
bool isStepping=false;
bool isRollout=false;
bool isCurl=false;