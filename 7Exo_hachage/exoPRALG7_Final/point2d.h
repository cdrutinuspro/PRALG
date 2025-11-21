#pragma once

#include <iostream>

/*
 * A 2D point given by (x,y) coordinates
 */
class Point2D
{
    // Coordinates
    float _x, _y;
public:
    // Create a new 2D point with given coordinates
    Point2D(float x, float y) : _x(x), _y(y) {}
    // Get coordinates
    inline float x() const { return _x; }
    inline float y() const { return _y; }
    // Test if two points are equal
    bool operator==(const Point2D &pt) const;
    // Order the points
    bool operator<(const Point2D &pt) const;
};

//
// Display 2D point
//
std::ostream &operator<<(std::ostream &os, Point2D const &pt);
std::ostream &operator<<(std::ostream &os, Point2D* const &p);
