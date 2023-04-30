//
// Created by Marcelo on 4/30/2023.
//

#ifndef FINALPROJECT_PIECETEXTURE_H
#define FINALPROJECT_PIECETEXTURE_H

class Piece;

#include "Texture.h"
#include "Piece.h"

class PieceTexture : public Texture {
public:
    PieceTexture(int width, int height) : Texture(width, height) {
    }
    void plot(Piece* p, TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY,
              double ux1, double uy1,
              double ux2, double uy2,
              double rot = 0.0, bool lighten = false);
};


#endif //FINALPROJECT_PIECETEXTURE_H
