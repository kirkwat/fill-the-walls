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

    /*
    //CImg<unsigned char> testImg("../program1/program1/400.jpg");
    string imgPath=filePath+"/400.jpg";
    //char* imgPath2=filePath+"/400.jpg";
    //open test image
    CImg<unsigned char> testImg(imgPath.c_str());*/


    //create blank wall
    CImg<unsigned char> wall;
    wall=CImg(w,h,1,3);
    //set wall color to black
    wall.fill(0);
    //sort images by smallest
    sortSmallest(0,images.size()-1);
    //place images on wall


    wall.draw_image(0,0,images[0].getImage());

    wall.draw_image(images[0].getWidth(),0,images[1].getImage());

    wall.draw_image(images[0].getWidth()+images[1].getWidth(),0,images[2].getImage());

    wall.draw_image(images[0].getWidth()+images[1].getWidth()+images[2].getWidth()-images[3].getWidth(),images[2].getHeight(),images[3].getImage());

    wall.draw_image(images[0].getWidth()+images[1].getWidth()+images[2].getWidth()-images[3].getWidth()-images[4].getWidth(),images[2].getHeight(),images[4].getImage());

    int x_coord=0;
    int y_coord=0;
    int imgCounter=1;
    int dir=0; //0 equals right, 1 equals left
    //before adding image check if it hits wall
    //switch direction when wall is reached
    //check image height
    bool space=true;

    //add first image
    if(images[0].getWidth()<w&&images[0].getHeight()<h){
        wall.draw_image(0,0,images[0].getImage());
    }
    //add next image
    while(space){
        //check for no room or no more images
        if(imgCounter==2){
            break;
        }
        //going right
        if(dir==0){
            x_coord+=images[imgCounter].getWidth();
            //if there is no more room right
            if(x_coord>w){
                dir=1;
                x_coord=w;
                y_coord+=images[imgCounter-1].getHeight();
                continue;
            }
            //add image
            else{
                x_coord-=images[imgCounter].getWidth();
                wall.draw_image(x_coord,y_coord,images[imgCounter].getImage());
                x_coord+=images[imgCounter].getWidth();
                imgCounter++;
            }
        }
        //going left
        else{
            x_coord-=images[imgCounter].getWidth();
            //if there is no more room left
            if(x_coord<0){
                dir=0;
                x_coord=0;
                y_coord+=images[imgCounter-1].getHeight();
                continue;
            }
            //add image
            else{
                x_coord+=images[imgCounter].getWidth();
                wall.draw_image(x_coord,y_coord,images[imgCounter].getImage());
                x_coord-=images[imgCounter].getWidth();
                imgCounter++;
            }
        }
    }

//TODO stop at right wall

    //put image on wall
    //wall.draw_image(0,0,testImg);
    //display wall
    wall.display("Wall Test");



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
            string imgPath=path+"/"+string(entry->d_name);
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
//TODO delete
void FillerAlgos::printPrices() {
    //set precision for prices
    cout<<fixed;
    cout<<setprecision(2);
    for(int x=0;x<images.size();x++){
        cout<<"Image "<<x+1<<": "<<images[x].getPrice()<<endl;
        cout<<"\tWidth: "<<images[x].getWidth()<<endl;
        cout<<"\tHeight: "<<images[x].getHeight()<<endl;
        cout<<"\tArea: "<<images[x].getArea()<<endl;
    }
}
//sort by smallest by area using quicksort
void FillerAlgos::sortSmallest(int left, int right){
    //end sort if size is less than or equal to 1
    if (left >= right){
        return;
    }
    //quicksort image list
    Image pivot = images[right];
    int num = left;
    for (int i = left; i <= right; i++){
        //sort by size
        if (images[i].getArea() <= pivot.getArea()){
            Image temp=images[num];
            images[num]=images[i];
            images[i]=temp;
            num++;
        }
    }
    //sort left side
    sortSmallest(left, num-2);
    //sort right side
    sortSmallest(num, right);
}
//sort by most expensive using quicksort
void FillerAlgos::sortMostValue(int left, int right){
    //end sort if size is less than or equal to 1
    if (left >= right){
        return;
    }
    //quicksort image list
    Image pivot = images[right];
    int num = left;
    for (int i = left; i <= right; i++){
        //sort by price
        if (images[i].getPrice() >= pivot.getPrice()){
            Image temp=images[num];
            images[num]=images[i];
            images[i]=temp;
            num++;
        }
    }
    //sort left side
    sortMostValue(left, num-2);
    //sort right side
    sortMostValue(num, right);
}