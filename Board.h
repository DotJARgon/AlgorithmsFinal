//
// Created by Marcelo on 4/23/2023.
//

#ifndef FINALPROJECT_BOARD_H
#define FINALPROJECT_BOARD_H


#include "Texture.h"
#include "PlotterTexture.h"
#include "Piece.h"

class Board {
private:
    PlotterTexture* plotter;
    Texture* texture;
    int num_rows, num_cols;
    //double array of pieces, note, must cleanup eventually
    //x by y will be the coordinates
    vector<vector<Piece>> board;
    Piece* selected;
public:
    Board(int num_rows, int num_cols, PlotterTexture* plotter, Texture* texture);
    void grab(int mousex, int mousey);
    void step(int mousex, int mousey);
    void draw();
    ~Board();
};


#endif //FINALPROJECT_BOARD_H
