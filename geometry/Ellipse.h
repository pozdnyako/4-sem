#ifndef ELLIPSE_H_INCLUDED
#define ELLIPSE_H_INCLUDED

#include "Shape.h"

class Ellipse : public Shape {
public:
    Ellipse() {}
    Ellipse(const Point&, const Point&, double);

    virtual double perimeter() const;
    virtual double area() const;

    virtual bool operator==(const Shape& another);
    virtual bool isCongruentTo(const Shape& another);

    virtual bool containsPoint(Point point) const;

    virtual int myType() const {return ELLIPSE;}

    std::pair<Point, Point> focuses() const;
    double eccentricity() const;
    Point center() const;

    Point getA() const { return A; }
    Point getB() const { return B; }
    double geta() const { return a; }
protected:
    Point A, B;
    double a, b;
};


#endif // ELLIPSE_H_INCLUDED
