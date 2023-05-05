#include <iostream>
#include <chrono>
#include <unistd.h>
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
    bool difficultySelect = false;
    bool displayStart = true;


    int a[37][10][7] = {{{0}}};

    initText(a);

    SDL_Plotter* g = new SDL_Plotter(500,1000);

    SoundHandler* soundHandler = new SoundHandler(g);

    PlotterTexture plotter(g);
    //Texture* texture = TextureLoader::test<Texture>(20, 30);

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
//    while(!enterHit){
//        for(int i = 0; i <= 1000; i++){
//            for(int j = 0; j < 500; j++){
//                g->plotPixel(i,j,0,0,0);
//            }
//        }
//
//        displayText("BOOTHS_PUZZLE_LEAGUE", 32, (1000/10) -
//                                                20, 500/3, 6, 255, 255, 255,*g, a);
//        displayText("PRESS_ENTER_TO_START", 15, (1000/10) +
//                                                100, 500/2, 2, 255, 255, 255,*g, a);
//        if(displayStart){
//            g->update();
//            sleep(10);
//            displayStart = false;
//        }
//
//        if(g->kbhit()){
//            cout << "you did it dumbass" << endl;
//            char tmpKey = g->getKey();
//
//            if(tmpKey == SDL_SCANCODE_RETURN){
//                enterHit = true;
//            }
//
//            g->update();
//        }
//    }



//    //Paints Screen Black
//    for(int i = 0; i <= 1000; i++){
//        for(int j = 0; j < 500; j++){
//            g->plotPixel(i,j,0,0,0);
//        }
//    }


    //Difficulty Select
//    displayText("SELECT DIFFICULTY", 32, (1000/5) - 20, 500/3, 6, 255,255,255, *g, a);
//    g->update();
//        displayText("EASY")
//        displayText("PRESS 1")
//        displayText("NORMAL")
//        displayText("PRESS 2")
//        displayText("HARD")
//        displayText("PRESS 3")

    //while(!difficultySelect){

//        displayText("SELECT DIFFICULTY", 32, (1000/5) - 20, 500/3, 6, 255,255,255, *g, a);
//        g->update();
//        displayText("EASY")
//        displayText("PRESS 1")
//        displayText("NORMAL")
//        displayText("PRESS 2")
//        displayText("HARD")
//        displayText("PRESS 3")
    //}


    //Image Select
//        displayText("SELECT_IMAGE")
//        displayText("LION")
//        displayText("PRESS_1")
//        displayText("HOGSMEADE")
//        displayText("PRESS_2")
//        displayText("ROCK_WALL")
//        displayText("PRESS_3")
//        displayText("WINDOWS_7")
//        displayText("PRESS_4")
//        displayText("STARRY_NIGHT")
//        displayText("PRESS_5")
//        displayText("TEXAS")
//        displayText("PRESS_6")
//        displayText("TATE")
//        displayText("PRESS_7")
//        displayText("ROOM")
//        displayText("PRESS_8")
//        displayText("EASTER_ISLAND")
//        displayText("PRESS_9")
//        displayText("MUSICIANS")
//        displayText("PRESS_0")




    //TODO Just doing this console input until we get the texture
    // class working for SDL if we do
    cout << "What difficulty?\n1.) Easy - 2x2\n2.)"
            " Medium - 4x4\n3.) Hard - 8x8\n";

    cin >> userInputDif;
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


    cout << "What picture would you like to use?" << endl;
    for(int i = 0; i < fileNames.size(); i++){
        cout << i + 1 << ".) " << fileNames.at(i) << endl;
    }
    cout << endl;
    cin >> userInputPic;
    PieceTexture* puzzle = TextureLoader::loadImage<PieceTexture>
            (fileNames.at(userInputPic - 1));


    Board board(userInputDif, userInputDif,
                &plotter, puzzle, soundHandler);

    long long start = std::chrono::system_clock::
            now().time_since_epoch().count();
    bool started = false;

    while (!g->getQuit() && !board.checkWin()){
        long long t1 = std::chrono::system_clock::
                now().time_since_epoch().count();
        if(t1 - start > 500000000 && !started) {
            started = true;
            soundHandler->playMusic();
        }
        plotter.clear(0);
        board.step();
        board.draw();
        long long t2 = std::chrono::system_clock::now().time_since_epoch().count();
        g->update();
    }
    sleep(6);

    return 0;
}
