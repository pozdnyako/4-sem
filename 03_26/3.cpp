#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin("3input.txt");

    if(!fin) {
        std::cout << "Can't open file" << std::endl;
        return 0;
    }

    char c = 0;

    int lst_space = -1;
    int cur_pos = 0;

    int n_words = 0;

    while(!fin.eof()) {
        fin.get(c);

        if(isspace(c)) {
            if(lst_space != cur_pos - 1)
                n_words ++;

            lst_space = cur_pos;
        }

        cur_pos ++;
    }

    if(lst_space == cur_pos)
        n_words ++;

    std::cout << n_words;
}
