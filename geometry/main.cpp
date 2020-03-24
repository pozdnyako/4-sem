#include <iostream>

#include "Tester.h"
#include "Polygon.h"

int main() {
    Tester tester;

    tester.checkLineCrossing(Tester::NO_LOG);
    tester.checkIsPolygon(Tester::NO_LOG);
    tester.checkPolygon(Tester::NO_LOG);
    tester.checkEllipse(Tester::NO_LOG);
    tester.checkShape(Tester::NO_LOG);

    tester.Log(Tester::ALL_TESTS);
}
