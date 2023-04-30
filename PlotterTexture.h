//
// Created by Marcelo on 1/23/2023.
//
#include "TextureBuffer.h"
#include "SDL_Plotter.h"

#ifndef FINALPROJECT_PLOTTERTEXTURE_H
#define FINALPROJECT_PLOTTERTEXTURE_H


class PlotterTexture : public TextureBuffer {
public:
    PlotterTexture(SDL_Plotter* plotter) : TextureBuffer(plotter->getCol(), plotter->getRow()) {
        this->plotter = plotter;
    }
    ~PlotterTexture() {}
    void plot(TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY, double ux1, double uy1, double ux2, double uy2, double rot = 0.0, bool lighten = false);
    void plot(TextureBuffer* textureBuffer, double x, double y, double w, double h);
    void replaceData(int* data);
    void copyData(int* data);

    void clear(int argb);
    void writePixel(int x, int y, int argb);
    int getPixel(int x, int y);

    SDL_Plotter* getPlotter();
private:
    SDL_Plotter* plotter;
};


#endif //FINALPROJECT_PLOTTERTEXTURE_H
