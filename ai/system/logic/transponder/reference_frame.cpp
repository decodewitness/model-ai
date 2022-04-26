// AI/SYSTEM/LOGIC/TRANSPONDER/REFERENCE_FRAME.CPP USED BY (NOT USED YET!!! EITHER AI/AI.H OR TRANSPONDER.H)

#include <string>

// structure reference_frame
struct reference_frame {
    std::string name;
    std::string subject1;
    std::string subject2;
    std::string subject3;
    std::string topic1;
    std::string topic2;
    std::string topic3;
    std::string relation1;
    std::string relation2;
    std::string relation3;
    std::string link1;
    std::string link2;
    std::string link3;
};

// assign method
reference_frame assign_reference_frame(std::string name, std::string subject1, std::string subject2, std::string subject3, std::string topic1, std::string topic2, std::string topic3, std::string relation1, std::string relation2, std::string relation3, std::string link1, std::string link2, std::string link3) {
    // assign new reference_frame
    reference_frame x;
    // assign all the values
    x.name = name;
    x.subject1 = subject1;
    x.subject2 = subject2;
    x.subject3 = subject3;
    x.topic1 = topic1;
    x.topic2 = topic2;
    x.topic3 = topic3;
    x.relation1 = relation1;
    x.relation2 = relation2;
    x.relation3 = relation3;
    x.link1 = link1;
    x.link2 = link2;
    x.link3 = link3;
    // return reference_frame
    return x;
};

// update methods
void update_reference_name(reference_frame &x, std::string s) {
    x.name = s;
};

void update_reference_subject1(reference_frame &x, std::string s) {
    x.subject1 = s;
};

void update_reference_subject2(reference_frame &x, std::string s) {
    x.subject2 = s;
};

void update_reference_subject3(reference_frame &x, std::string s) {
    x.subject3 = s;
};

void update_reference_topic1(reference_frame &x, std::string s) {
    x.topic1 = s;
};

void update_reference_topic2(reference_frame &x, std::string s) {
    x.topic2 = s;
};

void update_reference_topic3(reference_frame &x, std::string s) {
    x.topic3 = s;
};

void update_reference_relation1(reference_frame &x, std::string s) {
    x.relation1 = s;
};

void update_reference_relation2(reference_frame &x, std::string s) {
    x.relation2 = s;
};

void update_reference_relation3(reference_frame &x, std::string s) {
    x.relation3 = s;
};

void update_reference_link1(reference_frame &x, std::string s) {
    x.link1 = s;
};

void update_reference_link2(reference_frame &x, std::string s) {
    x.link2 = s;
};

void update_reference_link3(reference_frame &x, std::string s) {
    x.link3 = s;
};

// return methods
std::string return_reference_subject1(reference_frame &x) {
    return x.subject1;
};

std::string return_reference_subject2(reference_frame &x) {
    return x.subject2;
};

std::string return_reference_subject3(reference_frame &x) {
    return x.subject3;
};

std::string return_reference_topic1(reference_frame &x) {
    return x.topic1;
};

std::string return_reference_topic2(reference_frame &x) {
    return x.topic2;
};

std::string return_reference_topic3(reference_frame &x) {
    return x.topic3;
};

std::string return_reference_relation1(reference_frame &x) {
    return x.relation1;
};

std::string return_reference_relation2(reference_frame &x) {
    return x.relation2;
};

std::string return_reference_relation3(reference_frame &x) {
    return x.relation3;
};

std::string return_reference_link1(reference_frame &x) {
    return x.link1;
};

std::string return_reference_link2(reference_frame &x) {
    return x.link2;
};

std::string return_reference_link3(reference_frame &x) {
    return x.link3;
};