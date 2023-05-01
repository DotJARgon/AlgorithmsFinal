/*
* Authors: Tristan Brown, Marcelo Carpenter, Thomas Cho, 
*          Joshua Linnett, Aaron Mendoza, Harrison Williams
* Assignment Title: Jigsaw Puzzles Epic
* Assignment Description: This program allows users to solve a puzzle using
*                         their own images.
* Due Date: 5/02/2023
* Date Created: 1/23/2023
* Date Last Modified: 4/27/2023
*/

#include "TextureBuffer.h"

#ifndef FINALPROJECT_TEXTURE_H
#define FINALPROJECT_TEXTURE_H


class Texture : public TextureBuffer {
public:
    /*
    * description: Texture constructor
    * return: void                                          
    * precondition: width and height are given                           
    * postcondition: data of Texture object is allocated with the 
    *                according width and height                                                                 
    */
    Texture(int width, int height) : TextureBuffer(width, height) {
        this->data = new int[WIDTH*HEIGHT];
    }

    /*
    * description: Texture destructor
    * return: void                                          
    * precondition: Texture object exists                         
    * postcondition: Texture object is deallocated                                                                       
    */
    ~Texture();

    /*
    * description: plots a TextureBuffer with certain qualities
    * return: void                                          
    * precondition: necessary parameters are given including scaling
    *               and rotation                         
    * postcondition: TextureBuffer object is plotted with the parameters
    *                given                                                                       
    */
    void plot(TextureBuffer* textureBuffer, int x, int y,
        double scaleX, double scaleY, double ux1, double uy1, 
        double ux2, double uy2, double rot = 0.0, bool lighten = false);

    /*
    * description: plots a TextureBuffer at a certain location
    * return: void                                          
    * precondition: x-y coordinate along with width and height are
    *               given                          
    * postcondition: TextureBuffer object is created at the x-y
    *                coordinate with the specified width and height                                                                       
    */ 
    void plot(TextureBuffer* textureBuffer, double x, double y, double w, double h);

    /*
    * description: replaces data of TextureBuffer
    * return: void                                          
    * precondition: data exists                      
    * postcondition: TextureBuffer object data is replaced with new data                                                                    
    */
    void replaceData(int* data);

    /*
    * description: copies data of TextureBuffer 
    * return: void                                          
    * precondition: data exists                          
    * postcondition: TextureBuffer object data is copied                                                                       
    */
    void copyData(int* data);

    /*
    * description: clears a pixel 
    * return: void                                          
    * precondition: clears a rgb value                         
    * postcondition: pixel is cleared                                                                         
    */
    void clear(int argb);

    /*
    * description: writes a pixel   
    * return: void                                          
    * precondition: x and y coordinate exist along with rgb value                           
    * postcondition: pixel is written                                                                          
    */
    void writePixel(int x, int y, int argb);

    /*
    * description: gets a pixel's x-y coordinate 
    * return: int                                          
    * precondition: x and y coordinate exist                          
    * postcondition: pixel location                                                                      
    */
    int getPixel(int x, int y);

    /*
    * description: sets interpolation mode 
    * return: void                                          
    * precondition: whether or not to interpolate is passed in
    *               as a boolean                          
    * postcondition: interpolate is set to either true or false                                                                     
    */
    void setInterpolationMode(bool inter);
private:
    bool INTERPOLATE = false;
};


#endif //FINALPROJECT_TEXTURE_H
