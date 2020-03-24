#include <iostream>
#include <map>
#include <vector>

template<class T> class Array{
public:
    Array() {}

    T operator[](const int&);
    void push(T);
    void sort();

    int size();
private:
    std::vector<T> data;
};

template<class T> T Array<T>::operator[](const int& i) {
    int j = i;
    while(j < 0) { j += size(); }
    while(j >= size()) { j -= size(); }
    return data[j];
}

template<class T> void Array<T>::push(T t) {
    data.push_back(t);
}

template<class T> int Array<T>::size() {
    return data.size();
}

template<class T> void Array<T>::sort() {
    for(int i = 0; i < data.size(); i ++) {
    for(int j = i+1; j < data.size(); j ++) {

        if(data[i] > data[j]){
            std::swap(data[i], data[j]);
        }
    }}
}


int main(){
    Array<int> a;

    a.push(1);
    a.push(3);
    a.push(2);

    a.sort();

    for(int i = 0; i < a.size(); i ++) {
        std::cout << a[i] << " ";
    }

    std::cout << a[-1] << " " << a[3] << std::endl;
}
