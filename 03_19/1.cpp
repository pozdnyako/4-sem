#include <iostream>
#include <cmath>
#include <algorithm>

bool is_in(double x, double a, double b){
    return (x >= a && x <= b) || (x >= b && x <= a);
}

class RNum{
public:
    RNum();
    RNum(int, int);
    RNum(double);

    constexpr static double EPS = 0.000001;

    RNum operator+(const RNum&);
    RNum operator-(const RNum&);
    RNum operator*(const RNum&);
    RNum operator/(const RNum&);

    friend std::ostream& operator<<(std::ostream&, const RNum&);
private:
    int num, den;

    void update();

};

std::ostream& operator<<(std::ostream&, const RNum&);

RNum::RNum()
:num(0), den(1){}

RNum::RNum(int _num, int _den)
:num(_num), den(_den) {
    update();
}

RNum::RNum(double d)
:num(0), den(1) {

    bool pos = (d > 0);
    if(!pos){
        d *= -1;
    }

    while(!is_in(d*den - num, -EPS*den, EPS*den)) {
        if(d*den - num > 0) {
            num = ceil(d*den);
        } else{
            den ++;
        }
    }

    if(!pos) {
        num *= -1;
    }
}

std::ostream& operator<<(std::ostream &out, const RNum &r) {
    out << r.num << "/" << r.den;
    return out;
}

void RNum::update() {
    int k = std::__gcd(abs(num), den);
    num /= k;
    den /= k;
}

RNum RNum::operator+(const RNum& a) {
    if(a.den == den){
        return RNum(a.num + num, den);
    } else{
        return RNum(a.num * den + a.den * num, den * a.den);
    }
}

RNum RNum::operator-(const RNum& a) {
    if(a.den == den){
        return RNum(num - a.num, den);
    } else{
        return RNum(num * a.den - den * a.num, den * a.den);
    }
}

RNum RNum::operator*(const RNum& a) {
    return RNum(num * a.num, den * a.den);
}

RNum RNum::operator/(const RNum& a) {
    try{
        if(a.num == 0)
            throw 0;

    } catch(int i) {
        if(i == 0){
            std::cout << "division by 0" << std::endl;
        }

        throw;
    }
    return RNum(num * a.den, den * a.num);
}


int main() {
    RNum a(1, 3), b(1, 2);

    std::cout << "1/3 + 1/2 = " << a+b << std::endl;
    std::cout << "1/3 - 1/2 = " << a-b << std::endl;
    std::cout << "1/2 - 1/3 = " << b-a << std::endl;
    std::cout << "1/2 * 1/3 = " << b*a << std::endl;
    std::cout << "1/2 / 1/3 = " << b/a << std::endl;

    RNum z(0, 2);

    std::cout << a/z;

}
