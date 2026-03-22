#include <iostream>
#include "autoturism.hpp"

int Autoturism::cnt = 0;
Autoturism::Autoturism(unsigned int ca, double co) : capacitate(ca), consum(co)
{
    Autoturism::cnt++;
    std::cout << "constructor " << Autoturism::cnt << std::endl;
}

Autoturism::~Autoturism()
{
    Autoturism::cnt--;
    std::cout << "destructor " << Autoturism::cnt << std::endl;
}

std::istream &operator>>(std::istream &input, Roata &r)
{
    input >> r.dimensiune;
    return input;
}

std::ostream &operator<<(std::ostream &output, const Roata &r)
{
    output << r.dimensiune;
    return output;
}

std::istream &operator>>(std::istream &input, Autoturism &a)
{
    input >> a.capacitate >> a.consum;
    for (int i = 0; i < 4; i++)
        input >> a.roti[i];
    return input;
}

std::ostream &operator<<(std::ostream &output, const Autoturism &a)
{
    output << a.capacitate << " " << a.consum << "\n";
    for (int i = 0; i < 4; i++)
        output << a.roti[i] << " ";
    output << "\n";
    return output;
}