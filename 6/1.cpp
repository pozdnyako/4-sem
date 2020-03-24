#include <iostream>
#include <map>
#include <fstream>

int main(){
    std::map<char, int> symbols;

    std::ifstream fin("in.txt");
    std::string data;

    fin >> data;

    for(int i = 0; i < data.size(); i ++) {
        symbols[data[i]] ++;
    }

    for( auto i : symbols) {
        std::cout << i.first << " " << i.second << std::endl;
    }
}
