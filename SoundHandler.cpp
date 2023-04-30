//
// Created by Marcelo on 4/30/2023.
//

#include "SoundHandler.h"

SoundHandler::SoundHandler(SDL_Plotter* plotter) {
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

    for(const auto& sound_pair : this->sounds) {
        this->plotter->initSound(sound_pair.second);
    }

}
void SoundHandler::playSound(Sounds sound) {
    this->plotter->playSound(this->sounds.at(sound));
}