#include <iostream>
#define cimg_use_jpeg 1
#include "CImg.h"
#include <string>

using namespace std;
using namespace cimg_library;

int main(int argc, char** argv) {
    CImg<unsigned char> image("test1.JPG"), visu(500,400,1,3,0);
    const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
    image.blur(2.5);
    CImgDisplay main_disp(image,"Click a point"), draw_disp(visu,"Intensity profile");
    while (!main_disp.is_closed() && !draw_disp.is_closed()) {
        main_disp.wait();
        if (main_disp.button() && main_disp.mouse_y()>=0) {
            const int y = main_disp.mouse_y();
            visu.fill(0).draw_graph(image.get_crop(0,y,0,0,image.width()-1,y,0,0),red,1,1,0,255,0);
            visu.draw_graph(image.get_crop(0,y,0,1,image.width()-1,y,0,1),green,1,1,0,255,0);
            visu.draw_graph(image.get_crop(0,y,0,2,image.width()-1,y,0,2),blue,1,1,0,255,0).display(draw_disp);
        }
    }

    return 0;
}

//how to open ubuntu files
// \\wsl$
//important commands
//export DISPLAY=$(awk '/nameserver / {print $2; exit}' /etc/resolv.conf 2>/dev/null):0
//export LIBGL_ALWAYS_INDIRECT=1
//cat /etc/resolv.conf
//xeyes
//edit configurations - environment variables
//DISPLAY=172.28.240.1:0.0

//TODO
//learn cimg
//set up github

//cimg example
/*
CImg<unsigned char> img(640,400,1,3);         // Define a 640x400 color image with 8 bits per color component.
img.fill(0);                                  // Set pixel values to 0 (color : black)
unsigned char purple[] = { 255,0,255 };       // Define a purple color
img.draw_text(100,100,"Hello World",purple);  // Draw a purple "Hello world" at coordinates (100,100).
img.display("Window Title");                  // Display the image in a display window.
img.save_png("test.png");                     // Save as PNG to prove we linked correctly
img.save_jpeg("test.jpg");                    // Save as JPG to prove we linked correctly
*/