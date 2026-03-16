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

Timp::Timp(Timp &&t) : secunde(t.secunde), minute(t.minute), ore(t.ore)
{
    t.secunde = 0;
    t.minute = 0;
    t.ore = 0;
}

Timp::~Timp()
{
}

Timp Timp::operator+(const Timp &t)
{
    Timp temp(this->secunde + t.secunde, this->minute + t.minute, this->ore + t.ore);
    temp.normalizeaza();
    return temp;
}

// return true daca primul timp e mai scurt decat al doilea
bool Timp::operator<(const Timp &t)
{
    if (this->ore < t.ore)
        return true;
    else if (this->ore == t.ore)
    {
        if (this->minute < t.minute)
            return true;
        else if (this->minute == t.minute)
        {
            if (this->secunde < t.secunde)
                return true;
        }
    }
    return false;
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

void Timp::afisare()
{
    std::cout << this->ore << ":" << this->minute << ":" << this->secunde << std::endl;
}