#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    for(int n = 1; n < 100; n ++) {
        std::cout.width(10);
        std::cout.fill(' ');
        std::cout.precision(5);
        std::cout.setf(std::ios::right);
        std::cout << n;

        std::cout.width(10);
        std::cout.fill(' ');
        std::cout.precision(5);
        std::cout.setf(std::ios::right);
        std::cout << log(n);

        std::cout.width(10);
        std::cout.fill(' ');
        std::cout.precision(5);
        std::cout.setf(std::ios::right);
        std::cout << log10(n);

        std::cout << "\n";
    }
}
