#include <iostream>
#include "timp.hpp"

void Timp::normalizeaza()
{
    minute += secunde / 60;
    secunde %= 60;

    ore += minute / 60;
    minute %= 60;
}

Timp::Timp(int s, int m, int h) : secunde(s), minute(m), ore(h)
{
    this->normalizeaza();
}

Timp::Timp(const Timp &t) : secunde(t.secunde), minute(t.minute), ore(t.ore)
{
}

// Timp::Timp(Timp &&t) : secunde(t.secunde), minute(t.minute), ore(t.ore)
// {
//     t.secunde = 0;
//     t.minute = 0;
//     t.ore = 0;
// }

Timp::~Timp()
{
}

// citim secunde -> minute -> ore
// void Timp::citire()
// {
//     std::cin >> this->secunde >> this->minute >> this->ore;
//     this->normalizeaza();
// }

Timp Timp::operator+(const Timp &t) const
{
    Timp temp(this->secunde + t.secunde, this->minute + t.minute, this->ore + t.ore);
    temp.normalizeaza();
    return temp;
}

// return true daca primul timp e mai scurt decat al doilea
bool Timp::operator<(const Timp &t) const
{
    int t1 = this->ore * 3600 + this->minute * 60 + this->secunde;
    int t2 = t.ore * 3600 + t.minute * 60 + t.secunde;
    return t1 < t2 ? true : false;
}

bool Timp::operator>(const Timp &t) const
{
    int t1 = this->ore * 3600 + this->minute * 60 + this->secunde;
    int t2 = t.ore * 3600 + t.minute * 60 + t.secunde;
    return t1 > t2 ? true : false;
}

// pre-fixat - incrementam secundele cu 1
Timp &Timp::operator++()
{
    this->secunde++;
    this->normalizeaza();
    return *this;
}

// post-fixat - incrementam secundele cu 1
Timp Timp::operator++(int)
{
    Timp temp(*this);
    this->secunde++;
    this->normalizeaza();
    return temp;
}

// void Timp::afisare()
// {
//     std::cout << this->ore << ":" << this->minute << ":" << this->secunde << std::endl;
// }

std::ostream &operator<<(std::ostream &stream, const Timp &t)
{
    stream << t.ore << ":" << t.minute << ":" << t.secunde << std::endl;
    return stream;
}

std::istream &operator>>(std::istream &input, Timp &t)
{
    input >> t.secunde >> t.minute >> t.ore;
    t.normalizeaza();
    return input;
}
