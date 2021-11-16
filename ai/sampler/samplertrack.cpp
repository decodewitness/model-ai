#include <string>

#include "../system/definitions/encoder.cpp"

class SamplerTrack {
private:
    //int tracksPerTrack[8];
    int tracksInTrack[2048];                // tracks in one track
    bool initialized[2048];                 // initialized tracks
    double trackLength[2048];               // length of tracks
    int track;                              // current track
    std::string matrix[9];                  // data matrix  // max string length 8
    int nrOfCombinedMatrix[2048];                   // combined sets of matrixes per track that need to be read from file storage
    double indexesOfCombinedMatrix_i[4096][1];      // [] = index in track of combined matrix  [] = nr of combined per section is labeled as index
    int matrix_index[2048];                 // number of track which the matrix belongs to
    std::string tracks[2028];               // number of tracks
    int totalNumberOfTracks;                // total number of tracks
    int startAt;                            // start at interval
    int startAtTrack;                       // start with (#) track
    // sampler track here / record measure(s)

public:

    SamplerTrack(int trInTr=2, int t=1, double tl=1.00) { // t should at least be 1; trInTr should be equal or higher than "t=1"
        //this->tracks[0] = tr;
        this->totalNumberOfTracks=trInTr;
        this->track = t;
        this->startAtTrack = t;
        this->startAt = 0;

        for (int i=0; i<trInTr; i++) {
            // start track here with length of variable "tl"
            this->tracks[i] = "0";
            this->initialized[i] = true;
        }

        // open new track
        this->newThread();
    }

    void len(int n=0, int tracknr=1) {
        this->trackLength[tracknr] = n;
    }

    void newThread(int t=2) {
        this->tracksInTrack[this->track++] = t;
    }

    int totalTracks() {
        int x=0;
    
        for (int i=0; this->initialized[i] = true; i++) {
            x++;
        }
        return x;
    }

    // convert hex from matrix here with help of the hexencode hexdecode function or build a converter
};