// /AI/BAY.CPP - USED BY /AI/AI.H - FOR ACCESSING DATA RESTING IN THE BAY

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <thread>

#include "modular_bay.h"

class Bay {
    private:
        std::string path;
        std::string filename;
        std::ifstream file_data;

        bool file_is_open;
        int starting_time;

    public:
        Bay(std::string path) {
            // constructor

            // set the starting time for scanning periodically
                // in a thread
            this->timer();
            
            // set the filename
            this->path = path;

            std::cout << "~:: accessing modular bay construct." << std::endl;

            // periodically use this->scan() to find new data
            std::cout << "\t~:: opening " << MB_path << " for inspection." << std::endl;
            this->scan();
        };
        
        void timer() {
            
            std::cout << "\t~:: starting timer." << std::endl;

            // function declared below
            void funct();
            
            // use thread for funct()
            std::thread first_thread(funct);
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

        void glob() {
            // glob all content inside the bay area
            
            std::cout << "\t~:: glob()" << std::endl;
        }

        void scan() {
            // scan bay periodically based on the time ~ ca. once every 30 seconds or 60 seconds or so
            this->glob();
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
void funct() {

    int starting_time = time(NULL);
    int mean_time = time(NULL);

    for (int i=0;; i++) {
        if (i % 2000 == 1) {
            mean_time = time(NULL);
        }

        if (mean_time % 150 == 1) {
            std::cout << "~:: checking bay." << std::endl;
        }

        if ((mean_time - starting_time) % 100 == 1)  // break out of loop after no activity or reset timer here
            break;
    }
};