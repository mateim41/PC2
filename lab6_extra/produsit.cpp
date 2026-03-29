#include <iostream>
#include <string>
#include "produsit.hpp"

ProdusIT::ProdusIT(std::string denumire, double pret) : denumire(denumire), pret(pret)
{
}

std::ostream &operator<<(std::ostream &output, const ProdusIT &produs)
{
    output << "Nume: " << produs.denumire << ", pret = " << produs.pret << std::endl;
    return output;
}

void ProdusIT::aplicaReducere(double procent)
{
    pret -= procent * pret;
}

bool ProdusIT::operator<(const ProdusIT &p2)
{
    return this->pret < p2.pret ? false : true;
}

void afisareProduse(const std::vector<ProdusIT> &v)
{
    for (std::vector<ProdusIT>::const_iterator i = v.begin(); i != v.end(); i++)
    {
        std::cout << *i;
    }
    std::cout << std::endl;
}

std::vector<ProdusIT> transf_in_Vector(ProdusIT *v, int nrElem)
{
    return std::vector<ProdusIT>(v, v + nrElem);
}