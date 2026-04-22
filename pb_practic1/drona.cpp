#include <iostream>
#include <string>
#include "drona.hpp"

Baterie::Baterie(int capacitate, double sanatate) : capacitate_mAh(capacitate), sanatate_procent(sanatate)
{
}

Baterie::~Baterie()
{
    std::cout << "destructor baterie" << std::endl;
}

std::ostream &operator<<(std::ostream &output, const Baterie &b)
{
    output << b.capacitate_mAh << " " << b.sanatate_procent << std::endl;
    return output;
}

Drona::Drona(std::string fn_model, int fn_capacitate, double fn_procent) : model(fn_model), baterie_interna(new Baterie(fn_capacitate, fn_procent))
{
}

Drona::~Drona()
{
    delete baterie_interna;
    std::cout << "destructor drona" << std::endl;
}

OperatorDrona::OperatorDrona(std::string name, int nb_flights) : nume(name), numar_zboruri(nb_flights)
{
}

std::ostream &operator<<(std::ostream &output, const OperatorDrona &op)
{
    output << "Nume: " << op.nume << " Numar zboruri: " << op.numar_zboruri << std::endl;
    return output;
}

void eliminaIncepatori(std::vector<OperatorDrona> &v)
{
    for (std::vector<OperatorDrona>::iterator i = v.begin(); i != v.end();)
        if (i->get_nbFlights() < 10)
            i = v.erase(i);
        else
            ++i;
}

EchipaLivrare::EchipaLivrare(std::string team_name) : nume_echipa(team_name)
{
}

EchipaLivrare::~EchipaLivrare()
{
    std::cout << "destructor EchipaLivrare" << std::endl;
}

void EchipaLivrare::addOperator(OperatorDrona *op)
{
    this->v.push_back(op);
}

void EchipaLivrare::concediazaOperator(std::string nume)
{
    for (std::vector<OperatorDrona *>::iterator i = this->v.begin(); i != this->v.end();)
        if ((*i)->getName() == nume)
            i = this->v.erase(i);
        else
            ++i;
}

std::ostream &operator<<(std::ostream &output, const EchipaLivrare &e)
{
    output << "Nume echipa: " << e.nume_echipa << std::endl;
    for (std::vector<OperatorDrona *>::const_iterator i = e.v.begin(); i != e.v.end(); i++)
        output << *(*i);
    return output;
}