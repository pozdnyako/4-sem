#include "iostream"
#include <string>
#include <cmath>

int numToSymb(int n) {
    if(n >=0 && n < 10) {
        return n + '0';
    } else {
        return n - 10 + 'A';
    }
}

class Num{
public:
    Num():n(0) {};

    void set_n(int _n) { n = _n; }
    int get_n() { return n; }

    virtual void show() { std::cout << "    num: " << n << std::endl; }
protected:
    int n;
};

class HexNum : public Num {
public:
    void show();
};

void HexNum::show() {
    std::cout << "hex num: ";

    int len = 1;
    if(n != 0)
        len = (log(n) / log(16)) + 1;

    char* str = new char[len];

    int _n = n;

    for(int i = 0; i < len; i ++) {
        str[len - i - 1] = numToSymb(_n % 16);
        _n /= 16;
    }

    std::cout << str;
    std::cout << std::endl;

    delete str;
}

class OctNum : public Num {
public:
    void show();
};

void OctNum::show() {
    std::cout << "oct num: ";

    int len = 1;
    if(n != 0)
        len = (log(n) / log(8)) + 1;

    char* str = new char[len];

    int _n = n;

    for(int i = 0; i < len; i ++) {
        str[len - i - 1] = numToSymb(_n % 8);
        _n /= 8;
    }

    std::cout << str;
    std::cout << std::endl;

    delete str;
}


int main(){
    // real-time
    // наследники
    // виртуальные функции

    Num* n1 = new HexNum;

    for(int i = 0; i < 18; i ++) {
        n1->set_n(i);
        n1->show();
    }

    std::cout << std::endl;

    Num* n2 = new OctNum;

    for(int i = 0; i < 18; i ++) {
        n2->set_n(i);
        n2->show();
    }


    delete n1, n2;
}
