#include <iostream>

#include "Tester.h"

#include "Point.h"
#include "Line.h"

int main() {
    Tester tester;

    tester.checkLineCrossing(Tester::NO_LOG);
    tester.checkIsPolygon(Tester::NO_LOG);

    tester.Log(Tester::ALL_TESTS);
}
