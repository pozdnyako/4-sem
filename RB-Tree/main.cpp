// Main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Tree.h"

int main() {
    rbt::testingVsMap();

    rbt::Tree<int, int> tree;

    tree.insert(1, 0);
    tree.insert(2, 0);
        
    tree.printForGraphviz();
    tree.runDotty();
}
