#include <iostream>
#include "produs.hpp"

Produs::Produs(std::string nume, unsigned int releaseYear) : denumire(nume), anAparitie(releaseYear)
{
}

void Produs::afisare()
{
    std::cout << "Denumire: " << denumire << ", an aparitie: " << anAparitie << "\n";
}

Electrocasnic::Electrocasnic(std::string nume, unsigned int releaseYear, double greutate) : Produs(nume, releaseYear), greutateKg(greutate)
{
}

Electrocasnic::Electrocasnic(const Electrocasnic &e) : Produs(e), greutateKg(e.greutateKg)
{
}

void Electrocasnic::afisare()
{
    Produs::afisare();
    std::cout << "Greutate: " << this->greutateKg << '\n';
}

bool Electrocasnic::operator>(const Electrocasnic &e) const
{
    return this->greutateKg > e.greutateKg; //? true : false
}

Televizor::Televizor(std::string nume, unsigned int releaseYear, double greutate, double dim, double pricePerInch) : Electrocasnic(nume, releaseYear, greutate), diagonala(dim), pretPerInch(pricePerInch)
{
}

void Televizor::afisare()
{
    Electrocasnic::afisare();
    std::cout << "Dimensiune: " << diagonala << ", pret per inch: " << pretPerInch << "\n";
}

double Televizor::valEstimata() const
{
    return this->diagonala * this->pretPerInch;
}

bool Televizor::operator<(const Televizor &t) const
{
    return this->pretPerInch < t.pretPerInch; //? true : false
}

bool comparTV(const Televizor &t1, const Televizor &t2)
{
    return t1.valEstimata() > t2.valEstimata() ? true : false;
}