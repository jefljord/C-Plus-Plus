#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "stacker.h"

using namespace std;

int main() {

    stacker test;
    string fileName, stackName, outputName;
    int stackCount;
    string toFile;

    cout << "Please enter the name of the file you want to stack..." << endl;
    cin >> fileName;

    outputName = fileName;

    cout << "Please enter the number of images" << endl;
    cin >> stackCount;
    cout << "Stacking images now..." << endl;

    for(int i = 1; i <= stackCount; i++){ //needed to create the correct file name.

        if(i < 10){

            stackName = fileName+"_00";
            stackName = stackName + to_string(i);
            stackName = stackName + ".ppm";

            cout << "Now stacking " << outputName << "/" << stackName << endl; //sanity check
            toFile = fileName + "/" + stackName;
            test.readFile(toFile);
            test.findStandDev(toFile);
        }

        else{
            stackName = fileName+"_0";
            stackName = stackName + to_string(i);
            stackName = stackName + ".ppm";

            cout << "Now stacking " << outputName << "/" << stackName << endl; //sanity check

            toFile = fileName + "/" + stackName;
            test.readFile(toFile);
            test.findStandDev(toFile);
        }
    }
    cout << "Stacking succeeded..." << endl;
    test.printStdDev();

    outputName = outputName + ".ppm"; //creates the file name.
    test.saveImage(outputName);

    return 0;

}