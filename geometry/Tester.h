#ifndef TESTER_H_INCLUDED
#define TESTER_H_INCLUDED

#include <string>
#include <vector>

struct TestResult {
    std::string section;
    std::string name;

    bool res;

    TestResult(std::string section, std::string name, bool res)
    :section(section)
    ,name(name)
    ,res(res) {}
};

class Tester {
public:
    Tester() {};

    int checkLineCrossing(int logType = SHORT_LOG);

    static const int NO_LOG = 0;
    static const int SHORT_LOG = 1;
    static const int SHORT_SECTION_LOG = 2;
    static const int FULL_LOG = 3;
private:

    std::vector<TestResult> testResult;
};

#endif // TESTER_H_INCLUDED
