#ifndef INC_21S_PA01_WATSON_STATS_H
#define INC_21S_PA01_WATSON_STATS_H

#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Stats {
private:
    int algoType;
    double value1;
    double wastedSpace1;
    double value2;
    double wastedSpace2;

public:
    Stats();
    Stats(int);

    void printStats(ofstream&);

    void setValue1(double);
    void setWastedSpace1(double);
    void setValue2(double);
    void setWastedSpace2(double);
};


#endif //INC_21S_PA01_WATSON_STATS_H
