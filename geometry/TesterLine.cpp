#include "Tester.h"
#include "Line.h"
#include <iostream>

int checkLineCrossingFullLoger(int logType, Line &l1, Line &l2, int &n_res, std::vector<Point> &res) {
    if(logType >= Tester::FULL_LOG) {
        std::cout << l1 << std::endl << l2 << std::endl << "cross points " << n_res << ":" << std::endl;
        for(int i = res.size() - n_res; i < res.size(); i ++) {
            std::cout << "\t" << res[i] << std::endl;
        }
        std::cout << std::endl;
    }
}

void Tester::checkLineCrossing(int logType) {

    std::string section("Line::checkCrossing()");

    std::vector<Point> res;
    int n_tests = 0;
    {
        std::string name = "simple crossing 1";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        Line l1(Point(0, 0), Point(1, 1)), l2(Point(0, 1), Point(1, 0));
        int n_res = Line::checkCross(l1, l2, &res, true);

        bool _res = (n_res == 1 && res[res.size() - 1] == Point(0.5, 0.5));
        testResult.push_back(TestResult(section, name, _res));
        checkLineCrossingFullLoger(logType, l1, l2, n_res, res);
        n_tests ++;
    }
    {
        std::string name = "simple crossing 2";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        Line l1(Point(0, 0), Point(0, 2)), l2(Point(0.5, 1), Point(2, 2));
        int n_res = Line::checkCross(l1, l2, &res, true);

        bool _res = (n_res == 0);
        testResult.push_back(TestResult(section, name, _res));
        checkLineCrossingFullLoger(logType, l1, l2, n_res, res);
        n_tests ++;
    }
    {
        std::string name = "parallel";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        Line l1(Point(0, 0), Point(1, 0)), l2(Point(0, 1), Point(1, 1));
        int n_res = Line::checkCross(l1, l2, &res, true);

        bool _res = (n_res == 0);
        testResult.push_back(TestResult(section, name, _res));
        checkLineCrossingFullLoger(logType, l1, l2, n_res, res);
        n_tests ++;
    }
    {
        std::string name = "overlap";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        Line l1(Point(0, 0), Point(2, 0)), l2(Point(0, 0), Point(1, 0));
        int n_res = Line::checkCross(l1, l2, &res, true);

        bool _res = (n_res == 2 && res[res.size() - 2] == Point(0, 0) &&
                                   res[res.size() - 1] == Point(1, 0));
        testResult.push_back(TestResult(section, name, _res));
        checkLineCrossingFullLoger(logType, l1, l2, n_res, res);
        n_tests ++;
    }
    {
        std::string name = "containing";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        Line l1(Point(0, 0), Point(3, 0)), l2(Point(1, 0), Point(2, 0));
        int n_res = Line::checkCross(l1, l2, &res, true);

        bool _res = (n_res == 2 && res[res.size() - 2] == Point(1, 0) &&
                                   res[res.size() - 1] == Point(2, 0));
        testResult.push_back(TestResult(section, name, _res));
        checkLineCrossingFullLoger(logType, l1, l2, n_res, res);
        n_tests ++;
    }

    if(logType > SHORT_SECTION_LOG) {
        std::cout << std::endl;
    }

    sectionLog(section, logType);
}

