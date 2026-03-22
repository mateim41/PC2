#include <iostream>
#include <string.h>
#include "companie.hpp"

Angajat::Angajat(unsigned int vm) : vechimeMunca(vm)
{
    std::cout << "Constructor Angajat\n";
}

Angajat::~Angajat()
{
    std::cout << "Destructor Angajat " << vechimeMunca << "\n";
}

unsigned int Angajat::GetVechime()
{
    return this->vechimeMunca;
}

void Companie::addDepartament(Departament *d, unsigned int poz)
{
    this->arrayDepartamente[poz] = d;
}

void Companie::addAngajat(Angajat *a, unsigned int poz)
{
    this->arrayAngajati[poz] = a;
}

void Companie::AfisareAngajati()
{
    for (uint i = 0; i < 2; i++)
    {
        std::cout << arrayAngajati[i]->GetVechime() << " ";
    }
    std::cout << "\n";
}

void Companie::AfisareDepartamente()
{
    for (int i = 0; i < 2; i++)
    {
        arrayDepartamente[i]->afisareDepartament();
    }
}

Departament::Departament(char *name, int nbEmployees) : denumire(new char[strlen(name) + 1]), nrAngajati(nbEmployees)
{
    strcpy(denumire, name);
    std::cout << "Constructor Departament\n";
}

Departament::~Departament()
{
    std::cout << "Destructor Departament\n";
    delete[] denumire;
}

void Departament::afisareDepartament()
{
    std::cout << this->denumire << " " << this->nrAngajati << std::endl;
}
