// "/AI/DRUM_MACHINE/DRUMS.H" - USED BY "/AI/DRUM_MACHINE/DRUMS.CPP" FOR (MODEL-AI).

// various drum cycles              // ========= intervals in measure =========:
const double drum_cycle_one=1;         // in every 3 seconds or in every measure 1/x
const double drum_cycle_two=3;         // in every 3 seconds or in every measure 1/x
const double drum_cycle_three=4;       // in every 3 seconds or in every measure 1/x
const double drum_cycle_four=6;        // in every 3 seconds or in every measure 1/x

// doubles rhythm
const double drum_quarter = 0.75;   // every quarter 3 second measure or in every measure drums

// rpm measure
const int beat_rpm=128;             // speed of the beat

// intervals and pauses
const double Tstart=2.0;            // pause before start # time in seconds
const double startA=2.0;            // start A solo after # time in seconds
const double startB=2.0;            // start B solo after # time in seconds
const double startAB=1.0;           // start A+B solo after # time in seconds
const double duration=10.0;         // duration of entire sampling in the drums
const double linear_vex=120.0;      // vertical glide or slope / increase|decrease in tempo
const double chronotrigger=0.75;    // skipping measure in the beat / like a pause effect lasting # skips of the beat

// booleans
bool BSideFirst=0;                  // whether drumloops should start in reverse order


// class DrumMachine
class DrumMachine {

    private:

        double cycle_one[2];    // cycle (A)
        double cycle_two[2];    // cycle (B)

        double s1;  // start (A)
        double s2;  // start (B)

        double pose;  // pause before second drum solo kicks in from -00:00:00 seconds

        double beatEveryMeasure; // set the beat skipper
        double measureEveryBeat; // set the measure skipper

        double intervalA;    // skips in the beat on track (A)
        double intervalB;    // skips in the beat on track (B)

    public:

        DrumMachine();  // constructor
        DrumMachine(int z, int x, int y); // set with constructor // cycle (1-2), measure #1, measure #2    // only 2 cycles at the moment

        // functions
        void start();   // start the timer
        void reset();   // reset all pauses starting tracks to 0 seconds
        void status();  // advocate drum cycles in displays
        void reverse(); // reverse measures in drum cycle
        void reverseA();    // reverse only A
        void reverseB();    // reverse only B
        void setStartA();   // set the start of A
        void setStartB();   // set the start of B
        void setIntervalA();// interval (A) delay
        void setIntervalB();// interval (B) delay
        void setStartAB();  // set the start of A+B (predefined values)
        void setStartStatus(); // sets default starting pauses in s1 and s2 of 00:00:02 sec + 00:00:01 sec.
        void setBeatEveryMeasure(); // set the beat skipper
        void setMeasureEveryBeat(); // set the measure skipper
};

// EOF