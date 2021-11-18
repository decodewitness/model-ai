// /AI/SYSTEM/MODULES/MODULAR.CPP - USED BY "/AI/AI.H"
// DEFINES THE MODULAR CLASS FOR CREATING VARIOUS MODULES OR ENTITIES.

#include <string>
#include <iostream>

#include "ammodule/AMModule.cpp"

const int limit = 128;

class Modular {
private:

    bool moddata[limit];
    int data_in_module;
    
    std::string empty_module;
    std::string module_name;
    std::string module_type;
    std::string module_data[limit]; // increase data limit later

public:
    Modular();
    Modular(std::string n, std::string t); 
    
    void set_data(std::string dat); // set data
    void set_datas(int i, std::string dat); // set data at index

    std::string get_data(int index);    // returns data

    int get_index(); // returns index nr

    void query();   // show last index + last data
    int polldata(); // request all encapsulated data
};

Modular::Modular() {
    std::string str1 = "module";
    std::string str2 = "module";
    std::string str3 = "module";

    Modular modular(str1, str2);
    std::cout << std::endl << "-__:::: ( created ) modular template ::::__-" << std::endl << std::endl;

    //modular.set_data(str3);
    std::cout << "\t~:: filled in modular template with generic data." << std::endl;

    //this->moddata[] = true;
    this->moddata[0] = this->moddata[1] = this->moddata[2] = true;
    this->data_in_module = 0;
    // query the modular template
    //modular.query();
};

Modular::Modular(std::string n, std::string t) {
    this->module_name = n;
    this->module_type = t;
    //this->data_in_module = 0;
    //this->moddata = false;
};

void Modular::set_data(std::string dat) {
    if (this->data_in_module <= limit) {

        this->module_data[data_in_module] = dat;
        this->moddata[this->data_in_module] = true;
        this->data_in_module++;
        std::cout << "~: updated module - at index(" << (this->data_in_module - 1) << ")." << std::endl;

    } else {
        perror("!~ (ERROR) - setting Modular data");
        this->moddata[this->data_in_module] = false;
    }
};

// void Modular::set_datas(int i, std::string dat) {
    
//     std::cout << "\t~:: setting modular data (" << i << ")" << std::endl;
//     bool updated = true;
    
//     if (this->data_in_module <= limit-1) {
//         if (i <= this->data_in_module) {
//             this->module_data[i] = dat;
//             this->moddata = true;
//             std::cout << "\t~:: updated modular record (" << i << ")." << std::endl;
//         } else {
//             this->module_data[this->data_in_module++];
//         }
//     } else {
//         updated = false;
//         this->moddata = false;
//         perror("!~ (ERROR) - setting Modular data");
//     }
    
//     if (updated == true) {
//         std::cout << "~: updated module - index(" << (this->data_in_module - 1) << ")." << std::endl;
//     } else {
//         std::cout << "\t~!! bumped onto limit capacity of module (@ " << this->data_in_module << ")." << std::endl;
//         std::cout << "\t~:: index now at: " << this->get_index() << std::endl;
//     }
// };

std::string Modular::get_data(int index) {
    if (this->moddata[index] == true) {
        return this->module_data[index];
    } else {
        return this->empty_module;
    }
};

int Modular::get_index() {
    if (this->data_in_module > -1) {
        return this->data_in_module;
    } else {
        return 0;
    }
};

void Modular::query() {
    
    std::cout << "-:: query module ::-" << std::endl;
    
    if (this->moddata[this->data_in_module] == true) {
        std::cout << "\t~:: data inside modular template (index): (" << this->get_index() << ")" << std::endl;
        std::cout << "\t~:: data inside modular template (at index): (" << this->get_data(this->get_index()) << ")" << std::endl;
    } else {
        std::cout << "\t~:: (query) no data in this module!" << std::endl;
    }
};

int Modular::polldata() { // need to check this
    int i;
    
    if (this->moddata[this->data_in_module -1] == true) {
        for (i = 0; i < this->get_index(); i++) {
            std::cout << ":" << (i) << ": " << this->get_data(i) << std::endl;
        }
    } else {
        std::cout << "~:: (poll) no data in this module!" << std::endl;
        std::cout << "this->moddata[index] = " << this->data_in_module << "\tthis->get_index() = " << this->get_index() << std::endl;
    }

    return i;
};