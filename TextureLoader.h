//
// Created by Marcelo on 1/19/2023.
//
#include <string>
#include <fstream>
#include "TextureBuffer.h"

using namespace std;

#ifndef FINALPROJECT_IMAGELOADER_H
#define FINALPROJECT_IMAGELOADER_H

class TextureLoader {
public:
    //class must be of type TextureBuffer
    template<class T>
    static T* loadImage(string filename) {
        ifstream in;
        in.open(filename);

        if(!in) return nullptr;
        int width, height;
        in >> height >> width;
        in.get();

        int* data = new int[width*height];

        //string line;
        int i = 0;
        while(!in.eof()) {
            int r, g, b;
            in >> r >> g >> b;
            int argb = (r << 16) | (g << 8) | b;
            data[i++] = argb;
        }

        in.close();

        T* t = new T(width, height);
        reinterpret_cast<TextureBuffer*>(t)->replaceData(data);
        return t;
    }

    template<class T>
    static T* test(int width, int height) {
        int* data = new int[width*height];
        for(int i = 0; i < width; i++) {

            for(int j = 0; j < height; j++) {
                data[j * width + i] = ((i+j)%2)*255;
                //cout << data[j * width + i] << endl;
            }
        }

        T* t = new T(width, height);
        reinterpret_cast<TextureBuffer*>(t)->replaceData(data);
        return t;
    }
    template<class T>
    static T* test2(int width, int height) {
        int* data = new int[width*height];
        for(int i = 0; i < width; i++) {

            for(int j = 0; j < height; j++) {
                data[j * width + i] = (((i/2+j/2))%2)*255;
                //cout << data[j * width + i] << endl;
            }
        }

        T* t = new T(width, height);
        reinterpret_cast<TextureBuffer*>(t)->replaceData(data);
        return t;
    }

    template<class T>
    static T* loadAtlas(string filename) {
        ifstream in;
        in.open(filename);

        if(!in) return nullptr;
        int width, height;
        in >> width >> height;
        in.get();

        int* data = new int[width*height];

        string line;
        int i = 0;
        while(getline(in, line)) {
            int argb = stoi(line);
            data[i++] = argb;
        }

        in.close();

        T* t = new T(width, height);
        reinterpret_cast<TextureBuffer*>(t)->replaceData(data);
        return t;
    }
};

#endif //FINALPROJECT_IMAGELOADER_H
