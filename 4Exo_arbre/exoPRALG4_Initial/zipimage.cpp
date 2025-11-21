#include <Imagine/Graphics.h>
#include <iostream>
#include "quadtree/quadtree.h"

using namespace Imagine;
using namespace std;

// The path and name of the town file
const string default_image_file=srcPath("running-horse-square.png");

int main(int argc, char **argv) {
    string image_file = (argc>1)? argv[1]: default_image_file;
    octet* image;
    int width, height;
    cout << "Loading image: " << image_file << endl; 
    if(! loadGreyImage(image_file, image, width, height)) {
        cerr << "Error loading image file " << image_file << endl;
        return 1;
    }

    // Print statistics
    cout << "Image size: " << width << "x" << height << endl;
    cout << "Number of pixels: " << width*height << endl;

    // Display image
    Window window = openWindow(width, height);
    putGreyImage(0, 0, image, width, height);

    closeWindow(window);
    endGraphics();
    return 0;
}
