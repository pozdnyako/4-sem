#include <iostream>
#include <map>
#include <vector>

template<class T> class Stack{
public:
    Stack() {}
    Stack(std::string) {}

    void push(T);
    T pop();
    T lst();

    int size();
    void popPrint();

private:
    int size;
    std::string filename;
    std::fstream fs;
};

template<typename T> Stack<T>::Stack(std::string _filename) :
    filename(_filename),
    fs(_filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app) {
}

template<class T> void Stack<T>::push(T t) {
    ofstream out(filename.c_str());
    fs << size << " " << t << std::endl;
    out.close();

    size ++;
}

template<class T> int Stack<T>::size() {
    return size();
}

template<class T> T Stack<T>::pop() {
    if(size() == 0) {
        std::cout << "ERROR\t" << "Stack::pop()" << std::endl;
        return 0;
    }

    ifstream in(filename.c_str());
    in << t << std::endl;

    data.pop_back();

    return res;
}

template<class T> T Stack<T>::lst() {
    if(size() == 0) {
        std::cout << "ERROR\t" << "Stack::pop()" << std::endl;
        return 0;
    }

    return data[size() - 1];
}

template<class T> void Stack<T>::popPrint() {
    std::cout << pop();
}

int main(){
    Stack<std::string> a;

    a.push("1");
    a.push("2");
    a.push("3");

    std::string b = a.pop();
    std::string c = a.lst();
    std::cout << b << std::endl << c << std::endl;
    a.popPrint();
    std::cout << std::endl;
    std::string d = a.pop();
    std::cout << d << std::endl;

    a.pop();
}
