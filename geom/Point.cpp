#include "Point.h"

bool is_eql(const double &a, const double &b) {
    double d = (a-b);
    return d > -EPS && d < EPS;
}


bool Point::operator==(const Point& a) {
    return x == a.x && y == a.y;
}

bool Point::operator!=(const Point& a) {
    return (x != a.x) || (y != a.y);
}

Point Point::operator+(const Point &a) {
    return Point(x + a.x, y + a.y);
}

std::ostream& operator<<(std::ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
