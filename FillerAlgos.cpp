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
    splitImages();
}
//create wall with smallest images first
Stats FillerAlgos::smallest(int w1,int h1, int w2, int h2){
    Stats info=Stats(); //stores info of algo
    int usedArea1=0; //adds up total area used for wall 1
    int usedArea2=0; //adds up total area used for wall 2
    double totalVal1=0; //adds up total value used for wall 1
    double totalVal2=0; //adds up total value used for wall 2
    int x_coord=0; //x coordinate pointer
    int y_coord=0; //y coordinate pointer
    int imgCounter=1; //counts number of images added
    int dir=0; //0 equals right, 1 equals left
    int dirSwitch=0; //track which image had last direction switch
    bool space=true; //space to add more images
    //create blank wall
    CImg<unsigned char> wall1 = CImg(w1,h1,1,3);
    //set wall color to black
    wall1.fill(0);
    //sort images by smallest
    sortSmallest(0,images.size()-1);
    //add first image to wall
    if(images[0].getWidth()<w1&&images[0].getHeight()<h1){
        wall1.draw_image(0,0,images[0].getImage());
        x_coord+=images[0].getWidth();
        //add remaining images horizontally
        while(space){
            //check for no more images
            if(imgCounter==images.size()){
                break;
            }
            //going right
            if(dir==0){
                //if there is no more room right
                x_coord+=images[imgCounter].getWidth();
                if(x_coord>w1){
                    //switch direction to left
                    dir=1;
                    //x pointer moved to right wall
                    x_coord=w1;
                    //move y pointer below image row using largest height from row
                    int maxHeight=0;
                    for(int x=imgCounter-1;x>=dirSwitch;x--){
                        //change maxHeight if current height is larger
                        if(images[x].getHeight()>maxHeight){
                            maxHeight=images[x].getHeight();
                        }
                    }
                    y_coord+=maxHeight;
                    //update switch
                    dirSwitch=imgCounter;
                    continue;
                }
                //add image
                else{
                    //check if image height fits in wall
                    y_coord+=images[imgCounter].getHeight();
                    //end buiding wall if image does not fit
                    if(y_coord>h1){
                        space=false;
                        continue;
                    }
                        //if image fits, move y pointer back
                    else{
                        y_coord-=images[imgCounter].getHeight();
                    }
                    //move x pointer back
                    x_coord-=images[imgCounter].getWidth();
                    //add image
                    wall1.draw_image(x_coord,y_coord,images[imgCounter].getImage());
                    //add image area
                    usedArea1+=images[imgCounter].getArea();
                    //add image value
                    totalVal1+=images[imgCounter].getPrice();
                    //move x pointer
                    x_coord+=images[imgCounter].getWidth();
                    imgCounter++;
                }
            }
            //going left
            else{
                //move x pointer
                x_coord-=images[imgCounter].getWidth();
                //if there is no more room left
                if(x_coord<0){
                    //switch direction to left
                    dir=0;
                    //x pointer moved to left wall
                    x_coord=0;
                    //move y pointer below image row using largest height from row
                    int maxHeight=0;
                    for(int x=imgCounter-1;x>=dirSwitch;x--){
                        //change maxHeight if current height is larger
                        if(images[x].getHeight()>maxHeight){
                            maxHeight=images[x].getHeight();
                        }
                    }
                    y_coord+=maxHeight;
                    //update switch
                    dirSwitch=imgCounter;
                    continue;
                }
                    //add image
                else{
                    //check if image height fits in wall
                    y_coord+=images[imgCounter].getHeight();
                    //end buiding wall if image does not fit
                    if(y_coord>h1){
                        space=false;
                        continue;
                    }
                    //if image fits, move pointer back
                    else{
                        y_coord-=images[imgCounter].getHeight();
                    }
                    //add image
                    wall1.draw_image(x_coord,y_coord,images[imgCounter].getImage());
                    //add image area
                    usedArea1+=images[imgCounter].getArea();
                    //add image value
                    totalVal1+=images[imgCounter].getPrice();
                    imgCounter++;
                }
            }
        }
    }
    //TODO save wall1 stats
    //TODO save wall1 image

    //TODO repeat for wall1


    //display wall
    wall1.display("Wall Test");










































    //DONE!!!
    //TODO
    //update for 2 walls
    //save images
    //save stats
    //then move to next algo


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
//split images into 2 vectors for wall 1 and wall 2
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