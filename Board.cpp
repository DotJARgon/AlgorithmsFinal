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
            Piece* piece = new Piece(FLAT, FLAT, FLAT, FLAT);
            piece->absx = i;
            piece->absy = j;
            piece->gridx = i;
            piece->gridy = j;

            piece->x = double(i) / num_rows;
            piece->y = double(j) / num_cols;

            piece->ux = double(i) / num_rows;
            piece->uy = double(j) / num_cols;
            piece->width = 1.0 / num_rows;
            piece->height = 1.0 / num_cols;
            piece->rotation = 0;
            piece->rows = num_rows;
            piece->cols = num_cols;

            int rand = std::rand()%4;
            cout << rand << endl;

            for(int i = 0; i < rand; i++) {
                piece->rotate(RIGHT_ROT);
            }

            this->board.push_back(piece);
        }
        
    }
}
Board::~Board() {}

void Board::step() {
    int x = 0;
    int y = 0;
    this->plotter->getPlotter()->getMouseLocation(mousex, mousey);
    clicked |= this->plotter->getPlotter()->getMouseClick(x, y);
    double screenx = double(mousex) / plotter->WIDTH;
    double screeny = double(mousey) / plotter->HEIGHT;
    //as long as it is not null
    if(this->selected != nullptr) {
        this->selected->x = screenx;
        this->selected->y = screeny;

        if(this->plotter->getPlotter()->kbhit()) {
            if(this->plotter->getPlotter()->getKey() == RIGHT_ARROW) {
                this->selected->rotate(RIGHT_ROT);
            }
            else if(this->plotter->getPlotter()->getKey() == LEFT_ARROW) {
                this->selected->rotate(LEFT_ROT);
            }
        }
    }

    if(clicked) cout << "is clicked: " << std::chrono::system_clock::now().time_since_epoch().count() << endl;
    if(clicked && this->selected == nullptr) {
        grab(mousex, mousey);
    }
    else if(clicked) {
        this->selected->setGrid();
        this->selected->isSelected = false;
        this->selected = nullptr;
        /*for(int i = 0; i < this->board.size(); i++) {
            if(!this->board.at(i)->isSelected) {

            }
        }*/
    }

    clicked = false;
}
void Board::draw() {
    int x, y;
    for(Piece* p : this->board) {
        if(this->selected) {
            if(this->plotter->getPlotter()->kbhit()) {
                if(this->plotter->getPlotter()->getKey() == RIGHT_ARROW) {
                    this->selected->rotate(RIGHT_ROT);
                }
                else if(this->plotter->getPlotter()->getKey() == LEFT_ARROW) {
                    this->selected->rotate(LEFT_ROT);
                }
            }
        }
        this->plotter->getPlotter()->getMouseLocation(mousex, mousey);
        clicked |= this->plotter->getPlotter()->getMouseClick(x, y);
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