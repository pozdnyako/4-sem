#include "Point.h"
#include <cmath>

bool is_eql(const double &a, const double &b) {
    double d = (a-b);
    return d > -EPS && d < EPS;
}

bool is_in(const double &x, const double &a, const double &b) {
    return (x >= a && x <= b) ||
           (x >= b && x <= a);
}


bool Point::operator==(const Point& a) {
    return is_eql(x, a.x) && is_eql(y, a.y);
}

bool Point::operator!=(const Point& a) {
    return !is_eql(x, a.x) || !is_eql(y, a.y);
}

Point Point::operator+(const Point &a) {
    return Point(x + a.x, y + a.y);
}

std::ostream& operator<<(std::ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

double dist(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

bool Vector::operator==(const Vector& a) {
    return is_eql(x, a.x) && is_eql(y, a.y);
}

bool Vector::operator!=(const Vector& a) {
    return !is_eql(x, a.x) || !is_eql(y, a.y);
}

Vector Vector::operator+(const Vector& a) {
    return Vector(x + a.x, y + a.y);
}

Vector Vector::operator*(double k) {
    return Vector(x * k, y * k);
}

double Vector::operator*(const Vector &a){
    return a.x * x + a.y * y;
}

double vecX(const Vector &a, const Vector &b) {
    return a.x * b.y - b.x * a.y;

}
