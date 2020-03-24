#include <iostream>

/* динамический полиморфизм ?? */
/* удеальная передача */
/* std::clog, std::cerr */
/* паттерн-адаптер */

class Point{
public:
    Point();
    Point(double x, double y);


    double  get_x() const {return x;}
    double  get_y() const {return y;}

    void    set_x(double _x) {x = _x;}
    void    set_y(double _y) {y = _y;}

    void print();


//  friend Point operator+(Point, Point);
    Point operator+(Point);
    Point operator++();     // prefix
    Point operator++(int);  // postfix

    friend std::ostream& operator<<(std::ostream&, const Point&);

private:
    double x, y;

};

/*
Point operator+(Point left, Point right) {
    Point temp;

    temp.x = left.x + right.x;
    temp.y = left.y + right.y;

    return temp;
}
*/

Point Point::operator+(Point right) {
    Point temp;

    temp.x = x + right.x;
    temp.y = y + right.y;

    return temp;
}

Point Point::operator++() {
    x ++;
    y ++;

    return *this;
}

Point Point::operator++(int) {
    x ++;
    y ++;

    return *this;
}

Point::Point() :x(0.0f),
                y(0.0f) {}

Point::Point(double _x, double _y) :x(_x),
                                    y(_y) {}

void Point::print() {
    std::cout << "(" << x << ", " << y << ")";
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point p1 = Point();
    Point p2 = Point(1.2, 5.4);

    p1.set_x(4.3);
    p1.set_y(6.7);

    Point p3 = p1 + p2;

    std::cout << "p1 = " << p1 << std::endl;
    std::cout << "p2 = " << p2 << std::endl;
    std::cout << "p3 = " << p3 << std::endl;

}

/*
ostream& operatior << (ostream&, const int&)
*/

