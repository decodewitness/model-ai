#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

const std::string INFILES = "./ai/data/in/infiles";

class Construct {

private:
    ifstream inFiles;

    int nrOfFiles;

    bool mainset;
    bool dataset;

    std::string _dataFiles;
    std::string _mainFiles;
    std::string _fileString;

    vector<string> correct_files;

public:

    Construct() {
        std::cout << "~:: setting construct." << std::endl;

        this->_dataFiles = INFILES;
        this->dataset = true;
    };

    void preprocess() { // function opens the directives file and assigns a main file for data assimilation purposes

        std::cout << std::endl << "~:: preprocessing module." << std::endl;
        std::cout << "\t~:: set data-in-file as header->_dataFiles." << std::endl;

        // set data file here in "inFiles"
        std::cout << "\t~:: opening _dataFiles." << std::endl;
        this->inFiles.open(_dataFiles);

        if (this->inFiles.is_open() == true) {
            std::cout << "\t\t~:: open." << std::endl;

            // do logic
            std::string myFiles;
            
            // inside loop here
            while (this->inFiles >> myFiles) {

                this->_fileString = myFiles;
                
                stringstream s_stream(myFiles);

                while(s_stream.good()) {
                    string substr;
                    getline(s_stream, substr, ',');
                    this->correct_files.push_back(substr);
                }
                // take cabinets from string
                this->_mainFiles = _fileString;   // change algorithm here

                // generate output
                std::cout << std::endl;
                std::cout << "~:: files ::~" << std::endl;
                std::cout << "    -----" << std::endl;
                
                for (int i=0; i<this->correct_files.size(); i++) {
                    std::cout << "    (*)_mainFile(" << this->correct_files.at(i) << ")." << std::endl;
                    process(this->correct_files.at(i), i);
                }
                
                std::cout << std::endl;

                // call function to process main batch of data from myFile/_mainFile
            }

            this->mainset = true;
            this->inFiles.close();
            

            //this->inFiles >> myFile;

            // do error checking here
            

            // this->_mainFiles = myFiles;
            // this->mainset = true;
        }
    };

    void process(std::string filen, int sizedn) {

        ifstream datacab;
        std::string line;

        // for (int i=0; i < sizedn; i++) {
        std::cout << "\t- processing file: " << sizedn << ": ";
        std::cout << this->correct_files.at(sizedn);

        datacab.open(this->correct_files.at(sizedn));
        if (datacab.is_open() == true) {
            std::cout << std::endl << "\t- opened " << this->correct_files.at(sizedn) << "." << std::endl;
        }

        // do data logic on main set
        while (datacab >> line) {
            // math or abstract logic here

            std::cout << "x";

            // do string logic
        }

        std::cout << std::endl;
        std::cout << "\t- closing " << this->correct_files.at(sizedn) << std::endl;
        
        datacab.close();


        // for (int i=0; i < sized; i++) {
        //     std::cout << "\t- processing file: " << (i+1) << ": ";
        //     std::cout << this->correct_files.at(i);

        //     datacab.open(this->correct_files.at(i));

        //     // do data logic on main set
        //     while (datacab >> line) {
        //         // math or abstract logic here

        //         std::cout << "x";

        //         // do string logic
        //     }

        //     std::cout << std::endl;
        //     std::cout << "\t- closing " << this->correct_files.at(i) << std::endl;
            
        //     datacab.close();
        // }

    //     if (this->mainset == true) {
    //         std::cout << "\t~:: _mainFile is set." << std::endl;

    //         if (this->inFiles.is_open() == true) {
    //             // error
    //             perror("~:!: error. process()->inFiles; was already open.");
    //         } else {
    //             for (int i=0; i<correct_files.size(); i++) {
    //                 inFiles.open(this->correct_files.at(i));
    //             }
            
    //             if (this->inFiles.is_open() == true) {

    //                 // process data here
    //                 std::cout << "\t~:: processing batch in data." << std::endl;
                    
    //                 // (here)
    //                 // data arrive in batch size from _mainFile from "infile" inside "./ai/data"

    //                 // close file headers
    //                 this->inFiles.close();
    //             }
    //         }
    //     } else {
    //         perror("~:!: error. mainset is not ready.");
    //     }
    };
};

// eof