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
//create images by placing smallest images on wall first
Stats FillerAlgos::smallest(int w1,int h1, int w2, int h2){
    sortSmallest(0,images.size()-1);
    return fillWall(1,w1,h1,w2,h2,"wall1_smallest.jpg","wall2_smallest.jpg");
}
//create images by placing most expensive images on wall first
Stats FillerAlgos::mostExpensive(int w1,int h1, int w2, int h2){
    sortMostValue(0,images.size()-1);
    return fillWall(2,w1,h1,w2,h2,"wall1_most_expensive.jpg","wall2_most_expensive.jpg");
}
//create images by placing a combination of smallest and most expensive images on wall first
Stats FillerAlgos::myHeuristicAlgo(int w1,int h1, int w2, int h2){
    sortMyDesign1();
    return fillWall(3,w1,h1,w2,h2,"wall1_my_design.jpg","wall2_my_design.jpg");
}
//fill walls 1 and 2 with images
Stats FillerAlgos::fillWall(int mode, int w1, int h1, int w2, int h2, string img1, string img2){
    Stats info=Stats(mode); //stores info of algo
    double usedArea1=0; //adds up total area used for wall 1
    double totalVal1=0; //adds up total value used for wall 1
    int x_coord=0; //x coordinate pointer
    int y_coord=0; //y coordinate pointer
    int imgCounter=1; //counts number of images added
    int dir=0; //0 equals right, 1 equals left
    int dirSwitch=0; //track which image had last direction switch
    bool space=true; //space to add more images
    bool allOn1=false; //check if all images are used on the wall 1 to end build
    //create blank wall 1
    CImg<unsigned char> wall1 = CImg(w1,h1,1,3);
    //set wall color to black
    wall1.fill(0);
    //add images to wall 1
    if(images[0].getWidth()<w1&&images[0].getHeight()<h1){
        //add first image
        wall1.draw_image(0,0,images[0].getImage());
        usedArea1+=images[0].getArea();
        totalVal1+=images[0].getPrice();
        //move x pointer
        x_coord+=images[0].getWidth();
        //add remaining images horizontally
        while(space){
            //check for no more images
            if(imgCounter==images.size()){
                allOn1=true;
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
    //store wall 1 stats
    info.setValue1(totalVal1);
    info.setWastedSpace1(usedArea1/(w1*h1));
    //save wall 1 image
    wall1.save_jpeg(img1.c_str());
    //reset indicators
    double usedArea2=0;
    double totalVal2=0;
    x_coord=0;
    y_coord=0;
    dir=0;
    dirSwitch=imgCounter;
    space=true;
    //create blank wall 2
    CImg<unsigned char> wall2 = CImg(w2,h2,1,3);
    //set wall color to black
    wall2.fill(0);
    //check if all images were used on wall 1
    if(allOn1){
        //save blank wall 2 image
        wall2.save_jpeg(img2.c_str());
        //if all were used, end build
        return info;
    }
    //add images to wall 2
    if(images[imgCounter].getWidth()<w2&&images[imgCounter].getHeight()<h2){
        //add first image
        wall2.draw_image(0,0,images[imgCounter].getImage());
        usedArea2+=images[imgCounter].getArea();
        totalVal2+=images[imgCounter].getPrice();
        //move pointer
        x_coord+=images[imgCounter].getWidth();
        imgCounter++;
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
                if(x_coord>w2){
                    //switch direction to left
                    dir=1;
                    //x pointer moved to right wall
                    x_coord=w2;
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
                    if(y_coord>h2){
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
                    wall2.draw_image(x_coord,y_coord,images[imgCounter].getImage());
                    //add image area
                    usedArea2+=images[imgCounter].getArea();
                    //add image value
                    totalVal2+=images[imgCounter].getPrice();
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
                    if(y_coord>h2){
                        space=false;
                        continue;
                    }
                    //if image fits, move pointer back
                    else{
                        y_coord-=images[imgCounter].getHeight();
                    }
                    //add image
                    wall2.draw_image(x_coord,y_coord,images[imgCounter].getImage());
                    //add image area
                    usedArea2+=images[imgCounter].getArea();
                    //add image value
                    totalVal2+=images[imgCounter].getPrice();
                    imgCounter++;
                }
            }
        }
    }
    //store wall 2 stats
    info.setValue2(totalVal2);
    info.setWastedSpace2(usedArea2/(w2*h2));
    //save wall 2 image
    wall2.save_jpeg(img2.c_str());
    //return data
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
//sort by comparing price to size
void FillerAlgos::sortMyDesign1() {
    //score by ranks given when sorted by size and price
    sortSmallest(0,images.size()-1);
    //add rank to image score
    for(int x=0;x<images.size();x++){
        images[x].addToScore(x);
    }
    //sort by price
    sortMostValue(0,images.size()-1);
    //add rank to image score
    for(int x=0;x<images.size();x++){
        images[x].addToScore(x);
    }
    //sort for lowest scores
    sortMyDesign2(0,images.size()-1);
}
//sort by lowest scores using quicksort
void FillerAlgos::sortMyDesign2(int left, int right) {
    //end sort if size is less than or equal to 1
    if (left >= right){
        return;
    }
    //quicksort image list
    Image pivot = images[right];
    int num = left;
    for (int i = left; i <= right; i++){
        //sort by score
        if (images[i].getScore() <= pivot.getScore()){
            Image temp=images[num];
            images[num]=images[i];
            images[i]=temp;
            num++;
        }
    }
    //sort left side
    sortMyDesign2(left, num-2);
    //sort right side
    sortMyDesign2(num, right);
}