/*
* Authors: Tristan Brown, Marcelo Carpenter, Thomas Cho, 
*          Joshua Linnett, Aaron Mendoza, Harrison Williams
* Assignment Title: Jigsaw Puzzles Epic
* Assignment Description: This program allows users to solve a puzzle using
*                         their own images.
* Due Date: 5/02/2023
* Date Created: 1/26/2023
* Date Last Modified: 4/27/2023
*/

#ifndef FINALPROJECT_TEXTATLAS_H
#define FINALPROJECT_TEXTATLAS_H


#include "TextureBuffer.h"

class TextAtlas : public TextureBuffer {
private:
    int textColor;
    int textWidth;
public:
    /*
    * description: TextAtlas constructor
    * return: void                                          
    * precondition: width and height are given                           
    * postcondition: data, text color, and text width of a TextAtlas
    *                object is set                                                                
    */
    TextAtlas(int width, int height) : TextureBuffer(width, height) {
        this->data = new int[WIDTH*HEIGHT];
        this->textColor = 0xff00ff;
        this->textWidth = 128;
    }

    /*
    * description: Texture destructor
    * return: void                                          
    * precondition: TextAtlas object exists                          
    * postcondition: TextAtlas object is deallocated                                                               
    */
    ~TextAtlas();

    /*
    * description: plots a TextureBuffer with certain qualities
    * return: void                                          
    * precondition: necessary parameters are given including scaling
    *               and rotation                         
    * postcondition: TextureBuffer object is plotted with the parameters
    *                given                                                                       
    */
    void plot(TextureBuffer* textureBuffer, int x, int y, 
        double scaleX, double scaleY, double ux1, double uy1, double ux2, 
        double uy2, double rot = 0.0);
    
    /*
    * description: plots a TextureBuffer at a certain location
    * return: void                                          
    * precondition: x-y coordinate along with width and height are
    *               given                          
    * postcondition: TextureBuffer object is created at the x-y
    *                coordinate with the specified width and height                                                                       
    */ 
    void plot(TextureBuffer* textureBuffer, double x, double y, 
        double w, double h);
    
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
    * description: sets width of the text
    * return: void                                         
    * precondition: width of text is given                        
    * postcondition: text width is set                                                                     
    */
    void setTextWidth(int tw);
};


#endif //FINALPROJECT_TEXTATLAS_H
