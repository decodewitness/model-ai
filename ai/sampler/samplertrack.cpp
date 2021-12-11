#include <iostream>
#include <string>

#include "../system/definitions/encoder.cpp"

class SamplerTrack {
private:
    //int tracksPerTrack[8];
    int tracksInTrack[2048];                // tracks in one track
    bool initialized[2048];                 // initialized tracks
    double trackLength[2048];               // length of tracks
    int track;                              // current track
    std::string tracks[2028];               // number of tracks
    std::string matrix[9];                  // data matrix  // max string length 8
    int nrOfCombinedMatrix[2048];           // combined sets of matrixes per track that need to be read from file storage
    double indexesOfCombinedMatrix_i[4096][1];      // [] = index in track of combined matrix  [] = nr of combined per section is labeled as index
    int matrix_index[2048];                 // number of track which the matrix belongs to
    int totalNumberOfTracks;                // total number of tracks
    int startAt;                            // start at interval
    int startAtTrack;                       // start with (#) track
    double atIndex[2048];                   // difference between start and now index
    int samplerTracks;                      // number of tracks-in-track per track
    int total;                              // used to calculate initialized threads/tracks (not the tracks-in-track)
    // sampler track here / record measure(s)

public:

    SamplerTrack(int trInTr=2, double tl=1.00, int t=1) { // t should at least be 1; trInTr should be equal or higher than "t=1"
        //this->tracks[0] = tr;
        this->totalNumberOfTracks=trInTr;
        this->samplerTracks = trInTr;
        this->track = 0;
        std::cout << "\t~:: main sampler track set to track (" << this->track << ")." << std::endl;
        this->startAtTrack = t;
        this->startAt = 0;

        // open new track
        std::cout << "~:: sampler :: ~ :: starting new thread (" << t << ") tracks; with (" << trInTr << ") tracks-in-track." << std::endl << std::endl;    
        this->newThread(t, trInTr); // starts (default=2) new tracks in the main track

        for (int i=0, j=0; i<t; i++) {
            // start track here with length of variable "tl"
            std::cout << "~:: setting tracks-in-track (" << (1 + j++) << ") to (" << trInTr << ") tracks." << std::endl;
            this->tracks[i] = trInTr;
            this->initialized[i] = true;

            // set track index;
            std::cout << "~:: setting track [" << (i + 1)<< "] index to (00h/00m/00s)" << std::endl;
            this->atIndex[i] = 0.00;
        }
    }

    void len(int n=0, int tracknr=1) {
        this->trackLength[tracknr] = n;
    }

    void newThread(int trac, int y=2) {
        
        for (int i=0; i<trac; i++) {
            std::cout << "~:: sampler :: ~ :: initializing track [" << i << "]." << std::endl;
            this->tracksInTrack[this->track++] = y;
            
            this->initialized[i] = true;
            std::cout << "\t~:: initialized with (" << y << ") sampling tracks." << std::endl << std::endl;

            this->total += 1;
        }
        
        std::cout << "~:: sampler :: ~ :: generated (" << (y * this->track) << ")  new tracks-in-track." << std::endl;
        std::cout << "\t~:: total initialized tracks [" << (this->total) << "]." << std::endl << std::endl;
    }

    int totalTracks() {
        int x=0;
    
        for (int i=0; this->initialized[i] == true; i++) {
            x++;
        }
        return x;
    }

    // convert hex from matrix here with help of the hexencode hexdecode function or build a converter
};