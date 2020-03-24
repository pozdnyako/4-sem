#include "iostream"

class Dist{
public:
    Dist():dist(1000){}

    virtual void trav_time() = 0;

protected:
    double dist;
};

class Metric_Miles : public Dist {
public:
    void trav_time() { std::cout << dist << " miles takes \t" << dist / 60 << " h with velocity 60 mph" << std::endl; }
};

class Metric_Km : public Dist {
public:
    void trav_time() { std::cout << dist << " km takes \t\t" << dist / 100 << " h with velocity 100 kmph" << std::endl; }
};

int main(){
    // real-time
    // наследники
    // виртуальные функции

    Dist* a = new Metric_Miles;
    a->trav_time();
    delete a;

    a = new Metric_Km;
    a->trav_time();
    delete a;

}
