// AI/LOGIC/ANALYSIS/STATX.CPP - USED BY "AI/AI.H"
// FILE RESPONSIBLE FOR STAT(), GLOB(), GLOB2(), GLOB3C()

#ifndef _STATS_N_GLOB
#define _STATS_N_GLOB

#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include <unistd.h>
#include <glob.h>
#include <vector>
#include <dirent.h>

// #ifndef _GLOB_FUNCTION
// #define _GLOB_FUNCTION

// directory count -&- file counters
// int dcount=0;
// int fcount=0;

// // stats() stat directories
// int stats(std::string arg) {

//     std::cout << std::endl;
//     std::cout << "~:: stats() function:" << std::endl;

//     const std::string dir=arg;
//     struct stat st;
//     bool s;
//     bool isdir = false;

//     if (stat(dir.c_str(), &st) != 0) {
//         //std::cout << "~:: stats() -- not a directory." << std::endl;
//         s = false;
//     } else {
//         //std::cout << "~:: stats() -- is directory." << std::endl;
//         s = true;
//     }; // Correct

//     switch (st.st_mode & S_IFMT) {
//         case S_IFBLK:
//         printf("block device: ");
//         break;

//         case S_IFCHR:
//         printf("character device: ");
//         break;

//         case S_IFDIR:
//         printf("\t--directory: ");
//         isdir=true;
//         dcount++;
//         break;

//         case S_IFIFO:
//         printf("FIFO/pipe: ");
//         break;

//         case S_IFLNK:
//         printf("symlink: ");
//         break;
        
//         case S_IFREG:
//         printf("regular file: ");
//         isdir=false;
//         fcount++;
//         break;
        
//         case S_IFSOCK:
//         printf("socket: ");
//         break;
        
//         default:
//         printf("file or directory: ");
//         break;
//     };

//     if (s == true) {
//         return 0;
//     } else {
//         return 1;
//     }
// };

// 1st glob function
inline std::vector<std::string> glob(const std::string& pat){
    using namespace std;
    glob_t glob_result;
    glob(pat.c_str(),GLOB_TILDE,NULL,&glob_result);
    vector<string> ret;

    std::cout << "\t\t   :: files in directory ::" << std::endl;
    
    for(unsigned int i=0;i<glob_result.gl_pathc;++i){
        ret.push_back(string(glob_result.gl_pathv[i]));
    
        // print results
        std::cout << "\t\t\t * " << string(glob_result.gl_pathv[i]) << std::endl;
    }
    globfree(&glob_result);

return ret;
};

// second glob function
int glob2(int args, char argv[]) {
    struct dirent *entry = nullptr;
    DIR *dp = nullptr;

    std::string dirname = "/bay2";

    if (args==1) {
        std::cout << "~:: glob2(" << argv[1] << "):" << std::endl;
    } else {
        std::cout << "~:: glob2(" << dirname << "):" << std::endl;
    }

    //system("pwd");

    dp = opendir(args >= 1 ? (argv+1) : "/bay");
    if (dp != nullptr) {
        while ((entry = readdir(dp)))
            std::cout << entry->d_name << std::endl;
    }

    closedir(dp);

return 0;
};

// // 3rd glob function -- used by the "Modular Bay(s)"
    // defined in "modular_bay" -> "glob.cpp"
// int glob3c(int args, char argv[]) {
//     struct dirent *entry = nullptr;
//     DIR *dp = nullptr;
//     std::string dirc;
//     std::string xcomp;

//     std::string current_directory = ".";
//     std::string up_directory = "..";

//     if (args == 1) {
//         dirc = argv;
//     } else if (args == 2) {
//         dirc = "/bay2";
//     }
    
//     // debugging output
//     //std::cout << "(debug) dir=\"" << dirc << "\";" << std::endl;

// // debugging output here (commented out)
//     // if (args==1) {
//     //     std::cout << "(debug) ~:: glob3c() (0)(" << argv << ")" << std::endl;
//     //     std::cout << "(debug) glob3c(using argv[]);" << std::endl;
//     // } else if (args==2) {
//     //     std::cout << "~:: glob3c(" << dirc << "):" << std::endl;
//     //     std::cout << "(debug) glob3c(using dirname);" << std::endl;
//     // } else {
//     //     std::cout << "~:!: glob3c() - error - unknown argument passed (use 1 or 2)" << std::endl;
//     // }

//     dp = opendir((args==1) ? dirc.c_str() : "./bay");
//     if (dp != nullptr) {
//         while ((entry = readdir(dp))) {
//             xcomp = entry->d_name;
            
//             //std::cout << xcomp << std::endl;

//             if (stats(xcomp.c_str()) == 0) {
//                 // is directory

//                 if (xcomp.compare(current_directory) == 0 || xcomp.compare(up_directory) == 0) {
//                     std::cout << "(debug) xcomp=true; skipping \".\" -&- \"..\"" << std::endl;
                    
//                     // directory
//                     continue;
//                 } else {
//                     std::cout << "|__ /" << xcomp << std::endl;
//                 }
                
//                 std::cout << "\t~:: glob in :: \"" << entry->d_name << "\"" << std::endl;
//                 glob3c(1, entry->d_name);
                                
//                 //  else {
//                 //     // is "." or ".."
//                 //     //std::cout << "(debug) xcomp=false; ";
                    
//                 //     // recursive
//                 //     //std::cout << "\t- recursive function glob3c(entry->d_name);" << std::endl;
//                 // }
//             } else if (xcomp.compare(current_directory) != 0 && xcomp.compare(up_directory) != 0) {
//                 fcount++;

//                 // regular file
//                 std::cout << "-- ./" << xcomp << std::endl;
//             }
//         }
//     }
//     closedir(dp);

// return 0;
// };
#endif

// eof