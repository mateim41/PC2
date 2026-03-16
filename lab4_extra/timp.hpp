#ifndef TIMP_HPP
#define TIMP_HPP

class Timp
{
private:
    int secunde, minute, ore;
    void normalizeaza();

public:
    Timp(int s = 0, int m = 0, int h = 0);
    Timp(const Timp &t);
    Timp(Timp &&t);
    ~Timp();

    Timp operator+(const Timp &t);
    bool operator<(const Timp &t);
    Timp &operator++();
    Timp operator++(int);
    void afisare();
};

#endif