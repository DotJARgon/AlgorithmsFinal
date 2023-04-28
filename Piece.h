//
// Created by Marcelo on 4/22/2023.
//

#ifndef FINALPROJECT_PIECE_H
#define FINALPROJECT_PIECE_H

#include <vector>
#include <cmath>
#include "Rotate.h"
#include "Edge.h"
#include "Texture.h"
#include "PlotterTexture.h"

using namespace std;

class Piece {
private:
    void rotateEdgesRight();
    void rotateEdgesLeft();
public:
    bool isSelected;
    int rotation;
    Edge left, top, right, bottom;
    int absx, absy;
    int gridx, gridy;
    int rows, cols;
    double x, y;
    double width, height;
    double ux, uy;

    Piece(Edge left, Edge top, Edge right, Edge bottom);
    void rotate(Rotate rotation);
    bool isAdjacent(Piece* piece);
    bool canInterlock(Piece* piece);
    void setGrid();

    void drawSelf(Texture* texture, PlotterTexture* screen);
};


#endif //FINALPROJECT_PIECE_H
