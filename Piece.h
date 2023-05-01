/*
* Authors: Tristan Brown, Marcelo Carpenter, Thomas Cho,
*          Joshua Linnett, Aaron Mendoza, Harrison Williams
* Assignment Title: Jigsaw Puzzles Epic
* Assignment Description: This program allows users to solve a puzzle using
*                         their own images.
* Due Date: 5/2/2023
* Date Created: 4/22/2023
* Date Last Modified: 4/30/2023
*/

#ifndef FINALPROJECT_PIECE_H
#define FINALPROJECT_PIECE_H


class PieceTexture;

#include <vector>
#include <cmath>
#include "Rotate.h"
#include "Edge.h"
#include "Texture.h"
#include "PieceTexture.h"
#include "PlotterTexture.h"

using namespace std;

class Piece {
private:
    /*
     * description: updates the adjacent Piece pointers in a clockwise
     *              direction. top->right, right->bottom, bottom->left, and
     *              left->top
     * return: void
     * precondition: all Edge pointers are valid
     * postcondition: all Edge pointers have been reassigned
     */
    void rotateEdgesRight();

    /*
     * description: updates the adjacent Piece pointers in a counter clockwise
     *              direction. top->left, left->bottom, bottom->right, and
     *              right->top
     * return: void
     * precondition: all Edge pointers are valid
     * postcondition: all Edge pointers have been reassigned
     */
    void rotateEdgesLeft();

public:
    bool isSelected;
    int rotation;
    Edge left, top, right, bottom;
    int absx, absy;
    int gridx, gridy;
    int rows, cols;
    double x, y;
    double width, height;
    double ux, uy;


    /*
     * description: constructs a Piece object and sets default values for
     *              all variables contained within it
     * return: none
     * precondition: all Edges passed as parameters are valid
     * postcondition: all default variables are set and all Edges are set
     *                  equal to the appropriate passed parameters
     */
    Piece(Edge left, Edge top, Edge right, Edge bottom);

    /*
     * description: rotates the section of the original image
     * return: void
     * precondition: Rotate rotation is valid
     * postcondition: the image is rotated
     */
    void rotate(Rotate rotation);

    /*
     * description: determines if two pieces are adjacent to each other in the
     *              graphical interface
     * return: bool, true if adjacent
     * precondition: piece parameter is valid
     * postcondition: none
     */
    bool isAdjacent(Piece* piece);

    /*
     * description: determines if two pieces are oriented in the same direction
     *              and are adjacent on their appropriate sides to interlock
     * return: bool, true if able to interlock
     * precondition: piece parameter is valid
     * postcondition: none
     */
    bool canInterlock(Piece* piece);

    /*
     * description: determines if two pieces are intended to be next to each
     *              other
     * return: bool, true if neighbors
     * precondition: piece parameter is valid
     * postcondition: none
     */
    bool areNeighbors(Piece* piece);

    /*
     * description: determines the x and y coordinates from the original image
     *              that the specific Piece object will be responsible for
     * return: void
     * precondition: none
     * postcondition: gridx and gridy are set
     */
    void setGrid();


    /*
     * description: displays the portion of the original image that the Piece
     *              object pertains to as determined by setGrid
     * return: void
     * precondition: texture and screen parameters are valid
     * postcondition: the portion of the original image is drawn to the screen
     */
    void drawSelf(PieceTexture* texture, PlotterTexture* screen);
};


#endif //FINALPROJECT_PIECE_H
