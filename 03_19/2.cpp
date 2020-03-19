#include <iostream>
#include <new>
#include <cstdlib>

class Point3{
public:
    Point3() {};
    Point3(double _x, double _y, double _z):x(_x),y(_y),z(_z){};

    friend std::ostream& operator<<(std::ostream&, const Point3&);

    void* operator new(size_t);
    void* operator new[](size_t);

    void operator delete(void *);
    void operator delete[](void *);

    void setX(double _x) {x = _x;}
    void setY(double _y) {y = _y;}
    void setZ(double _z) {z = _z;}
private:
    double x, y, z;
};

std::ostream& operator<<(std::ostream& out, const Point3& a) {
    out << "(" << a.x << ", " << a.y << ", " << a.z << ")";
    return out;
}

void* Point3::operator new(size_t size) {
    void* p = NULL;
    try{
        p = malloc(size);
    } catch(std::bad_alloc& ba) {
        std::cerr << "bad_alloc caught:" << ba.what() << "\n";
    }
    return p;
}

void* Point3::operator new[](size_t size) {
    void *p = NULL;
    try{
        p = malloc(size);
    } catch(std::bad_alloc& ba) {
        std::cerr << "bad_alloc caught:" << ba.what() << "\n";
    }
    return p;
}

void Point3::operator delete(void* p) {
    free(p);
}

void Point3::operator delete[](void* p) {
    free(p);
}

int main() {
    Point3 *a = new Point3(1, 2, 3);
    Point3 *c = new Point3[2];

    c[0].setX(0.1); c[0].setY(0.2); c[0].setZ(0.3);
    c[1].setX(1.1); c[1].setY(1.2); c[1].setZ(1.3);

    std::cout << *a << std::endl;
    std::cout << c[0] << std::endl;
    std::cout << c[1] << std::endl;

    delete a;
    delete[] c;
}
