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

void Piece::drawSelf(Texture* texture, PlotterTexture* screen) {

    double scaleX = 0.5*double(screen->WIDTH) / (this->rows*texture->WIDTH);
    double scaleY = double(screen->HEIGHT) / (this->cols*texture->HEIGHT);
    if(this->isSelected) {
        double r = rotation*3.1415926535 / 2.0;
        texture->plot(screen, x*screen->WIDTH, y*screen->HEIGHT, scaleX, scaleY, ux, uy, ux + width, uy + height, r);
    }
    else {
        double x = 0.5*double(gridx) / this->rows + 0.5 / this->rows;
        double y = double(gridy) / this->cols + 0.5 / this->cols;

        double r = this->rotation*3.1415926535 / 2.0;
        texture->plot(screen, x*screen->WIDTH, y*screen->HEIGHT, scaleX, scaleY, ux, uy, ux + width, uy + height, r);
    }
}