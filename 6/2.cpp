#include <iostream>
#include <map>
#include <vector>

template<class T> T sqr(T t) {
    return t * t;
}



template<class T> std::vector<T> operator* (std::vector<T>& a, std::vector<T>& b) {
    std::vector<T> c = a;

    if(a.size() != b.size()){
        std::cout << "ERROR  vector * vector";
    }
    for(int i = 0; i < a.size(); i ++) {
        c[i] = a[i] * b[i];
    }

    return c;
}


template<class T, class X> std::map<X, T> operator* (std::map<X, T>& a, std::map<X, T>& b) {
    std::map<X, T> c;

    for(auto i: a) {
        c[i.first] = i.second * b.find(i.first)->second;
    }

    return c;
}

int main(){
    sqr(int a);

    std::vector<int> a{3, 4 ,5}, c;
    c = sqr(a);

    for(int i = 0; i < a.size(); i ++) {
        std::cout << a[i] << " -> " << c[i] << std::endl;
    }

    std::map<std::string, int> b, d;
    b["a"] = 3;
    b["b"] = 4;
    b["c"] = 5;

    d = sqr(b);

    for(auto i: b) {
        std::cout << i.first << ": " << i.second << " -> " << d.find(i.first)->second << std::endl;
    }
}
