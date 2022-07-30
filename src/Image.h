//Kirk Watson - 47876885 - CS3353
#ifndef INC_21S_PA01_WATSON_IMAGE_H
#define INC_21S_PA01_WATSON_IMAGE_H

#include <string>
#include <sstream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

//This class contains the image object that will store the image itself
//as well as value information such as value and dimensions.
class Image {
private:
    int width;                  //width of image
    int height;                 //height of image
    double price;               //value of image
    string path;                //file path to image
    CImg<unsigned char> image;  //actual image
    int score;                  //score used for myDesign algorithm

public:
    Image();
    Image(string);

    void setDimensions();
    void setPrice();
    void addToScore(int);
    int getWidth();
    int getHeight();
    double getPrice();
    int getArea();
    string getPath();
    CImg<unsigned char> getImage();
    int getScore();
};


#endif //INC_21S_PA01_WATSON_IMAGE_H
