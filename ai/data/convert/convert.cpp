// AI/DATA/CONVERT/CONVERT.CPP  -   CONVERTS DATA   -   NOT USED YET!

#include <iostream>
#include <string>
#include <fstream>

const std::string outfile = "my_output.txt";

void convert_data(std::string filename, int lines) {
    std::ifstream file;
    std::ofstream output;

    std::string data;

    file.open(filename);
    output.open(outfile);

    if (file.is_open() == true && output.is_open() == true) {
        
        for (int i=0; i<lines; i++) {
            // process handle
            file >> data;
            output << data << "\t";

            // process description
            std::getline(file, data);
            output << data;

            // process tags
            output << "\t[]\t{}";
        }
    } else {
        std::cout << "(!) error - convert_data() - opening files for reading/writing." << std::endl;
    }

    if (file.is_open() == true) {
        file.close();
    }

    if (output.is_open() == true) {
        output.close();
    }
};

// eof