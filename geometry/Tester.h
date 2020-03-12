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

std::ostream& operator<<(std::ostream&, const TestResult&);

class Tester {
public:
    Tester() {};

    void checkLineCrossing(int logType = SHORT_LOG);
    void checkIsPolygon(int logType = SHORT_LOG);

    void sectionLog(std::string, int logType = SHORT_LOG);
    void Log(int logType = ONLY_FAILED);

    static const int NO_LOG = 0;
    static const int SHORT_LOG = 1;
    static const int SHORT_SECTION_LOG = 2;
    static const int FULL_LOG = 3;

    static const int ALL_TESTS = 0;
    static const int ONLY_FAILED = 1;

private:
    std::vector<TestResult> testResult;
};

#endif // TESTER_H_INCLUDED
