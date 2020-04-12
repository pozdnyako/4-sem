// Main.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
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
