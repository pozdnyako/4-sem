#include <iostream>
#include <cmath>
#include <algorithm>
#include <typeinfo>

template<typename T>
class Num {
public:
    Num<T>(T _n):n(_n) {}

    virtual T get_val() { return n; }

protected:
    T n;
};

template<typename T>
class Sqr : public Num<T> {
public:
    Sqr<T>(T _n):Num<T>(_n) {};

    T get_val() { return Num<T>::n * Num<T>::n; }
};

template<typename T>
class Sqrt : public Num<T> {
public:
    Sqrt<T>(T _n):Num<T>(_n) {};

    T get_val() { return sqrt(Num<T>::n); }
};

template<typename T>
Num<T>* const generator(T n) {
    Num<T>* ptr = NULL;
    int num = rand()%2;

    switch(num) {
    case 0:
        ptr = new Sqr<T>(n);
        break;
    case 1:
        ptr = new Sqrt<T>(n);
        break;
    }

    return ptr;
}

int main() {
    Num<int> *num = generator<int>(9);

    if(dynamic_cast<Sqrt<int>* >(num))
        std::cout << "sqrt: ";
    if(dynamic_cast<Sqr<int>* >(num))
        std::cout << "sqr: ";

    std::cout << num->get_val();
}
