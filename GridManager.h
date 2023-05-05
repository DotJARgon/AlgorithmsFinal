/*
* Author: Team Team (Tristan Brown, Marcelo Carpenter, Thomas Cho,
*          Joshua Linnett, Aaron Mendoza, Harrison Williams)
* Assignment Title: Jigsaw Puzzle Group Project
* Assignment Description: This is GridManager .h file
* Due Date: 5/4/2023
* Date Created: 4/27/2023
* Date Last Modified: 5/4/2023
 */
#ifndef FINALPROJECT_GRIDMANAGER_H
#define FINALPROJECT_GRIDMANAGER_H


#include "TextureBuffer.h"
#include <cstring>

enum Alignment {
    LEFT, CENTER, RIGHT
};

struct Grid {
private:
    bool keepAspectRatio = false;
    Alignment alignment = CENTER;
    
    double w = 0;
    double h = 0;

    double x = 0;
    double y = 0;

    TextureBuffer* buffer = nullptr;
public:
    /*
     * description: These are getters/setters of Grid class
     * return:
     * precondition:
     * postcondition:
     */
    void setAspectRatio(bool aspect);
    void setAlignment(Alignment alignment);

    bool getAspectRatio();
    Alignment getAlignment();

    void setWidth(double w);
    void setHeight(double h);

    void setX(double x);
    void setY(double y);

    double getWidth();
    double getHeight();

    double getX();
    double getY();

    void setBuffer(TextureBuffer* buffer);
    TextureBuffer* getBuffer();
};

class GridManager : private TextureBuffer {
private:
    Grid** grid = nullptr;
    double* columnWidths = nullptr;
    double* rowHeights = nullptr;

    TextureBuffer* backBuffer;

    bool updated = false;
    
    int columns = 0;
    int rows = 0;
public:
    /*
     * description: This is GridManager constructor
     *
     * return: void
     * precondition: Input arguments are valid
     * postcondition: GridManager instance is created
     */
    GridManager(int bufferW, int bufferH, int columns, int rows) : TextureBuffer(0, 0) {
        this->columns = columns;
        this->rows = rows;

        this->grid = new Grid*[this->rows];
        for(int i = 0; i < this->rows; i++) {
            this->grid[i] = new Grid[this->columns];
        }

        this->columnWidths = new double[this->columns];
        this->rowHeights   = new double[this->rows];

        for(int i = 0; i < this->columns; i++) this->columnWidths[i] = 1.0;
        for(int i = 0; i < this->rows; i++) this->rowHeights[i] = 1.0;

/*
        for(int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns; j++) {
                this->grid[i][j].setWidth(1.0 / this->columns);
                this->grid[i][j].setHeight(1.0 / this->rows);
            }
        }*/

        this->updated = true;

        this->update();
    }
    /*
     * description: GridManager Destructor
     * return: void
     * precondition:
     * postcondition:
     */
    ~GridManager();
/*
     * description: This plots grid and input texture to desired coordinate
     * return: void
     * precondition: all input arguments are valid
     * postcondition: input texture is plotted in corresponding coordinate
     */
    void plot(TextureBuffer* textureBuffer, int x, int y, double scaleX, double scaleY, double ux1, double uy1, double ux2, double uy2, double rot = 0.0);
    /*
     * description: This plots grid and input texture to desired coordinate
     * return: void
     * precondition: all input arguments are valid
     * postcondition: input texture is plotted in corresponding coordinate
     */
    void plot(TextureBuffer* textureBuffer, double x, double y, double w, double h);

    /*
     * description: replaces data with input argument
     * return: void
     * precondition: input data is valid type and not null
     * postcondition: data value is replaced with input argument
     */
    void replaceData(int* data);
    /*
     * description: This copies this->data into argument data
     * return: void
     * precondition: argument and this->data match in type
     * postcondition: argument data is updated with this->data
     */
    void copyData(int* data);

    /*
     * description: This clears grid at input argument (RGB)
     * return: void
     * precondition: input is valid argument
     * postcondition: grid at input is cleared
     */
    void clear(int argb);
    /*
     * description: writes at input (X,Y) coordinate with input RGB
     * return: void
     * precondition: input argument are valid numerical values
     * postcondition: input RGB is written at input coordinate
     */
    void writePixel(int x, int y, int argb);
    /*
     * description: Getter for pixel data at input coordinate
     * return: int
     * precondition: input coordinates are valid
     * postcondition: corresponding RGB value in int is returned
     */
    int getPixel(int x, int y);

    /*
     * description: this changes column width data with input width
     * return: void
     * precondition: input values are valid width is not negative
     * postcondition: column width is updated
     */
    void changeColumnWidth(int column, double width);
    /*
     * description: this changes row height data with input height
     * return: void
     * precondition: input values are valid height is not negative
     * postcondition: row height is updated
     */
    void changeRowHeight(int row, double height);
    /*
     * description: this is setter for Grid element with texture buffer
     * return: void
     * precondition: input values are valid; TextureBuffer is not null
     * postcondition: grid element is updated
     */
    void setGridElement(int row, int column, TextureBuffer* textureBuffer);
    /*
     * description: updates height and width of grid element
     * return: void
     * precondition: grid is not null
     * postcondition: grid height and width is updated
     */
    void update();

};


#endif //FINALPROJECT_GRIDMANAGER_H
