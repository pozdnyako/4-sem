#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin("4input.txt");
    std::ofstream fout("4output.txt");

    if(!fin) {
        std::cout << "Can't open input file" << std::endl;
        return 0;
    }
    if(!fout) {
        std::cout << "Can't open output file" << std::endl;
        return 0;
    }

    char c1 = 0, c2 = 0;

    while(!fin.eof()) {
        fin.get(c1);

        if(fin.eof())
            break;

        fin.get(c2);

        fout << c2 << c1;
    }
}
