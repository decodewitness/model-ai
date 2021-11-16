class SamplerTrack {

private:
    //int tracksPerTrack[8];
    int tracksInTrack[2048];
    bool initialized[256];
    int trackLength[256];
    int track;
    int tracks;
    int totalNumberOfTracks;
    int startAt;
    int startTrack;
    // sampler track here / record measure(s)

public:
    SamplerTrack(int tr=2, int t=1) {
        //this->tracks[0] = tr;
        this->tracks=tr;
        this->track = t;

        this->startTrack = 1;
        this->startAt = 0;
        
        // open new track
        this->newThread();
    }

    void len(int n=0, int tracknr=1) {
        this->trackLength[tracknr] = n;
    }

    void newThread(int t=2) {
        this->tracksInTrack[this->track++] = t;
    }
};