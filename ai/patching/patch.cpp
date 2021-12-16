// AI/PATCHING/PATCH.CPP - USED BY /AI/AI.H

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

const int max_cabinets = 1024;

void patch_module() {

    std::string ARCHIVE_LIST  = "./ai/patching/files/archives_list.csv";
    std::string REPOSITORY = "https://model-ai.com/archive";
    std::string PATCH_SCRIPT = "./ai/patching/repos";

    std::ifstream archives;
    std::string cabinet[max_cabinets];
    std::string cabinets_line;
    std::string str;

    int count = 0;
    int files_count = 0;
    char ch = '0';


    archives.open(ARCHIVE_LIST);

    if (archives.is_open() == true) {
        while (getline(archives, cabinets_line)) {
            std::cout << "~:: (DEBUG) cabinets:" << std::endl;
            std::cout << cabinets_line << std::endl;

            for (int i=0, j=0, k=0; i<cabinets_line.length(); i++) {
                if (cabinets_line[i] == '{' || cabinets_line[i] == '}') {
                    continue;
                }

                if (cabinets_line[i] == '"') {
                    files_count++;
                    continue;
                }

                if (cabinets_line[i] != ',') {
                    str = cabinets_line[i];
                    cabinet[k].append(str);
                } else if (j<max_cabinets-1) {
                    //cabinet[k][j] = '\0';
                    k++;
                    count = k;
                    j=0;
                    continue;
                }
            }
        }

        files_count = files_count / 2;
        std::cout << "~:: (PATCHING FILES)::(" << files_count << "):" << std::endl;

        for (int i=0; i<files_count; i++) {
            std::cout << "\t* (" << (i+1) << ") * " << cabinet[i] << " ~ being patched." << std::endl;

            // curl or wget cabinet file here

        }

        // wait for 1 second
        sleep(1);
    }
};