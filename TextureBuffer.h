/*
* Authors: Tristan Brown, Marcelo Carpenter, Thomas Cho, 
*          Joshua Linnett, Aaron Mendoza, Harrison Williams
* Assignment Title: Jigsaw Puzzles Epic
* Assignment Description: This program allows users to solve a puzzle using
*                         their own images.
* Due Date: 5/02/2023
* Date Created: 1/19/2023
* Date Last Modified: 4/27/2023
*/

#include "WriteableBuffer.h"

#ifndef FINALPROJECT_TEXTUREBUFFER_H
#define FINALPROJECT_TEXTUREBUFFER_H

class TextureBuffer : public WriteableBuffer {
public:
    const int WIDTH, HEIGHT;

    /*
    * description: TextureBuffer constructor 
    * return: void                                          
    * precondition: width and height are given                          
    * postcondition: TextureBuffer object is created with specified
    *                width and height                                                                        
    */
    TextureBuffer(int width, int height): WIDTH(width), HEIGHT(height) {}

    /*
    * description: plots a TextureBuffer with certain qualities
    * return: void                                          
    * precondition: necessary parameters are given including scaling
    *               and rotation                         
    * postcondition: TextureBuffer object is plotted with the parameters
    *                given                                                                       
    */
    virtual void plot(TextureBuffer* textureBuffer, int x, int y, 
        double scaleX, double scaleY, double ux1, double uy1, 
        double ux2, double uy2, double rot = 0.0) = 0;

    /*
    * description: plots a TextureBuffer at a certain location
    * return: void                                          
    * precondition: x-y coordinate along with width and height are
    *               given                          
    * postcondition: TextureBuffer object is created at the x-y
    *                coordinate with the specified width and height                                                                       
    */    
    virtual void plot(TextureBuffer* textureBuffer, double x, double y, 
        double w, double h) = 0;

    /*
    * description: replaces data of TextureBuffer
    * return: void                                          
    * precondition: data exists                      
    * postcondition: TextureBuffer object data is replaced with new data                                                                    
    */
    virtual void replaceData(int* data) = 0;

    /*
    * description: copies data of TextureBuffer 
    * return: void                                          
    * precondition: data exists                          
    * postcondition: TextureBuffer object data is copied                                                                       
    */
    virtual void copyData(int* data) = 0;

    /*
    * description: clears a pixel 
    * return: void                                          
    * precondition: clears a rgb value                         
    * postcondition: pixel is cleared                                                                         
    */
    virtual void clear(int argb) = 0;

    /*
    * description: writes a pixel   
    * return: void                                          
    * precondition: x and y coordinate exist along with rgb value                           
    * postcondition: pixel is written                                                                          
    */
    virtual void writePixel(int x, int y, int argb) = 0;

    /*
    * description: gets a pixel's x-y coordinate 
    * return: int                                          
    * precondition: x and y coordinate exist                          
    * postcondition: pixel location                                                                      
    */
    virtual int getPixel(int x, int y) = 0;
protected:
    int* data = nullptr;
};

#endif //FINALPROJECT_TEXTUREBUFFER_H
