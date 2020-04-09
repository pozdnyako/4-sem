#include <iostream>
#include <cmath>
#include <algorithm>
#include <typeinfo>
#include <stack>
#include <queue>

template<typename T>
class DataStruct {
public:
    static DataStruct<T>* DataStructFactory(char s);
};

template<typename T>
class Stack : public DataStruct<T>, public std::stack<T> {
};

template<typename T>
class Queue : public DataStruct<T>, public std::queue<T> {
};

template<typename T>
DataStruct<T>* DataStruct<T>::DataStructFactory(char s) {
    DataStruct<T> *ptr;

    switch(s) {
    case 's':
        ptr = new Stack<T>;
        break;
    case 'q':
        ptr = new Queue<T>;
        break;
    default:
        std::cout << "ERROR";
        break;
    }

    return ptr;
}

int main() {
    DataStruct<int> *a = DataStruct<int>::DataStructFactory('s');
    DataStruct<int> *b = DataStruct<int>::DataStructFactory('q');

    Stack<int> *_a = static_cast<Stack<int>* >(a);
    Queue<int> *_b = static_cast<Queue<int>* >(b);

    _a->push(10);
    std::cout << _a->top() << std::endl;

    _b->push(12);
    std::cout << _b->front() << std::endl;
}
