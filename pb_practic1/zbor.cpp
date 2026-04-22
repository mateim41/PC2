#include <iostream>
#include <string>
#include <algorithm>
#include "zbor.hxx"

Zbor::Zbor(std::string dest, unsigned int nb_passangers, float price) : destinatie(dest), numarPasageri(nb_passangers), pretBilet(price)
{
}
std::ostream &operator<<(std::ostream &output, const Zbor &z)
{
    output << "Destinatie: " << z.destinatie << ", nr pasageri: " << z.numarPasageri << ", pretBilet: " << z.pretBilet << std::endl;
    return output;
}
bool Zbor::operator>(const Zbor &z2) const
{
    return this->pretBilet > z2.pretBilet; //? true : false;
}
bool comp(const Zbor &z1, const Zbor &z2)
{
    return z1.getPret() > z2.getPret(); //? true : false
}

Pilot::Pilot(std::string name, int ore) : nume(name), oreZbor(ore)
{
}
Pilot::Pilot(const Pilot &p) : nume(p.nume), oreZbor(p.oreZbor)
{
}
Pilot::Pilot(Pilot &&p) : nume(std::move(p.nume)), oreZbor(p.oreZbor)
{
    p.oreZbor = 0;
}
std::ostream &operator<<(std::ostream &output, const Pilot &p)
{
    output << p.nume << " " << p.oreZbor << std::endl;
    return output;
}

void CompanieAeriana::addPilot(Pilot *p)
{
    piloti.push_back(p);
}

void CompanieAeriana::addEchipaPiloti(std::vector<Pilot> p)
{
}

void CompanieAeriana::firePilot(std::string id)
{
    for (std::vector<Pilot *>::iterator i = piloti.begin(); i != piloti.end();)
        if ((*i)->getName() == id)
        {
            i = piloti.erase(i);
            break;
        }
        else
            ++i;
}

void CompanieAeriana::afisareCompanie()
{
    for (std::vector<Pilot *>::iterator i = this->piloti.begin(); i != piloti.end(); i++)
        std::cout << *(*i);
}