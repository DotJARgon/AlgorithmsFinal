//
// Created by Marcelo on 1/23/2023.
//

#ifndef FINALPROJECT_WRITEABLEBUFFER_H
#define FINALPROJECT_WRITEABLEBUFFER_H


class WriteableBuffer {
public:
    virtual void writePixel(int x, int y, int argb) = 0;
    virtual void clear(int argb) = 0;
    virtual int getPixel(int x, int y) = 0;
    //virtual void writeSelection(int x, int y, int startX, int startY, int width, int height);
};


#endif //FINALPROJECT_WRITEABLEBUFFER_H
