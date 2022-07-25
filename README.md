# Fill the Walls - CS 3353 Project 1
Developed and maintained by Kirk Watson.

Email: klwatson@smu.edu

Class: Algorithms CS 3353 - Spring 2021

Southern Methodist University

## Functionality
This program takes a group of images with monetary values and efficiently places them on 2 different walls.
There are 3 different ways to place the images on the wall which include smallest first, most expensive first, and a combination of both.
This program is designed to use all 3 algorithms for both walls resulting in 6 total images.

In addition, a final stats file will be created with information on each of the walls generated.
This data includes total wall value, wall space that is not used, and total profit for the given algorithm.

## How to Use
To use this program, the user will need to provide some command-line arguments and an image folder.

### There are 5 command-line arguments:
* Directory name of images
* Wall 1 width
* Wall 1 height
* Wall 2 width
* Wall 2 height

Here is an example:

`./placement images/set1/ 10000 4000 12000 4000`

### Image folder
This folder will contain JPEG images. Each image will have a numbered file name to represent its value.
