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
    Stats temp=imgCreator.smallest(w1,h1,w2,h2);
    temp.setWallNum(1);
    walls.push_back(temp);











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
    for(int x=1;x<=3;x++){
        if(x==1){
            file<<"Smallest first"<<endl;
        }
        else if(x==2){
            file<<"Most expensive first"<<endl;
        }
        else{
            file<<"My developed heuristic algorithm"<<endl;
        }
        //print info for each image
        double total=0;
        for(int y=0;y<walls.size();y++){
            //print correct image with algo type
            if(x==walls[y].getAlgoType()){
                walls[y].printStats(file);
                total+=walls[y].getValue();
            }
        }
        //set precision for total
        file<<fixed;
        file<<setprecision(2);
        file<<"Total profit: $"<<total<<endl<<endl;
    }
    //close file
    file.close();
    cout<<"...Complete"<<endl;
}