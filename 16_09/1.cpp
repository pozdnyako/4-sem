#include <iostream>
#include <cmath>
#include <algorithm>
#include <typeinfo>


class three_d {
    double x, y, z;
public:

    three_d():x(0),y(0),z(0) {}
    three_d(double a, double b, double c ) :
        x(a), y(b), z(c) {}

    friend std::ostream& operator<<(std::ostream&, const three_d&);
};

std::ostream& operator<<(std::ostream& os, const three_d& point) {
    os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<three_d> &ar) {
    for(auto i = ar.begin(); i != ar.end(); i++) {
        os << (*i) << std::endl;
    }

    return os;
}

int main() {
    std::vector<three_d> ar;
    ar.push_back(three_d(1, 2 ,3));
    ar.push_back(three_d(3, 4 ,5));

    std::cout << ar;
}
