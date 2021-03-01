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
    Stats info=Stats(1); //stores info of algo
    double usedArea1=0; //adds up total area used for wall 1
    double totalVal1=0; //adds up total value used for wall 1
    int x_coord=0; //x coordinate pointer
    int y_coord=0; //y coordinate pointer
    int imgCounter=1; //counts number of images added
    int dir=0; //0 equals right, 1 equals left
    int dirSwitch=0; //track which image had last direction switch
    bool space=true; //space to add more images
    //sort images by smallest
    sortSmallest(0,images.size()-1);
    //split images for wall 1 and 2
    splitImages();
    //create blank wall 1
    CImg<unsigned char> wall1 = CImg(w1,h1,1,3);
    //set wall color to black
    wall1.fill(0);
    //add images to wall 1
    if(w1Images[0].getWidth()<w1&&w1Images[0].getHeight()<h1){
        //add first image
        wall1.draw_image(0,0,w1Images[0].getImage());
        usedArea1+=w1Images[0].getArea();
        totalVal1+=w1Images[0].getPrice();
        //move x pointer
        x_coord+=w1Images[0].getWidth();
        //add remaining images horizontally
        while(space){
            //check for no more images
            if(imgCounter==w1Images.size()){
                break;
            }
            //going right
            if(dir==0){
                //if there is no more room right
                x_coord+=w1Images[imgCounter].getWidth();
                if(x_coord>w1){
                    //switch direction to left
                    dir=1;
                    //x pointer moved to right wall
                    x_coord=w1;
                    //move y pointer below image row using largest height from row
                    int maxHeight=0;
                    for(int x=imgCounter-1;x>=dirSwitch;x--){
                        //change maxHeight if current height is larger
                        if(w1Images[x].getHeight()>maxHeight){
                            maxHeight=w1Images[x].getHeight();
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
                    y_coord+=w1Images[imgCounter].getHeight();
                    //end buiding wall if image does not fit
                    if(y_coord>h1){
                        space=false;
                        continue;
                    }
                    //if image fits, move y pointer back
                    else{
                        y_coord-=w1Images[imgCounter].getHeight();
                    }
                    //move x pointer back
                    x_coord-=w1Images[imgCounter].getWidth();
                    //add image
                    wall1.draw_image(x_coord,y_coord,w1Images[imgCounter].getImage());
                    //add image area
                    usedArea1+=w1Images[imgCounter].getArea();
                    //add image value
                    totalVal1+=w1Images[imgCounter].getPrice();
                    //move x pointer
                    x_coord+=w1Images[imgCounter].getWidth();
                    imgCounter++;
                }
            }
            //going left
            else{
                //move x pointer
                x_coord-=w1Images[imgCounter].getWidth();
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
                        if(w1Images[x].getHeight()>maxHeight){
                            maxHeight=w1Images[x].getHeight();
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
                    y_coord+=w1Images[imgCounter].getHeight();
                    //end buiding wall if image does not fit
                    if(y_coord>h1){
                        space=false;
                        continue;
                    }
                    //if image fits, move pointer back
                    else{
                        y_coord-=w1Images[imgCounter].getHeight();
                    }
                    //add image
                    wall1.draw_image(x_coord,y_coord,w1Images[imgCounter].getImage());
                    //add image area
                    usedArea1+=w1Images[imgCounter].getArea();
                    //add image value
                    totalVal1+=w1Images[imgCounter].getPrice();
                    imgCounter++;
                }
            }
        }
    }
    //store wall 1 stats
    info.setValue1(totalVal1);
    info.setWastedSpace1(usedArea1/(w1*h1));
    //save wall 1 image
    wall1.save_jpeg("wall1_smallest.jpg");
    //reset indicators
    double usedArea2=0;
    double totalVal2=0;
    x_coord=0;
    y_coord=0;
    imgCounter=1;
    dir=0;
    dirSwitch=0;
    space=true;
    //create blank wall 2
    CImg<unsigned char> wall2 = CImg(w2,h2,1,3);
    //set wall color to black
    wall2.fill(0);
    //add images to wall 2
    if(w2Images[0].getWidth()<w2&&w2Images[0].getHeight()<h2){
        //add first image
        wall2.draw_image(0,0,w2Images[0].getImage());
        usedArea2+=w2Images[0].getArea();
        totalVal2+=w2Images[0].getPrice();
        //move pointer
        x_coord+=w2Images[0].getWidth();
        //add remaining images horizontally
        while(space){
            //check for no more images
            if(imgCounter==w2Images.size()){
                break;
            }
            //going right
            if(dir==0){
                //if there is no more room right
                x_coord+=w2Images[imgCounter].getWidth();
                if(x_coord>w2){
                    //switch direction to left
                    dir=1;
                    //x pointer moved to right wall
                    x_coord=w2;
                    //move y pointer below image row using largest height from row
                    int maxHeight=0;
                    for(int x=imgCounter-1;x>=dirSwitch;x--){
                        //change maxHeight if current height is larger
                        if(w2Images[x].getHeight()>maxHeight){
                            maxHeight=w2Images[x].getHeight();
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
                    y_coord+=w2Images[imgCounter].getHeight();
                    //end buiding wall if image does not fit
                    if(y_coord>h2){
                        space=false;
                        continue;
                    }
                    //if image fits, move y pointer back
                    else{
                        y_coord-=w2Images[imgCounter].getHeight();
                    }
                    //move x pointer back
                    x_coord-=w2Images[imgCounter].getWidth();
                    //add image
                    wall2.draw_image(x_coord,y_coord,w2Images[imgCounter].getImage());
                    //add image area
                    usedArea2+=w2Images[imgCounter].getArea();
                    //add image value
                    totalVal2+=w2Images[imgCounter].getPrice();
                    //move x pointer
                    x_coord+=w2Images[imgCounter].getWidth();
                    imgCounter++;
                }
            }
            //going left
            else{
                //move x pointer
                x_coord-=w2Images[imgCounter].getWidth();
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
                        if(w2Images[x].getHeight()>maxHeight){
                            maxHeight=w2Images[x].getHeight();
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
                    y_coord+=w2Images[imgCounter].getHeight();
                    //end buiding wall if image does not fit
                    if(y_coord>h2){
                        space=false;
                        continue;
                    }
                    //if image fits, move pointer back
                    else{
                        y_coord-=w2Images[imgCounter].getHeight();
                    }
                    //add image
                    wall2.draw_image(x_coord,y_coord,w2Images[imgCounter].getImage());
                    //add image area
                    usedArea2+=w2Images[imgCounter].getArea();
                    //add image value
                    totalVal2+=w2Images[imgCounter].getPrice();
                    imgCounter++;
                }
            }
        }
    }
    //store wall 2 stats
    info.setValue2(totalVal2);
    info.setWastedSpace2(usedArea2/(w2*h2));
    //save wall 2 image
    wall2.save_jpeg("wall2_smallest.jpg");
    //return data
    return info;
}
//create wall with most expensive images first
Stats FillerAlgos::mostExpensive(int w1,int h1, int w2, int h2){
    Stats info=Stats(1); //stores info of algo
    double usedArea1=0; //adds up total area used for wall 1
    double totalVal1=0; //adds up total value used for wall 1
    int x_coord=0; //x coordinate pointer
    int y_coord=0; //y coordinate pointer
    int imgCounter=1; //counts number of images added
    int dir=0; //0 equals right, 1 equals left
    int dirSwitch=0; //track which image had last direction switch
    bool space=true; //space to add more images
    //sort images by smallest
    sortMostValue(0,images.size()-1);
    //split images for wall 1 and 2
    splitImages();
    //create blank wall 1
    CImg<unsigned char> wall1 = CImg(w1,h1,1,3);
    //set wall color to black
    wall1.fill(0);
    //add images to wall 1
    if(w1Images[0].getWidth()<w1&&w1Images[0].getHeight()<h1){
        //add first image
        wall1.draw_image(0,0,w1Images[0].getImage());
        usedArea1+=w1Images[0].getArea();
        totalVal1+=w1Images[0].getPrice();
        //move x pointer
        x_coord+=w1Images[0].getWidth();
        //add remaining images horizontally
        while(space){
            //check for no more images
            if(imgCounter==w1Images.size()){
                break;
            }
            //going right
            if(dir==0){
                //if there is no more room right
                x_coord+=w1Images[imgCounter].getWidth();
                if(x_coord>w1){
                    //switch direction to left
                    dir=1;
                    //x pointer moved to right wall
                    x_coord=w1;
                    //move y pointer below image row using largest height from row
                    int maxHeight=0;
                    for(int x=imgCounter-1;x>=dirSwitch;x--){
                        //change maxHeight if current height is larger
                        if(w1Images[x].getHeight()>maxHeight){
                            maxHeight=w1Images[x].getHeight();
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
                    y_coord+=w1Images[imgCounter].getHeight();
                    //end buiding wall if image does not fit
                    if(y_coord>h1){
                        space=false;
                        continue;
                    }
                        //if image fits, move y pointer back
                    else{
                        y_coord-=w1Images[imgCounter].getHeight();
                    }
                    //move x pointer back
                    x_coord-=w1Images[imgCounter].getWidth();
                    //add image
                    wall1.draw_image(x_coord,y_coord,w1Images[imgCounter].getImage());
                    //add image area
                    usedArea1+=w1Images[imgCounter].getArea();
                    //add image value
                    totalVal1+=w1Images[imgCounter].getPrice();
                    //move x pointer
                    x_coord+=w1Images[imgCounter].getWidth();
                    imgCounter++;
                }
            }
                //going left
            else{
                //move x pointer
                x_coord-=w1Images[imgCounter].getWidth();
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
                        if(w1Images[x].getHeight()>maxHeight){
                            maxHeight=w1Images[x].getHeight();
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
                    y_coord+=w1Images[imgCounter].getHeight();
                    //end buiding wall if image does not fit
                    if(y_coord>h1){
                        space=false;
                        continue;
                    }
                        //if image fits, move pointer back
                    else{
                        y_coord-=w1Images[imgCounter].getHeight();
                    }
                    //add image
                    wall1.draw_image(x_coord,y_coord,w1Images[imgCounter].getImage());
                    //add image area
                    usedArea1+=w1Images[imgCounter].getArea();
                    //add image value
                    totalVal1+=w1Images[imgCounter].getPrice();
                    imgCounter++;
                }
            }
        }
    }
    //store wall 1 stats
    info.setValue1(totalVal1);
    info.setWastedSpace1(usedArea1/(w1*h1));
    //save wall 1 image
    wall1.save_jpeg("wall1_most_expensive.jpg");
    //reset indicators
    double usedArea2=0;
    double totalVal2=0;
    x_coord=0;
    y_coord=0;
    imgCounter=1;
    dir=0;
    dirSwitch=0;
    space=true;
    //create blank wall 2
    CImg<unsigned char> wall2 = CImg(w2,h2,1,3);
    //set wall color to black
    wall2.fill(0);
    //add images to wall 2
    if(w2Images[0].getWidth()<w2&&w2Images[0].getHeight()<h2){
        //add first image
        wall2.draw_image(0,0,w2Images[0].getImage());
        usedArea2+=w2Images[0].getArea();
        totalVal2+=w2Images[0].getPrice();
        //move pointer
        x_coord+=w2Images[0].getWidth();
        //add remaining images horizontally
        while(space){
            //check for no more images
            if(imgCounter==w2Images.size()){
                break;
            }
            //going right
            if(dir==0){
                //if there is no more room right
                x_coord+=w2Images[imgCounter].getWidth();
                if(x_coord>w2){
                    //switch direction to left
                    dir=1;
                    //x pointer moved to right wall
                    x_coord=w2;
                    //move y pointer below image row using largest height from row
                    int maxHeight=0;
                    for(int x=imgCounter-1;x>=dirSwitch;x--){
                        //change maxHeight if current height is larger
                        if(w2Images[x].getHeight()>maxHeight){
                            maxHeight=w2Images[x].getHeight();
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
                    y_coord+=w2Images[imgCounter].getHeight();
                    //end buiding wall if image does not fit
                    if(y_coord>h2){
                        space=false;
                        continue;
                    }
                        //if image fits, move y pointer back
                    else{
                        y_coord-=w2Images[imgCounter].getHeight();
                    }
                    //move x pointer back
                    x_coord-=w2Images[imgCounter].getWidth();
                    //add image
                    wall2.draw_image(x_coord,y_coord,w2Images[imgCounter].getImage());
                    //add image area
                    usedArea2+=w2Images[imgCounter].getArea();
                    //add image value
                    totalVal2+=w2Images[imgCounter].getPrice();
                    //move x pointer
                    x_coord+=w2Images[imgCounter].getWidth();
                    imgCounter++;
                }
            }
                //going left
            else{
                //move x pointer
                x_coord-=w2Images[imgCounter].getWidth();
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
                        if(w2Images[x].getHeight()>maxHeight){
                            maxHeight=w2Images[x].getHeight();
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
                    y_coord+=w2Images[imgCounter].getHeight();
                    //end buiding wall if image does not fit
                    if(y_coord>h2){
                        space=false;
                        continue;
                    }
                        //if image fits, move pointer back
                    else{
                        y_coord-=w2Images[imgCounter].getHeight();
                    }
                    //add image
                    wall2.draw_image(x_coord,y_coord,w2Images[imgCounter].getImage());
                    //add image area
                    usedArea2+=w2Images[imgCounter].getArea();
                    //add image value
                    totalVal2+=w2Images[imgCounter].getPrice();
                    imgCounter++;
                }
            }
        }
    }
    //store wall 2 stats
    info.setValue2(totalVal2);
    info.setWastedSpace2(usedArea2/(w2*h2));
    //save wall 2 image
    wall2.save_jpeg("wall2_most_expensive.jpg");
    //return data
    return info;
}
//create wall with my unique algo
Stats FillerAlgos::myHeuristicAlgo(int w1,int h1, int w2, int h2){
    Stats info=Stats();


    //TODO


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
void FillerAlgos::splitImages() {
    w1Images.clear();
    w2Images.clear();
    for(int x=0;x<images.size();x++){
        //divide by odd and even
        if(x%2==0){
            w1Images.push_back(images[x]);
        }
        else{
            w2Images.push_back(images[x]);
        }
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