#include <iostream>
#include <list>
#include <iterator>
#include <string>


class Project {
public:
    Project(const std::string &_name, int d)
        :name(_name),
        days_to_complite(d) {}

    void add_days(int n) { days_to_complite += n; }
    void sub_days(int n) { days_to_complite -= n; }

    bool complited() const { return days_to_complite <= 0; }
    void report(std::ostream&) const;

    friend bool operator< (const Project &, const Project &);
private:
    std::string name;
    int days_to_complite;
};

void Project::report(std::ostream &os) const {
    os << "\"" << name << "\" : " << days_to_complite << " days " << std::endl;
}

bool operator< (const Project &a, const Project &b) {
    if(a.days_to_complite == b.days_to_complite)
        return a.name < b.name;
    return a.days_to_complite < b.days_to_complite;
}

std::ostream& operator<< (std::ostream& os, const std::list<Project>& lst) {
    for(auto i = lst.begin(); i != lst.end(); i ++) {
        i->report(os);
    }
    os << std::endl;
}

int main() {
    std::list<Project> lst;

    lst.push_back(Project("a", 7));
    lst.push_back(Project("b", 3));
    lst.push_back(Project("a", 2));

    std::cout << lst;

    int day = 0;
    bool is_all_cmpl = false;

    while(!is_all_cmpl) {
        is_all_cmpl = true;

        for(auto i = lst.begin(); i != lst.end(); i ++) {
            if(!i->complited()) {
                is_all_cmpl = false;
                i->sub_days(1);
            }
        }
        day ++;
    }


    std::cout << "after " << day << " days: \n" << lst;
}
