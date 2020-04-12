// Main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Tree.h"
#include <chrono>
#include <map>


int main() {
    rbt::Tree<int, int> tree;
        
    tree.printForGraphviz();
    tree.runDotty();
}

void tree_Testing() {
    rbt::Tree<int, int> tree;
    std::map<int, int> map;

    std::ofstream fout("out.dat", std::ios::binary);
    
    const int N_OP = 100000;
    float tree_insert_time = 0.0f;
    float tree_find_time = 0.0f;

    float map_insert_time = 0.0f;
    float map_find_time = 0.0f;

    for(int i = 0; i < N_OP; i++) {
        auto t_start = std::chrono::high_resolution_clock::now();
        tree.insert(rand(), rand());
        auto t_end = std::chrono::high_resolution_clock::now();
        tree_insert_time += std::chrono::duration<double, std::nano>(t_end-t_start).count();

        t_start = std::chrono::high_resolution_clock::now();
        tree.find(rand());
        t_end = std::chrono::high_resolution_clock::now();
        tree_find_time += std::chrono::duration<double, std::nano>(t_end-t_start).count();

        t_start = std::chrono::high_resolution_clock::now();
        map.insert({ rand(), rand() });
        t_end = std::chrono::high_resolution_clock::now();
        map_insert_time += std::chrono::duration<double, std::nano>(t_end-t_start).count();

        t_start = std::chrono::high_resolution_clock::now();
        map.find(rand());
        t_end = std::chrono::high_resolution_clock::now();
        map_find_time += std::chrono::duration<double, std::nano>(t_end-t_start).count();

        if(i % (N_OP/1000) == 0) {
            fout << i << "\t" << tree_insert_time/1000.0f << "\n";
            //fout << tree_insert_time/1000.0f << "\t" << map_insert_time/1000.0f << "\t" << tree_find_time/1000.0f << "\t" << map_find_time / 1000.0f << "\n";
            tree_insert_time = 0.0f;
            map_insert_time = 0.0f;
            tree_find_time = 0.0f;
            map_find_time = 0.0f;
        }

        if(i % (N_OP/100) == 0)
            std::cout << i /(N_OP/100) << "\n";
    }

    fout.close();
}

