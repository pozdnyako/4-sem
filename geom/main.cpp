#include <iostream>

#include "Point.h"
#include "Line.h"

int main() {
    Line l1(Point(0, 0), Point(4, 4));
    Line l2(Point(1, 1), Point(5, 5));

    std::cout << l1 << std::endl << l2 << std::endl;

    std::vector<Point> res;
    int n_res = Line::checkCross(l1, l2, &res, true);

    std::cout << n_res << ":" << std::endl;
    for(int i = 0; i < n_res; i ++) {
        std::cout << "\t" << res[i] << std::endl;
    }
    std::cout << std::endl;
}
