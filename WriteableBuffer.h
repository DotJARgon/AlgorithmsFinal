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

#ifndef FINALPROJECT_WRITEABLEBUFFER_H
#define FINALPROJECT_WRITEABLEBUFFER_H


class WriteableBuffer {
public:
    /*
    * description: writes a pixel   
    * return: void                                          
    * precondition: x and y coordinate exist along with rgb value                           
    * postcondition: pixel is written                                                                          
    */
    virtual void writePixel(int x, int y, int argb) = 0;

    /*
    * description: clears a pixel 
    * return: void                                          
    * precondition: clears a rgb value                         
    * postcondition: pixel is cleared                                                                         
    */
    virtual void clear(int argb) = 0;

    /*
    * description: gets a pixel's x-y coordinate 
    * return: int                                          
    * precondition: x and y coordinate exist                          
    * postcondition: pixel location                                                                      
    */
    virtual int getPixel(int x, int y) = 0;
};


#endif //FINALPROJECT_WRITEABLEBUFFER_H
