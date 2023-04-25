//
// Created by Marcelo on 1/23/2023.
//

#include "PlotterTexture.h"

void PlotterTexture::plot(TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY, double ux1, double uy1, double ux2, double uy2, double rot) {}
void PlotterTexture::plot(TextureBuffer* textureBuffer, double x, double y, double w, double h) {}
void PlotterTexture::replaceData(int* data) {}
void PlotterTexture::copyData(int* data) {}

void PlotterTexture::clear(int argb) {
    this->plotter->clear();
}
void PlotterTexture::writePixel(int x, int y, int argb) {
    if(x > 0 && x < this->WIDTH && y > 0 && y < this->HEIGHT) {
        int b = argb&0xff;
        int g = (argb >> 8) & 0xff;
        int r = (argb >> 16) & 0xff;
        this->plotter->plotPixel(x, y, r, g, b);
    }
}
int PlotterTexture::getPixel(int x, int y) {}

SDL_Plotter* PlotterTexture::getPlotter() {
    return this->plotter;
}