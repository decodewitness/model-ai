// AI/SYSTEM/AUDIO/AUDIO.CPP - NOT USED YET BY MODEL - USED BY "AI/AI.H"

// g++ -o alsatut1 alsatut1.cpp -lasound
    // sudo apt-get install libsdl2-dev libsdl2-mixer-dev libsdl2-net-dev libsdl2-ttf-dev libsdl2-image-dev libsdl2-gfx-dev

// the simplest idea is to add pkg-config --cflags --libs sdl2 while compiling the code.
    // g++ file.cpp `pkg-config --cflags --libs sdl2`

#include <alsa/asoundlib.h>
#include <iostream>

//#include 
//#ifdef WIN32
//#include "SDL/include/SDL.h"
//#undef main
//#include "SDL/SDL_mixer.h"
//#include "SDL/SDL_image.h"
//#endif
//#ifndef WIN32

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_image.h"
#include <SDL2/SDL_ttf.h>

//#include 
//#include 
//#include 
//#else
//#include "Windows.h"
//#endif
//#include

using namespace std;

// Globals are generally a bad idea in code.  We're using one here to keep it simple.
snd_pcm_t * _soundDevice;

bool aInit(const char *name) {
  int i;
  int err;
  snd_pcm_hw_params_t *hw_params;

  if( name == NULL ) {
      // Try to open the default device
      err = snd_pcm_open( &_soundDevice, "plughw:0,0", SND_PCM_STREAM_PLAYBACK, 0 );
  }
  else {
      // Open the device we were told to open.
      err = snd_pcm_open (&_soundDevice, name, SND_PCM_STREAM_PLAYBACK, 0);
  }

  // Check for error on open.
  if( err < 0 ) {
      cout << "aInit: cannot open audio device " << name << " (" << snd_strerror (err) << ")" << endl;
      return false;
  }
  else {
      cout << "Audio device opened successfully." << endl;
  }

  // Allocate the hardware parameter structure.
  if ((err = snd_pcm_hw_params_malloc (&hw_params)) < 0) {
      cout << "aInit: cannot allocate hardware parameter structure (" << snd_strerror (err) << ")" << endl;
      return false;
  }

  if ((err = snd_pcm_hw_params_any (_soundDevice, hw_params)) < 0) {
      cout << "Init: cannot initialize hardware parameter structure (" << snd_strerror (err) << ")" << endl;
      return false;
  }

  // Enable resampling.
  unsigned int resample = 1;
  err = snd_pcm_hw_params_set_rate_resample(_soundDevice, hw_params, resample);
  if (err < 0) {
      cout << "aInit: Resampling setup failed for playback: " << snd_strerror(err) << endl;
      return err;
  }

  // Set access to RW interleaved.
  if ((err = snd_pcm_hw_params_set_access (_soundDevice, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0) {
      cout << "aInit: cannot set access type (" << snd_strerror (err) << ")" << endl;
      return false;
  }

  if ((err = snd_pcm_hw_params_set_format (_soundDevice, hw_params, SND_PCM_FORMAT_S16_LE)) < 0) {
      cout << "aInit: cannot set sample format (" << snd_strerror (err) << ")" << endl;
      return false;
  }

  // Set channels to stereo (2).
  if ((err = snd_pcm_hw_params_set_channels (_soundDevice, hw_params, 2)) < 0) {
      cout << "aInit: cannot set channel count (" << snd_strerror (err) << ")" << endl;
      return false;
  }

  // Set sample rate.
  unsigned int actualRate = 44100;
  if ((err = snd_pcm_hw_params_set_rate_near (_soundDevice, hw_params, &actualRate, 0)) < 0) {
      cout << "aInit: cannot set sample rate to 44100. (" << snd_strerror (err) << ")"  << endl;
      return false;
  }
  if( actualRate < 44100 ) {
      cout << "aInit: sample rate does not match requested rate. (" << "44100 requested, " << actualRate << " acquired)" << endl;
  }

  // Apply the hardware parameters that we've set.
  if ((err = snd_pcm_hw_params (_soundDevice, hw_params)) < 0) {
      cout << "aInit: cannot set parameters (" << snd_strerror (err) << ")" << endl;
      return false;
  }
  else {
     cout << "Audio device parameters have been set successfully." << endl;
  }

  // Get the buffer size.
  snd_pcm_uframes_t bufferSize;
  snd_pcm_hw_params_get_buffer_size( hw_params, &bufferSize );
  // If we were going to do more with our sound device we would want to store
  // the buffer size so we know how much data we will need to fill it with.
  cout << "aInit: Buffer size = " << bufferSize << " frames." << endl;

  // Display the bit size of samples.
  cout << "aInit: Significant bits for linear samples = " << snd_pcm_hw_params_get_sbits(hw_params) << endl;

  // Free the hardware parameters now that we're done with them.
  snd_pcm_hw_params_free (hw_params);

  // Prepare interface for use.
  if ((err = snd_pcm_prepare (_soundDevice)) < 0) {
      cout << "aInit: cannot prepare audio interface for use (" << snd_strerror (err) << ")" << endl;
      return false;
  }
  else {
      cout << "Audio device has been prepared for use." << endl;
  }

return true;
};

bool UnInit() {
  snd_pcm_close (_soundDevice);
  cout << "Audio device has been uninitialized." << endl;
  return true;
};

int prep_audio() {  // function to prep the audio (run it)...
        aInit(NULL);
        // UnInit();
        return 0;
};

int unprep_audio() {    // function to unprep audio.
    UnInit();
    return 0;
}

#define NUM_WAVEFORMS 2
const char* _waveFileNames[] =
{
"Kick-Drum-1.wav",
"Snare-Drum-1.wav",
};

Mix_Chunk* _sample[2];

// Initializes the application data
int Init(void) 
{
    memset(_sample, 0, sizeof(Mix_Chunk*) * 2);

    // Set up the audio stream
    int result = Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 512);
    if( result < 0 )
    {
        fprintf(stderr, "Unable to open audio: %s\n", SDL_GetError());
        exit(-1);
    }

    result = Mix_AllocateChannels(4);
    if( result < 0 )
    {
        fprintf(stderr, "Unable to allocate mixing channels: %s\n", SDL_GetError());
        exit(-1);
    }

    // Load waveforms
    for( int i = 0; i < NUM_WAVEFORMS; i++ )
    {
        _sample[i] = Mix_LoadWAV(_waveFileNames[i]);
        if( _sample[i] == NULL )
        {
            fprintf(stderr, "Unable to load wave file: %s\n", _waveFileNames[i]);
        }
    }

    return true;
}

int play_audio_device() {
    // Initialize the SDL library with the Video subsystem
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO );
    atexit(SDL_Quit);

    SDL_Window* window = SDL_CreateWindow("DrumPads",
										  SDL_WINDOWPOS_UNDEFINED,
										  SDL_WINDOWPOS_UNDEFINED,
										  256,
										  256,
 										  SDL_WINDOW_RESIZABLE);

    // Application specific Initialize of data structures
    if (Init() == false)
        return -1;

    // Event descriptor
    SDL_Event Event;

    bool done = false;
    while (!done)
    {
        bool gotEvent = SDL_PollEvent(&Event);

        while (!done && gotEvent)
        {
            switch (Event.type)
            {
                case SDL_KEYDOWN:
                    switch (Event.key.keysym.sym)
                    {
                        case 'q':
                            Mix_PlayChannel(-1, _sample[0], 0);
                            break;
                        case 'w':
                            Mix_PlayChannel(-1, _sample[1], 0);
                            break;
                        default:
                            break;
                    }
                    break;

                case SDL_QUIT:
                    done = true;
                    break;

                default:
                    break;
            }
            if( !done ) gotEvent = SDL_PollEvent(&Event);
        }
#ifndef WIN32
		usleep(1000);
#else
		Sleep(1);
#endif
    }

    for( int i = 0; i < NUM_WAVEFORMS; i++ )
    {
        Mix_FreeChunk(_sample[i]);
    }

    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}