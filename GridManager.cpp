//
// Created by Marcelo on 1/28/2023.
//

#include "GridManager.h"
#include <iostream>
using namespace std;


GridManager::~GridManager() {}

void GridManager::plot(TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY, double ux1, double uy1, double ux2, double uy2, double rot) {}
void GridManager::plot(TextureBuffer* textureBuffer, double x, double y, double w, double h) {
    for(int i = 0; i < this->rows; i++) {
        for(int j = 0; j < this->columns; j++) {
            Grid g = this->grid[i][j];

            if(g.getBuffer()) {
                if(g.getAspectRatio()) {
                    double scaleW = g.getWidth() * w;
                    double scaleH = g.getHeight() * h;
                    double scaleAspect = scaleH / scaleW;
                    double currAspect = g.getBuffer()->HEIGHT / ((double) g.getBuffer()->WIDTH);

                    double newAspect = scaleAspect / currAspect;

                    g.getBuffer()->plot(textureBuffer, x + g.getX() * w, y + g.getY() * h, g.getWidth() * w * newAspect, g.getHeight() * h);
                }
                else {
                    /*cout << "dimensions[" << i << "][" << j << "]: " << g.getWidth() * w << ", " << g.getHeight() * h << endl;
                    cout << "positions[" << i << "][" << j << "]:  " << g.getX() * w << ", " << g.getY() * h << endl;*/
                    g.getBuffer()->plot(textureBuffer, x + g.getX() * w, y + g.getY() * h, g.getWidth() * w, g.getHeight() * h);
                }
            }
        }
    }
}

void GridManager::replaceData(int* data) {
    this->backBuffer->replaceData(data);
}
void GridManager::copyData(int* data) {
    this->backBuffer->copyData(data);
}

void GridManager::clear(int argb) {
    this->backBuffer->clear(argb);
}
void GridManager::writePixel(int x, int y, int argb) {
    this->backBuffer->writePixel(x, y, argb);
}
int GridManager::getPixel(int x, int y) {
    return this->backBuffer->getPixel(x, y);
}

void GridManager::changeColumnWidth(int column, double width) {
    if(column >= 0 && column < this->columns) {
        this->columnWidths[column] = width;
        this->updated = true;
    }
}
void GridManager::changeRowHeight(int row, double height) {
    if(row >= 0 && row < this->rows) {
        this->rowHeights[row] = row;
        this->updated = true;
    }
}

void GridManager::setGridElement(int row, int column, TextureBuffer* textureBuffer) {
    if(row >= 0 && row < this->rows && column >= 0 && column < this->columns) {
        this->grid[row][column].setBuffer(textureBuffer);
    }
}

void GridManager::update() {
    if(updated) {
        double totalHeight = 0;
        for(int i = 0; i < this->rows; i++) totalHeight += this->rowHeights[i];
        double totalWidth = 0;
        for(int i = 0; i < this->columns; i++) totalWidth += this->columnWidths[i];

        double y = 0;
        for(int i = 0; i < this->rows; i++) {
            double x = 0;
            for(int j = 0; j < this->columns; j++) {
                Grid* g = &this->grid[i][j];
                g->setX(x);
                g->setY(y);
                g->setWidth(this->columnWidths[j] / totalWidth);
                g->setHeight(this->rowHeights[i] / totalHeight);
                x += this->columnWidths[j] / totalWidth;
            }
            y += this->rowHeights[i] / totalHeight;
        }

        this->updated = false;
    }
}


void Grid::setAspectRatio(bool aspect) {this->keepAspectRatio = aspect;}
void Grid::setAlignment(Alignment alignment) {this->alignment = alignment;}

bool Grid::getAspectRatio() {return this->keepAspectRatio;}
Alignment Grid::getAlignment() {return this->alignment;}

void Grid::setWidth(double w) {this->w = w;}
void Grid::setHeight(double h) {this->h = h;}

void Grid::setX(double x) {this->x = x;}
void Grid::setY(double y) {this->y = y;}

double Grid::getWidth() {return this->w;}
double Grid::getHeight() {return this->h;}

double Grid::getX() {return this->x;}
double Grid::getY() {return this->y;}

void Grid::setBuffer(TextureBuffer* buffer) {this->buffer = buffer;}
TextureBuffer* Grid::getBuffer() {return this->buffer;}