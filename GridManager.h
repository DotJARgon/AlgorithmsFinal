//
// Created by Marcelo on 1/28/2023.
//

#ifndef FINALPROJECT_GRIDMANAGER_H
#define FINALPROJECT_GRIDMANAGER_H


#include "TextureBuffer.h"
#include <cstring>

enum Alignment {
    LEFT, CENTER, RIGHT
};

struct Grid {
private:
    bool keepAspectRatio = false;
    Alignment alignment = CENTER;
    
    double w = 0;
    double h = 0;

    double x = 0;
    double y = 0;

    TextureBuffer* buffer = nullptr;
public:
    void setAspectRatio(bool aspect);
    void setAlignment(Alignment alignment);

    bool getAspectRatio();
    Alignment getAlignment();
    
    void setWidth(double w);
    void setHeight(double h);

    void setX(double x);
    void setY(double y);
    
    double getWidth();
    double getHeight();

    double getX();
    double getY();

    void setBuffer(TextureBuffer* buffer);
    TextureBuffer* getBuffer();
};

class GridManager : private TextureBuffer {
private:
    Grid** grid = nullptr;
    double* columnWidths = nullptr;
    double* rowHeights = nullptr;

    TextureBuffer* backBuffer;

    bool updated = false;
    
    int columns = 0;
    int rows = 0;
public:
    GridManager(int bufferW, int bufferH, int columns, int rows) : TextureBuffer(0, 0) {
        this->columns = columns;
        this->rows = rows;

        this->grid = new Grid*[this->rows];
        for(int i = 0; i < this->rows; i++) {
            this->grid[i] = new Grid[this->columns];
        }

        this->columnWidths = new double[this->columns];
        this->rowHeights   = new double[this->rows];

        for(int i = 0; i < this->columns; i++) this->columnWidths[i] = 1.0;
        for(int i = 0; i < this->rows; i++) this->rowHeights[i] = 1.0;

/*
        for(int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns; j++) {
                this->grid[i][j].setWidth(1.0 / this->columns);
                this->grid[i][j].setHeight(1.0 / this->rows);
            }
        }*/

        this->updated = true;

        this->update();
    }

    ~GridManager();

    void plot(TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY, double ux1, double uy1, double ux2, double uy2);
    void plot(TextureBuffer* textureBuffer, double x, double y, double w, double h);

    void replaceData(int* data);
    void copyData(int* data);

    void clear(int argb);
    void writePixel(int x, int y, int argb);
    int getPixel(int x, int y);


    void changeColumnWidth(int column, double width);
    void changeRowHeight(int row, double height);

    void setGridElement(int row, int column, TextureBuffer* textureBuffer);

    void update();

};


#endif //FINALPROJECT_GRIDMANAGER_H
