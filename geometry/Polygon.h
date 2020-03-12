#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

#include "Shape.h"
#include "Line.h"
#include "Tester.h"
#include <vector>

class Polygon : public Shape {
public:
    Polygon() {}
    Polygon(const std::vector<Point> &);

    int vertecesCount();

    bool isConvex();

    static bool isPolygon(std::vector<Point> &, int logType = Tester::NO_LOG);
private:
    std::vector<Point> vertex;
};

#endif // POLYGON_H_INCLUDED
