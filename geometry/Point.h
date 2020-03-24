#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>

const double EPS = 0.001;
const double PI = 3.14159265358979323846;

bool is_eql(const double &a, const double &b);
bool is_in(const double &x, const double&a, const double &b);

struct Vector;

struct Point {
    Point() {}
    Point(double x, double y):x(x), y(y){}

    double x, y;

    bool operator==(const Point &) const;
    bool operator!=(const Point &) const;

    const Point operator+(const Point &) const;
    const Point operator-(const Point &) const;

    const Point operator/(double) const;
    const Point operator*(double) const;

    const Point operator+(const Vector &) const;
    const Point operator-(const Vector &) const;
};

double dist(const Point &, const Point&);

std::ostream& operator<<(std::ostream&, const Point&);


struct Vector {
    Vector() {}
    Vector(double x, double y):x(x), y(y) {}
    Vector(Point a, Point b):x(b.x - a.x), y(b.y - a.y) {}

    double x, y;

    bool operator==(const Vector&) const;
    bool operator!=(const Vector&) const;

    const Vector operator+(const Vector&) const;

    const Vector operator*(double k) const;
    const double operator*(const Vector&) const;

};

const double vecX(const Vector &, const Vector &);
#endif // POINT_H_INCLUDED
