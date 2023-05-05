/*
* Author: Team Team (Tristan Brown, Marcelo Carpenter, Thomas Cho,
*          Joshua Linnett, Aaron Mendoza, Harrison Williams)
* Assignment Title: Jigsaw Puzzle Group Project
* Assignment Description: This is input handler for input events using SDL library
* Due Date: 5/4/2023
* Date Created: 4/27/2023
* Date Last Modified: 5/4/2023
 */

#ifndef FINALPROJECT_PIECETEXTURE_H
#define FINALPROJECT_PIECETEXTURE_H

class Piece;

#include "Texture.h"
#include "Piece.h"

class PieceTexture : public Texture {
public:
    /*
 * description: PieceTexture constructor
 * return:
 * precondition:
 * postcondition:
 */
    PieceTexture(int width, int height) : Texture(width, height) {
    }
    /*
 * description: plots texture to piece
 * return: void
 * precondition: input arguments are valid
 * postcondition: piece object is updated with texture
 */
    void plot(Piece* p, TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY,
              double ux1, double uy1,
              double ux2, double uy2,
              double rot = 0.0, bool lighten = false);
};


#endif //FINALPROJECT_PIECETEXTURE_H
