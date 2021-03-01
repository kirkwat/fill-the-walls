#include "Stats.h"
//default constructor
Stats::Stats(){
    algoType=0;
    value1=0;
    wastedSpace1=0;
    value2=0;
    wastedSpace2=0;
}
//overloaded constructor with algo type
Stats::Stats(int a){
    algoType=a;
    value1=0;
    wastedSpace1=0;
    value2=0;
    wastedSpace2=0;
}
//display stats to output file
void Stats::printStats(ofstream &file) {
    //set precision for prices
    file<<fixed;
    file<<setprecision(2);
    //display algo type
    if(algoType==1){
        file<<"Smallest first"<<endl;
    }
    else if(algoType==2){
        file<<"Most expensive first"<<endl;
    }
    else{
        file<<"My developed heuristic algorithm"<<endl;
    }
    //display stats
    file<<"\tWall 1:"<<endl;
    file<<"\t\tTotal value:   $"<<value1<<endl;
    file<<"\t\tWasted Space:  "<<wastedSpace1<<"%"<<endl;
    file<<"\tWall 2:"<<endl;
    file<<"\t\tTotal value:   $"<<value2<<endl;
    file<<"\t\tWasted Space:  "<<wastedSpace2<<"%"<<endl;
    file<<"Total profit: $"<<value1+value2<<endl<<endl;
}
//set wall 1 value
void Stats::setValue1(double val){
    value1=val;
}
//set wall 2 value
void Stats::setValue2(double val){
    value2=val;
}
//set wasted space 1
void Stats::setWastedSpace1(double space){
    wastedSpace1=(1-space)*100;
}
//set wasted space 2
void Stats::setWastedSpace2(double space){
    wastedSpace2=(1-space)*100;
}