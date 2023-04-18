//
// Created by Marcelo on 1/23/2023.
//
#include <iostream>
#include "Texture.h"
#include <cstring>
#include <cmath>

using namespace std;

Texture::~Texture() {
  delete[] this->data;
}

void Texture::setInterpolationMode(bool inter) {
    this->INTERPOLATE = inter;
}

void Texture::plot(TextureBuffer* textureBuffer, double x, double y, double w, double h) {
    int sx = textureBuffer->WIDTH * x;
    int sy = textureBuffer->HEIGHT * y;

    double sw = textureBuffer->WIDTH * w;
    double sh = textureBuffer->HEIGHT * h;

    //optimization for screen write
    for(int i = max(sx, 0); i < sx + sw && i < textureBuffer->WIDTH; i++) {
        for(int j = max(sy, 0); j < sy + sh && j < textureBuffer->HEIGHT; j++) {
            //convert to texture coords
            double tx = ((i - sx) / sw) * this->WIDTH;
            double ty = ((j - sy) / sh) * this->HEIGHT;
            //get the pixel and plot in new space
            int argb = this->getPixel(tx, ty);
            textureBuffer->writePixel(i, j, argb);
        }
    }
}

void Texture::plot(TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY, double ux1, double uy1, double ux2, double uy2) {
    for(int i = 0; i < this->WIDTH * scaleX; i++) {
        for(int j = 0; j < this->HEIGHT * scaleY; j++) {
            double sx = ((i / scaleX)*(ux2 - ux1)) + this->WIDTH*ux1;
            double sy = ((j / scaleY)*(uy2 - uy1)) + this->HEIGHT*uy1;
            //double sx = i / scaleX;
            //double sy = j / scaleY;
            int argb = this->getPixel(sx, sy);
            textureBuffer->writePixel(x + i, y + j, argb);
        }
    }
}

void Texture::replaceData(int* data) {
    delete[] this->data;
    this->data = data;
}
void Texture::copyData(int* data) {
    memcpy(this->data, data, this->HEIGHT * this->WIDTH * sizeof(int));
}

void Texture::clear(int argb) {
    memset(this->data, argb, this->HEIGHT * this->WIDTH * sizeof(int));
}
void Texture::writePixel(int x, int y, int argb) {
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        this->data[y * this->WIDTH + x] = argb;
    }
}
int Texture::getPixel(int x, int y) {
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        return this->data[y * this->WIDTH + x];
    }
    else return 0;
}