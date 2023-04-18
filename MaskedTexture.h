//
// Created by Marcelo on 4/18/2023.
//

#ifndef FINALPROJECT_MASKEDTEXTURE_H
#define FINALPROJECT_MASKEDTEXTURE_H


#include "Texture.h"

class MaskedTexture : public Texture {
private:
    TextureBuffer* mask = nullptr;
public:
    MaskedTexture(int width, int height) : Texture(width, height) {

    }
    bool setMask(TextureBuffer* mask);
    int getPixel(int x, int y);
};


#endif //FINALPROJECT_MASKEDTEXTURE_H
