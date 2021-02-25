//
// Created by watso on 2/17/2021.
//

#ifndef INC_21S_PA01_WATSON_WALLFILLER_H
#define INC_21S_PA01_WATSON_WALLFILLER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include "CImg.h"
#include "Stats.h"
#include "FillerAlgos.h"

using namespace std;
using namespace cimg_library;

class WallFiller {
private:
    FillerAlgos imgCreator;
    vector<Stats> images;
    string filePath;

public:
    WallFiller();
    WallFiller(string);

    void fillWall(int,int,int);
    void outputStats();
};


#endif //INC_21S_PA01_WATSON_WALLFILLER_H
