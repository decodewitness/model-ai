#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const std::string INFILE = "./ai/data/infile";

class Construct {

private:
    ifstream inFiles;

    int nrOfFiles;

    bool mainset;
    bool dataset;

    std::string _dataFile;
    std::string _mainFiles;
    std::string _fileString;

public:

    Construct() {
        std::cout << "~:: setting construct." << std::endl;

        this->_dataFile = INFILE;
        this->dataset = true;
    };

    void preprocess() { // function opens the directives file and assigns a main file for data assimilation purposes
        std::cout << std::endl << "~:: preprocessing module." << std::endl;
        std::cout << "\t~:: set data infile as header->_dataFile." << std::endl;

        // set data file here in "inFiles"
        std::cout << "\t~:: opening _dataFile." << std::endl;
        this->inFiles.open(_dataFile);

        if (this->inFiles.is_open() == true) {
            std::cout << "\t\t~:: open." << std::endl;

            // do logic
            std::string myFiles;

            // inside loop here
            while (this->inFiles >> myFiles) {
                this->_fileString = myFiles;

                // take cabinets from string
                this->_mainFiles = _fileString;   // change algorithm here

                // generate output
                std::cout << std::endl;
                std::cout << "~:: files ::~" << std::endl;
                std::cout << "    -----" << std::endl;
                std::cout << "    (*)_mainFile(" << _mainFiles << ")." << std::endl;
                std::cout << std::endl;

                // call function to process main batch of data from myFile/_mainFile
                process();
            }
            
            //this->inFiles >> myFile;

            // do error checking here
            this->mainset = true;

            // this->_mainFiles = myFiles;
            // this->mainset = true;

            this->inFiles.close();
        }
    };

    void process() {
        if (this->mainset == true) {
            std::cout << "\t~:: _mainFile is set." << std::endl;

            if (this->inFiles.is_open() == true) {
                // error
                perror("~:!: error. process()->inFiles; was already open.");
            } else {
                inFiles.open(_mainFiles);
            
                if (this->inFiles.is_open() == true) {

                    // process data here
                    std::cout << "\t~:: processing batch in data." << std::endl;
                    
                    // (here)
                    // data arrive in batch size from _mainFile from "infile" inside "./ai/data"

                    // close file headers
                    this->inFiles.close();
                }
            }
        } else {
            perror("~:!: error. mainset is not ready.");
        }
    };
};

// eof