// (in AI directory) AI/SAMPLER.CPP used by "AI.H" FOR MODEL AI

#include <iostream>

class Sampler {

private:
    int threads;

    bool promiscuous;
    bool recording;
    bool pause;
    bool repeat_cycle;

public:
    Sampler(int t) {
        std::cout << "\t-:: starting sampler." << std::endl;
        this->threads = 8;
        std::cout << "\t\t-:: set " << this->threads << " threads." << std::endl;
    }

    void setTo(int n) {
        switch (n) {
            case 0:
                this->recording=false;
                this->pause=false;
                this->repeat_cycle=false;
                this->promiscuous=true;
                std::cout << "\t-:: sampler set to promiscuous." << std::endl;
            break;
            case 1:
                this->pause=false;
                this->repeat_cycle=false;
                this->promiscuous=false;
                this->recording=true;
                std::cout << "\t-:: sampler set to recording." << std::endl;
            break;
            case 2:
                this->repeat_cycle=false;
                this->promiscuous=false;
                this->recording=false;
                this->pause=true;
                std::cout << "\t-:: sampler set to pause." << std::endl;
            break;
            case 3:
                this->promiscuous=false;
                this->recording=false;
                this->pause=false;
                this->repeat_cycle=true;
                std::cout << "\t-:: sampler set to repeatcycle." << std::endl;
        };
    }

    void init() {
        this->setTo(1);
    }

    void decouple() {
        this->setTo(2);
    }
};

// eof