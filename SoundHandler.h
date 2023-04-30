//
// Created by Marcelo on 4/30/2023.
//

#ifndef FINALPROJECT_SOUNDHANDLER_H
#define FINALPROJECT_SOUNDHANDLER_H

#include <map>
#include <string>
#include "Sounds.h"
#include "SDL_Plotter.h"

using namespace std;

class SoundHandler {
private:
    map<Sounds, string> sounds;
    SDL_Plotter* plotter;
public:
    SoundHandler(SDL_Plotter* plotter);
    void playSound(Sounds sound);
};


#endif //FINALPROJECT_SOUNDHANDLER_H
