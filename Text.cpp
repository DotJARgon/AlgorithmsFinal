/*
Author: Joshua Linnett
Assignment Title: Group Project
Assignment Description: Puzzle game
Due Date: 5/4/2023
Date Created: 5/3/2023
Date Last Modified: 5/4/2023

*/

#include "Text.h"

void initText(int a[][10][7]){

    int row, col, num;
    ifstream file;
    string fileName;
    string sentence = "abcdefghijklmnopqrstuvwxyz0123456789_";

    for (int i = 0; i < sentence.size(); i++){

        fileName = toupper(sentence[i]);
        fileName = fileName + ".txt";
        file.open(fileName);

        file >> col >> row;

        for(int y = 0; y < row; y++){
            for(int x = 0; x < col; x++){
                file >> num;

                a[i][y][x] = num;
            }
        }
        file.close();
    }


}

void displayText(string sentence, int space ,int offX ,int offY, int size, int R, int G, int B, SDL_Plotter& g, int a[][10][7]){


    int row = 10, col = 7, num, character;
    string fileName;
    int spaceOffset;

    for (int i = 0; i < sentence.size(); i++){
        //finds correct ASCII position for each character
        if (isalpha( sentence.at(i) )){
            character = sentence.at(i) - 'A';
        }
        else if (isdigit( sentence.at(i))) {
            character = sentence.at(i) - 22;
        }
        // '' is used to create spaces
        else if(sentence.at(i) == '_') {
            character = 38;
        }

        spaceOffset = space * i;

        for(int y = 0; y < row; y++){
            for(int x = 0; x < col; x++){
                num = a[character][y][x];
                //print square
                if(num == 1){
                    for(int i = 0; i < size; i++){
                        for(int j = 0; j < size; j++){
                            g.plotPixel(offX + x * size + i + spaceOffset, offY + y*size + j ,R,G,B);
                        }
                    }
                }
            }
        }
    }
}
