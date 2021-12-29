// /AI/BAY.CPP - USED BY /AI/AI.H - FOR ACCESSING DATA RESTING IN THE BAY

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <thread>

#include "modular_bay.h"

class ModularBay {
    private:
        std::string path_var;
        std::string filename;
        std::ifstream file_data;

        bool file_is_open;
        int starting_time;

    public:
        ModularBay() {
            // constructor

            // set the starting time for scanning periodically
                // in a thread
            
            // set the filename
            this->path_var = MB_path;

            std::cout << "~:: accessing modular bay construct." << std::endl;

            // periodically use this->scan() to find new data
            std::cout << "\t~:: opening \"/" << MB_path << "\" for inspection." << std::endl;
            //this->timer();
        };
        
        void timer() {
            std::cout << "\t~:: starting timer." << std::endl;
            //int starting_time = time(NULL);
            //int mean_time = time(NULL);

            // for (int i=0;; i++) {
            //     if (i % 2000 == 1) {
            //         mean_time = time(NULL);
            //     }

            //     if (mean_time % 150 == 1) {
            //         std::cout << "~:: checking bay." << std::endl;
            //     }

            //     if ((mean_time - starting_time) % 100 == 1)  // break out of loop after no activity or reset timer here
            //         break;
            // }
        };
        
        void open() {
            // open the file for input
            std::cout << "\t~:: opening file: " << this->filename << std::endl;
            this->file_data.open(this->filename);

            if (this->file_data.is_open() == true) {
                this->file_is_open = true;
            }
        };

        void close() {
            // close the file
            std::cout << "\t~:: closing file: " << this->filename << std::endl << std::endl;
            this->file_data.close();
            this->file_is_open = false;
        }

        void globf(std::string pattern) {
            // glob all content inside the bay area
            std::cout << "\t\t~:: glob() in directory: (" << this->path_var << "):" << std::endl;
            
            // glob here
                // handle string vector
            glob(pattern.c_str());
        }

        void scan() {
            std::cout << "\t~:: scanning() directory: (" << this->path_var << ")." << std::endl;
            // scan bay periodically based on the time ~ ca. once every 30 seconds or 60 seconds or so
            this->globf(pattern);
        }

        void analyze() {
            // analyze data
            // read file and analyze text based of headers
            std::cout << "\t~:: analyzing content of file." << std::endl;
        };
};

// glob bay for (new) files

// format data




// functions
// void funct() {
//    int starting_time = time(NULL);
//     int mean_time = time(NULL);

//     for (int i=0;; i++) {
//         if (i % 2000 == 1) {
//             mean_time = time(NULL);
//         }

//         if (mean_time % 150 == 1) {
//             std::cout << "~:: checking bay." << std::endl;
//         }

//         if ((mean_time - starting_time) % 100 == 1)  // break out of loop after no activity or reset timer here
//             break;
//     } 
// };