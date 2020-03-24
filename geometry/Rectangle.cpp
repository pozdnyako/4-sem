#include "Rectangle.h"

std::vector<Point> calcPoints(const Line &d, const Point &A) {
    Point C = (d.getA() + d.getB()) / 2.0f;

    Vector CA(C, A);

    return std::vector<Point>({d.getA(), C, d.getB(), C - CA * 2.0f});
}

Rectangle::Rectangle(const Line &d,  const Point &A) :
    Polygon(calcPoints(d, A)){
}

Point Rectangle::center() const {
    return (vertex[0] + vertex[2]) / 2.0f;
}

const std::pair<Line, Line> Rectangle::diagonals() const {
    return std::make_pair(Line(vertex[0], vertex[2]),
                          Line(vertex[1], vertex[3]));
}

Point findThird(const Point &A, const Point& B) {
    Point C = (A + B) / 2.0f;

    Vector CA(C, A);

    return C + Vector(-CA.y, CA.x);
}

Square::Square(const Point &A, const Point& B):
    Rectangle(Line(A, B), findThird(A, B)) {
}

const Circle Square::circumscribedCircle() const {
    return Circle(center(), Line(vertex[0], vertex[2]).length());
}

#define SQRT_2 1.41421356237

const Circle Square::inscribedCircle() const {
    return Circle(center(), Line(vertex[0], vertex[2]).length() / SQRT_2);
}

#undef SQRT_2
