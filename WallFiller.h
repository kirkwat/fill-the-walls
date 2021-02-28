//
// Created by watso on 2/17/2021.
//

#ifndef INC_21S_PA01_WATSON_WALLFILLER_H
#define INC_21S_PA01_WATSON_WALLFILLER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Stats.h"
#include "FillerAlgos.h"

using namespace std;

class WallFiller {
private:
    FillerAlgos imgCreator;
    vector<Stats> walls;

public:
    WallFiller();
    WallFiller(string);

    void fillWall(int,int,int);
    void outputStats();
};


#endif //INC_21S_PA01_WATSON_WALLFILLER_H
