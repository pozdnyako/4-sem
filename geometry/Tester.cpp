#include "Tester.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const TestResult& test) {
    if(test.res)
        std::cout << "pass ";
    else
        std::cout << "fail ";

    std::cout << "\"" << test.section << "." << test.name << "\"";
}

void Tester::sectionLog(std::string section, int logType) {
    int n_pass_tests = 0;
    int n_tests = 0;
    for(int i = 0; i < testResult.size();i ++) {
        if(section != testResult[i].section)
            continue;
        n_tests ++;

        if(testResult[i].res) {
            n_pass_tests ++;
        }

        if(logType >= SHORT_SECTION_LOG) {
            std::cout << testResult[i] << std::endl;
        }
    }

    if(logType > SHORT_LOG) {
        std::cout << std::endl;
    }

    if(logType >= SHORT_LOG) {
        std::cout << n_pass_tests << "/" << n_tests
                  << " passed " << "\"" << section << "\"" << std::endl;
        std::cout << std::endl;
    }
}

void Tester::Log(int logType) {
    int n_passed = 0;

    for(int i = 0; i < testResult.size(); i ++) {
        if(testResult[i].res)
            n_passed ++;
        if(logType == ALL_TESTS) {
            std::cout << testResult[i] << std::endl;
        } else if(logType == ONLY_FAILED) {
            if(!testResult[i].res) {
                std::cout << testResult[i] << std::endl;
            }
        }
    }

    std::cout << std::endl << "passed: " << n_passed << "/" << testResult.size() << std::endl;
}
