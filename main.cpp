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

using namespace std;

int main(int argc, char ** argv)
{
    //Texture* texture = TextureLoader::test<Texture>(20, 30);

    // Set the filenames of the images to be used as the puzzle pieces
    vector<string> fileName = {"lion.txt", "hogsmeade.txt",
                               "baylorRockWall.txt",
                               "windows7.txt", "starryNight.txt",
                               "Texas.txt", "TATE.txt",
                               "room.txt", "easterIsland.txt"};
    int userInputDif, userInputPic;
    //TODO Just doing this console input until we get the texture
    // class working for SDL if we do

    // Ask the user for the puzzle difficulty level
    cout << "What difficulty?\n1.) Easy - 2x2\n2.)"
            " Medium - 4x4\n3.) Hard - 8x8\n";
    cin >> userInputDif;

    // Convert user input to appropriate dimensions
    switch (userInputDif){
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

    // Ask the user for the image to use for the puzzle pieces
    cout << "What picture would you like to use?" << endl;
    for(int i = 0; i < fileName.size(); i++){
        cout << i + 1 << ".) " << fileName.at(i) << endl;
    }
    cout << endl;
    cin >> userInputPic;

    // Load the selected image using TextureLoader and save as PieceTexture object
    PieceTexture* puzzle = TextureLoader::loadImage<PieceTexture>
            (fileName.at(userInputPic - 1));

    // Create SDL_Plotter object and SoundHandler object
    SDL_Plotter* g = new SDL_Plotter(500,1000);
    SoundHandler* soundHandler = new SoundHandler(g);

    // Create PlotterTexture object using SDL_Plotter object
    PlotterTexture plotter(g);

    // Create Board object using user-defined difficulty, plotter, puzzle, and soundHandler objects
    Board board(userInputDif, userInputDif,
                &plotter, puzzle, soundHandler);

    // Start the timer for playing background music
    long long start = std::chrono::system_clock::
            now().time_since_epoch().count();
    bool started = false;

    // While the user has not quit the game and the puzzle has not been solved
    while (!g->getQuit() && !board.checkWin()){
        // Start playing background music after a set time has elapsed
        long long t1 = std::chrono::system_clock::
                now().time_since_epoch().count();
        if(t1 - start > 500000000 && !started) {
            started = true;
            soundHandler->playMusic();
        }
        plotter.clear(0);   // Clear the plotter buffer
        board.step();   // Advance the game state by one step.
        board.draw();   // Draw the game board.
        long long t2 = std::chrono::system_clock::now().time_since_epoch().count();

        // Update the SDL window with the new drawing.
        g->update();
    }

    // Pause the game for 6 seconds before terminating.
    sleep(6);

    return 0;
}
