#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
 
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_image.h"
#include <SDL2/SDL_ttf.h>
 
#define NUM_WAVEFORMS 17

int nr_wav() {
    int num = NUM_WAVEFORMS;
return num;
}

void print_nr_wav() {
    std::cout << std::endl << "~:: number of wave forms: (" << nr_wav() << ")." << std::endl;
}

int play_audio_device(int s=1) {
    // if (argc != 2)
    // {
    //     fprintf(stderr, "You must enter 1 argument!");
    //     exit(1);
    // }
 
    const char* _waveFileNames[] =
    {
        "ai/system/audio/samples/chirp.wav",
        "ai/system/audio/samples/clfuh.wav",
        "ai/system/audio/samples/clong.wav",
        "ai/system/audio/samples/clug_clug.wav",
        "ai/system/audio/samples/fix.wav",
        "ai/system/audio/samples/flir.wav",
        "ai/system/audio/samples/gorge.wav",
        "ai/system/audio/samples/krggg.wav",
        "ai/system/audio/samples/krggg_krg_krg.wav",
        "ai/system/audio/samples/tab.wav",
        "ai/system/audio/samples/taptaptap.wav",
        "ai/system/audio/samples/teep.wav",
        "ai/system/audio/samples/teep2.wav",
        "ai/system/audio/samples/thungs.wav",
        "ai/system/audio/samples/vwoof.wav",
        "ai/system/audio/samples/vworge.wav",
        "ai/system/audio/samples/vworng.wav"  
    };

    //SDL_Surface *screen;            //Pointer to the main screen surface
    Mix_Chunk *sound = NULL;        //Pointer to our sound, in memory
    int channel;                //Channel on which our sound is played
 
 
    int audio_rate = 22050;            //Frequency of audio playback
    Uint16 audio_format = AUDIO_S16SYS;     //Format of the audio we're playing
    int audio_channels = 2;            //2 channels = stereo
    int audio_buffers = 4096;        //Size of the audio buffers in memory
 
 
    //Initialize BOTH SDL video and SDL audio
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
 
 
    //Initialize SDL_mixer with our chosen audio settings
    if(Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 512)) {
        printf("Unable to initialize audio: %s\n", Mix_GetError());
        exit(1);
    }
 
 
    //Load our WAV file from disk
    sound = Mix_LoadWAV(_waveFileNames[s]);
    if(sound == NULL) {
        printf("Unable to load WAV file: %s\n", Mix_GetError());
    }
 
 
    //Set the video mode to anything, just need a window
    // screen = SDL_SetVideoMode(0, 0, 0, SDL_ANYFORMAT);
    // if (screen == NULL) {
    //     printf("Unable to set video mode: %s\n", SDL_GetError());
    //     return 1;
    // }
 
 
    // const char sound[] = _waveFileNames[1];

    //Play our sound file, and capture the channel on which it is played
    channel = Mix_PlayChannel(-1, sound, 0);
    if(channel == -1) {
        printf("~::!:: (error) :: unable to play WAV file: %s\n", Mix_GetError());
    }
 
 
    //Wait until the sound has stopped playing
    while(Mix_Playing(channel) != 0);
 
 
    //Release the memory allocated to our sound
    Mix_FreeChunk(sound);
 
 
    //Need to make sure that SDL_mixer and SDL have a chance to clean up
    Mix_CloseAudio();
    SDL_Quit();
 
 
    //Return success!
    return 0;
}

int play_audio_f(std::string f="0") {
     #define NUM_WAVEFORM 1
    const char* _waveFileNames[] = { f.c_str() };
    
    //SDL_Surface *screen;            //Pointer to the main screen surface
    Mix_Chunk *sound = NULL;        //Pointer to our sound, in memory
    int channel;                //Channel on which our sound is played
 
 
    int audio_rate = 22050;            //Frequency of audio playback
    Uint16 audio_format = AUDIO_S16SYS;     //Format of the audio we're playing
    int audio_channels = 2;            //2 channels = stereo
    int audio_buffers = 4096;        //Size of the audio buffers in memory
 
 
    //Initialize BOTH SDL video and SDL audio
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
 
 
    //Initialize SDL_mixer with our chosen audio settings
    if(Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 512)) {
        printf("Unable to initialize audio: %s\n", Mix_GetError());
        exit(1);
    }
 
 
    //Load our WAV file from disk
    sound = Mix_LoadWAV(_waveFileNames[0]);
    if(sound == NULL) {
        printf("Unable to load WAV file: %s\n", Mix_GetError());
    }
 
 
    //Set the video mode to anything, just need a window
    // screen = SDL_SetVideoMode(0, 0, 0, SDL_ANYFORMAT);
    // if (screen == NULL) {
    //     printf("Unable to set video mode: %s\n", SDL_GetError());
    //     return 1;
    // }
 
 
    // const char sound[] = _waveFileNames[1];

    //Play our sound file, and capture the channel on which it is played
    channel = Mix_PlayChannel(-1, sound, 0);
    if(channel == -1) {
        printf("~::!:: (error) :: unable to play WAV file: %s\n", Mix_GetError());
    }
 
 
    //Wait until the sound has stopped playing
    while(Mix_Playing(channel) != 0);
 
 
    //Release the memory allocated to our sound
    Mix_FreeChunk(sound);
 
 
    //Need to make sure that SDL_mixer and SDL have a chance to clean up
    Mix_CloseAudio();
    SDL_Quit();
 
 
    //Return success!
    return 0;
}

// eof