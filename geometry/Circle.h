#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Ellipse.h"

class Circle : public Ellipse {
public:
    Circle() {}
    Circle(const Point&, double);

    double radius() const { return a; }
};


#endif // CIRCLE_H_INCLUDED
