//Kirk Watson - 47876885 - CS3353
#ifndef INC_21S_PA01_WATSON_FILLERALGOS_H
#define INC_21S_PA01_WATSON_FILLERALGOS_H

#include <iostream>
#include <vector>
#include <dirent.h>
#include "Stats.h"
#include "Image.h"
#include "CImg.h"

using namespace std;
using namespace cimg_library;

//This class contains functions that place images on the walls.
//Images are placed in the wall in a zigzag pattern from top to bottom after they are sorted.
//There are 3 different ways to sort the images before placing on the walls.
//Smallest- This algorithm will sort the images in order from smallest to largest by area.
//Most expensive- This algorithm will sort images in order from most expensive to least expensive.
//My design- This algorithm will sort the images by smallest and track the placement.
    //Then it will sort the images by most expensive and track the placement.
    //The algorithm will rank which images will be placed first by comparing their ranks for both optimizations.
class FillerAlgos {
private:

    string filePath;        //stores file path to image folder
    vector<Image> images;   //stores images gathered from image folder

public:
    FillerAlgos();
    FillerAlgos(string);

    Stats smallest(int,int,int,int);
    Stats mostExpensive(int,int,int,int);
    Stats myHeuristicAlgo(int,int,int,int);
    Stats fillWall(int, int, int, int, int,string,string);
    void getImages(string);
    void sortSmallest(int,int);
    void sortMostValue(int,int);
    void sortMyDesign1();
    void sortMyDesign2(int,int);

};


#endif //INC_21S_PA01_WATSON_FILLERALGOS_H
