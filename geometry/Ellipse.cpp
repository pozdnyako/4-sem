#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse(const Point& _A, const Point &_B, double _a) :
    A(_A),
    B(_B),
    a(_a) {

    if(dist(_A, _B) > 2 * a)
        std::cout << "ERROR\t" << "wrong points at Ellipse::Ellipse(const Point&, const Point&, double)" << std::endl;
    else {
        double c = dist(A, B) / 2;
        b = sqrt(a*a - c*c);
    }
}

double Ellipse::perimeter() const {
    return 4 * (PI * a * b + a - b) / (a + b);
}

double Ellipse::area() const {
    return PI * a * b;
}

bool Ellipse::operator==(const Shape &another) {
    if(myType() != another.myType())
        return false;

    const Ellipse &ellipse = static_cast<const Ellipse&>(another);

    if(ellipse.getA() != A || ellipse.getB() != B || ellipse.geta() != a) {
        return false;
    }

    return true;
}

bool Ellipse::isCongruentTo(const Shape &another) {
    if(myType() != another.myType())
        return false;

    const Ellipse &ellipse = static_cast<const Ellipse&>(another);

    if((ellipse.getA() != A || ellipse.getB() != B || ellipse.geta() != a) &&
       (ellipse.getA() != B || ellipse.getB() != A || ellipse.geta() != a) ){
        return false;
    }

    return true;
}

bool Ellipse::containsPoint(Point point) const {
    double _dist = dist(point, A) + dist(point, B);
    return (_dist < 2 * a);
}

std::pair<Point, Point> Ellipse::focuses() const {
    return std::make_pair(A, B);
}

double Ellipse::eccentricity() const {
    return dist(A, B) / 2 / a;
}

Point Ellipse::center() const {
    Point C = (A + B);
    C = C / 2.0f;
    return C;
}

