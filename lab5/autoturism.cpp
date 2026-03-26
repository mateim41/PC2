#include <iostream>
#include "autoturism.hpp"

int Autoturism::cnt = 0;
Autoturism::Autoturism(unsigned int ca, double co) : capacitate(ca), consum(co)
{
    Autoturism::cnt++;
    std::cout << "constructor " << Autoturism::cnt << std::endl;
}
Autoturism::~Autoturism()
{
    Autoturism::cnt--;
    std::cout << "destructor " << Autoturism::cnt << std::endl;
}
std::istream &operator>>(std::istream &input, Autoturism &a)
{
    if (a.capacitate == 0 && a.consum == 0)
        input >> a.capacitate >> a.consum;
    for (int i = 0; i < 4; i++)
        input >> a.roti[i];

    return input;
}
std::ostream &operator<<(std::ostream &output, const Autoturism &a)
{
    output << a.capacitate << " " << a.consum << "\n";
    for (int i = 0; i < 4; i++)
        output << a.roti[i] << " ";
    output << std::endl;
    
    int *temp = a.componente->Get_elem();
    for (int i = 0; i < a.componente->Get_nrComp(); i++)
        output << temp[i] << " ";
    output << std::endl;
    return output;
}

std::istream &operator>>(std::istream &input, Roata &r)
{
    input >> r.dimensiune;
    return input;
}
std::ostream &operator<<(std::ostream &output, const Roata &r)
{
    output << r.dimensiune;
    return output;
}

ComponenteElectrice::ComponenteElectrice(int nrComp) : nrComponente(nrComp), elemente(new int[nrComp])
{
    std::cout << "constructor ComponenteElectrice\n";
}
ComponenteElectrice::~ComponenteElectrice()
{
    std::cout << "destructor ComponenteElectrice\n";
    delete[] elemente;
}
void Autoturism::addComponenteElectrice(ComponenteElectrice *c)
{
    this->componente = c;
}
std::istream &operator>>(std::istream &input, ComponenteElectrice &CE)
{
    for (int i = 0; i < CE.nrComponente; i++)
        input >> CE.elemente[i];
    return input;
}
std::ostream &operator<<(std::ostream &output, const ComponenteElectrice &CE)
{
    output << "Nr componente electrice: " << CE.nrComponente << std::endl;
    for (int i = 0; i < CE.nrComponente; i++)
        output << CE.elemente[i] << " ";
    output << std::endl;
    return output;
}