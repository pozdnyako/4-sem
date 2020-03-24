#include <iostream>
#include <new>
#include <cmath>

class MathEx {
public:
    virtual std::string what() = 0;
};

class ErrNew : public MathEx {
public:
    std::string what() { return std::string("bad_alloc at Math"); }
};

class DiaEx : public MathEx {
public:
    std::string what() { return std::string("Not Triangle"); }
};

struct Point {
    Point() {}
    Point(double x, double y):x(x), y(y){}

    double x, y;
};

std::ostream& operator<<(std::ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

double dist(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

class Triangle {
public:
    Triangle(const Point&, const Point&, const Point&);

private:
    Point* points;
};

Triangle::Triangle(const Point& a, const Point& b, const Point& c) {
    try{
        points = new Point[100000000000000];
    } catch(std::bad_alloc &ba) {
        throw ErrNew();
    }
}

int main() {
    try{
        Triangle(Point(0,0), Point(0,0), Point(0,0));
    } catch(ErrNew &en) {
        std::cout << en.what();
    }

}
