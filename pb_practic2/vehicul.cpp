#include <iostream>
#include <string>
#include "vehicul.hpp"

Vehicul::Vehicul(std::string producer) : producator(producer)
{
}

Autoturism::Autoturism(std::string producer, int capacitate) : Vehicul(producer), capacitate_cilindrica(capacitate)
{
}

double Autoturism::calculeazaImpozit()
{
    return capacitate_cilindrica * 0.5;
}

void Autoturism::afisare()
{
    std::cout << "Producator: " << producator << ", capacitate cilindrica: " << capacitate_cilindrica << "\n";
}

Camion::Camion(std::string producer, double weight) : Vehicul(producator), tonaj(weight)
{
}

double Camion::calculeazaImpozit()
{
    return tonaj * 150;
}

double Camion::AplicaReducereFlota(double impozit)
{
    return impozit - 0.1 * impozit;
}

void Camion::afisare()
{
    std::cout << "Producator: " << producator << ", tonaj: " << tonaj << "\n";
}

double Motocicleta::calculeazaImpozit()
{
    if (are_atas == 1)
        return 80;
    else
        return 50;
}

void Motocicleta::afisare()
{
    std::cout << "Proucator: " << producator;
    if (are_atas == 1)
        std::cout << ", are atas\n";
    else
        std::cout << ", nu are atas\n";
}