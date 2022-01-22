#include "db.h"

DB::DB() {
    this->row=0;
    this->column=0;
    this->count=0;
    this->xy_prev_x=0;
    this->xy_prev_y=0;
    this->prev_x=0;
    this->prev_y=0;
};

// row & colums
void DB::setrow(int x) {
    this->row = x;
};

void DB::setcolumn(int x) {
    this->column = x;
};

int DB::getrow() {
    return this->row;
};

int DB::getcolumn() {
    return this->column;
};

// setters
void DB::setrc1_x(int x) {
    this->vector_rc_1[0] = x;
};

void DB::setrc1_y(int x) {
    this->vector_rc_1[1] = x;
};

void DB::setrc2_x(int x) {
    this->vector_rc_2[0] = x;
};

void DB::setrc2_y(int x) {
    this->vector_rc_2[1] = x;
};

// getters
int DB::getrc1_x() {
    return this->vector_rc_1[0];
};

int DB::getrc1_y() {
    return this->vector_rc_1[1];
};

int DB::getrc2_x() {
    return this->vector_rc_2[0];
};

int DB::getrc2_y() {
    return this->vector_rc_2[1];
};

// assign_label
void DB::set_al(std::string s) {
    this->assign_label = s;
};

std::string DB::get_al() {
    return this->assign_label;
};

void DB::set_xy(int x, int y){
    this->prev_x = this->xy_prev_x;
    this->prev_y = this->xy_prev_y;
    this->xy_x[this->xy_prev_x] = 0;
    this->xy_y[this->xy_prev_y] = 0;
    this->xy_x[x] = 1;
    this->xy_y[y] = 1;
    this->xy_prev_x = this->row;
    this->xy_prev_y = this->column;
    this->row = x;
    this->column = y;
};

void DB::prep_xy() {
    this->xy[0] = row;
    this->xy[1] = column;
};