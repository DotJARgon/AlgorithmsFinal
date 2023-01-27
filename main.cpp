#include <iostream>
#include <cmath>
#include <unistd.h>
#include "SDL_Plotter.h"
#include "TextureLoader.h"
#include "Texture.h"
#include "PlotterTexture.h"
#include "InputHandler.h"
#include "TextAtlas.h"

using namespace std;

int testThread(void* params) {
    cout << reinterpret_cast<int*>(params)[0] << endl;
    return 0;
}

int main(int argc, char ** argv)
{
    TextAtlas* texture = TextureLoader::loadAtlas<TextAtlas>("textmap");
    //Texture* texture = TextureLoader::test<Texture>(15, 10);
    cout << texture->WIDTH << " by " << texture->HEIGHT << endl;

    SDL_Plotter* g = new SDL_Plotter(500,500);

    PlotterTexture plotter(g);

    //InputHandler input;


    bool stopped = false;
    int mouseX = 250;
    int mouseY = 250;
    int x,y;

    double scaleX = 0.5;
    double scaleY = 0.5;

    bool pressed = false;
    int tw = 32;
    texture->setTextWidth(tw);
    double t = 0;
    while (!g->getQuit())
    {
        t += 0.1;
        if(!stopped){
            long long t1 = std::chrono::system_clock::now().time_since_epoch().count();
            g->kbhit();
            if(g->getKey() == '1' && !pressed) {
                pressed = true;
                if(tw < 255) tw ++;
            }
            else if(g->getKey() != '1' && pressed) {
                pressed = false;
            }
            else if(g->getKey() == '2' && !pressed) {
                pressed = true;
                if(tw > 0) tw--;
            }
            else if(g->getKey() != '2' && pressed) {
                pressed = false;
            }
            texture->setTextWidth(tw);
            g->getMouseLocation(mouseX, mouseY);
            plotter.clear(0);
            //cout << scaleF << endl;
            double xp = ((double)mouseX) / plotter.WIDTH;
            double yp = ((double)mouseY) / plotter.HEIGHT;
            scaleX = (sin(t1 / 300000000.0) + 1.5)*0.5;
            scaleY = (cos(t1 / 300000000.0) + 1.5)*0.5;
            texture->plot(&plotter, xp - scaleX * 0.5, yp - scaleY * 0.5, scaleX, scaleY);

            long long t2 = std::chrono::system_clock::now().time_since_epoch().count();

            if(t2 - t1 < 16) {
                usleep(16-(t2-t1));
            }

            //texture->plot(&plotter, 0, 0, 10.0, 10.0);
        }

        g->update();
    }

    return 0;
}
