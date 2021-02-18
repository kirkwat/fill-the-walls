//
// Created by watso on 2/17/2021.
//
#include "WallFiller.h"
//default constructor
WallFiller::WallFiller(){
    filePath="NULL";
    width=-1;
    height=-1;
}
//overloaded constructor with image folder path
WallFiller::WallFiller(string path) {
    filePath=path;
    width=-1;
    height=-1;
    cout<<endl<<"File Path: "<<filePath<<endl;
}

void WallFiller::fillWall(int w, int h){
    width=w;
    height=h;
    cout<<"\tWall Width: "<<width<<endl;
    cout<<"\tWall Height: "<<height<<endl;
}

void WallFiller::outputStats(){
    cout<<endl<<"Saving algorithm and wall to stats.txt..."<<endl;
    //open file
    ofstream file("stats.txt");
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file stats.txt." << endl;
        return;
    }
    //TODO OUTPUT STATS
    //create class that stores info
    file<<"Hello World"<<endl;
    //close file
    file.close();
    cout<<"...Complete"<<endl;
}