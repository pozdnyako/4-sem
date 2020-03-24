#include "Tester.h"
#include "Ellipse.h"
#include <iostream>

void Tester::checkEllipse(int logType) {
    std::string section = "Ellipse";
    {
        std::string name = "eccentricity";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        Point A(-1, 0), B(1, 0);
        double a = 2;
        Ellipse ell(A, B, a);

        bool _res = (is_eql(ell.eccentricity(), 0.5) == true);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }
    {
        std::string name = "center";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        Point A(-1, 0), B(1, 0);
        double a = 2;
        Ellipse ell(A, B, a);

        bool _res = ((ell.center() == Point(0, 0)) == true);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }
}
