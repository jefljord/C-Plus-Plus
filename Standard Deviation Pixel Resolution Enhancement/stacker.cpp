#include "stacker.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

void stacker::readFile(string s){

    ifstream fin;
    pixel holder;
    fin.open(s.c_str());

    fin >> magic_number;

    fin >> width;
    fin >> height;

    fin >> max_color;

    pixels.resize(width*height);
    pixels1.resize(width*height);
    devColor.resize(width*height);
    devColor2.resize(width*height);

    for(int i = 0; i < width * height;  i++) {

        fin >> holder.r;
        fin >> holder.g;
        fin >> holder.b;

        pixels1[i].r += holder.r;
        pixels1[i].g += holder.g;
        pixels1[i].b += holder.b;


    }

    fin.close();

    for (int i = 0; i < height*width; i++) {

        pixels[i].r = (pixels1[i].r / 10);
        pixels[i].g = (pixels1[i].g / 10);
        pixels[i].b = (pixels1[i].b / 10);

    }

}

void stacker::saveImage(string d){

    ofstream fileIn;

    fileIn.open(d.c_str());

    fileIn << magic_number << endl;
    fileIn << width << " " << height << endl;
    fileIn << max_color << " " << endl;

    for(int i = 0; i < width * height;  i++) {

        fileIn << pixels[i].r << " ";
        fileIn << pixels[i].g << " ";
        fileIn << pixels[i].b << " ";

    }

    fileIn.close();

}

void stacker::findStandDev(string x) {

    ifstream fin;
    pixel holder1;
    fin.open(x.c_str());

    fin >> magic_number;

    fin >> width;
    fin >> height;

    fin >> max_color;

    for(int i = 0; i < width * height;  i++) {

        fin >> holder1.r;
        fin >> holder1.g;
        fin >> holder1.b;

        devColor[i].red += (holder1.r - pixels[i].r) * (holder1.r - pixels[i].r);
        devColor[i].green += (holder1.g - pixels[i].g) * (holder1.g - pixels[i].g);
        devColor[i].blue += (holder1.b - pixels[i].g) * (holder1.g - pixels[i].g);

    }

    fin.close();

    for (int i = 0; i < width * height; i++){
        devColor2[i].red = devColor[i].red / 10;
        devColor2[i].green = devColor[i].green / 10;
        devColor2[i].blue = devColor[i].blue / 10;
    }

    for (int i = 0; i < width * height; i++){
        devColor[i].red = sqrt(devColor2[i].red);
        devColor[i].green = sqrt(devColor2[i].green);
        devColor[i].blue = sqrt(devColor2[i].blue);
    }

}

void stacker::printStdDev() {
    double maxr = 0.0;
    double maxg = 0.0;
    double maxb = 0.0;

    for (int i = 0; i < height * width; i++){
        if (devColor[i].red > maxr){
            maxr = devColor[i].red;
        }
        if (devColor[i].green > maxg){
            maxg = devColor[i].green;
        }
        if (devColor[i].blue > maxb){
            maxb = devColor[i].blue;
        }
    }
    cout << "The maximum deviation at position red is " << maxr << endl;
    cout << "The maximum deviation at position green is " << maxg << endl;
    cout << "The maximum deviation at position blue is " << maxb << endl;
}

