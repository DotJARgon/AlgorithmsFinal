//
// Created by Marcelo on 4/23/2023.
//

#include "Board.h"

Board::Board(int num_rows, int num_cols, PlotterTexture* plotter, Texture* texture) {
    this->num_rows = num_rows;
    this->num_cols = num_cols;
    this->plotter = plotter;
    this->texture = texture;

    for(int i = 0; i < num_cols; i++) {
        vector<Piece> column;
        for(int j = 0; j < num_rows; j++) {
            Piece piece(FLAT, FLAT, FLAT, FLAT);
            piece.absx = i;
            piece.absy = i;
            piece.rotation = 0;
            column.push_back(piece);
        }
        this->board.push_back(column);
    }
}

Board::~Board() {

}