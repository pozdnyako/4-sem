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


bool Point::operator==(const Point& a) const{
    return is_eql(x, a.x) && is_eql(y, a.y);
}

bool Point::operator!=(const Point& a) const{
    return !is_eql(x, a.x) || !is_eql(y, a.y);
}

const Point Point::operator+(const Point &a) const{
    return Point(x + a.x, y + a.y);
}

const Point Point::operator-(const Point &a) const{
    return Point(x - a.x, y - a.y);
}

const Point Point::operator*(double k) const{
    return Point(x * k, y * k);
}

const Point Point::operator/(double k) const{
    return Point(x / k, y / k);
}

const Point Point::operator+(const Vector& vec) const{
    return Point(x + vec.x, y + vec.y);
}

const Point Point::operator-(const Vector& vec) const{
    return Point(x - vec.x, y - vec.y);
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

bool Vector::operator==(const Vector& a) const {
    return is_eql(x, a.x) && is_eql(y, a.y);
}

bool Vector::operator!=(const Vector& a) const {
    return !is_eql(x, a.x) || !is_eql(y, a.y);
}

const Vector Vector::operator+(const Vector& a) const{
    return Vector(x + a.x, y + a.y);
}

const Vector Vector::operator*(double k) const{
    return Vector(x * k, y * k);
}

const double Vector::operator*(const Vector &a) const{
    return a.x * x + a.y * y;
}

const double vecX(const Vector &a, const Vector &b) {
    return a.x * b.y - b.x * a.y;
}
