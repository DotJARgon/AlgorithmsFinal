#include <iostream>
#include <unistd.h>
#include "SDL_Plotter.h"
#include "TextureLoader.h"
#include "Texture.h"
#include "PlotterTexture.h"
#include "InputHandler.h"
#include "TextAtlas.h"
#include "GridManager.h"
#include "MaskedTexture.h"
#include "Board.h"

using namespace std;

int main(int argc, char ** argv)
{
    Texture* texture = TextureLoader::test<Texture>(20, 30);

    SDL_Plotter* g = new SDL_Plotter(500,1000);

    PlotterTexture plotter(g);

    Board board(4, 4, &plotter, texture);

    bool stopped = false;
    int mouseX = 250;
    int mouseY = 250;
    int x,y;

    bool pressed = false;
    double t = 0;
    double test = 0;
    double delta = .01;
    while (!g->getQuit())
    {
        t += 0.01;
        test += delta;
        if(test > 1.0) {
            test = 1.0;
            delta = -delta;
        }
        else if(test < 0.0) {
            test = 0.0;
            delta = -delta;
        }
        if(!stopped){
            long long t1 = std::chrono::system_clock::now().time_since_epoch().count();
            //g->kbhit();
            plotter.clear(0);
            board.step();
            board.draw();

            long long t2 = std::chrono::system_clock::now().time_since_epoch().count();

            /*if(t2 - t1 < 16) {
                usleep(16-(t2-t1));
            }*/
        }
        SDL_PumpEvents();
        SDL_FlushEvents(SDL_USEREVENT, SDL_LASTEVENT);
        g->update();
    }

    return 0;
}
