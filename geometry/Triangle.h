#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "Polygon.h"
#include "Circle.h"

class Triangle : public Polygon {
public:
    Triangle() {}
    Triangle(const Point&, const Point&, const Point&);

    const Circle circumscribedCircle() const;
    const Circle inscribedCircle() const;

    Point centroid() const;
    Point orthocenter() const;

    const Line EulerLine() const;
    const Circle ninePointsCircle() const;
};

#endif // TRIANGLE_H_INCLUDED
