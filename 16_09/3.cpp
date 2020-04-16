#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <map>

class Word {
public:
    Word(const char* _s) : s(_s) {}
    bool operator<(const Word&) const;

    friend std::ostream& operator<<(std::ostream &, const Word&);
private:
    std::string s;
};

std::ostream& operator<<(std::ostream & os, const Word& word) {
    os << word.s;
    return os;
}

bool Word::operator<(const Word& word) const {
    for(int i = 0; i < std::min(s.length(), word.s.length()); i ++) {
        if(s[i] == word.s[i])
            continue;

        return s[i] < word.s[i];
    }

    return s.length() < word.s.length();
}

int main() {

    std::map<Word, Word> opposite;

    opposite.insert({"good", "bad"});
    opposite.insert({"bad", "good"});

    std::cout << opposite.find(Word("good"))->second;
}
