#include <iostream>
#include "SDL_Plotter.h"
#include "TextureLoader.h"
#include "Texture.h"
#include "PlotterTexture.h"
#include "InputHandler.h"
#include "Board.h"

using namespace std;

int main(int argc, char ** argv)
{
    //Texture* texture = TextureLoader::test<Texture>(20, 30);

    Texture* puzzle = TextureLoader::loadImage<Texture>("puzzle.txt");

    SDL_Plotter* g = new SDL_Plotter(500,1000);

    SoundHandler* soundHandler = new SoundHandler(g);

    PlotterTexture plotter(g);

    Board board(3, 3, &plotter, puzzle, soundHandler);

    bool stopped = false;

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
