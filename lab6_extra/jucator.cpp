#include <iostream>
#include <string>
#include <vector>
#include "jucator.hpp"

Jucator::Jucator(std::string name, int nb_on_shirt) : nume(name), numarTricou(nb_on_shirt)
{
}

std::ostream &operator<<(std::ostream &output, const Jucator &j)
{
    output << "Nume: " << j.nume << ", numar pe tricou = " << j.numarTricou << std::endl;
    return output;
}

bool operator==(const Jucator &j1, const Jucator &j2)
{
    return (j1.numarTricou == j2.numarTricou && j1.nume == j2.nume) ? true : false;
}

void elimJucator(std::vector<Jucator> &j)
{
    for (int i = 0; i < j.size();)
        if (j[i].getNumar() > 50)
            j.erase(j.begin() + i);
        else
            i++;
}

bool compareJucator(Jucator &j1, Jucator &j2)
{
    return j1.getNumar() > j2.getNumar() ? true : false;
}