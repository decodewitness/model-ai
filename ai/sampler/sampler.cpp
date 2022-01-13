// (in AI directory) AI/SAMPLER.CPP used by "AI.H" FOR MODEL AI

#include <iostream>

#include "sampler_track.cpp"

class Sampler {

private:
    int threads;

    bool promiscuous;
    bool recording;
    bool pause;
    bool repeat_cycle;

    int track;    // main track in sampler
    int initialize;

    SamplerTrack *samplerTrack;

public:
    Sampler(int t) {
        std::cout << "\t-:: starting sampler." << std::endl;
        this->threads = 8;
        std::cout << "\t\t-:: sampling is set to (" << this->threads << ") threads." << std::endl;

        this->track = 1;
        this->initialize = this->track;

        this->samplerTrack = new SamplerTrack(2,1,8);
    }

    // int maximumThreads=128;
    // bool threads_initialized[128];
    
    // int track=1;    // main track in sampler
    // int initialize=track;

    // SamplerTrack samplerTrack;

    void setTo(int n) {
        switch (n) {
            case 0:
                this->recording=false;
                this->pause=false;
                this->repeat_cycle=false;
                this->promiscuous=true;
                std::cout << "\t-:: sampler set to promiscuous." << std::endl;
                std::cout << "\t\t(- promisc. -)" << std::endl;

            break;
            case 1:
                this->pause=false;
                this->repeat_cycle=false;
                this->promiscuous=false;
                this->recording=true;
                std::cout << "\t-:: sampler set to recording." << std::endl;
                std::cout << "\t\t(- >iO -)" << std::endl;

            break;
            case 2:
                this->repeat_cycle=false;
                this->promiscuous=false;
                this->recording=false;
                this->pause=true;
                std::cout << "\t-:: sampler set to pause." << std::endl;
                std::cout << "\t\t(-  ||  -)" << std::endl;
            break;
            case 3:
                this->promiscuous=false;
                this->recording=false;
                this->pause=false;
                this->repeat_cycle=true;
                std::cout << "\t-:: sampler set to repeatcycle." << std::endl;
                std::cout << "\t\t(- *<--R -)" << std::endl;
            default:
                this->setTo(this->initialize);
            break;
        };
    }

    void init() {
        this->setTo(this->initialize);
    }

    void decouple() {
        this->setTo(2);
    }
};

// eof