// Main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Tree.h"
#include <chrono>


int main() {
    rbt::Tree<int> tree;

    std::ofstream fout("out.txt");
    
    const int N_OP = 1000000;
    float insert_time = 0.0f;
    float find_time = 0.0f;

    for(int i = 0; i < N_OP; i++) {
        auto t_start = std::chrono::high_resolution_clock::now();
        tree.insert(rand());
        auto t_end = std::chrono::high_resolution_clock::now();
        insert_time += std::chrono::duration<double, std::nano>(t_end-t_start).count();

        t_start = std::chrono::high_resolution_clock::now();
        tree.find(rand());
        t_end = std::chrono::high_resolution_clock::now();
        find_time += std::chrono::duration<double, std::nano>(t_end-t_start).count();

        if(i % (N_OP/1000) == 0) {
            fout << insert_time/1000.0f << "\t" << find_time/1000.0f << "\n";
            insert_time = 0.0f;
            find_time = 0.0f;
        }

        if(i % (N_OP/100) == 0)
            std::cout << i /(N_OP/100) << "\n";
    }
    
//    tree.printForGraphviz();
//    tree.runDotty();
}

