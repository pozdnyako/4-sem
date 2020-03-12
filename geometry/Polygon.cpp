#include "Polygon.h"

Polygon::Polygon(const std::vector<Point> &point) {
    vertex = point;
}

int Polygon::vertecesCount() {
    return vertex.size();
}

bool isConvex() {

}

bool Polygon::isPolygon(std::vector<Point> &point) {

    for(int i = 0;  i < point.size(); i ++) {
        int j = i - 1;
        if(i == 0)
            j = point.size() - 1;

        if(point[i] != point[j])
            continue;

        return false;
    }

    std::vector<Line> line(point.size());

    for(int i = 0; i < point.size(); i ++) {
        int j = i - 1;
        if(i == 0)
            j = point.size() - 1;

        line[i] = Line(point[i], point[j]);
    }

    std::vector<Point> crosses;
    std::vector<std::pair<int, int> > crosses_type;

    for(int i = 0;     i < line.size(); i ++) {
    for(int j = i + 1; j < line.size(); j ++) {
        int n_points = Line::checkCross(line[i], line[j], &crosses, true);

        if(n_points > 0)
            crosses_type.push_back(std::make_pair(n_points, i));
    }}

    int j = 0;
    for(int i = 0; i < crosses_type.size(); i ++) {
        for(int _j = 0; _j < crosses_type[i].second; _j ++) {

            if(crosses[j] != line[crosses_type[i].first].getA() &&
               crosses[j] != line[crosses_type[i].first].getB()) {

                return false;
            }
            j++;
        }
    }
    return true;
}
