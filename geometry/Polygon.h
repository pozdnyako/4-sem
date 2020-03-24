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

    virtual double perimeter() const;
    virtual double area() const;

    virtual bool operator==(const Shape& another);
    virtual bool isCongruentTo(const Shape& another);

    virtual bool containsPoint(Point point) const;

    virtual int myType() const {return POLYGON;}


    int vertecesCount() const;
    bool isConvex();

    static bool isPolygon(const std::vector<Point> &, int logType = Tester::NO_LOG);

    const std::vector<Point>& getVertex() const;

protected:
    std::vector<Point> vertex;
};

#endif // POLYGON_H_INCLUDED
