//
// Created by Admin on 3/16/22.
//


#ifndef PROJECT2_IMAGE_H
#define PROJECT2_IMAGE_H

#include <iostream>
#include <math.h>
#include<string>
#include<vector>
#include <fstream>

using namespace std;

struct Header{
    char idLength = 0;
    char  colorMapType= 0;
    char  dataTypeCode= 2;
    short colorMapOrigin= 0;
    short colorMapLength= 0;
    char  colorMapDepth= 0;
    short xOrigin= 0;
    short yOrigin= 0;
    short width= 0;
    short height= 0;
    char  bitsPerPixel= 24;
    char  imageDescriptor= 0;
    Header() = default;
};

//void Header :: WriteData(const char* fileHeader){

//is it ok to inherit Header for pixels struct because I need to use the width and height from the header

class Image : public Header{
    struct Pixels{

        //data is the bytes value 0-255
        unsigned char data;
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        Pixels(){}
        Pixels(unsigned int r, unsigned int g, unsigned int b){
                 red = r;
                 green = g;
                 blue = b;
        }
    };

public:
    char idLength = 0;
    char  colorMapType= 0;
    char  dataTypeCode= 2;
    short colorMapOrigin= 0;
    short colorMapLength= 0;
    char  colorMapDepth= 0;
    short xOrigin= 0;
    short yOrigin= 0;
    short width= 0;
    short height= 0;
    char  bitsPerPixel= 24;
    char  imageDescriptor= 0;

    Image() = default;
    Image(const short& width, const short& height, vector<Pixels> vectPic){
        this -> width = width;
        this -> height = height;
        this -> pixelObj = vectPic;
    }
     void WriteImage(const char *fileData);
    void Print();
    //static Image ReadImage(const char* fileData);
     void ReadImage(string fileData);

    vector<Pixels> pixelObj;

    bool compare(Image &image);
    void Multiply(Image &firstLayer, Image &secondLayer);
    void Subtract(Image &firstLayer, Image &secondLayer);
    void Screen(Image &firstLayer, Image &secondLayer);
  //  string testScreen(Image &firstLayer, Image &secondLayer, Image&thirdLayer);
    void Overlay(Image &firstLayer, Image &secondLayer);
    void AddToGreen(Image &img);
    void Red(Image &img);
    void Separate(Image &img, int num);
    void Combine(Image &img, Image &img1, Image &img2);
    void Rotate(Image &img);
};

#endif //PROJECT2_IMAGE_H
