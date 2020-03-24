#include "iostream"

class Base{
public:
    virtual void print() { std::cout << "Base" << std::endl; }
private:
};

class First : public Base {
public:
    void print() { std::cout << "First" << std::endl; }
};

class Second : public First {
public:
    void print() { std::cout << "Second" << std::endl; }
};

int main(){
    // real-time
    // наследники
    // виртуальные функции

    Base *a = new Base;
    First *b = new First;
    Second *c = new Second;

    Base *d = b;
    Base *e = c;

    a->print(); // -> "Base"
    b->print(); // -> "First"
    c->print(); // -> "Second"

    d->print(); // -> "First"
    e->print(); // -> "Second"
}
