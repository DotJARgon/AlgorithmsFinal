/*
* Author: Team Team (Tristan Brown, Marcelo Carpenter, Thomas Cho,
*          Joshua Linnett, Aaron Mendoza, Harrison Williams)
* Assignment Title: Jigsaw Puzzle Group Project
* Assignment Description: This is board class implementation file
* Due Date: 5/4/2023
* Date Created: 4/27/2023
* Date Last Modified: 5/4/2023
 */

#ifndef FINALPROJECT_BOARD_H
#define FINALPROJECT_BOARD_H


#include "Texture.h"
#include "PlotterTexture.h"
#include "Piece.h"
#include "SoundHandler.h"

class Board {
private:
    PlotterTexture* plotter;
    PieceTexture* texture;
    SoundHandler* soundHandler;
    Texture* background;
    int num_rows, num_cols;
    //double array of pieces, note, must cleanup eventually
    //x by y will be the coordinates
    vector<Piece*> board;
    Piece* selected;
    int mousex;
    int mousey;
    bool clicked;
    bool winState;
public:
    /*
     * description: This is Board constructor; This will generate fundamental layer of
     *              puzzle game in provided dimensions, plotter, texture, and sounds
     * return: void
     * precondition: dimension values are positive, plotter and texture and soundHandler pointers
     *               are valid
     * postcondition: Board layer is generated
     */
    Board(int num_rows, int num_cols, PlotterTexture* plotter, PieceTexture* texture, SoundHandler* soundHandler);
    /*
     * description: ActionHandler for mouse input that handles picking up piece
     * return: void
     * precondition: mouse input is valid
     * postcondition: corresponding action is performed
     */
    void grab(int mousex, int mousey);
    /*
     * description: ActionHandler for mouse inputs
     * return: void
     * precondition: mouse is clicked
     * postcondition: corresponding action is performed
     */
    void step();
    /*
     * description: Populates board layer with plots and texture
     * return: void
     * precondition: board is valid
     * postcondition: board is populated with texture and plotter
     */
    void draw();
    /*
     * description: validates winning scenario.
     * return: bool
     * precondition: program is running && no edges are held
     * postcondition: ends the gaming process and display/play winning effects
     */
    bool checkWin();
    /*
     * description: Board Destructor
     * return: void
     * precondition:
     * postcondition:
     */
    bool getWinState();

    ~Board();
};


#endif //FINALPROJECT_BOARD_H
