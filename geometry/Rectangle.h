#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Polygon.h"
#include "Circle.h"

class Rectangle : public Polygon {
public:
    Rectangle() {}
    Rectangle(const Line&, const Point &);

    Point center() const;
    const std::pair<Line, Line> diagonals() const;
};

class Square : public Rectangle {
public:
    Square() {}
    Square(const Point&, const Point&);

    const Circle circumscribedCircle() const;
    const Circle inscribedCircle() const;
};

#endif // RECTANGLE_H_INCLUDED
