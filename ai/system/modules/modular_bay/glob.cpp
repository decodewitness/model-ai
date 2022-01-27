// AI/SYSTEM/MODULES/GLOB.CPP - USED BY "AI/SYSTEM/MODULES/MODULAR_BAY.H"
// FILE RESPONSIBLE FOR STAT(), GLOB3C()

#ifndef _GLOB_3C_FILE
#define _GLOB_3C_FILE

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

int dcount=0;
int fcount=0;

// stats() stat directories
int stats(std::string arg) {

    std::cout << std::endl;
    std::cout << "~:: stats() function:" << std::endl;

    const std::string dir=arg;
    struct stat st;
    bool s;
    bool isdir = false;

    if (stat(dir.c_str(), &st) != 0) {
        //std::cout << "~:: stats() -- not a directory." << std::endl;
        s = false;
    } else {
        //std::cout << "~:: stats() -- is directory." << std::endl;
        s = true;
    }; // Correct

    switch (st.st_mode & S_IFMT) {
        case S_IFBLK:
        printf("block device: ");
        break;

        case S_IFCHR:
        printf("character device: ");
        break;

        case S_IFDIR:
        printf("\t--directory: ");
        isdir=true;
        dcount++;
        break;

        case S_IFIFO:
        printf("FIFO/pipe: ");
        break;

        case S_IFLNK:
        printf("symlink: ");
        break;
        
        case S_IFREG:
        printf("regular file: ");
        isdir=false;
        fcount++;
        break;
        
        case S_IFSOCK:
        printf("socket: ");
        break;
        
        default:
        printf("file or directory: ");
        break;
    };

    if (s == true) {
        return 0;
    } else {
        return 1;
    }
};

// 3rd glob function -- used by the "Modular Bay(s)"
int glob3c(int args, char argv[]) {
    struct dirent *entry = nullptr;
    DIR *dp = nullptr;
    std::string dirc;
    std::string xcomp;

    std::string current_directory = ".";
    std::string up_directory = "..";

    if (args == 1) {
        dirc = argv;
    } else if (args == 2) {
        dirc = "/bay2";
    }
    
    // debugging output
    //std::cout << "(debug) dir=\"" << dirc << "\";" << std::endl;

// debugging output here (commented out)
    // if (args==1) {
    //     std::cout << "(debug) ~:: glob3c() (0)(" << argv << ")" << std::endl;
    //     std::cout << "(debug) glob3c(using argv[]);" << std::endl;
    // } else if (args==2) {
    //     std::cout << "~:: glob3c(" << dirc << "):" << std::endl;
    //     std::cout << "(debug) glob3c(using dirname);" << std::endl;
    // } else {
    //     std::cout << "~:!: glob3c() - error - unknown argument passed (use 1 or 2)" << std::endl;
    // }

    dp = opendir((args==1) ? dirc.c_str() : "./bay");
    if (dp != nullptr) {
        while ((entry = readdir(dp))) {
            xcomp = entry->d_name;
            
            //std::cout << xcomp << std::endl;

            if (stats(xcomp.c_str()) == 0) {
                // is directory

                if (xcomp.compare(current_directory) == 0 || xcomp.compare(up_directory) == 0) {
                    std::cout << "(debug) xcomp=true; skipping \".\" -&- \"..\"" << std::endl;
                    
                    // directory
                    continue;
                } else {
                    std::cout << "|__ /" << xcomp << std::endl;
                }
                
                std::cout << "\t~:: glob in :: \"" << entry->d_name << "\"" << std::endl;
                glob3c(1, entry->d_name);
                                
                //  else {
                //     // is "." or ".."
                //     //std::cout << "(debug) xcomp=false; ";
                    
                //     // recursive
                //     //std::cout << "\t- recursive function glob3c(entry->d_name);" << std::endl;
                // }
            } else if (xcomp.compare(current_directory) != 0 && xcomp.compare(up_directory) != 0) {
                fcount++;

                // regular file
                std::cout << "-- ./" << xcomp << std::endl;
            }
        }
    }
    closedir(dp);

return 0;
};
#endif

// eof