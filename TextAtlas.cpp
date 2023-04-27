/*
* Authors: Tristan Brown, Marcelo Carpenter, Thomas Cho, 
*          Joshua Linnett, Aaron Mendoza, Harrison Williams
* Assignment Title: Jigsaw Puzzles Epic
* Assignment Description: This program allows users to solve a puzzle using
*                         their own images.
* Due Date: 5/02/2023
* Date Created: 1/26/2023
* Date Last Modified: 4/27/2023
*/

#include "TextAtlas.h"

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

TextAtlas::~TextAtlas() {
    delete[] this->data;
}

void TextAtlas::setTextWidth(int tw) {
    this->textWidth = tw;
}

void TextAtlas::plot(TextureBuffer* textureBuffer, double x, double y, double w, double h) {
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
            if(((argb >> 24) & 0xff) > this->textWidth) textureBuffer->writePixel(i, j, this->textColor);
        }
    }
}

void TextAtlas::plot(TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY, double ux1, double uy1, double ux2, double uy2, double rot) {
}

void TextAtlas::replaceData(int* data) {
    delete[] this->data;
    this->data = data;
}
void TextAtlas::copyData(int* data) {
    memcpy(this->data, data, this->HEIGHT * this->WIDTH * sizeof(int));
}

void TextAtlas::clear(int argb) {
    memset(this->data, argb, this->HEIGHT * this->WIDTH * sizeof(int));
}
void TextAtlas::writePixel(int x, int y, int argb) {
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        this->data[y * this->WIDTH + x] = argb;
    }
}
int TextAtlas::getPixel(int x, int y) {
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        return this->data[x * this->HEIGHT + y];
    }
    else return 0;
}