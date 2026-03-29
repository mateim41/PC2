#ifndef PRODUSIT_HPP
#define PRODUSIT_HPP

#include <iostream>
#include <string>
#include <vector>

class ProdusIT
{
    std::string denumire;
    double pret;

public:
    ProdusIT(std::string denumire = "0", double pret = 0);
    friend std::ostream &operator<<(std::ostream &output, const ProdusIT &produs);
    void aplicaReducere(double procent);

    bool operator<(const ProdusIT &p2);
    std::string Get_Denumire() { return denumire; };
    double Get_Pret() { return pret; };
};
void afisareProduse(const std::vector<ProdusIT> &v); // afisez toate produsele dintr-un vector
std::vector<ProdusIT> transf_in_Vector(ProdusIT *v, int nrElem);

#endif