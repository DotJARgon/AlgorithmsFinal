//
// Created by Marcelo on 4/22/2023.
//

#include "Piece.h"

//actually likely not necessary but here in case
bool matches(Edge e1, Edge e2) {
    if(e1 == FLAT) return e2 == FLAT;
    if(e1 == ONE_INLET) return e2 == ONE_OUTLET;
    if(e1 == ONE_OUTLET) return e2 == ONE_INLET;
    return false;
}


Piece::Piece(Edge left, Edge top, Edge right, Edge bottom) {
    this->left = left;
    this->top = top;
    this->right = right;
    this->bottom = bottom;

    this->gridx = 0;
    this->gridy = 0;
    this->absx = 0;
    this->absy = 0;

    this->x = 0;
    this->y = 0;

    this->ux = 0;
    this->uy = 0;

    this->rows = 0;
    this->cols = 0;

    this->isSelected = false;

    this->rotation = 0;
}

void Piece::setGrid() {
    this->gridx = int(2.0*this->x * this->rows);
    this->gridy = int(this->y * this->cols);
}

void Piece::rotateEdgesRight() {
    Edge temp = this->bottom;
    this->bottom = this->right;
    this->right = this->top;
    this->top = this->left;
    this->left = temp;
}
void Piece::rotateEdgesLeft() {
    Edge temp = this->left;
    this->left = this->top;
    this->top = this->right;
    this->right = this->bottom;
    this->bottom = temp;
}
void Piece::rotate(Rotate rotation) {
    if(rotation == LEFT_ROT) this->rotation = (this->rotation + 1) % 4;
    else if(rotation == RIGHT_ROT) this->rotation = (this->rotation + 3) % 4;

    double cos_rot = cos(this->rotation*3.1415926535 / 2.0);
    double sin_rot = sin(this->rotation*3.1415926535 / 2.0);
    if(rotation == LEFT_ROT) this->rotateEdgesLeft();
    else if(rotation == RIGHT_ROT) this->rotateEdgesRight();
}


bool Piece::isAdjacent(Piece* piece) {
    int dx = piece->gridx - this->gridx;
    int dy = piece->gridy - this->gridy;
    //if one away
    return (abs(dx) == 1 && dy == 0) || (abs(dy) == 1 && dx == 0);
}

bool Piece::canInterlock(Piece* piece) {
    int dx = piece->gridx - this->gridx;
    int dy = piece->gridy - this->gridy;
    //if one away
    if(abs(dx) == 1 || abs(dy) == 1) {
        if(dx == 1 && dy == 0)  return matches(this->right, piece->left); //piece is right
        if(dx == -1 && dy == 0) return matches(this->left, piece->right); //piece is left
        if(dy == 1 && dx == 0)  return matches(this->top, piece->bottom); //piece is above
        if(dy == -1 && dx == 0) return matches(this->bottom, piece->top); //piece is below
    }
    return false;
}
bool Piece::areNeighbors(Piece* piece) {
    //this checks whether the pieces are meant to be next to eachother
    //on the board and match on the correct side
    bool adj = this->isAdjacent(piece);
    int adx = piece->absx - this->absx;
    int ady = piece->absy - this->absy;
    //if their absolute positions are not adjacent, then it should return false
    //immediately
    if(!((abs(adx) == 1 && ady == 0) || (abs(ady) == 1 && adx == 0))) return false;
    //if they are adjacent we can check if they are neighbors
    if(adj) {
        //if the rotations match
        //if they do not that side should not be connected
        if(this->rotation == piece->rotation) {
            //get the grid dx and dy
            int dx = piece->gridx - this->gridx;
            int dy = piece->gridy - this->gridy;

            if(adx == 1 && ady == 0) {
                if(this->rotation == 0) return dx ==  1; //no rotation
                if(this->rotation == 1) return dy ==  1; //90 degree ccw
                if(this->rotation == 2) return dx == -1; //180 degrees ccw
                if(this->rotation == 3) return dy == -1; //270 degrees ccw
            }

            if(adx == -1 && ady == 0) {
                if(this->rotation == 0) return dx == -1; //no rotation
                if(this->rotation == 1) return dy == -1; //90 degree ccw
                if(this->rotation == 2) return dx ==  1; //180 degrees ccw
                if(this->rotation == 3) return dy ==  1; //270 degrees ccw
            }

            if(adx == 0 && ady == 1) {
                if(this->rotation == 0) return dy ==  1; //no rotation
                if(this->rotation == 1) return dx == -1; //90 degree ccw
                if(this->rotation == 2) return dy == -1; //180 degrees ccw
                if(this->rotation == 3) return dx ==  1; //270 degrees ccw
            }

            if(adx == 0 && ady == -1) {
                if(this->rotation == 0) return dy == -1; //no rotation
                if(this->rotation == 1) return dx ==  1; //90 degree ccw
                if(this->rotation == 2) return dy ==  1; //180 degrees ccw
                if(this->rotation == 3) return dx == -1; //270 degrees ccw
            }
        }
        else return false;
    }
    return false;
}

void Piece::drawSelf(Texture* texture, PlotterTexture* screen) {

    double scaleX = 0.5*double(screen->WIDTH) / (this->rows*texture->WIDTH);
    double scaleY = double(screen->HEIGHT) / (this->cols*texture->HEIGHT);
    if(this->isSelected) {

        double x = 0.5*double(gridx) / this->rows + 0.5 / this->rows;
        double y = double(gridy) / this->cols + 0.5 / this->cols;

        double r = this->rotation*3.1415926535 / 2.0;
        texture->plot(screen, x*screen->WIDTH, y*screen->HEIGHT, scaleX, scaleY, ux, uy, ux + width, uy + height, r, true);

        texture->plot(screen, this->x*screen->WIDTH, this->y*screen->HEIGHT, scaleX, scaleY, ux, uy, ux + width, uy + height, r);
    }
    else {
        double x = 0.5*double(gridx) / this->rows + 0.5 / this->rows;
        double y = double(gridy) / this->cols + 0.5 / this->cols;

        double r = this->rotation*3.1415926535 / 2.0;
        texture->plot(screen, x*screen->WIDTH, y*screen->HEIGHT, scaleX, scaleY, ux, uy, ux + width, uy + height, r);
    }
}