//
// Created by watso on 2/17/2021.
//

#ifndef INC_21S_PA01_WATSON_WALLFILLER_H
#define INC_21S_PA01_WATSON_WALLFILLER_H

#include <string>
#include <iostream>
#include <fstream>
#include <dirent.h>

using namespace std;

class WallFiller {
private:
    string filePath;
    int width, height;

public:
    WallFiller();
    WallFiller(string);

    void fillWall(int,int);
    void outputStats();
};


#endif //INC_21S_PA01_WATSON_WALLFILLER_H
