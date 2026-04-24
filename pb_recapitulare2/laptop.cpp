#include <iostream>
#include "laptop.hpp"

Laptop::Laptop(std::string manufacturer, u_int year, double weight) : Dispozitiv(manufacturer, year), greutateKg(weight)
{
}

Laptop::Laptop(const Laptop &l1) : Dispozitiv(l1)
{
    greutateKg = l1.greutateKg;
}   

void Laptop::afisare()
{
    Dispozitiv::afisare();
    std::cout << "Greutate: " << greutateKg << "\n";
}

bool operator>(const Laptop &l1, const Laptop &l2)
{
    return l1.greutateKg > l2.greutateKg ? true : false;
}