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
    // Timp(Timp &&t);
    ~Timp();

    // void citire();
    Timp operator+(const Timp &t) const;
    bool operator<(const Timp &t) const;
    bool operator>(const Timp &t) const;
    Timp &operator++();
    Timp operator++(int);
    // void afisare();
    friend std::ostream &operator<<(std::ostream &stream, const Timp &t);
    friend std::istream &operator>>(std::istream &input, Timp &t);
};

#endif