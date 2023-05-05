/*
* Author: Team Team (Tristan Brown, Marcelo Carpenter, Thomas Cho,
*          Joshua Linnett, Aaron Mendoza, Harrison Williams)
* Assignment Title: Jigsaw Puzzle Group Project
* Assignment Description: This is input handler for input events using SDL library
* Due Date: 5/4/2023
* Date Created: 4/27/2023
* Date Last Modified: 5/4/2023
 */
#include "TextureBuffer.h"
#include "SDL_Plotter.h"

#ifndef FINALPROJECT_PLOTTERTEXTURE_H
#define FINALPROJECT_PLOTTERTEXTURE_H


class PlotterTexture : public TextureBuffer {
public:
    /*
 * description: PlotterTexture constructor
 * return:
 * precondition: Input arguments are valid
 * postcondition: PlotterTexture constructor is created
 */
    PlotterTexture(SDL_Plotter* plotter) : TextureBuffer(plotter->getCol(), plotter->getRow()) {
        this->plotter = plotter;
    }
    /*
 * description: PieceTexture destructor
 * return:
 * precondition:
 * postcondition:
 */
    ~PlotterTexture() {}
    /*
    * description: plots texture to destination
    * return: void
    * precondition: input arguments are valid
    * postcondition: target object is updated with texture
    */
    void plot(TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY, double ux1, double uy1, double ux2, double uy2, double rot = 0.0, bool lighten = false);
    /*
    * description: plots texture to destination
    * return: void
    * precondition: input arguments are valid
    * postcondition: target object is updated with texture
    */
    void plot(TextureBuffer* textureBuffer, double x, double y, double w, double h);
    /*
    * description: replaces RGB data with input
    * return: void
    * precondition: input arguments are valid
    * postcondition: target object is replaced with argument RGB value
    */
    void replaceData(int* data);
    /*
    * description: copies this->RGB data into argument
    * return: void
    * precondition: input data is initialized
    * postcondition: target object is updated with new RGB value
    */
    void copyData(int* data);
    /*
    * description: clears data's RGB
    * return: void
    * precondition: input arguments are valid
    * postcondition: target object RGB value is cleared
    */
    void clear(int argb);
    /*
    * description: writes input RGB value to target coordinate
    * return: void
    * precondition: input arguments are valid
    * postcondition: RGB written at target coordinate on grid
    */
    void writePixel(int x, int y, int argb);
    /*
    * description: gets pixel value at given coordinate
    * return: int
    * precondition: input arguments are valid location
    * postcondition: target pixel value returned
    */
    int getPixel(int x, int y);
    /*
    * description: getter for Plotter
    * return: SDL_Plotter*
    * precondition: SDL_Plotter properly setup
    * postcondition: Plotter data returned
    */
    SDL_Plotter* getPlotter();
private:
    SDL_Plotter* plotter;
};


#endif //FINALPROJECT_PLOTTERTEXTURE_H
