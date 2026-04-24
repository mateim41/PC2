#include <iostream>
#include "cires.hpp"

Cires::Cires(std::string name, u_int age, double height, double kg, double price) : Pom(name, age, height), nrKg(kg), pretPerKg(price)
{
}

double Cires::get_nrKg() const
{
    return this->nrKg;
}

double Cires::recolta()
{
    return nrKg * pretPerKg;
}

void Cires::afisare()
{
    Pom::afisare();
    std::cout << "Nr Kg cirese: " << nrKg << ", pret per Kg: " << pretPerKg << "\n";
}

bool comparCires(const Cires &c1, const Cires &c2)
{
    return c1.get_nrKg() > c2.get_nrKg() ? true : false;
}