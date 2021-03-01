#include "Image.h"
//default constructor
Image::Image() {
    path="NULL";
    width=-1;
    height=-1;
    price=-1;
    score=0;
}
//overloaded constructor with path
Image::Image(string p){
    path=p;
    setPrice();
    setDimensions();
    score=0;
}
//set dimensions of image
void Image::setDimensions() {
    image=CImg<unsigned char>(path.c_str());
    width = image.width();
    height = image.height();
}
//set price
void Image::setPrice(){
    //get num from file name
    string priceStr=path.substr(path.find_last_of('/')+1,path.find_last_of('.')-path.find_last_of('/')-1);
    //convert string to int
    stringstream strToInt(priceStr);
    int priceInt=0;
    strToInt>>priceInt;
    price=double(priceInt);
}
//add rank to score
void Image::addToScore(int rank){
    score+=rank;
}
//get width
int Image::getWidth(){
    return width;
}
//get height
int Image::getHeight(){
    return height;
}
//get price
double Image::getPrice(){
    return price;
}
//get area
int Image::getArea(){
    return width*height;
}
//get path
string Image::getPath() {
    return path;
}
//get image
CImg<unsigned char> Image::getImage(){
    return image;
}
//get score
int Image::getScore(){
    return score;
}