#include <iostream>

#include "Tester.h"
#include "Polygon.h"

int main() {
    Tester tester;

    tester.checkLineCrossing(Tester::NO_LOG);
    tester.checkIsPolygon(Tester::NO_LOG);
    tester.checkPolygon(Tester::NO_LOG);

    tester.Log(Tester::ALL_TESTS);

    std::vector<Point> points{Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)};
    Polygon poly(points);

    std::cout << poly.perimeter();
}
