#include <iostream>
#include <string>
#include <vector>

class Dic{
    Dic();

    void add(std::string word1, std::string word2);
    int count(std::string word);
    bool checkout(std::string word1, std::string word2);

private:
    std::vector< std::pair <std::string, std::string> > pairs;
    int n_pairs;
};

void Dic :: add(std::string word1, std::string word2) {
    pairs.push_back(std::make_pair(word1, word2));
}

int Dic :: count(std::string word) {
    for(auto i : pairs) {
        std::cout << i;
        if(std::get<0>(i))
    }
}

int main(){
    Dic dic;

    dic.add("asd", "sd");
}
