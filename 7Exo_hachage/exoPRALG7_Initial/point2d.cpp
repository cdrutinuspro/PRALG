#include "point2d.h"

ostream& operator<<(ostream &os, const Point2D& pt) {
    return os << "(" << pt.x << "," << pt.y << ")";
}
