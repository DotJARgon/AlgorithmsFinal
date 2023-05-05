//
// Created by Marcelo on 4/30/2023.
//

#include "SoundHandler.h"
#include "unistd.h"

SoundHandler::SoundHandler(SDL_Plotter* plotter) {
    //populate the mapping
    this->plotter = plotter;
    this->sounds.emplace(CLICK1, "Click-1.wav");
    this->sounds.emplace(CLICK2, "Click-2.wav");

    this->sounds.emplace(DROP1, "Drop-1.wav");
    this->sounds.emplace(DROP2, "Drop-2.wav");
    this->sounds.emplace(DROP3, "Drop-3.wav");

    this->sounds.emplace(FAILED1, "Failed-1.wav");
    this->sounds.emplace(FAILED2, "Failed-2.wav");
    this->sounds.emplace(FAILED3, "Failed-3.wav");
    this->sounds.emplace(FAILED4, "Failed-4.wav");

    this->sounds.emplace(GRAB1, "Grab-1.wav");
    this->sounds.emplace(GRAB2, "Grab-2.wav");
    this->sounds.emplace(GRAB3, "Grab-3.wav");

    this->sounds.emplace(GRAZE_ON_THE_ROOF, "GrazeOnTheRoof.wav");

    this->sounds.emplace(RIGHT1, "Right-1.wav");
    this->sounds.emplace(RIGHT2, "Right-2.wav");
    this->sounds.emplace(RIGHT3, "Right-3.wav");
    this->sounds.emplace(RIGHT4, "Right-4.wav");

    this->sounds.emplace(SPECIAL_DROP, "SpecialDrop.wav");
    this->sounds.emplace(SPECIAL_GRAB, "SpecialGrab.wav");

    this->sounds.emplace(YEA_BABY, "Yea-Baby.wav");
    this->special = false;


    //initialize all of the sound mappings!
    for(const auto& sound_pair : this->sounds) {
        this->plotter->initSound(sound_pair.second);
    }



}
void SoundHandler::playSound(Sounds sound) {
    //play the sound corresponding to the mapping
    this->plotter->playSound(this->sounds.at(sound));
}

void SoundHandler::playClick() {
    //randomized click sounds!
    srand(time(nullptr));
    int i = (rand() % 2) + 1;

    switch (i) {
        case 1:
            this->plotter->playSound(this->sounds.at(CLICK1));
            break;
        case 2:
            this->plotter->playSound(this->sounds.at(CLICK2));
            break;
    }

}
void SoundHandler::playDrop() {
    //randomized drop sounds!
    srand(time(nullptr));
    int i = (rand() % 3) + 1;

    //uses the boolean variable to make sure if a special grab is used
    //then special drop is always going to correspond with it.
    if(this->special){
        this->plotter->playSound(this->sounds.at(SPECIAL_DROP));
        this->special = false;
    }
    else {
        switch (i) {
            case 1:
                this->plotter->playSound(this->sounds.at(DROP1));
                break;
            case 2:
                this->plotter->playSound(this->sounds.at(DROP2));
                break;
            case 3:
                this->plotter->playSound(this->sounds.at(DROP3));
                break;
        }
    }

}
void SoundHandler::playFail() {
    //randomized failure :(
    srand(time(nullptr));
    int i = (rand() % 4) + 1;

    switch (i) {
        case 1:
            this->plotter->playSound(this->sounds.at(FAILED1));
            break;
        case 2:
            this->plotter->playSound(this->sounds.at(FAILED2));
            break;
        case 3:
            this->plotter->playSound(this->sounds.at(FAILED3));
            break;
        case 4:
            this->plotter->playSound(this->sounds.at(FAILED4));
            break;
    }


}
void SoundHandler::playGrab() {
    //randomized grabbing sounds!
    srand(time(nullptr));
    int i = (rand() % 4) + 1;

    switch (i) {
        case 1:
            this->plotter->playSound(this->sounds.at(GRAB1));
            break;
        case 2:
            this->plotter->playSound(this->sounds.at(GRAB2));
            break;
        case 3:
            this->plotter->playSound(this->sounds.at(GRAB3));
            break;
        case 4:
            this->plotter->playSound(this->sounds.at(SPECIAL_GRAB));
            this->special = true;
            break;
    }
}
void SoundHandler::playRight() {
    //ranzomized correct sounds!
    srand(time(nullptr));
    int i = (rand() % 4) + 1;

    switch (i) {
        case 1:
            this->plotter->playSound(this->sounds.at(RIGHT1));
            break;
        case 2:
            this->plotter->playSound(this->sounds.at(RIGHT2));
            break;
        case 3:
            this->plotter->playSound(this->sounds.at(RIGHT3));
            break;
        case 4:
            this->plotter->playSound(this->sounds.at(RIGHT4));
            break;
    }
}
void SoundHandler::playVictory() {
    //this cuts off the main music and plays the win condition sound
    this->plotter->quitSound(this->sounds.at(GRAZE_ON_THE_ROOF));
    this->plotter->playSound(this->sounds.at(YEA_BABY));
}


void SoundHandler::playMusic() {
    //plays the main sound track!
    this->plotter->playSound(this->sounds.at(GRAZE_ON_THE_ROOF));
}
