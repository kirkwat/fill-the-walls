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

class FillerAlgos {
private:
    string filePath;
    vector<Image> images;

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
