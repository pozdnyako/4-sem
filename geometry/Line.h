#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include "Point.h"
#include <vector>

class Line{
public:
    Line() {}
    Line(Point, Point);
    Line(Point, double k, double dx);

    bool operator==(const Line&);
    bool operator!=(const Line&);
    friend std::ostream& operator<<(std::ostream&, const Line&);

    Point getA();
    Point getB();

    static int checkCross(Line, Line, std::vector<Point> *, bool addToVector = false);
private:
    Point A, B;
    double a, b, c;

    void updateCoef();
    void updateAB();

};

std::ostream& operator<<(std::ostream&, const Line&);


#endif // LINE_H_INCLUDED
