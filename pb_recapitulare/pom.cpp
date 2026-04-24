#include <iostream>
#include <string>
#include "pom.hpp"

Pom::Pom(std::string name, u_int age, double height) : Planta(name, age), inaltime(height)
{
}

Pom::Pom(const Pom &p) : Planta(p)
{
    this->inaltime = p.inaltime;
}

void Pom::setInaltime(double h)
{
    inaltime = h;
}

void Pom::afisare()
{
    Planta::afisare();
    std::cout << "Inaltime: " << inaltime << "\n";
}

bool Pom::operator<(const Pom &p)
{
    return this->inaltime < p.inaltime ? true : false;
}