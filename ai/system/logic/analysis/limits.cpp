// "AI/LOGIC/LIMITS.CPP" - USED BY "/AI/AI.H" -- SOME OPPOSING LIMITS FOR THE AI MODEL


// limits char arrays
const int med=1024;
const int max=4096;

// zero
const int zero=0;
// nil
const int nil=0;

//entropy
int entropy1[8] = { 1, 0, 1, 0, 1, 0, 1, 0 };
int entropy2[8] = { 0, 1, 1, 2, 3, 5, 8, 13 };
int entropy3[8] = { 21, 34, 55, 89, 144, 233, 377, 600};

// entropy
int entropy11[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// small entropy
int entropy20[4] = {0, 0, 0, 0};
int entropy21[4] = {1, 0, 1, 0};
int entropy22[4] = {1, 0, 0, 1};
int entropy23[4] = {0, 0, 1, 1};
int entropy24[4] = {0, 1, 1, 0};
int entropy25[4] = {1, 1, 0, 0};

// hex array
char hex[4][2];

// characters
char percent[2] = "%";
char backslash[2] = "\\";

// alphanumeric characters
char alpha[128] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '!', '-', '+', '*', '=', '&', '$', '#', '@', '/', '^', '(', ')', '_'};

// ascii
int asciitab[128] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87};

// some more arrays
char carriage_return[2][2] = {'\r', '\n'};

// eof