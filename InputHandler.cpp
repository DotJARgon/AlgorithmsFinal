/*
* Author: Team Team (Tristan Brown, Marcelo Carpenter, Thomas Cho,
*          Joshua Linnett, Aaron Mendoza, Harrison Williams)
* Assignment Title: Jigsaw Puzzle Group Project
* Assignment Description: This is inputHandler implementation file
* Due Date: 5/4/2023
* Date Created: 4/27/2023
* Date Last Modified: 5/4/2023
 */
#include <SDL_thread.h>
#include "InputHandler.h"

void InputHandler::add(void (*call)()) {
    this->safety.lock();
    this->callbacks.push_back(call);
    this->safety.unlock();
}

int InputHandler::sdl_thread_func(void * inputObj) {
    reinterpret_cast<InputHandler*>(inputObj)->sdl_thread_input_loop();
    return 0;
}

void InputHandler::sdl_thread_input_loop() {
    this->safety.lock();
    for(const auto call : callbacks) {
        //call each callback
        (*call)();
    }
    this->safety.unlock();
}

void InputHandler::startSDLThread() {
    if(!this->started) {
        this->threadID = SDL_CreateThread(InputHandler::sdl_thread_func, "InputThread", this);
    }
}