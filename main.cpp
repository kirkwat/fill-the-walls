#define cimg_use_jpeg 1
#include "CImg.h"
#include <string>
#include <iostream>
#include "WallFiller.h"

using namespace std;
using namespace cimg_library;

int main(int argc, char** argv) {
    //create wall filler
    WallFiller filler1=WallFiller(argv[1]);


    //test wall
    filler1.fillWall(1000,1000,1);
    //test stats
    //filler1.outputStats();

    //TODO change to have the two walls made at the same time with different images

    /*
    //fill wall 1 with 3 algorithms
    cout<<"Filling Wall 1..."<<endl;
    filler1.fillWall(stoi(argv[2]),stoi(argv[3]),1);
    cout<<"...Complete"<<endl<<endl;
    //wall 2 with 3 algorithms
    cout<<"Filling Wall 2..."<<endl;
    filler1.fillWall(stoi(argv[4]),stoi(argv[5]),2);
    cout<<"...Complete"<<endl;
     //output algorithm stats with wall 1 and wall 2
    filler1.outputStats();
     */






    //todo cimg example 1
    /*
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
    */
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
    return 0;
}


//width by height


//how to open ubuntu files
    // \\wsl$
//important commands
    //export DISPLAY=$(awk '/nameserver / {print $2; exit}' /etc/resolv.conf 2>/dev/null):0
    //export LIBGL_ALWAYS_INDIRECT=1
    //cat /etc/resolv.conf
    //xeyes
//edit configurations - environment variables
    //DISPLAY=172.28.240.1:0.0

//TODO plan
//learn cimg
//navigate directory - use dirent from search engine
//put images on a blank canvas
//figure out file input
//start sorting
//output results


//deliverables
    //6 images
        //3 wall 1, 3 wall 2
        //3 different algos
    //text file with info for each algo
        //wall 1 value
        //wall 2 value
        //wall 1 % wasted space
        //wall 2 % wasted space
        //total profit?


//TO DO fix
    //absolute path
        //does it need to be in ubuntu files