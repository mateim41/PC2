#include <iostream>
#include <string>
#include "planta.hpp"

Planta::Planta(std::string name, u_int age) : denumire(name), varsta(age)
{
}

void Planta::afisare()
{
    std::cout << "Specie: " << denumire << ", varsta: " << varsta << "\n";
}