#include <Imagine/Graphics.h>
#include <algorithm>
#include <iostream>
#include "quadtree/quadtree.h"

using namespace std;
using namespace Imagine;

// Initializations
QuadLeaf<bool>* black_leaf = new QuadLeaf<bool>(true);
QuadLeaf<bool>* white_leaf = new QuadLeaf<bool>(false);

/// Return the smallest power of 2 that is larger than both w and h
int pow2max(int w, int h) {
    int wmax=1, hmax=1;
    w--, h--;
    while(w>0) { w /= 2; wmax *= 2; }
    while(h>0) { h /= 2; hmax *= 2; }
    return max(wmax,hmax);
}

// --- Encode B/W ---

/// Return quadtree encoding image region (x,y)-(x+d-1,y+d-1)
QuadTree<bool>* encodeBW(const octet* image, int w, int h, int x, int y, int d) {
    if(x>=w || y>=h) // If coordinates are out of bounds
        return QuadTree<bool>::protect_leaves_from_destruction?
            white_leaf: new QuadLeaf<bool>(false);
    if(d==1) {
        if(QuadTree<bool>::protect_leaves_from_destruction)
            return (image[x+y*w]==0)? black_leaf: white_leaf;
        return new QuadLeaf<bool>(image[x+y*w]==0);
    }
    // If the image size is more than 1: encode the quadrants
    int d2 = d/2;
    QuadTree<bool>* nw = encodeBW(image, w, h, x,    y,    d2);
    QuadTree<bool>* ne = encodeBW(image, w, h, x+d2, y,    d2);
    QuadTree<bool>* se = encodeBW(image, w, h, x+d2, y+d2, d2);
    QuadTree<bool>* sw = encodeBW(image, w, h, x,    y+d2, d2);
    // If they all are leaves with identical values
    if(nw->isLeaf() && ne->isLeaf() && se->isLeaf() && sw->isLeaf() &&
       nw->value() == ne->value() &&
       ne->value() == se->value() &&
       se->value() == sw->value()) {
        if(! QuadTree<bool>::protect_leaves_from_destruction) {
            delete ne; delete se; delete sw;            
        }
        return nw;
    }
    return new QuadNode<bool>(nw, ne, se, sw);
}

/// Return quadtree encoding image (non necessarily square or power of 2)
QuadTree<bool>* encodeBW(octet* image, int w, int h) {
    return encodeBW(image, w, h, 0, 0, pow2max(w,h));
}

// --- Encode Grey ---

/// Return quadtree encoding image region (x,y)-(x+d-1,y+d-1)
QuadTree<octet>* encodeGrey(const octet* image, int w, int h, int x, int y, int d,
                           int threshold=10) {
    if(x>=w || y>=h) // If coordinates are out of bounds
        return new QuadLeaf<octet>(255);
    if(d==1)
        return new QuadLeaf<octet>(image[x+y*w]);
    // If the image size is more than 1: encode the quadrants
    int d2 = d/2;
    QuadTree<octet>* nw = encodeGrey(image, w, h, x,    y,    d2);
    QuadTree<octet>* ne = encodeGrey(image, w, h, x+d2, y,    d2);
    QuadTree<octet>* se = encodeGrey(image, w, h, x+d2, y+d2, d2);
    QuadTree<octet>* sw = encodeGrey(image, w, h, x,    y+d2, d2);
    if(nw->isLeaf() && ne->isLeaf() && se->isLeaf() && sw->isLeaf()) {
        octet v = (nw->value() + ne->value() + se->value() + sw->value())/4;
        if(abs(nw->value()-v) <= threshold && abs(ne->value()-v) <= threshold &&
           abs(se->value()-v) <= threshold && abs(sw->value()-v) <= threshold) {
            delete nw; delete ne; delete se; delete sw;
            return new QuadLeaf<octet>(v);
        }
    }
    return new QuadNode<octet>(nw, ne, se, sw);
}

/// Return quadtree encoding image (non necessarily square or power of 2)
QuadTree<octet>* encodeGrey(octet* image, int w, int h) {
    return encodeGrey(image, w, h, 0, 0, pow2max(w,h));
}

// --- Decode BW ---

/// Fill image region (x,y)-(x+d-1,y+d-1) from quadtree
void decode(octet* image, int w, int h, int x, int y, int d,
            const QuadTree<bool>* t, bool drawSquare) {
    if(! t->isLeaf()) {
        int d2 = d/2;
        decode(image, w, h, x,    y,    d2, t->child(NW), drawSquare);
        decode(image, w, h, x+d2, y,    d2, t->child(NE), drawSquare);
        decode(image, w, h, x+d2, y+d2, d2, t->child(SE), drawSquare);
        decode(image, w, h, x,    y+d2, d2, t->child(SW), drawSquare);
        return;
    }

    int xmax = min(w,x+d), ymax = min(h,y+d);
    for(int j=y; j<ymax; j++)
        for(int i=x; i<xmax; i++)
            image[i+j*w] = t->value()? 0: 255;
    // Possibly draw square
    if(drawSquare && d >= 16) {
        if(y<ymax)
            for(int i=x; i<xmax; i++) {
                image[i+y       *w] = 127;
                image[i+(ymax-1)*w] = 127;
            }
        if(x<xmax)
            for(int j=y+1; j<ymax-1; j++) {
                image[x     +j*w] = 127;
                image[xmax-1+j*w] = 127;
            }
    }
}

/// Fill image from quadtree
void decode(octet* image, int w, int h, const QuadTree<bool>* t,
            bool drawSquare=true) {
    return decode(image, w, h, 0, 0, pow2max(w,h), t, drawSquare);
}

// --- Decode Grey ---

/// Fill image region (x,y)-(x+d-1,y+d-1) from quadtree
void decode(octet* image, int w, int h, int x, int y, int d,
            const QuadTree<octet>* t, bool drawSquare) {
    if(! t->isLeaf()) {
        int d2 = d/2;
        decode(image, w, h, x,    y,    d2, t->child(NW), drawSquare);
        decode(image, w, h, x+d2, y,    d2, t->child(NE), drawSquare);
        decode(image, w, h, x+d2, y+d2, d2, t->child(SE), drawSquare);
        decode(image, w, h, x,    y+d2, d2, t->child(SW), drawSquare);
        return;
    }

    int xmax = min(w,x+d), ymax = min(h,y+d);
    for(int j=y; j<ymax; j++)
        for(int i=x; i<xmax; i++)
            image[i+j*w] = t->value();
    // Possibly draw square
    if(drawSquare && d >= 16) {
        if(y<ymax)
            for(int i=x; i<xmax; i++) {
                image[i+y       *w] = 127;
                image[i+(ymax-1)*w] = 127;
            }
        if(x<xmax)
            for(int j=y+1; j<ymax-1; j++) {
                image[x     +j*w] = 127;
                image[xmax-1+j*w] = 127;
            }
    }
}

/// Fill image from quadtree
void decode(octet* image, int w, int h, const QuadTree<octet>* t,
            bool drawSquare=false) {
    return decode(image, w, h, 0, 0, pow2max(w,h), t, drawSquare);
}

// --- main ---

int main(int argc, char **argv) {
    string imageBW = (argc>1)? argv[1]: srcPath("running-horse-rect.png");
    string imageColor = (argc>2)? argv[2]: srcPath("lena.jpg");

    // --- BW ---
    // Load image
    octet* image;
    int width, height;
    cout << "Loading image: " << imageBW << endl; 
    if(! loadGreyImage(imageBW, image, width, height)) {
        cerr << "Unable to load image " << imageBW << endl;
        return 1;
    }
    std::cout << "Image size: " << width << "x" << height << endl;

    // Display image
    Window window = openWindow(width, height);
    putGreyImage(IntPoint2(0,0), image, width, height);
    click();

    // Compress image
    QuadTree<bool>::protect_leaves_from_destruction = true;
    QuadTree<bool>* qtree = encodeBW(image, width, height);
    delete [] image;

    // Print statistics
    cout << "Number of pixels: " << width*height
         << ", bits: "           << width*height/8<< endl;
    cout << "Tree size:        ";
    cout << (QuadTree<bool>::protect_leaves_from_destruction?
        qtree->nNodes() *sizeof(QuadNode<bool>) + 2*sizeof(QuadLeaf<bool>):
        qtree->nNodes() *sizeof(QuadNode<bool>)+
        qtree->nLeaves()*sizeof(QuadLeaf<bool>)) << endl;

    // Decompress image
    octet* output = new octet[width*height];    
    decode(output, width, height, qtree); delete qtree;
    putGreyImage(IntPoint2(0,0), output, width, height);
    delete [] output;
    click(); closeWindow(window);

    // --- Grey ---
    // Load image
    octet *r, *g, *b;
    cout << "Loading image: " << imageColor << endl; 
    if(! loadColorImage(imageColor, r,g,b, width, height)) {
        cerr << "Unable to load image " << imageColor << endl;
        return 1;
    }
    std::cout << "Image size: " << width << "x" << height << endl;

    // Display image
    window = openWindow(width, height); setActiveWindow(window);
    putGreyImage(IntPoint2(0,0), r, width, height);
    click();

    // Compress image
    QuadTree<octet>* rtree = encodeGrey(r, width, height);

    // Print statistics
    cout << "Number of pixels: " << width*height << endl;
    cout << "Tree size:        ";
    cout << rtree->nNodes() *sizeof(QuadNode<octet>)+
            rtree->nLeaves()*sizeof(QuadLeaf<octet>) << endl;

    // Decompress image
    octet* R = new octet[width*height];
    decode(R, width, height, rtree); delete rtree;
    putGreyImage(IntPoint2(0,0), R, width, height);
    click();

    // --- Color ---
    putColorImage(IntPoint2(0,0), r, g, b, width, height);
    QuadTree<octet>* gtree = encodeGrey(g, width, height);
    QuadTree<octet>* btree = encodeGrey(b, width, height);
    octet *G = new octet[width*height], *B = new octet[width*height];
    decode(G, width, height, gtree); delete gtree;
    decode(B, width, height, btree); delete btree;
    click();
    putColorImage(IntPoint2(0,0), R, G, B, width, height);

    delete [] r; delete [] g; delete [] b;
    delete [] R; delete [] G; delete [] B;
    endGraphics();
    return 0;
}
