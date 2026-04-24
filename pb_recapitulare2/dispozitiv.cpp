#include <iostream>
#include "dispozitiv.hpp"

Dispozitiv::Dispozitiv(std::string manufacturer, u_int year) : producator(manufacturer), anFabricatie(year)
{
}

void Dispozitiv::afisare()
{
    std::cout << "Producator: " << producator << ", An fabricatie: " << anFabricatie << "\n";
}