//
// Created by Marcelo on 1/25/2023.
//

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