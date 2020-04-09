#include <iostream>
#include <cmath>
#include <algorithm>
#include <typeinfo>

class Shape{
public:
    virtual void show() = 0;
};

class NullShape : public Shape {
public:
    void show() {}
};
class Line : public Shape {
public:
    void show() { std::cout << "Line\n"; }
};
class Rectangle : public Shape {
public:
    virtual void show() { std::cout << "Rect\n"; }
};
class Square : public Rectangle {
public:
    void show() { std::cout << "Square\n"; }
};

Shape* const generator() {
    Shape* ptr = NULL;

    int num = rand() % 4;

    switch(num) {
    case 0:
        ptr = new NullShape;
        break;
    case 1:
        ptr = new Line;
        break;
    case 2:
        ptr = new Rectangle;
        break;
    case 3:
        ptr = new Square;
        break;
    default:
        std::cout << "ERROR";
        break;
    }

    return ptr;
}

int main() {
    Shape* a = generator();
    if(typeid(*a) != typeid(NullShape))
        a->show();

    std::cout << "Type: " << typeid(*a).name();
}
