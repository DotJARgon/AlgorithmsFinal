/*
* Author: Tristan Brown, Marcelo Carpenter,  Cho Thomas, Linnett Joshua, Mendoza Aaron, Williams Harrison
* Assignment Title: Algorithms Final Group Project
* Assignment Description: This file is the interface for the local files interacting with the SLD sound functions
* Due Date: 5/4/2023
* Date Created: 4/27/2023
* Date Last Modified: 4/27/2023
*/


#include "Music.h"


void clickSound(SDL_Plotter sdlPlotter){

    int i;
    i = (rand() % 3) + 1;
    string s;
    switch (i){
        case 1:
            //TODO do I include the .m4a?
            s = "Click-1";
            break;
        case 2:
            s = "Click-2";
            break;
        case 3:
            s = "Click-3";
            break;
        default:
            cout << "This went wrong dog";
            s = nullptr;
    }
    sdlPlotter.initSound(s);
    sdlPlotter.playSound(s);
    //TODO I initialized the noises like this for most functions but
    //i need to know when I should stop the sounds??

}
void dropSound(SDL_Plotter sdlPlotter){
    int i;
    i = (rand() % 4) + 1;
    string s;
    switch (i){
        case 1:
            //TODO do I include the .m4a?
            s = "Drop-1";
            break;
        case 2:
            s = "Drop-2";
            break;
        case 3:
            s = "Drop-3";
            break;
        case 4:
            s = "SpecialDrop";
            break;
        default:
            cout << "This went wrong dog";
            s = nullptr;
    }
    sdlPlotter.initSound(s);
    sdlPlotter.playSound(s);
}
void failureSound(SDL_Plotter sdlPlotter){
    int i;
    i = (rand() % 4) + 1;
    string s;
    switch (i){
        case 1:
            //TODO do I include the .m4a?
            s = "Failure-1";
            break;
        case 2:
            s = "Failure-2";
            break;
        case 3:
            s = "Failure-3";
            break;
        case 4:
            s = "Failure-4";
            break;
        default:
            cout << "This went wrong dog";
            s = nullptr;
    }
    sdlPlotter.initSound(s);
    sdlPlotter.playSound(s);
}
void correctSound(SDL_Plotter sdlPlotter){
    int i;
    i = (rand() % 4) + 1;
    string s;
    switch (i){
        case 1:
            //TODO do I include the .m4a?
            s = "Right-1";
            break;
        case 2:
            s = "Right-2";
            break;
        case 3:
            s = "Right-3";
            break;
        case 4:
            s = "Right-4";
            break;
        default:
            cout << "This went wrong dog";
            s = nullptr;
    }
    sdlPlotter.initSound(s);
    sdlPlotter.playSound(s);
}
void grabSound(SDL_Plotter sdlPlotter){
    int i;
    i = (rand() % 4) + 1;
    string s;
    switch (i){
        case 1:
            //TODO do I include the .m4a?
            s = "Grab-1";
            break;
        case 2:
            s = "Grab-2";
            break;
        case 3:
            s = "Grab-3";
            break;
        case 4:
            s = "SpecialGrab";
            break;
        default:
            cout << "This went wrong dog";
            s = nullptr;
    }
    sdlPlotter.initSound(s);
    sdlPlotter.playSound(s);
}
void musicSound(SDL_Plotter sdlPlotter){
    //TODO leave the switch case for when i add more songs
    int i;
    i = (rand() % 1) + 1;
    string s;
    switch (i){
        case 1:
            s = "GrazeOnTheRoof";
            break;
        default:
            cout << "This went wrong dog";
            s = nullptr;
    }
    sdlPlotter.initSound(s);
    sdlPlotter.playSound(s);
}
void victorySound(SDL_Plotter sdlPlotter){
    string s = "Yea-Baby";
    sdlPlotter.initSound(s);
    sdlPlotter.playSound(s);
}
