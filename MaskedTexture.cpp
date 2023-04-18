//
// Created by Marcelo on 4/18/2023.
//
#include <iostream>
using namespace std;
#include "MaskedTexture.h"

bool MaskedTexture::setMask(TextureBuffer* mask) {
    if(mask->WIDTH == this->WIDTH && mask->HEIGHT == this->HEIGHT) {
        this->mask = mask;
        return true;
    }
    return false;
}
int MaskedTexture::getPixel(int x, int y) {
    int argb = 0;
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        argb = this->data[y * this->WIDTH + x];
    }
    if(this->mask) { return (this->mask->getPixel(x, y)) ? argb : (0xff000000 | argb); }
    return argb;
}