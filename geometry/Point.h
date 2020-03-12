#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>

const double EPS = 0.001;
bool is_eql(const double &a, const double &b);
bool is_in(const double &x, const double&a, const double &b);

struct Point {
    Point() {}
    Point(double x, double y):x(x), y(y){}

    double x, y;

    bool operator==(const Point &);
    bool operator!=(const Point &);

    Point operator+(const Point &);
};

double dist(const Point &, const Point&);

std::ostream& operator<<(std::ostream&, const Point&);


struct Vector {
    Vector() {}
    Vector(double x, double y):x(x), y(y) {}
    Vector(Point a, Point b):x(b.x - a.x), y(b.y - a.y) {}

    double x, y;

    bool operator==(const Vector&);
    bool operator!=(const Vector&);

    Vector operator+(const Vector&);

    Vector operator*(double k);
    double operator*(const Vector&);

};

double vecX(const Vector &, const Vector &);
#endif // POINT_H_INCLUDED
