#pragma once

#include <iostream>
using std::ostream;

// A 2D point given by (x,y) coordinates
class Point2D {
public:
    // Coordinates
    float x, y;
    // Create a new 2D point with given coordinates
    Point2D(float x0, float y0) : x(x0), y(y0) {}
};

// Display 2D point
ostream& operator<<(ostream &os, const Point2D& pt);
