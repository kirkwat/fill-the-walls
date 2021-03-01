//
// Created by watso on 2/20/2021.
//

#include "Stats.h"
//default constructor
Stats::Stats(){
    algoType=0;
    value=0;
    wastedSpace=0;

}
//display stats to output file
void Stats::printStats(ofstream &file) {
    //set precision for prices
    file<<fixed;
    file<<setprecision(2);
    //display stats
    file<<"\tWall "<<wallNum<<":"<<endl;
    file<<"\t\tTotal value:   $"<<value<<endl;
    file<<"\t\tWasted Space:  "<<wastedSpace<<"%"<<endl;
}
//add image value to wall value
void Stats::addToValue(int toAdd){
    value+=toAdd;
}
//set algorithm type
void Stats::setAlgoType(int type){
    algoType=type;
}
//set wall value
void Stats::setValue(double val){
    value=val;
}
//set wasted space
void Stats::setWastedSpace(double space){
    wastedSpace=space;
}
//get algorithm type
int Stats::getAlgoType(){
    return algoType;
}
//get wall value
double Stats::getValue(){
    return value;
}
//get wasted space
double Stats::getWastedSpace(){
    return wastedSpace;
}