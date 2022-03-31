// /AI/LOGIC/ASSEMBLY/LOGIC.H: USED BY "/AI/LOGIC/ASSEMBLY/INPUT.CPP" TO SET THE MODE OF INPUT
#include "command.h"

// LOGIC CONTENT OVERRIDE CONTENT
//  adapt yy to logic and logic to AI
//  and set yy to manually override or
//  change it to 0 to not manually override.

const int yy = 3;
const int logic = yy;

// when not a command but language
bool isLogic=false;

// booleans for in "AI/AI.CPP" -- query() function
bool isHelp=false;
bool isVersion=false;
bool isSim=false;
bool isConvert=false;
bool isConvertUSD=false;
bool isHash=false;
bool isKill=false;
bool isStepping=false;
bool isRollout=false;
bool isCurl=false;
bool isBank=false;
bool isTable=false;
bool isTableTo=false;
bool isDice=false;
bool isDice2=false;
bool isStat=false;
bool isRm=false;
bool isCp=false;
bool isAdd=false;
bool isSubtract=false;
bool isMultiply=false;
bool isDivide=false;
bool isPower=false;
bool isPlayAudio=false;
bool isReturnPunch=false;
bool isPrintPunch=false;
bool isAddData=false;
bool isConvertData=false;
bool isRunPytube=false;
bool isToggleAudio=false;
bool isNewCred=false;
bool isListCred=false;
bool isMenu=false;
bool isTest=false;
bool isClearQue=false;
bool isWhatHave=false;
bool isAnswer=false;
// eof