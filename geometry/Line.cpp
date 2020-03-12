#include "Line.h"
#include <iostream>
#include <cmath>

Line::Line(Point _A, Point _B) {
    if(_A == _B){
        std::cout << "[ERROR]\t" << "Line(const Point& a, const Point& b)" << std::endl;
    }
    A = _A;
    B = _B;

    updateAB();
    updateCoef();
}

Line::Line(Point _A, double k, double dx) {
    if(dx == 0.0) {
        std::cout << "[ERROR]\t" << "Line(const Point& a, double k, double l)" << std::endl;
    }
    A = _A;
    B = _A + Point(dx, dx * k);

    updateAB();
    updateCoef();
}

void Line::updateCoef() {
    a = A.y - B.y;
    b = B.x - A.x;
    c = - a * A.x - b * A.y;

    double z = sqrt(a * a + b * b);
    a /= z, b /= z, c /= z;

    if(a < 0.0f){
        a *= -1.0f, b *= -1.0f, c *= -1.0f;
    }
}

void Line::updateAB() {
    if(B.x < A.x)
        std::swap(A, B);
}

bool Line::operator==(const Line &a) {
    return (A == a.A && B == a.B) || (A == a.B && B == a.A);
}

bool Line::operator!=(const Line &a) {
    return (A != a.A || B != a.B) && (A != a.B || B != a.A);
}

std::ostream& operator<<(std::ostream& out, const Line& line) {
    out << line.A << "->" << line.B << ", "
        << line.a << "*x + " << line.b << "*y + " << line.c;
}

Point Line::getA() {
    return A;
}

Point Line::getB() {
    return B;
}

int Line::checkCross(Line a, Line b, std::vector<Point> *res, bool addToVector) {
    int n_point = 0;

    if(a.A.x > b.A.x)
        std::swap(a, b);

    if(is_eql(a.a, b.a) && is_eql(a.b, b.b)) {
        if(is_eql(a.c, b.c)){

            if(a.B.x > b.A.x) {
                n_point = 2;

                if(addToVector) res->push_back(b.A);

                if(b.B.x > a.B.x){
                    if(addToVector) res->push_back(a.B);
                } else {
                    if(addToVector) res->push_back(b.B);
                }

                return n_point;
            } else {
                return 0;
            }
        } else {

            return 0;
        }
    } else {
        double den = a.a * b.b - a.b * b.a;

        Point predict(-(a.c * b.b - b.c * a.b) / den,
                      -(a.a * b.c - b.a * a.c) / den);

        if(predict.x >= a.A.x && predict.x <= a.B.x &&
           predict.y >= a.A.y && predict.y <= a.B.y) {
            n_point = 1;

            if(addToVector) res->push_back(predict);

            return 1;
        } else{
            return 0;
        }
    }

    return -1;
}


