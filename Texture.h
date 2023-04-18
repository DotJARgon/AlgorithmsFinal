//
// Created by Marcelo on 1/23/2023.
//

#include "TextureBuffer.h"

#ifndef FINALPROJECT_TEXTURE_H
#define FINALPROJECT_TEXTURE_H


class Texture : public TextureBuffer {
public:
    Texture(int width, int height) : TextureBuffer(width, height) {
        this->data = new int[WIDTH*HEIGHT];
    }
    ~Texture();
    void plot(TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY, double ux1, double uy1, double ux2, double uy2);
    void plot(TextureBuffer* textureBuffer, double x, double y, double w, double h);
    void replaceData(int* data);
    void copyData(int* data);

    void clear(int argb);
    void writePixel(int x, int y, int argb);
    int getPixel(int x, int y);

    void setInterpolationMode(bool inter);
private:
    bool INTERPOLATE = false;
};


#endif //FINALPROJECT_TEXTURE_H
