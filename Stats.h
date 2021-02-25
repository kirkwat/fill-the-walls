//
// Created by watso on 2/20/2021.
//

#ifndef INC_21S_PA01_WATSON_STATS_H
#define INC_21S_PA01_WATSON_STATS_H

#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Stats {
private:
    int wallNum;
    int algoType;
    double value;
    double wastedSpace;

public:
    Stats();

    void printStats(ofstream&);
    void addToValue(int);

    void setWallNum(int);
    void setAlgoType(int);
    void setValue(double);
    void setWastedSpace(double);

    int getWallNum();
    int getAlgoType();
    double getValue();
    double getWastedSpace();
};


#endif //INC_21S_PA01_WATSON_STATS_H
