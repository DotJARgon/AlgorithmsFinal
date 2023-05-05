/*
* Author: Team Team (Tristan Brown, Marcelo Carpenter, Thomas Cho,
*          Joshua Linnett, Aaron Mendoza, Harrison Williams)
* Assignment Title: Jigsaw Puzzle Group Project
* Assignment Description: This is main.cpp file for Jigsaw puzzle group project
* Due Date: 5/4/2023
* Date Created: 4/27/2023
* Date Last Modified: 5/4/2023
 */
#include <iostream>
#include <chrono>
#include <unistd.h> // used for sleep function
#include "SDL_Plotter.h"
#include "TextureLoader.h"
#include "PieceTexture.h"
#include "PlotterTexture.h"
#include "Board.h"
#include "Text.h"

using namespace std;

int main(int argc, char ** argv)
{


    bool enterHit = false;


    int a[37][10][7] = {{{0}}};

    initText(a);

    // Create SDL_Plotter object and SoundHandler object
    SDL_Plotter *g = new SDL_Plotter(500, 1000);
    SoundHandler *soundHandler = new SoundHandler(g);

    // Create PlotterTexture object using SDL_Plotter object
    PlotterTexture plotter(g);

    vector<string> fileNames = {"lion.txt", "hogsmeade.txt",
                               "baylorRockWall.txt",
                               "windows7.txt", "starryNight.txt",
                               "Texas.txt", "TATE.txt",
                               "room.txt", "easterIsland.txt",
                               "musicians.txt"};
    int userInputDif, userInputPic;

 //Commented out Menu The kbhit isnt working for me. I left the template for
 // the 3 menus Look at Text.cpp for the implementation All test must be Capital letters only.

    //Main Menu
    while(!g->getQuit() && !enterHit){
        for(int i = 0; i < 1000; i++){
            for(int j = 0; j < 500; j++){
                plotter.writePixel(i,j,0);
            }
        }

        displayText("BOOTHS_PUZZLE_LEAGUE",
                    32, (1000/10) - 20, 500/3, 6, 255, 255, 255,*g, a);
        displayText("PRESS_ANY_KEY_TO_START",
                    15, (1000/10) + 100, 500/2, 2, 255, 255, 255,*g, a);


        if(g->kbhit()){
            enterHit = true;
        }

        g->update();
    }


    //Paints Screen Black
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 500; j++){
            plotter.writePixel(i,j,0);
        }
    }


    //font size 10x7
    //multiply by integer values

    //Difficulty Select
    displayText("SELECT_DIFFICULTY",
                32, 500 - 28*9, 50, 4, 255,255,255, *g, a);
    displayText("EASY",
                32, 28*2, 200, 4, 0,255,0, *g, a);
    displayText("NORMAL",
                32, 500-28*3, 200, 4, 255,128,0, *g, a);
    displayText("HARD",
                32, 1000-28*6, 200, 4, 255,0,0, *g, a);

    displayText("PRESS_1",
                16, 14*4.5, 300, 2, 255,255,255, *g, a);
    displayText("PRESS_2",
                16, 500-14*3.5, 300, 2, 255,255,255, *g, a);
    displayText("PRESS_3",
                16, 1000-14*11.5, 300, 2, 255,255,255, *g, a);

    g->update();

    char press;

    //delay to prevent clicking too quick
    sleep(1);

    //polling for input until proper keys are clicked
    while(!g->getQuit()){
        if(g->kbhit()){
            press = g->getKey();

            if(press == '1') {
                userInputDif = 1;
                break;
            }
            else if(press == '2') {
                userInputDif = 2;
                break;
            }
            else if(press == '3') {
                userInputDif = 3;
                break;
            }
        }

        g->update();
    }

    //Paints Screen Black
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 500; j++){
            plotter.writePixel(i,j,0);
        }
    }


    //draws all of the text to the screen for the menu
    displayText("SELECT_IMAGE",
                32, 500 - 28*6, 50, 4, 255,255,255, *g, a);


    displayText("LION",
                16, 14*2, 150, 2, 255,255,255, *g, a);
    displayText("PRESS_1",
                16, 14, 200, 2, 255,255,255, *g, a);

    displayText("HOGSMEADE",
                16, 228 - 14*4.5, 150, 2, 255,255,255, *g, a);
    displayText("PRESS_2",
                16, 228-14*3.5, 200, 2, 255,255,255, *g, a);

    displayText("ROCK_WALL",
                16, 428 - 14*4.5, 150, 2, 255,255,255, *g, a);
    displayText("PRESS_3",
                16, 428-14*3.5, 200, 2, 255,255,255, *g, a);

    displayText("WINDOWS_7",
                16, 628 - 14*4.5, 150, 2, 255,255,255, *g, a);
    displayText("PRESS_4",
                16, 628-14*3.5, 200, 2, 255,255,255, *g, a);

    displayText("STARRY_NIGHT",
                16, 828 - 14*6, 150, 2, 255,255,255, *g, a);
    displayText("PRESS_5",
                16, 828-14*3.5, 200, 2, 255,255,255, *g, a);


    displayText("TEXAS",
                16, 14*2.5, 350, 2, 255,255,255, *g, a);
    displayText("PRESS_6",
                16, 14, 400, 2, 255,255,255, *g, a);

    displayText("TATE",
                16, 228 - 14*2, 350, 2, 255,255,255, *g, a);
    displayText("PRESS_7",
                16, 228-14*3.5, 400, 2, 255,255,255, *g, a);

    displayText("ROOM",
                16, 428 - 14*2, 350, 2, 255,255,255, *g, a);
    displayText("PRESS_8",
                16, 428-14*3.5, 400, 2, 255,255,255, *g, a);

    displayText("EASTER_ISLAND",
                16, 628 - 14*6.5, 350, 2, 255,255,255, *g, a);
    displayText("PRESS_9",
                16, 628-14*3.5, 400, 2, 255,255,255, *g, a);

    displayText("MUSICIANS",
                16, 828 - 14*4.5, 350, 2, 255,255,255, *g, a);
    displayText("PRESS_0",
                16, 828-14*3.5, 400, 2, 255,255,255, *g, a);

    g->update();

    //delay to prevent fast click
    sleep(1);

    //grab user input, encoding the keys
    while(!g->getQuit()){
        if(g->kbhit()){
            press = g->getKey();

            if(press == '1') {
                userInputPic = 0;
                break;
            }
            else if(press == '2') {
                userInputPic = 1;
                break;
            }
            else if(press == '3') {
                userInputPic = 2;
                break;
            }
            else if(press == '4') {
                userInputPic = 3;
                break;
            }
            else if(press == '5') {
                userInputPic = 4;
                break;
            }
            else if(press == '6') {
                userInputPic = 5;
                break;
            }
            else if(press == '7') {
                userInputPic = 6;
                break;
            }
            else if(press == '8') {
                userInputPic = 7;
                break;
            }
            else if(press == '9') {
                userInputPic = 8;
                break;
            }
            else if(press == '0') {
                userInputPic = 9;
                break;
            }
        }

        g->update();
    }

    // Convert user input to appropriate dimensions
    switch (userInputDif) {
        case 1:
            userInputDif = 2;
            break;
        case 2:
            userInputDif = 4;
            break;
        case 3:
            userInputDif = 8;
            break;
        default:
            cout << "Not a valid option...\nRestart program";
            return 0;
    }

    // Load the selected image using TextureLoader and save as PieceTexture object
    PieceTexture *puzzle = TextureLoader::loadImage<PieceTexture>
        (fileNames.at(userInputPic));

    // Create Board object using user-defined difficulty, plotter, puzzle, and soundHandler objects
    Board board(userInputDif, userInputDif,
                &plotter, puzzle, soundHandler);

    // Start the timer for playing background music
    long long start = std::chrono::system_clock::
    now().time_since_epoch().count();
    bool started = false;


    // While the user has not quit the game and the puzzle has not been solved
    while (!g->getQuit() && !board.checkWin()) {
        // Start playing background music after a set time has elapsed

        // Get the current system time in nanoseconds
        long long t1 = std::chrono::system_clock::
        now().time_since_epoch().count();
        // If 500 milliseconds have passed and the music has not started playing yet
        if (t1 - start > 500000000 && !started) {
            started = true;
            soundHandler->playMusic();// Start playing background music
        }
        plotter.clear(0);   // Clear the plotter buffer
        board.step();   // Advance the game state by one step.
        board.draw();   // Draw the game board.
        long long t2 = std::chrono::system_clock::now().time_since_epoch().count();

        // Update the SDL window with the new drawing.
        g->update();
    }// End of outer while loop

    // Pause the game for 6 seconds before terminating.
    sleep(6);

    return 0;
}

