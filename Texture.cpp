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

void Texture::plot(TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY) {
    for(int i = 0; i < this->WIDTH * scaleX; i++) {
        for(int j = 0; j < this->HEIGHT * scaleY; j++) {
            /*if(scaleX < 1.0) {
                int largb = this->getPixel(i / scaleX, j);
                int rargb = this->getPixel(i / scaleX + 1, j);

                double ix = i*scaleX;

                int lx = (int) (i * scaleX);
                int ux = lx + 1;

                int wr = ((largb>>16)&0xff) * (ix - lx) + ((rargb>>16)&0xff) * (ux - ix);
                int wg = ((largb>>8)&0xff) * (ix - lx) + ((rargb>>8)&0xff) * (ux - ix);
                int wb = (largb&0xff) * (ix - lx) + (rargb&0xff) * (ux - ix);

                textureBuffer->writePixel(x + i, y + j, (wr<<16) + (wg<<8) + wb);
            }*/
            if(this->INTERPOLATE) {
                double sx = i / scaleX;
                double sy = j / scaleY;
                int argb = this->getPixel(sx, sy);

                double pR = (argb>>16)&0xff;
                double pG = (argb>>8)&0xff;
                double pB = (argb)&0xff;

                if(scaleX > 1.0) {
                    double lowX = min(ceil(sx + 0.5), this->WIDTH-1.0);
                    int argb2 = this->getPixel(lowX, sy);
                    double pR2 = (argb2>>16)&0xff;
                    double pG2 = (argb2>>8)&0xff;
                    double pB2 = (argb2)&0xff;

                    cout << (sx - floor(sx - 0.5)) << " + " << lowX - sx
                    << " = " << (((sx - floor(sx - 0.5))) + (lowX - sx)) << endl;

                    pR = (sx - floor(sx - 0.5)) * pR + (lowX - sx) * pR2;
                    pG = (sx - floor(sx - 0.5)) * pG + (lowX - sx) * pG2;
                    pB = (sx - floor(sx - 0.5)) * pB + (lowX - sx) * pB2;
                    pR /= (((sx - floor(sx - 0.5))) + (lowX - sx));
                    pG /= (((sx - floor(sx - 0.5))) + (lowX - sx));
                    pB /= (((sx - floor(sx - 0.5))) + (lowX - sx));

                }

                int R = pR;
                int G = pG;
                int B = pB;

                //cout << R << ", " << G << ", " << B << endl;

                textureBuffer->writePixel(x + i, y + j, (R<<16) + (G<<8) + B);
            }
            else {
                double sx = i / scaleX;
                double sy = j / scaleY;
                int argb = this->getPixel(sx, sy);
                textureBuffer->writePixel(x + i, y + j, argb);
            }






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