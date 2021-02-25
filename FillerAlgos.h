//
// Created by watso on 2/20/2021.
//

#ifndef INC_21S_PA01_WATSON_FILLERALGOS_H
#define INC_21S_PA01_WATSON_FILLERALGOS_H

#include
#include "Stats.h"
#include "CImg.h"

class FillerAlgos {
private:

public:
    FillerAlgos();

    Stats smallest(int,int);
    Stats mostExpensive(int,int);
    Stats myHeuristicAlgo(int,int);
};


#endif //INC_21S_PA01_WATSON_FILLERALGOS_H
