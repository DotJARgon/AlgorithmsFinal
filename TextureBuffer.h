//
// Created by Marcelo on 1/19/2023.
//
#include "WriteableBuffer.h"

#ifndef FINALPROJECT_TEXTUREBUFFER_H
#define FINALPROJECT_TEXTUREBUFFER_H

class TextureBuffer : public WriteableBuffer {
public:
    const int WIDTH, HEIGHT;

    TextureBuffer(int width, int height): WIDTH(width), HEIGHT(height) {}

    virtual void plot(TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY, double ux1, double uy1, double ux2, double uy2, double rot = 0.0) = 0;
    virtual void plot(TextureBuffer* textureBuffer, double x, double y, double w, double h) = 0;

    virtual void replaceData(int* data) = 0;
    virtual void copyData(int* data) = 0;

    virtual void clear(int argb) = 0;
    virtual void writePixel(int x, int y, int argb) = 0;
    virtual int getPixel(int x, int y) = 0;
protected:
    int* data = nullptr;
};

#endif //FINALPROJECT_TEXTUREBUFFER_H
