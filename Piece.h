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
    Edge left, top, right, bottom;
    vector<Piece> pieces;
    int rotation;
    void rotateEdgesRight();
    void rotateEdgesLeft();
public:
    int gridx, gridy;
    double x, y;
    double width, height;
    double ux, uy;

    Piece(Edge left, Edge top, Edge right, Edge bottom);
    void rotate(double scaleX, double scaleY, Rotate rotation);
    bool canAdd(Piece& piece);
    void add(Piece& piece);

};


#endif //FINALPROJECT_PIECE_H
