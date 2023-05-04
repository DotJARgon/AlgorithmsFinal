#include <iostream>
#include <chrono>
#include <unistd.h>
#include "SDL_Plotter.h"
#include "TextureLoader.h"
#include "PieceTexture.h"
#include "PlotterTexture.h"
#include "Board.h"

using namespace std;

int main(int argc, char ** argv)
{
    //Texture* texture = TextureLoader::test<Texture>(20, 30);

    vector<string> fileName = {"lion.txt", "hogsmeade.txt",
                               "baylorRockWall.txt",
                               "windows7.txt", "starryNight.txt",
                               "Texas.txt", "TATE.txt",
                               "room.txt", "easterIsland.txt",
                               "musicians.txt"};
    int userInputDif, userInputPic;
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
    for(int i = 0; i < fileName.size(); i++){
        cout << i + 1 << ".) " << fileName.at(i) << endl;
    }
    cout << endl;
    cin >> userInputPic;
    PieceTexture* puzzle = TextureLoader::loadImage<PieceTexture>
            (fileName.at(userInputPic - 1));

    SDL_Plotter* g = new SDL_Plotter(500,1000);

    SoundHandler* soundHandler = new SoundHandler(g);

    PlotterTexture plotter(g);


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
