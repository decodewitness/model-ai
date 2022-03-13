// AI/DATA/CONVERT/CONVERT.CPP  -   CONVERTS DATA   -   NOT USED YET!

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

// const std::string outfile = "my_output.txt";
const std::string outfile = "ai/data/in/pipeline";


std::string passthrough_filter(std::string d) {
    std::string raw;
    std::string ommitted;
    std::string filter;
    std::string output;

    raw = d;
    output = d;

    std::cout << "~:: passthrough_filter() : " << std::endl;
    std::cout << std::endl;
    std::cout << "\t-> (mutable):" << std::endl;
    std::cout << "\t\t\"" << raw << "\"." << std::endl;

    // remove characters
    output.erase(remove(output.begin(), output.end(), '?'), output.end());
    output.erase(remove(output.begin(), output.end(), '!'), output.end());

    std::cout << std::endl;
    std::cout << "\t-> (mutated):" << std::endl;
    std::cout << "\t\t\"" << output << "\"" << std::endl;

    std::cout << std::endl;

    return output;
};

void convert_datas(std::string filename, int lines) {
    std::ifstream file;
    std::ofstream output;

    std::string data;
    std::string filtered;

    file.open(filename);
    output.open(outfile);

    if (file.is_open() == true && output.is_open() == true) {
        for (int i=0; i<lines; i++) {
            // process handle
//            file >> data;
//            output << data << "\t";

            // process description
            std::getline(file, data);

            filtered = passthrough_filter(data);
            output << filtered;

            // process tags
            //output << "\t[]\t{}";
        }
    } else {
        std::cout << "(!) error - convert_data() - error opening files for reading/writing." << std::endl;
    }

    if (file.is_open() == true) {
        file.close();
    }

    if (output.is_open() == true) {
        output.close();
    }
};

// eof