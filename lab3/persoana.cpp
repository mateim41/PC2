#include <iostream>
#include <cstring>
#include "persoana.hpp"

Persoana::Persoana()
{
    std::cout << "constructor implicit" << std::endl;
    varsta = 0;
    nume = new char[1]();
}
Persoana::Persoana(char *n, int v)
{
    std::cout << "constructor cu parametri" << std::endl;
    nume = new char[strlen(n) + 1];
    strcpy(nume, n);
    varsta = v;
}
Persoana::Persoana(const Persoana &obiectDeCopiat)
{
    nume = new char[strlen(obiectDeCopiat.nume) + 1];
    strcpy(nume, obiectDeCopiat.nume);
    varsta = obiectDeCopiat.varsta;
}
Persoana::Persoana(Persoana &&pers)
{
    std::cout << "constructor de mutare" << std::endl;
    nume = pers.nume;
    varsta = pers.varsta;

    pers.nume = nullptr;
    pers.varsta = 0;
}
Persoana::~Persoana()
{
    std::cout << "destructor" << std::endl;
    // if (nume) <- nu se intampla nimic daca nu fac verificarea, pot da linistit delete[] nullptr
    delete[] nume;
}
void Persoana::afiseaza()
{
    std::cout << "Nume = " << nume << ", Varsta = " << varsta << std::endl;
}
bool Persoana::compara(Persoana p)
{
    if (varsta > p.varsta)
        return true;
    return false;
}