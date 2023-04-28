//
// Created by Marcelo on 4/23/2023.
//

#include "Board.h"
#include <random>
#include <chrono>

Board::Board(int num_rows, int num_cols, PlotterTexture* plotter, Texture* texture) {
    this->num_rows = num_rows;
    this->num_cols = num_cols;
    this->plotter = plotter;
    this->texture = texture;

    this->mousex = 0;
    this->mousey = 0;
    this->clicked = false;

    this->selected = nullptr;

    for(int i = 0; i < num_cols; i++) {
        for(int j = 0; j < num_rows; j++) {
            Piece* piece = new Piece(FLAT, ONE_OUTLET, FLAT, ONE_INLET);
            piece->absx = j;
            piece->absy = i;
            piece->gridx = j;
            piece->gridy = i;

            piece->x = double(j) / num_rows;
            piece->y = double(i) / num_cols;

            piece->ux = double(j) / num_rows;
            piece->uy = double(i) / num_cols;
            piece->width = 1.0 / num_rows;
            piece->height = 1.0 / num_cols;
            piece->rotation = 0;
            piece->rows = num_rows;
            piece->cols = num_cols;

            int rand = std::rand()%4;

            for(int i = 0; i < rand; i++) {
                piece->rotate(RIGHT_ROT);
            }

            this->board.push_back(piece);
        }
        
    }
}
Board::~Board() {}

void Board::step() {
    this->plotter->getPlotter()->getMouseLocation(mousex, mousey);
    clicked = this->plotter->getPlotter()->mouseClick();
    if(clicked) this->plotter->getPlotter()->getMouseClick();
    double screenx = double(mousex) / plotter->WIDTH;
    double screeny = double(mousey) / plotter->HEIGHT;
    //as long as it is not null
    if(this->selected != nullptr) {
        this->selected->x = screenx;
        this->selected->y = screeny;

        char key = this->plotter->getPlotter()->getKey();
        if(key == RIGHT_ARROW) {
            this->selected->rotate(RIGHT_ROT);
        }
        else if(key == LEFT_ARROW) {
            this->selected->rotate(LEFT_ROT);
        }
    }

    if(clicked && this->selected == nullptr) {
        grab(mousex, mousey);
    }
    else if(clicked) {
        this->selected->setGrid();
        bool collision = false;
        for(Piece* p : this->board) {
            if(p != this->selected) {
                if(p->isAdjacent(this->selected)) {
                    cout << "esta: " << this->selected->gridx << " - " << this->selected->gridy << endl;
                    cout << "esa:  " << p->gridx << " - " << p->gridy << endl;
                    if(!p->canInterlock(this->selected)) {
                        collision = true;
                        break;
                    }
                }
            }
        }
        if(!collision) {
            this->selected->isSelected = false;
            this->selected = nullptr;
        }
    }

    clicked = false;
}
void Board::draw() {
    for(Piece* p : this->board) {
        if(p != this->selected) p->drawSelf(texture, plotter);
    }
    if(this->selected != nullptr) this->selected->drawSelf(texture, plotter);
}

void Board::grab(int mousex, int mousey) {
    double screenx = double(mousex) / plotter->WIDTH;
    double screeny = double(mousey) / plotter->HEIGHT;

    double dist = INFINITY;

    this->selected = nullptr;

    for(Piece* p : this->board) {
        p->isSelected = false;
        double dx = p->x - screenx;
        double dy = p->y - screeny;
        double d = dx*dx + dy*dy;
        if(d < dist) {
            dist = d;
            this->selected = p;
        }
    }

    this->selected->isSelected = true;
}