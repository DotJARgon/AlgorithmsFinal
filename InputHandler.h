/*
* Author: Team Team (Tristan Brown, Marcelo Carpenter, Thomas Cho,
*          Joshua Linnett, Aaron Mendoza, Harrison Williams)
* Assignment Title: Jigsaw Puzzle Group Project
* Assignment Description: This is input handler for input events using SDL library
* Due Date: 5/4/2023
* Date Created: 4/27/2023
* Date Last Modified: 5/4/2023
 */
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
    /*
     * description: returns array of callbacks
     * return: vector<void>
     * precondition: vector is initialized to valid type
     * postcondition: vector of callbacks is returned
     */
    vector<void(*)()> callbacks;
    /*
     * description: Adds call to the back of callbacks vector
     * return: void
     * precondition: vector<callbacks> is initialized
     * postcondition: vector<callbacks> is updated
     */
    void add(void (*call)());
    /*
     * description: starts SDLThread function
     * return: void
     * precondition: SDL is properly set up
     * postcondition: SDLThread runs
     */
    void startSDLThread();
};


#endif //FINALPROJECT_INPUTHANDLER_H
