//
// Created by Marcelo on 4/30/2023.
//

#include "PieceTexture.h"

void PieceTexture::plot(Piece* p, TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY, double ux1, double uy1, double ux2, double uy2, double rot, bool lighten) {
    double cos_rot = cos(rot);
    double sin_rot = sin(rot);

    for(int i = 0; i < this->WIDTH * scaleX; i++) {
        for(int j = 0; j < this->HEIGHT * scaleY; j++) {
            double sx = ((i / scaleX)*(ux2 - ux1)) + this->WIDTH*ux1;
            double sy = ((j / scaleY)*(uy2 - uy1)) + this->HEIGHT*uy1;

            int argb = this->getPixel(sx, sy);
            if(!(argb&0xff000000)) {
                double nx = i - this->WIDTH*scaleX*0.5;
                double ny = j - this->HEIGHT*scaleY*0.5;

                int x_pos = nx*cos_rot - ny*sin_rot + x;
                int y_pos = nx*sin_rot + ny*cos_rot + y;

                if(lighten) {
                    int r = ((((argb&0xff0000) >> 16) + 255)/2) & 0xff;
                    int g = ((((argb&0xff00) >> 8) + 255) / 2) & 0xff;
                    int b = (((argb&0xff) + 255) / 2) & 0xff;

                    argb = (r<<16) | (g << 8) | b;
                }

                if(p->right == ONE_INLET) {
                    double dx = this->WIDTH*scaleX*0.5 - (x_pos - x);
                    double dy = y_pos - y;
                    if(dx*dx + dy*dy > this->WIDTH*0.5) textureBuffer->writePixel(x_pos, y_pos, argb);
                }
                else if(p->left == ONE_INLET) {
                    double dx = (x_pos - x) + this->WIDTH*scaleX*0.5;
                    double dy = y_pos - y;
                    if(dx*dx + dy*dy > this->WIDTH*0.5) textureBuffer->writePixel(x_pos, y_pos, argb);
                }
                else if(p->bottom == ONE_INLET) {
                    double dx = x_pos - x;
                    double dy = this->HEIGHT*scaleY*0.5 - (y_pos - y);
                    if(dx*dx + dy*dy > this->HEIGHT*0.5) textureBuffer->writePixel(x_pos, y_pos, argb);
                }
                else if(p->top == ONE_INLET) {
                    double dx = x_pos - x;
                    double dy = (y_pos - y) + this->HEIGHT*scaleY*0.5;
                    if(dx*dx + dy*dy > this->HEIGHT*0.5) textureBuffer->writePixel(x_pos, y_pos, argb);
                }
                else textureBuffer->writePixel(x_pos, y_pos, argb);
            }
        }

        if(p->top == ONE_OUTLET) {

            for(int i = 0; i < this->WIDTH * scaleX * 0.5; i++) {
                for(int j = 0; j < this->HEIGHT * scaleY * 0.5; j++) {
                    double x_pos = i - this->WIDTH * scaleX * 0.5 + x;
                    double y_pos = j - this->HEIGHT * scaleY * 0.5 + y;
                    double dx = x_pos - x;
                    double dy = y_pos - y;
                    if(dx*dx + dy*dy < this->WIDTH*0.25) {
                        textureBuffer->writePixel(x_pos, y_pos, 0);
                    }
                }
            }
        }
    }
}