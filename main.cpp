#include <iostream>
#include <chrono>

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

    while (!g->getQuit() && !board.checkWin()){
        long long t1 = std::chrono::system_clock::now().time_since_epoch().count();
        plotter.clear(0);
        board.step();
        board.draw();
        long long t2 = std::chrono::system_clock::now().time_since_epoch().count();
        g->update();
    }

    return 0;
}
