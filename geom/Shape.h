#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include "Point.h"

class Shape {
public:
    Shape() {}

    virtual double perimeter() = 0;
    virtual double area() = 0;

    bool operator==(const Shape& another);
    bool isCongruentTo(const Shape& another);

    virtual bool containsPoint(Point point) = 0;
protected:

    int type = 0;
};

#endif // SHAPE_H_INCLUDED
