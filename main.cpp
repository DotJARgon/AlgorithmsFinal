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

    PieceTexture* puzzle = TextureLoader::loadImage<PieceTexture>("puzzle.txt");

    SDL_Plotter* g = new SDL_Plotter(500,1000);

    SoundHandler* soundHandler = new SoundHandler(g);

    PlotterTexture plotter(g);

    Board board(2, 2, &plotter, puzzle, soundHandler);

    long long start = std::chrono::system_clock::now().time_since_epoch().count();
    bool started = false;

    while (!g->getQuit() && !board.checkWin()){
        long long t1 = std::chrono::system_clock::now().time_since_epoch().count();
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
