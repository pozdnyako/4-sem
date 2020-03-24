#include "Tester.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#include <iostream>

void Tester::checkShape(int logType) {
    std::string section = "Shape operator==";
    {
        std::string name = "polygon and ellipse";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        Point A(-1, 0), B(1, 0);
        double a = 2;
        Ellipse ell(A, B, a);

        std::vector<Point> points{Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)};
        Polygon poly(points);

        Shape *_ell = &ell, *_poly = &poly;

        bool _res = ((*_ell == *_poly) == false);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }
    {
        std::string name = "polygon and sqare";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        std::vector<Point> points{Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)};
        Polygon poly(points);

        Square sq(Point(0,0), Point(2,2));

        Shape *_sq = &sq, *_poly = &poly;

        bool _res = ((*_sq == *_poly) == false);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }
}
