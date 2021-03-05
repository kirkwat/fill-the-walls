//Kirk Watson - 47876885 - CS3353
#ifndef INC_21S_PA01_WATSON_WALLFILLER_H
#define INC_21S_PA01_WATSON_WALLFILLER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Stats.h"
#include "FillerAlgos.h"

using namespace std;

//This class is the launcher of the program which controls functionality of the wall creation.
class WallFiller {
private:
    FillerAlgos imgCreator; //image creator with wall filler algorithms
    vector<Stats> data;     //info from all the walls created in

public:
    WallFiller();
    WallFiller(string);

    void fillWall(int,int,int,int);
    void outputStats();
};


#endif //INC_21S_PA01_WATSON_WALLFILLER_H