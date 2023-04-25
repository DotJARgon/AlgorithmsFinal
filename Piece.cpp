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
    if(this->pieces.size() == 0) {
        this->gridx = int(this->x * this->rows);
        this->gridy = int(this->y * this->cols);
    }
    else {
        //all pieces are centered around a point so we need to take that
        //into account
        for(Piece& p : this->pieces) {
            p.gridx = int((p.x + this->x) * this->rows);
            p.gridy = int((p.y + this->y) * this->cols);
        }
    }
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

    //case of this being the only piece
    if(this->pieces.size() == 0) {
        if(rotation == LEFT_ROT) this->rotateEdgesLeft();
        else if(rotation == RIGHT_ROT) this->rotateEdgesRight();
    }
    else {
        //this is the case that this is a collection of
        //pieces
        for(Piece& p : this->pieces) {
            if(rotation == LEFT_ROT) this->rotateEdgesLeft();
            else if(rotation == RIGHT_ROT) this->rotateEdgesRight();

            double dx = p.x - this->x;
            double dy = p.y - this->y;
            double rx = dx*cos_rot - dy*sin_rot + this->x;
            double ry = dx*sin_rot + dy*cos_rot + this->y;
            p.x = rx;
            p.y = ry;
        }
    }
}

bool canFuse(vector<Piece>& pieces1, vector<Piece>& pieces2) {
    vector<Piece> m1;
    vector<Piece> m2;
    for(Piece p1 : pieces1) {
        for(Piece p2 : pieces2) {
            //no overlaps allowed for fusing pieces
            if(p1.gridx == p2.gridx && p1.gridy == p2.gridy) return false;
            //left or right
            if(abs(p1.gridx - p2.gridx) == 1 && abs(p1.gridy - p2.gridy) == 0) {

                //check if these pieces really are supposed to line up
                if(abs(p1.absx - p2.absx) == 1 && abs(p1.absy - p2.absy) == 0) {
                    m1.push_back(p1);
                    m2.push_back(p2);
                }
            }
            //top or bottom
            else if(abs(p1.gridx - p2.gridx) == 0 && abs(p1.gridy - p2.gridy) == 1) {

                //check if these pieces really are supposed to line up
                if(abs(p1.absx - p2.absx) == 0 && abs(p1.absy - p2.absy) == 1) {
                    m1.push_back(p1);
                    m2.push_back(p2);
                }
            }
            //we do not care about diagonal, no fusion occurs on diagonals
        }
    }

    //there are no possible matches
    if(m1.size() == 0 && m2.size() == 0) return false;

    //if there are possible matches, that is, pieces next to
    //each other that belong next to eachother,
    //we need to make sure their edges match
    for(int i = 0; i < m1.size(); i++) {
        Piece& p1 = m1.at(i);
        Piece& p2 = m2.at(i);

        //if the pieces belong next to eachother, and
        //their rotations match, they must be able to join
        //eachother (we have determined they belong to eachother
        //in the previous loop
        if(p1.rotation != p2.rotation) return false;

        /*int dx = p1.gridx - p2.gridx;
        int dy = p1.gridy - p2.gridy;
        bool match = false;

        //p1 is to the right
        if(dx == 1) {
            match = matches(p1.left, p2.right);
        }
        //p1 to the left
        else if(dx == -1) {
            match = matches(p1.right, p2.left);
        }
        //p1 above
        else if(dy == 1) {
            match = matches(p1.bottom, p2.top);
        }
        //p1 below
        else if(dy == -1) {
            match = matches(p1.top, p2.bottom);
        }

        if(!match) {
            return false;
        }*/
    }

    return true;
}

//this function is meant for fusing pieces together
bool Piece::canAdd(Piece& piece) {
    vector<Piece> myself;
    vector<Piece> other;

    if(this->pieces.size() == 0) myself.push_back(*this);
    else {
        for(Piece& p : this->pieces) myself.push_back(p);
    }

    if(piece.pieces.size() == 0) other.push_back(piece);
    else {
        for(Piece& p : piece.pieces) other.push_back(p);
    }

    return canFuse(myself, other);
}
void Piece::add(Piece& piece) {
    //create a shallow copy of this object to prevent
    //recursion
    Piece myself = *this;
    if(this->pieces.size() == 0) this->pieces.push_back(myself);

    if(piece.pieces.size() == 0) this->pieces.push_back(piece);
    else {
        for(Piece& p : piece.pieces) this->pieces.push_back(p);
        //clear out all of the pieces of the other one since they are no
        //longer needed
        piece.pieces.clear();
    }

    //center the pieces
    double avgx = 0;
    double avgy = 0;

    for(Piece& p : this->pieces) {
        avgx += p.x;
        avgy += p.y;
    }
    avgx /= this->pieces.size();
    avgy /= this->pieces.size();
    for(Piece& p : this->pieces) {
        p.x -= avgx;
        p.y -= avgy;
    }
}

void Piece::drawSelf(Texture* texture, PlotterTexture* screen) {

    double scaleX = double(screen->WIDTH) / (this->rows*texture->WIDTH);
    double scaleY = double(screen->HEIGHT) / (this->cols*texture->HEIGHT);
    if(this->isSelected) {
        if(this->pieces.size() == 0) {
            double r = rotation*3.1415926535 / 2.0;
            texture->plot(screen, x*screen->WIDTH, y*screen->HEIGHT, scaleX, scaleY, ux, uy, ux + width, uy + height, r);
        }
        else {
            for(Piece& p : this->pieces) {
                double x = p.x + this->x;
                double y = p.y + this->y;
                double r = p.rotation*3.1415926535 / 2.0;
                texture->plot(screen, x*screen->WIDTH, y*screen->HEIGHT, scaleX, scaleY, p.ux, p.uy, p.ux + p.width, p.uy + p.height, r);
            }
        }
    }
    else {
        if(this->pieces.size() == 0) {
            double x = double(gridx) / this->rows + 0.5 / this->rows;
            double y = double(gridy) / this->cols + 0.5 / this->cols;

            double r = this->rotation*3.1415926535 / 2.0;
            texture->plot(screen, x*screen->WIDTH, y*screen->HEIGHT, scaleX, scaleY, ux, uy, ux + width, uy + height, r);
        }
        else {
            for(Piece& p : this->pieces) {
                double x = double(p.gridx) / this->rows;
                double y = double(p.gridy) / this->cols;
                double r = p.rotation*3.1415926535 / 2.0;
                texture->plot(screen, x*screen->WIDTH, y*screen->HEIGHT, scaleX, scaleY, p.ux, p.uy, p.ux + p.width, p.uy + p.height, r);
            }
        }
    }
}