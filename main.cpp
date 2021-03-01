#define cimg_use_jpeg 1
#include "CImg.h"
#include <string>
#include <iostream>
#include "WallFiller.h"

using namespace std;
using namespace cimg_library;

int main(int argc, char** argv) {
    //COMMAND LINE ARGUMENTS FORMAT EXAMPLE - "../program1 10000 4000 12000 4000" - file path, wall 1 width, wall 1 height, wall 2 width, wall 2 height
    //create wall filler
    WallFiller filler1=WallFiller(argv[1]);
    //fill walls 1 and 2 with 3 algorithms
    cout<<"Filling Walls..."<<endl;
    filler1.fillWall(atoi(argv[2]),atoi(argv[3]),atoi(argv[4]),atoi(argv[5]));
    cout<<"...Complete"<<endl;
     //output algorithm stats with wall 1 and wall 2
    filler1.outputStats();

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