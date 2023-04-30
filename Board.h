//
// Created by Marcelo on 4/23/2023.
//

#ifndef FINALPROJECT_BOARD_H
#define FINALPROJECT_BOARD_H


#include "Texture.h"
#include "PlotterTexture.h"
#include "Piece.h"
#include "SoundHandler.h"

class Board {
private:
    PlotterTexture* plotter;
    Texture* texture;
    SoundHandler* soundHandler;
    int num_rows, num_cols;
    //double array of pieces, note, must cleanup eventually
    //x by y will be the coordinates
    vector<Piece*> board;
    Piece* selected;
    int mousex;
    int mousey;
    bool clicked;
public:
    Board(int num_rows, int num_cols, PlotterTexture* plotter, Texture* texture, SoundHandler* soundHandler);
    void grab(int mousex, int mousey);
    void step();
    void draw();
    ~Board();
};


#endif //FINALPROJECT_BOARD_H
