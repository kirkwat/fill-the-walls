//Kirk Watson - 47876885 - CS3353
#ifndef INC_21S_PA01_WATSON_STATS_H
#define INC_21S_PA01_WATSON_STATS_H

#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//This class is used to store information on the walls 1 and 2 made by the algorithms.
class Stats {
private:
    int algoType;           //lets us know which algorithm was used for this set
    double value1;          //value of wall 1
    double wastedSpace1;    //amount of space wasted in wall 1
    double value2;          //value of wall 2
    double wastedSpace2;    //amount of space wasted in wall 2

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
