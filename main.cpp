#include <iostream>
#include <cmath>
#include <unistd.h>
#include "SDL_Plotter.h"
#include "TextureLoader.h"
#include "Texture.h"
#include "PlotterTexture.h"
#include "InputHandler.h"
#include "TextAtlas.h"
#include "GridManager.h"

using namespace std;

int testThread(void* params) {
    cout << reinterpret_cast<int*>(params)[0] << endl;
    return 0;
}

int main(int argc, char ** argv)
{
    Texture* texture = TextureLoader::test<Texture>(20, 20);
    TextAtlas* atlas = TextureLoader::loadAtlas<TextAtlas>("textmap");

    SDL_Plotter* g = new SDL_Plotter(500,500);

    PlotterTexture plotter(g);

    GridManager* gridManager = new GridManager(500, 500, 2, 2);

    gridManager->setGridElement(0, 0, texture);
    gridManager->setGridElement(1, 1, texture);
    gridManager->setGridElement(0, 1, atlas);
    gridManager->setGridElement(1, 0, atlas);

    //InputHandler input;


    bool stopped = false;
    int mouseX = 250;
    int mouseY = 250;
    int x,y;

    bool pressed = false;
    int tw = 128;
    atlas->setTextWidth(tw);
    double t = 0;
    while (!g->getQuit())
    {
        t += 0.1;
        if(!stopped){
            long long t1 = std::chrono::system_clock::now().time_since_epoch().count();
            g->kbhit();
            if(g->getKey() == '1') {
                gridManager->changeColumnWidth(1, 2.0);
                gridManager->update();
            }

            g->getMouseLocation(mouseX, mouseY);
            plotter.clear(0);
            //cout << scaleF << endl;
            double xp = ((double)mouseX) / plotter.WIDTH;
            double yp = ((double)mouseY) / plotter.HEIGHT;

            gridManager->plot(&plotter, 0.0, 0.0, xp, yp);

            long long t2 = std::chrono::system_clock::now().time_since_epoch().count();

            if(t2 - t1 < 16) {
                usleep(16-(t2-t1));
            }
        }

        g->update();
    }

    return 0;
}
