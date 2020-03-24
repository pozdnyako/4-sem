#include "Tester.h"
#include "Polygon.h"
#include <iostream>

void Tester::checkIsPolygon(int logType) {
    std::string section = "Polygon::isPolygon()";

    {
        std::string name = "normal polygon";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        std::vector<Point> point;
        point.push_back(Point(0, 0));
        point.push_back(Point(1, 0));
        point.push_back(Point(1, 1));

        bool _res = (Polygon::isPolygon(point, logType) == true);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }
    {
        std::string name = "2 same points";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        std::vector<Point> point;
        point.push_back(Point(0, 0));
        point.push_back(Point(1, 0));
        point.push_back(Point(1, 0));
        point.push_back(Point(1, 1));

        bool _res = (Polygon::isPolygon(point, logType) == false);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }
    {
        std::string name = "overlap";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        std::vector<Point> point;
        point.push_back(Point(0, 0));
        point.push_back(Point(1, 0));
        point.push_back(Point(0.5, 0));

        bool _res = (Polygon::isPolygon(point, logType) == false);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }
    {
        std::string name = "self-intersection";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        std::vector<Point> point;
        point.push_back(Point(0, 0));
        point.push_back(Point(1, 0));
        point.push_back(Point(0, 1));
        point.push_back(Point(1, 1));

        bool _res = (Polygon::isPolygon(point, logType) == false);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }
    {
        std::string name = "only 2 points";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        std::vector<Point> point;
        point.push_back(Point(0, 0));
        point.push_back(Point(1, 0));

        bool _res = (Polygon::isPolygon(point, logType) == false);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }

    if(logType > SHORT_SECTION_LOG) {
        std::cout << std::endl;
    }

    sectionLog(section, logType);
}

void Tester::checkPolygon(int logType) {
    std::string section = "Polygon";
    {
        std::string name = "square perimeter";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        std::vector<Point> points{Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)};
        Polygon poly(points);

        bool _res = (is_eql(poly.perimeter(), 4.0) == true);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }
    {
        std::string name = "square area";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        std::vector<Point> points{Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)};
        Polygon poly(points);

        bool _res = (is_eql(poly.area(), 1.0) == true);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }

    {
        std::string name = "no covnex area";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        std::vector<Point> points{Point(0, 0), Point(2, 0), Point(2, 2),
                                  Point(1, 1), Point(0, 2)};
        Polygon poly(points);

        bool _res = (is_eql(poly.area(), 3) == true);
        if(logType == FULL_LOG) std::cout << "area = " << poly.area() << std::endl;

        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }
    {
        std::string name = "operator== for same objects";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        std::vector<Point> points{Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)};
        Polygon poly1(points);
        Polygon poly2(points);

        bool _res = ((poly1==poly2) == true);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }
    {
        std::string name = "operator== for congruent";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        std::vector<Point> points1{Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)};
        std::vector<Point> points2{Point(1, 0), Point(1, 1), Point(0, 1), Point(0, 0)};
        Polygon poly1(points1);
        Polygon poly2(points2);

        bool _res = ((poly1==poly2) == false);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }
    {
        std::string name = "isCongurentTo() for congruent";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        std::vector<Point> points1{Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)};
        std::vector<Point> points2{Point(1, 0), Point(1, 1), Point(0, 1), Point(0, 0)};
        Polygon poly1(points1);
        Polygon poly2(points2);

        bool _res = (poly1.isCongruentTo(poly2) == true);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }
    {
        std::string name = "isCongurentTo() for not congruent";
        if(logType == FULL_LOG) std::cout << name << std::endl;
        std::vector<Point> points1{Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)};
        std::vector<Point> points2{Point(1, 0.5), Point(1, 1), Point(0, 1), Point(0, 0)};
        Polygon poly1(points1);
        Polygon poly2(points2);

        bool _res = (poly1.isCongruentTo(poly2) == false);
        testResult.push_back(TestResult(section, name, _res));
        if(logType == FULL_LOG) std::cout << std::endl;
    }

}
