//
// Created by Marcelo on 4/22/2023.
//

#include "Piece.h"

Piece::Piece(Edge left, Edge top, Edge right, Edge bottom) {
    this->left = left;
    this->top = top;
    this->right = right;
    this->bottom = bottom;
    this->gridx = 0;
    this->gridy = 0;
    this->x = 0;
    this->y = 0;
    this->ux = 0;
    this->uy = 0;
    this->rotation = 0;
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
void Piece::rotate(double scaleX, double scaleY, Rotate rotation) {

    if(rotation == LEFT) this->rotation++;
    else if(rotation == RIGHT) this->rotation--;

    double cos_rot = cos(this->rotation*3.1415926535 / 2.0);
    double sin_rot = sin(this->rotation*3.1415926535 / 2.0);

    //case of this being the only piece
    if(this->pieces.size() == 0) {
        if(rotation == LEFT) this->rotateEdgesLeft();
        else if(rotation == RIGHT) this->rotateEdgesRight();

        this->gridx = this->x*scaleX;
        this->gridy = this->y*scaleY;
    }
    else {
        //this is the case that this is a collection of
        //pieces
        for(Piece p : this->pieces) {
            if(rotation == LEFT) this->rotateEdgesLeft();
            else if(rotation == RIGHT) this->rotateEdgesRight();

            double dx = p.x - this->x;
            double dy = p.y - this->y;
            double rx = dx*cos_rot - dy*sin_rot + this->x;
            double ry = dx*sin_rot + dy*cos_rot + this->y;
            p.x = rx;
            p.y = ry;
        }
    }
}

bool canAdd(Piece& piece) {

}
void add(Piece& piece) {}