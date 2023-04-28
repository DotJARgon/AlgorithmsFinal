/*
* Author: Tristan Brown, Marcelo Carpenter,  Cho Thomas, Linnett Joshua, Mendoza Aaron, Williams Harrison
* Assignment Title: Algorithms Final Group Project
* Assignment Description: This file is the interface for the local files interacting with the SLD sound functions
* Due Date: 5/4/2023
* Date Created: 4/27/2023
* Date Last Modified: 4/27/2023
*/

#ifndef FINALPROJECT_MUSIC_H
#define FINALPROJECT_MUSIC_H

#include "iostream"
#include "SDL_Plotter.h"
using namespace std;

struct Music{
    void clickSound(SDL_Plotter sdlPlotter);
    void dropSound(SDL_Plotter sdlPlotter);
    void failureSound(SDL_Plotter sdlPlotter);
    void correctSound(SDL_Plotter sdlPlotter);
    void grabSound(SDL_Plotter sdlPlotter);
    void musicSound(SDL_Plotter sdlPlotter);
    void victorySound(SDL_Plotter sdlPlotter);
};


/*
* description: calculate total price of item with tax
* return: double
* precondition: price and tax are valid
* postcondition: returns sum of price and tax
*/
#endif //FINALPROJECT_MUSIC_H
