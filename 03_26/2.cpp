#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

int main() {
    for(int n = 1; n < 100; n ++) {
        std::cout << std::setw(10) << std::right << std::setfill(' ') << n <<
                     std::setw(10) << std::right << std::setfill(' ') << log(n) <<
                     std::setw(10) << std::right << std::setfill(' ') << log10(n) << std::endl;
    }
}
