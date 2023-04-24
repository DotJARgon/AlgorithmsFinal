//
// Created by Marcelo on 4/23/2023.
//

#include "Board.h"

Board::Board(int num_rows, int num_cols, PlotterTexture* plotter, Texture* texture) {
    this->num_rows = num_rows;
    this->num_cols = num_cols;
    this->plotter = plotter;
    this->texture = texture;

    this->selected = nullptr;

    for(int i = 0; i < num_cols; i++) {
        vector<Piece> column;
        for(int j = 0; j < num_rows; j++) {
            Piece piece(FLAT, FLAT, FLAT, FLAT);
            piece.absx = i;
            piece.absy = j;
            piece.ux = double(i) / num_rows;
            piece.uy = double(j) / num_cols;
            piece.width = 1.0 / num_rows;
            piece.height = 1.0 / num_cols;
            piece.rotation = 0;
            column.push_back(piece);
        }
        this->board.push_back(column);
    }
}
Board::~Board() {}

void Board::step(int mousex, int mousey) {
    double screenx = double(mousex) / plotter->WIDTH;
    double screeny = double(mousey) / plotter->HEIGHT;
    //as long as it is not null
    if(this->selected != nullptr) {
        this->selected->x = screenx;
        this->selected->y = screeny;
    }
    //calc grid coords
    this->selected->setGrid();
}
void Board::draw() {
    for(vector<Piece>& col : this->board) {
        for(Piece& p : col) {
            p.drawSelf(texture, plotter);
        }
    }
}

void Board::grab(int mousex, int mousey) {
    double screenx = double(mousex) / plotter->WIDTH;
    double screeny = double(mousey) / plotter->HEIGHT;

    double dist = INFINITY;

    this->selected = nullptr;

    for(vector<Piece> col : this->board) {
        for(int i = 0; i < col.size(); i++) {
            Piece& p = col.at(i);
            p.isSelected = false;
            double dx = p.x - screenx;
            double dy = p.y - screeny;
            double d = dx*dx + dy*dy;
            if(d < dist) {
                dist = d;
                this->selected = &col.at(i);
                this->selected->isSelected = true;
            }
        }
    }
}