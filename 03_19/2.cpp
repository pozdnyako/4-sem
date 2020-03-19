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

    std::cout << *a;

    delete a;
    delete[] c;
}
