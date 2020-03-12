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

int Tester::checkLineCrossing(int logType) {

    std::string section("line crossing");

    std::vector<Point> res;
    {
        std::string name = "simple crossing";
        Line l1(Point(0, 0), Point(1, 1)), l2(Point(0, 1), Point(1, 0));
        int n_res = Line::checkCross(l1, l2, &res, true);

        bool _res = (n_res == 1 && res[res.size() - 1] == Point(0.5, 0.5));
        testResult.push_back(TestResult(section, name, _res));
        checkLineCrossingFullLoger(logType, l1, l2, n_res, res);
    }
    {
        std::string name = "parallel";
        Line l1(Point(0, 0), Point(1, 0)), l2(Point(0, 1), Point(1, 1));
        int n_res = Line::checkCross(l1, l2, &res, true);

        bool _res = (n_res == 0);
        testResult.push_back(TestResult(section, name, _res));
        checkLineCrossingFullLoger(logType, l1, l2, n_res, res);
    }
    {
        std::string name = "overlap";
        Line l1(Point(0, 0), Point(2, 0)), l2(Point(0, 0), Point(1, 0));
        int n_res = Line::checkCross(l1, l2, &res, true);

        bool _res = (n_res == 2 && res[res.size() - 2] == Point(0, 0) &&
                                   res[res.size() - 1] == Point(1, 0));
        testResult.push_back(TestResult(section, name, _res));
        checkLineCrossingFullLoger(logType, l1, l2, n_res, res);
    }
    {
        std::string name = "containing";
        Line l1(Point(0, 0), Point(3, 0)), l2(Point(1, 0), Point(2, 0));
        int n_res = Line::checkCross(l1, l2, &res, true);

        bool _res = (n_res == 2 && res[res.size() - 2] == Point(1, 0) &&
                                   res[res.size() - 1] == Point(2, 0));
        testResult.push_back(TestResult(section, name, _res));
        checkLineCrossingFullLoger(logType, l1, l2, n_res, res);
    }

    if(logType > SHORT_SECTION_LOG) {
        std::cout << std::endl;
    }

    bool result = true;
    int n_tests = 0, n_pass_tests = 0;
    for(int i = 0; i < testResult.size();i ++) {
        n_tests ++;
        if(!testResult[i].res) {
            result = false;
        } else {
            n_pass_tests ++;
        }

        if(logType >= SHORT_SECTION_LOG) {
            if(testResult[i].res)
                std::cout << "pass";
            else
                std::cout << "fail";

            std::cout << " - ";
            std::cout << "\"" << testResult[i].section << "." << testResult[i].name << "\"" << std::endl;
        }
    }

    if(logType > SHORT_LOG) {
        std::cout << std::endl;
    }

    if(logType >= SHORT_LOG) {
        std::cout << n_pass_tests << "/" << n_tests
                  << " passed in " << "\"" << section << "\"" << std::endl;
        std::cout << std::endl;
    }

    return result;
}

