//
// Created by watso on 2/20/2021.
//

#include "FillerAlgos.h"
//default constructor
FillerAlgos::FillerAlgos(){
    filePath="NULL";
}
//overloaded constructor with path
FillerAlgos::FillerAlgos(string path) {
    filePath=path;
    getImages(filePath);
}
//create wall with smallest images first
Stats FillerAlgos::smallest(int w,int h){
    Stats info=Stats();


    //CImg<unsigned char> testImg("../program1/program1/400.jpg");

    string imgPath=filePath+"/400.jpg";
    //char* imgPath2=filePath+"/400.jpg";

    //open test image
    CImg<unsigned char> testImg(imgPath.c_str());
    //create blank wall
    CImg<unsigned char> wall;
    wall=CImg(w,h,1,3);
    //set wall color to black
    wall.fill(0);
    //put images on wall
    //TODO organize by smallest, then place on wall

    /*
    //put image on wall
    wall.draw_image(0,0,testImg);
    //display wall
    wall.display("Wall Test");
    */



    //todo cimg example 2
    /*
    CImg<unsigned char> img(640,400,1,3);         // Define a 640x400 color image with 8 bits per color component.
    img.fill(0);                                  // Set pixel values to 0 (color : black)
    unsigned char purple[] = { 255,0,255 };       // Define a purple color
    img.draw_text(100,100,"Hello World",purple);  // Draw a purple "Hello world" at coordinates (100,100).
    img.display("Window Title");                  // Display the image in a display window.
    img.save_png("test.png");                     // Save as PNG to prove we linked correctly
    img.save_jpeg("test.jpg");                    // Save as JPG to prove we linked correctly
    */














    return info;
}
//create wall with most expensive images first
Stats FillerAlgos::mostExpensive(int,int){
    Stats info=Stats();





    return info;
}
//create wall with my unique algo
Stats FillerAlgos::myHeuristicAlgo(int,int){
    Stats info=Stats();





    return info;
}
//read through image directory
void FillerAlgos::getImages(string path) {
    DIR *directory;
    struct dirent *entry;
    struct stat info;
    //open directory
    directory=opendir(path.c_str());
    //check if directory exists
    if(!directory){
        cout<<"Folder not found"<<endl;
        return;
    }
    //read directory
    while((entry=readdir(directory))!=nullptr){
        if(entry->d_name[0]!='.'){
            //get path
            //TODO confirm path works
            string imgPath=path+"\\\\"+string(entry->d_name);
            //check if path is another directory
            stat(imgPath.c_str(),&info);
            if(S_ISDIR(info.st_mode)){
                //open directory
                getImages((char*)imgPath.c_str());
                filePath=imgPath;
            }
            //read path source if path is file
            else{
                images.push_back(Image(imgPath));
            }
        }
    }
    //close directory
    closedir(directory);
}