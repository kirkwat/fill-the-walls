//
// Created by watso on 2/26/2021.
//

#include "Image.h"
//default constructor
Image::Image() {
    path="NULL";
    width=-1;
    height=-1;
    price=-1;
}
//overloaded constructor with path
Image::Image(string p){
    path=p;
    setPrice();
    setDimensions();
}
//set dimensions of image
void Image::setDimensions() {
    image=CImg<unsigned char>(path.c_str());
    width = image.width();
    height = image.height();
}
//set price
void Image::setPrice(){
    string priceStr=path.substr(path.find_last_of('/')+1,path.find_last_of('.')-path.find_last_of('/')-1);
    stringstream strToInt(priceStr);
    int priceInt=0;
    strToInt>>priceInt;
    price=double(priceInt);
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