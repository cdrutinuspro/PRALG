#include "point2d.h"

// Test if two points are equal
bool Point2D::operator==(const Point2D &pt) const {
    return _x == pt._x && _y == pt._y;
}

// Order the points
bool Point2D::operator<(const Point2D &pt) const {
    return _x < pt._x || (_x == pt._x && _y < pt._y);
}

//
// Display 2D point
//
std::ostream &operator<<(std::ostream &os, Point2D const &pt) {
    return os << "(" << pt.x() << "," << pt.y() << ")";
}
std::ostream &operator<<(std::ostream &os, Point2D* const &p) {
    return os << *p;
}
