//
// Created by Marcelo on 1/26/2023.
//

#ifndef FINALPROJECT_TEXTATLAS_H
#define FINALPROJECT_TEXTATLAS_H


#include "TextureBuffer.h"

class TextAtlas : public TextureBuffer {
private:
    int textColor;
    int textWidth;
public:
    TextAtlas(int width, int height) : TextureBuffer(width, height) {
        this->data = new int[WIDTH*HEIGHT];
        this->textColor = 0xff00ff;
        this->textWidth = 128;
    }
    ~TextAtlas();
    void plot(TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY);
    void plot(TextureBuffer* textureBuffer, double x, double y, double w, double h);
    void replaceData(int* data);
    void copyData(int* data);

    void clear(int argb);
    void writePixel(int x, int y, int argb);
    int getPixel(int x, int y);
    void setTextWidth(int tw);
};


#endif //FINALPROJECT_TEXTATLAS_H
