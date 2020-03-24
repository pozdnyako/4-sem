#include "Polygon.h"

Polygon::Polygon(const std::vector<Point> &point) {
    if(isPolygon(point)) {
        vertex = point;
    }
    else {
        std::cout << "ERROR\t" << "wrong point at Polygon(const std::vector<Point> &point)" << std::endl;
    }

}

const std::vector<Point>& Polygon::getVertex() const{
    return vertex;
}

int Polygon::vertecesCount() const {
    return vertex.size();
}

bool Polygon::isConvex() {

}

bool Polygon::isPolygon(const std::vector<Point> &point, int logType) {

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

    for(int i = 0; i < line.size(); i ++) {
        int j = i - 1;
        if(i == 0)
             j = line.size() - 1;

        if(line[i] != line[j])
            continue;

        if(logType == Tester::FULL_LOG) {
            std::cout << line[i] <<  " == " << line[j] << std::endl;
        }
        return false;
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

            if((crosses[j] != line[crosses_type[i].first].getA() &&
               crosses[j] != line[crosses_type[i].first].getB())){

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

double Polygon::perimeter() const {
    double l = 0;

    for(int i = 0; i < vertex.size(); i ++) {
        int j = i-1;
        if(j < 0)
            j = vertex.size() - 1;

        l += dist(vertex[i], vertex[j]);
    }

    return l;
}

double Polygon::area() const {
    Point center(0, 0);

    for(int i = 0; i < vertex.size(); i ++) {
        center.x += vertex[i].x / vertex.size();
        center.y += vertex[i].y / vertex.size();
    }

    double A = 0.0f;

    for(int i = 0; i < vertex.size(); i ++) {
        int j = i - 1;
        if(i == 0)
            j = vertex.size() - 1;

        Vector prev(center, vertex[j]);
        Vector cur(center, vertex[i]);

        A += 0.5 * vecX(prev, cur);
    }

    return abs(A);
}

bool Polygon::containsPoint(Point point) const {

}

bool Polygon::operator==(const Shape& another) {
    if(another.myType() != myType()) {
        return false;
    }

    const Polygon &poly = static_cast<const Polygon&>(another);

    if(vertex.size() != poly.getVertex().size()) {
        return false;
    }

    for(int i = 0; i < vertex.size(); i ++) {
        if(vertex[i] != poly.getVertex().at(i))
            return false;
    }

    return true;
}

bool Polygon::isCongruentTo(const Shape&another) {
    if(another.myType() != myType()) {
        return false;
    }

    const Polygon &poly = static_cast<const Polygon&>(another);

    if(vertex.size() != poly.getVertex().size()) {
        return false;
    }

    for(int k = 0; k < vertex.size(); k ++) {
        bool isCongruent = true;
        for(int i = 0; i < vertex.size(); i ++) {
            if(vertex[i] != poly.getVertex().at( (i+k)%vertex.size()) ){
                isCongruent = false;
                break;
            }
        }
        if(isCongruent) {
            return true;
        }
    }

    return false;
}
