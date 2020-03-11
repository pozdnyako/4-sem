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


}
