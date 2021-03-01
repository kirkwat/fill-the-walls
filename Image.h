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
    int score;

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
