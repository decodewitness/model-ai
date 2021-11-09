// "/AI/AL/AL.H" - ARTIFICIAL LIFE HEADER - USED BY "AI/AL/AL.CPP"

#include <iostream>
#include "mem/disk.h"
#include "splash-al.h"

// limits for the Artificial Life Routine in "/ai/al/al.cpp"
int alr_limit = 2500;
int alr_countdown = alr_limit - (alr_limit / 10);

// in this demo setup this is being multiplied by (big=10)
const int quantum = 200;	// nr of pins you can place

// sizes to multiply quantum with below:
const int small = 2;
const int big = 10;
const int bigger = 20;
const int biggest = 500;

// class artificial life
class AL {

private:
	int nr;
	double mem;
	char ch; // for use with getchar()

protected:
	char c;	// used to stop the artificial life routine
	char x; // used as scapegoat

	// ROUTINES FOR GRID ARTIFICIAL LIFE HABITS	-- MULTIPLY WITH SIZES DECLARED ABOVE (small, big, bigger, biggest)
	bool grid[quantum*big];

	int xt[quantum*big]; // occurrence of time on nr. of pin
	int t[quantum*big];	// duration of time

	int cattle;
	int sheep;

	int size_of_mass_equation[quantum*big];	// catch size of the equation
	int size_of_measures_equation[quantum*big];	// catch size of measures in the equation
	int total_mass_and_size_equation[quantum*big];	// catch total size in approximation
	int distribution[quantum*big];	// various distribution along the spectrum

	int valueX[2]; // value[0] is the value; value[1] is at what pin it hits.
	int valueY[2]; // same
	int valueZ[2]; // same

	int pin[quantum*big];	// set number of pin at which to become active
	int numbers[quantum*big]; // set numbers in the equation to become a mutation in the sequence

	bool minus[quantum*big];	// whether to perform the minus operation for number in equation
	bool plus[quantum*big];	// wheter to perform plus for number in the equation
	bool divide[quantum*big];	// whether to divide the number in the equation
	bool multiplication[quantum*big];	// if the multiplication is active on the number in the equation
	int percent_bonus[quantum*big];	// how much percent the multiplier must decrease or increase

	std::string control_group_names[quantum*big];	// names of control groups
	int control_groups[quantum*big];	// numbers of peers in control group
	
	std::string peers1[quantum*big]; // control group peer1
	std::string peers2[quantum*big]; // control group peer2
	std::string peers3[quantum*big]; // control group peer3
	std::string peers4[quantum*big]; // control group peer4
	std::string peers5[quantum*big]; // control group peer5
	std::string peers6[quantum*big]; // control group peer6
	std::string peers7[quantum*big]; // control group peer7
	std::string peers8[quantum*big]; // control group peer8
	std::string peers9[quantum*big]; // control group peer9
	std::string peers10[quantum*big]; // control group peer10
	
	std::string research_names[quantum*big];	// carries name for your research

	std::string research1_group;
	std::string research2_group;
	std::string research3_group;
	std::string research4_group;
	std::string research5_group;

	int n[quantum*big];	// (bingo) how many times it hit on n[#]

	std::string label1[quantum*big];	// labels
	std::string label2[quantum*big];	// labels
	std::string label3[quantum*big];	// labels
	std::string label4[quantum*big];	// labels
	std::string label5[quantum*big];	// labels
	std::string label6[quantum*big];	// labels
	std::string label7[quantum*big];	// labels
	std::string label8[quantum*big];	// labels 
	std::string label9[quantum*big];	// labels 
	std::string label10[quantum*big];	// labels 
	
	std::string range_label_1;	// label for range
	int r1;	// pin value for range 1
	int range1;	// range value

	std::string range_label_2;	// label for range
	int r2; // pin value for range 2
	int range2;	// range value

	std::string range_label_3;	// label for range
	int r3; // pin value for range 3
	int range3; // range value

	std::string range_label_custom;	// label for range
	int range_custom;	// value custom range
	int rr;	// pin value for custom range;

public:
	AL();
	~AL();

	// shepard notifies you when a pin is due
	void shepard(int n, int i) {
		if (n==i) {
			this->sheep++;
			std::cout << std::endl << "-:: SHEPARD @(\"" << n << "\")(sheep=\"" << sheep << "\")" << std::endl << std::endl;
			//this->ch = getchar();
		}
	}

	int how_many_sheep() { return this->sheep; }

	void kbuild(double i);	// reserve memory

	int live();	// artificial life routine
	void modifies_behaviour();
	void life();	// artificial habits

	void assess(int n) {
		// bool grid[quantum*big];
		// int xt[quantum*big]; // occurrence of time on nr. of pin
		// int t[quantum*big];	// duration of time

		// int cattle;
		// int sheep;

		// int size_of_mass_equation[quantum*big];	// catch size of the equation
		// int size_of_measures_equation[quantum*big];	// catch size of measures in the equation
		// int total_mass_and_size_equation[quantum*big];	// catch total size in approximation
		// int distribution[quantum*big];	// various distribution along the spectrum

		// int valueX[2]; // value[0] is the value; value[1] is at what pin it hits.
		// int valueY[2]; // same
		// int valueZ[2]; // same

		// int pin[quantum*big];	// set number of pin at which to become active
		// int numbers[quantum*big]; // set numbers in the equation to become a mutation in the sequence

		// bool minus[quantum*big];	// whether to perform the minus operation for number in equation
		// bool plus[quantum*big];	// wheter to perform plus for number in the equation
		// bool divide[quantum*big];	// whether to divide the number in the equation
		// bool multiplication[quantum*big];	// if the multiplication is active on the number in the equation
		// int percent_bonus[quantum*big];	// how much percent the multiplier must decrease or increase

		// std::string control_group_names[quantum*big];	// names of control groups
		// int control_groups[quantum*big];	// numbers of peers in control group
		
		// std::string peers1[quantum*big]; // control group peer1
		// std::string peers2[quantum*big]; // control group peer2
		// std::string peers3[quantum*big]; // control group peer3
		// std::string peers4[quantum*big]; // control group peer4
		// std::string peers5[quantum*big]; // control group peer5
		// std::string peers6[quantum*big]; // control group peer6
		// std::string peers7[quantum*big]; // control group peer7
		// std::string peers8[quantum*big]; // control group peer8
		// std::string peers9[quantum*big]; // control group peer9
		// std::string peers10[quantum*big]; // control group peer10
		
		// std::string research_names[quantum*big];	// carries name for your research

		// std::string research1_group;
		// std::string research2_group;
		// std::string research3_group;
		// std::string research4_group;
		// std::string research5_group;

		// int n[quantum*big];	// (bingo) how many times it hit on n[#]

		// std::string label1[quantum*big];	// labels
		// std::string label2[quantum*big];	// labels
		// std::string label3[quantum*big];	// labels
		// std::string label4[quantum*big];	// labels
		// std::string label5[quantum*big];	// labels
		// std::string label6[quantum*big];	// labels
		// std::string label7[quantum*big];	// labels
		// std::string label8[quantum*big];	// labels 
		// std::string label9[quantum*big];	// labels 
		// std::string label10[quantum*big];	// labels 
		
		// std::string range_label_1;	// label for range
		// int r1;	// pin value for range 1
		// int range1;	// range value

		// std::string range_label_2;	// label for range
		// int r2; // pin value for range 2
		// int range2;	// range value

		// std::string range_label_3;	// label for range
		// int r3; // pin value for range 3
		// int range3; // range value

		// std::string range_label_custom;	// label for range
		// int range_custom;	// value custom range
		// int rr;	// pin value for custom range;
}

	void check(int n) {
		if (grid[n] == true) { assess(n);}
	}
};


class HAL : public AL {

private:
	int running;
	int runlevel;

public:

	HAL();
	~HAL();
};
