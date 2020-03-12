#include "Polygon.h"

Polygon::Polygon(const std::vector<Point> &point) {
    vertex = point;
}

int Polygon::vertecesCount() {
    return vertex.size();
}

bool isConvex() {

}

bool Polygon::isPolygon(std::vector<Point> &point, int logType) {

    for(int i = 0; i < point.size(); i ++) {
        int j = i - 1;
        if(i == 0)
            j = point.size() - 1;

        if(point[i] != point[j])
            continue;

        if(logType == Tester::FULL_LOG) {
            std::cout << point[i] <<  " == " << point[j] << std::endl;
        }
        return false;
    }

    std::vector<Line> line(point.size());

    for(int i = 0; i < point.size(); i ++) {
        int j = i - 1;
        if(i == 0)
            j = point.size() - 1;

        line[i] = Line(point[i], point[j]);

        if(logType == Tester::FULL_LOG) {
            std::cout << line[i] << std::endl;
        }
    }

    if(logType == Tester::FULL_LOG) {
        std::cout <<  std::endl;
    }

    std::vector<Point> crosses;
    std::vector<std::pair<int, int> > crosses_type;

    for(int i = 0;     i < line.size(); i ++) {
    for(int j = i + 1; j < line.size(); j ++) {
        int n_points = Line::checkCross(line[i], line[j], &crosses, true);

        if(n_points > 0) {
            crosses_type.push_back(std::make_pair(i, n_points));

            if(logType == Tester::FULL_LOG) {
                std::cout << line[i] << " cross " << line[j] << " = { ";
                for(int i = crosses.size() - n_points; i < crosses.size(); i++) {
                    std::cout << crosses[i] << " " ;
                }
                std::cout << "}" << std::endl << std::endl;
            }
        }
    }}

    int j = 0;

    bool result = true;
    for(int i = 0; i < crosses_type.size(); i ++) {
        if(logType == Tester::FULL_LOG) {
            std::cout << "line: " << crosses_type[i].first << " points: { ";
        }

        for(int _j = 0; _j < crosses_type[i].second; _j ++) {
            if(logType == Tester::FULL_LOG)
                std::cout << crosses[j] << " ";

            if(crosses[j] != line[crosses_type[i].first].getA() &&
               crosses[j] != line[crosses_type[i].first].getB()) {

                result = false;
            }
            j++;
        }
        if(logType == Tester::FULL_LOG)
            std::cout << "}" << std::endl;

        if(!result)
            return result;
    }
    return true;
}
