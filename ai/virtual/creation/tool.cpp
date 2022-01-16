// ./AI/VIRTUAL/CREATION/TOOL.CPP -- USED TO CREATE THE "TOOL" EXECUTABLE.
// "AI/BIN/TOOL" PROGRAM.

// THE TOOL PROGRAM WILL CHECK THE CHECKSUMS FOR ALL FILES INTEGRITY
// ALSO WILL SET ALL THE EXECUTE PERMISSIONS FOR ALL THE SCRIPTS (HANDLED BY "AI/BIN/SCRIPT/PERM.SH" NOW)
// ALSO WILL HANDLE CREATION OF THE VIRTUAL FILESYSTEM (INCLUDING ALL THE FILES AND COMPILE THE "VIRTUAL-CD")

#include <iostream>

using namespace std;

#define TOOL "(tool): "

int main(int argc, char *argv[]) {

    std::cout << "tool://matrix" << std::endl;

    if (argc >= 2 && argv[1][0] == '-') {
        switch (argv[1][1]) {
            case 'p':   // set executable attribute on scripts
                std::cout << TOOL << "- setting permissions." << std::endl;
                system("chmod +x ai/bin/script/perm.sh");
                system("ai/bin/script/perm.sh");
            break;

            default:

            break;
        };
    }
return 0;
}