#include <iostream>
#include "timp.hpp"

void Timp::normalizeaza() // 275 325 2
{
    this->secunde %= 60;
    this->minute += this->secunde / 60;
    this->minute %= 60;
    this->ore += this->minute / 60;
}

Timp::Timp(int h, int m, int s) : ore(h), minute(m), secunde(s)
{
    this->normalizeaza();
}

std::istream &operator>>(std::istream &input, Timp &t1)
{
    input >> t1.ore >> t1.minute >> t1.secunde;
    t1.normalizeaza();
    return input;
}
std::ostream &operator<<(std::ostream &output, Timp &t1)
{
    output << t1.ore << ":" << t1.minute << ":" << t1.secunde << std::endl;
    return output;
}

Timp Timp::operator+(const Timp &t2) const
{
    return Timp(this->ore + t2.ore, this->minute + t2.minute, this->secunde + t2.secunde);
}

Timp Timp::operator+(int x) const
{
    return Timp(ore, minute, secunde + x);
}

Timp operator+(int x, const Timp &t1)
{
    return Timp(t1.ore, t1.minute, t1.secunde + x);
}

bool Timp::operator==(const Timp &t1) const
{
    int a = this->ore * 3600 + this->minute * 60 + this->secunde;
    int b = t1.ore * 3600 + t1.minute * 60 + t1.secunde;
    return a == b; //? true : false
}

bool Timp::operator<(const Timp &t1) const
{
    int a = this->ore * 3600 + this->minute * 60 + this->secunde;
    int b = t1.ore * 3600 + t1.minute * 60 + t1.secunde;
    
}