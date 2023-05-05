/*
Author: Joshua Linnett
Assignment Title: Group Project
Assignment Description: Puzzle game
Due Date: 5/4/2023
Date Created: 5/3/2023
Date Last Modified: 5/4/2023

*/

#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include "SDL_Plotter.h"


using namespace std;

// description:
//    fills a three dimensional array with the points used to display text
// return: void
// precondition:
//    a three dimensional integer array is created
// postcondition:
//    all data has been inputted into the array
void initText(int a[][10][7]);

// description:
//    displays text to the screen using SDL plotter
// return: void
// precondition:
//    a three dimensional array has been assigned points correctly using initText()
//    a SDL_PLOTTER is initialized
//    a string sentence is created
//    7 integers are created to customize display
// postcondition:
//    all data has been inputted into the array
void displayText(string sentence, int offX, int offY,int space, int size, int R, int G, int B, SDL_Plotter&, int a[][10][7]);

#endif // TEXT_H_INCLUDED
