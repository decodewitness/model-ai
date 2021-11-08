// /AI/SYSTEM/MODULES/MODULAR.CPP - USED BY "/AI/AI.H"
// DEFINES THE MODULAR CLASS FOR CREATING VARIOUS MODULES OR ENTITIES.

#include <string>
#include <iostream>

const int limit = 64;

class Modular {
private:    
    int data_in_module;
    
    std::string module_name;
    std::string module_type;
    std::string module_data[limit]; // increase data limit later

public:
    Modular(std::string n, std::string t); 
    ~Modular();

    void set_data(std::string dat);
    std::string get_data(int index);

    int get_index();
};

Modular::Modular(std::string n, std::string t) {
    this->module_name = n;
    this->module_type = t;
    this->data_in_module = 0;
};

void Modular::set_data(std::string dat) {
    if (this->data_in_module < limit) {
        this->module_data[data_in_module] = dat;
        this->data_in_module++;
        std::cout << "~: updated module - index(" << (this->data_in_module - 1) << ")." << std::endl;
    } else {
        perror("!~ (ERROR) - setting Modular data");
    }
};

std::string Modular::get_data(int index) {
    return this->module_data[index];
};

int Modular::get_index() {
    return this->data_in_module;
}