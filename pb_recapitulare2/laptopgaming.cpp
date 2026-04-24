#include <iostream>
#include "laptopgaming.hpp"

LaptopGaming::LaptopGaming(std::string manufacturer, u_int year, double weight, int nb_games, double medium_price) : Laptop(manufacturer, year, weight), numarJocuri(nb_games), pretMediuPerJoc(medium_price)
{
}

void LaptopGaming::afisare()
{
    Laptop::afisare();
    std::cout << "Nr jocuri: " << numarJocuri << ", pret mediu per joc: " << pretMediuPerJoc << "\n";
}

double LaptopGaming::val_estimata_colectie()
{
    return numarJocuri * pretMediuPerJoc;
}

bool LaptopGaming::operator<(const LaptopGaming &l2) const
{
    return this->pretMediuPerJoc < l2.pretMediuPerJoc; // ? true : false;
}