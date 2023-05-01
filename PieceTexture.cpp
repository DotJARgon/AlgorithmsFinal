//
// Created by Marcelo on 4/30/2023.
//

#include "PieceTexture.h"

void PieceTexture::plot(Piece* p, TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY, double ux1, double uy1, double ux2, double uy2, double rot, bool lighten) {

    double r = 0.01;

    double cos_rot = cos(rot);
    double sin_rot = sin(rot);

    for(int i = 0; i < this->WIDTH * scaleX * 1.5; i++) {
        for(int j = 0; j < this->HEIGHT * scaleY * 1.5; j++) {
            double sx = ((i / (scaleX))*(ux2 - ux1)) + this->WIDTH*ux1 - this->WIDTH*(ux2-ux1)*0.25;
            double sy = ((j / (scaleY))*(uy2 - uy1)) + this->HEIGHT*uy1 - this->HEIGHT*(uy2-uy1)*0.25;

            int argb = this->getPixel(sx, sy);
            if(!(argb&0xff000000)) {
                double nx = i - this->WIDTH*scaleX*1.5*0.5;
                double ny = j - this->HEIGHT*scaleY*1.5*0.5;

                int x_pos = nx*cos_rot - ny*sin_rot + x;
                int y_pos = nx*sin_rot + ny*cos_rot + y;

                if(lighten) {
                    int r = ((((argb&0xff0000) >> 16) + 255)/2) & 0xff;
                    int g = ((((argb&0xff00) >> 8) + 255) / 2) & 0xff;
                    int b = (((argb&0xff) + 255) / 2) & 0xff;

                    argb = (r<<16) | (g << 8) | b;
                }

                double xp = (x_pos - x) / (this->WIDTH * scaleX);
                double yp = (y_pos - y) / (this->HEIGHT * scaleY);

                //parts to draw
                if(p->right == ONE_OUTLET) {
                    double dx = xp-0.5;
                    double dy = yp;
                    if(dx*dx + dy*dy < r) {
                        textureBuffer->writePixel(x_pos, y_pos, argb);
                        continue;
                    }
                }
                if(p->left == ONE_OUTLET) {
                    double dx = xp+0.5;
                    double dy = yp;
                    if(dx*dx + dy*dy < r) {
                        textureBuffer->writePixel(x_pos, y_pos, argb);
                        continue;
                    }
                }
                if(p->bottom == ONE_OUTLET) {
                    double dx = xp;
                    double dy = yp - 0.5;
                    if(dx*dx + dy*dy < r) {
                        textureBuffer->writePixel(x_pos, y_pos, argb);
                        continue;
                    }
                }
                if(p->top == ONE_OUTLET) {
                    double dx = xp;
                    double dy = yp + 0.5;
                    if(dx*dx + dy*dy < r) {
                        textureBuffer->writePixel(x_pos, y_pos, argb);
                        continue;
                    }
                }

                //parts not to draw
                if(p->right == ONE_INLET) {
                    double dx = xp-0.5;
                    double dy = yp;
                    if(dx*dx + dy*dy < r) continue;
                }
                if(p->left == ONE_INLET) {
                    double dx = xp+0.5;
                    double dy = yp;
                    if(dx*dx + dy*dy < r) continue;
                }
                if(p->bottom == ONE_INLET) {
                    double dx = xp;
                    double dy = yp - 0.5;
                    if(dx*dx + dy*dy < r) continue;
                }
                if(p->top == ONE_INLET) {
                    double dx = xp;
                    double dy = yp + 0.5;
                    if(dx*dx + dy*dy < r) continue;
                }

                //exclude extra
                if(!(xp < -0.5 || xp > 0.5 || yp < -0.5 || yp > 0.5)) {
                    textureBuffer->writePixel(x_pos, y_pos, argb);
                }
            }
        }
    }
}