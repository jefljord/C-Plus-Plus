//
// Created by jeffj on 10/11/2019.
//
#include <string>
#include <vector>

#ifndef IMAGEVECTOR_STACKER_H
#define IMAGEVECTOR_STACKER_H


class stacker {

private:
    std::string magic_number;
    int width, height, max_color;

    struct pixel {
        int r, g, b;
    };
    struct stddev {
        double red, green, blue;
    };

    std::vector<pixel> pixels;
    std::vector<pixel> pixels1;
    std::vector<stddev> devColor;
    std::vector<stddev> devColor2;

public:
    void readFile(std::string s);
    void saveImage(std::string d);
    void findStandDev(std::string x);
    void printStdDev();

};


#endif //IMAGEVECTOR_STACKER_H

