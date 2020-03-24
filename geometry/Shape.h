#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include "Point.h"

class Shape {
public:
    Shape() {}

    virtual double perimeter() const = 0;
    virtual double area() const = 0;

    virtual bool operator==(const Shape& another);
    virtual bool isCongruentTo(const Shape& another);

    virtual bool containsPoint(Point point) const = 0;

    static const int POLYGON = 1;
    static const int ELLIPSE = 2;

    virtual int myType()const = 0;
};

#endif // SHAPE_H_INCLUDED
