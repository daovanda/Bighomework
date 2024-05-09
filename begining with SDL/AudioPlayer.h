#ifndef _AUDIOPLAYER_H
#define _AUDIOPLAYER_H

#include <SDL_mixer.h>
#include <unordered_map>
#include <string>

class AudioPlayer {

public:

    void PlayMusic(const std::string& dir)
    {
        Mix_Music* temp = Mix_LoadMUS(dir.c_str());
        if (temp == nullptr)
        {
            printf("Load music error: %s.\n", Mix_GetError());
            return;
        }
        Mix_PlayMusic(temp, 0);
    }

    void PlaySFX(const std::string& dir)
    {
        return;
    }
};

#endif // _AUDIOPLAYER_H


