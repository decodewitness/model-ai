// /AI/SYSTEM/MODULES/MODULAR.CPP - USED BY "/AI/AI.H"
// DEFINES THE MODULAR CLASS FOR CREATING VARIOUS MODULES OR ENTITIES.

#include <string>
#include <iostream>

#include "AMModule.h"

const int limit = 64;

class Modular {
private:    
    int data_in_module;
    
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
    std::cout << std::endl << "-:: created modular template." << std::endl;

    modular.set_data(str3);
    std::cout << "\t~:: filled in modular template with generic data." << std::endl;

    // query the modular template
    modular.query();
};

Modular::Modular(std::string n, std::string t) {
    this->module_name = n;
    this->module_type = t;
    this->data_in_module = 1;
};

void Modular::set_data(std::string dat) {
    if (this->data_in_module < limit-1) {
        this->module_data[data_in_module] = dat;
        this->data_in_module++;
        std::cout << "~: updated module - index(" << (this->data_in_module - 1) << ")." << std::endl;
    } else {
        perror("!~ (ERROR) - setting Modular data");
    }
};

void Modular::set_datas(int i, std::string dat) {
    
    bool updated = true;
    
    if (this->data_in_module <= limit-1) {
        if (i <= this->data_in_module) {
            this->module_data[i] = dat;
            std::cout << "\t~:: updated record (" << i << ")." << std::endl;
        } else {
            this->module_data[this->data_in_module++];
        }
    } else {
        updated = false;
        perror("!~ (ERROR) - setting Modular data");
    }
    
    if (updated == true) {
        std::cout << "~: updated module - index(" << (this->data_in_module - 1) << ")." << std::endl;
    } else {
        std::cout << "\t~!! bumped onto limit capacity of module (@ " << this->data_in_module << ")." << std::endl;
        std::cout << "\t~:: index now at: " << this->get_index() << std::endl;
    }
};


std::string Modular::get_data(int index) {
    return this->module_data[index];
};

int Modular::get_index() {
    return this->data_in_module - 1;
}

void Modular::query() {
    std::cout << "-:: query module ::-" << std::endl;
    std::cout << "\t~:: data inside modular template (index): (" << this->get_index() << ")" << std::endl;
    std::cout << "\t~:: data inside modular template (at index): (" << this->get_data(this->get_index()) << ")" << std::endl;
};

int Modular::polldata() {
    int i;
    for (i = 0; i < this->get_index(); i++) {
        std::cout << ":" << (i+1) << ": " << this->get_data(i) << std::endl;
    }

    return i;
};