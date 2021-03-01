//
// Created by watso on 2/17/2021.
//
#include "WallFiller.h"
//default constructor
WallFiller::WallFiller(){
    imgCreator=FillerAlgos();
}
//overloaded constructor with image folder path
WallFiller::WallFiller(string path) {
    imgCreator=FillerAlgos(path);
}
//create walls with the three different algos
void WallFiller::fillWall(int w1, int h1, int w2, int h2){
    //create image with smallest first and store data
    data.push_back(imgCreator.smallest(w1,h1,w2,h2));
    //create image with most expensive first and store data
    data.push_back(imgCreator.mostExpensive(w1,h1,w2,h2));











    //TODO uncomment after completing smallest first
    /*
    //create image with most expensive first and store data
    temp=imgCreator.mostExpensive(w,h);
    temp.setWallNum(wallNum);
    images.push_back(temp);
    //create image with my algo and store data
    temp=imgCreator.myHeuristicAlgo(w,h);
    temp.setWallNum(wallNum);
    images.push_back(temp);*/
}
//output stats for walls and algorithms
void WallFiller::outputStats(){
    cout<<endl<<"Saving algorithm and wall data to stats.txt..."<<endl;
    //open file
    ofstream file("stats.txt");
    //check if it was opened properly
    if (!file.is_open()) {
        cout << "Could not open file stats.txt." << endl;
        return;
    }
    file<<"Fill the Walls Data"<<endl;
    //display stats for each algorithm
    for(int y=0;y<data.size();y++){
        data[y].printStats(file);
    }
    //close file
    file.close();
    cout<<"...Complete"<<endl;
}