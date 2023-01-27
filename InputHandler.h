//
// Created by Marcelo on 1/25/2023.
//
#include <vector>
#include <functional>
#include <mutex>

using namespace std;
#ifndef FINALPROJECT_INPUTHANDLER_H
#define FINALPROJECT_INPUTHANDLER_H


class InputHandler {
private:
    bool started = false;
    std::mutex safety;
    SDL_Thread* threadID;
    static int sdl_thread_func(void*);
    void sdl_thread_input_loop();
public:
    vector<void(*)()> callbacks;
    void add(void (*call)());
    void startSDLThread();
};


#endif //FINALPROJECT_INPUTHANDLER_H
