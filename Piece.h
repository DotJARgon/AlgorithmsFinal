//
// Created by Marcelo on 4/22/2023.
//

#ifndef FINALPROJECT_PIECE_H
#define FINALPROJECT_PIECE_H

#include <vector>
#include <cmath>
#include "Texture.h"

using namespace std;

enum Edge {
    FLAT, ONE_INLET, ONE_OUTLET
};

enum Rotate {
    LEFT, RIGHT
};

class Piece {
private:
    vector<Piece> pieces;
    void rotateEdgesRight();
    void rotateEdgesLeft();
public:
    int rotation;
    Edge left, top, right, bottom;
    int absx, absy;
    int gridx, gridy;
    double x, y;
    double width, height;
    double ux, uy;

    Piece(Edge left, Edge top, Edge right, Edge bottom);
    void rotate(Rotate rotation);
    bool canAdd(Piece& piece);
    void add(Piece& piece);
};


#endif //FINALPROJECT_PIECE_H
