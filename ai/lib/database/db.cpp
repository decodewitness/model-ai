// AI/LIB/DATABASE/DB.CPP   -   !!! NOT USED YET !!!

#include "db.h"

DB::DB() {  // database constructor
    this->row=0;
    this->column=0;
    this->count=0;
    this->xy_prev_x=0;
    this->xy_prev_y=0;
    this->prev_x=0;
    this->prev_y=0;
};

// row & colums
void DB::setrow(int x) {    // sets a row to a size
    this->row = x;
};

void DB::setcolumn(int x) {    // sets a column to a size
    this->column = x;
};

int DB::getrow() {  // gets row size
    return this->row;
};

int DB::getcolumn() {  // gets column size
    return this->column;
};

// setters
void DB::setrc1_x(int x) {  // sets this->vector_rc_1[0]
    this->vector_rc_1[0] = x;
};

void DB::setrc1_y(int x) {  // sets this->vector_rc_1[1]
    this->vector_rc_1[1] = x;
};

void DB::setrc2_x(int x) {  // sets this->vector_rc_2[0]
    this->vector_rc_2[0] = x;
};

void DB::setrc2_y(int x) {  // sets this->vector_rc_2[1]
    this->vector_rc_2[1] = x;
};

// getters
int DB::getrc1_x() {    // gets this->vector_rc_1[0]
    return this->vector_rc_1[0];
};

int DB::getrc1_y() {    // gets this->vector_rc_1[1]
    return this->vector_rc_1[1];
};

int DB::getrc2_x() {    // gets this->vector_rc_2[0]
    return this->vector_rc_2[0];
};

int DB::getrc2_y() {    // gets this->vector_rc_2[1]
    return this->vector_rc_2[1];
};

// assign_label
void DB::set_al(std::string s) {    // assigns label s to this->assign_label
    this->assign_label = s;
};

std::string DB::get_al() {  // gets the assigned label of this->assign_label
    return this->assign_label;
};

void DB::set_xy(int x, int y){  // sets all "xy" variables
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

void DB::prep_xy() {    // sets this->xy[2] to [0]row + [1]column
    this->xy[0] = row;
    this->xy[1] = column;
};

// eof