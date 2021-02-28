//A
// Created by watso on 2/26/2021.
//

#ifndef INC_21S_PA01_WATSON_IMAGE_H
#define INC_21S_PA01_WATSON_IMAGE_H

#include <string>
#include <sstream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

class Image {
private:
    int width;
    int height;
    double price;
    string path;
    CImg<unsigned char> image;

public:
    Image();
    Image(string);

    void setDimensions();
    void setPrice();
    int getWidth();
    int getHeight();
    double getPrice();
    int getArea();
    string getPath();
    CImg<unsigned char> getImage();
};


#endif //INC_21S_PA01_WATSON_IMAGE_H
