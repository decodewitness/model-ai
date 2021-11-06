// (in AI directory) AI/DRUMS.H - USED BY "DRUMS.CPP" FOR MODEL AI

const int drum_cycle_one=4;
const int drum_cycle_two=2;

class DrumMachine {

private:
    int cycle_one;
    int cycle_two;

public:
    DrumMachine();
    DrumMachine(int x, int y);

    void cycle();
    void reverse();
};

// eof