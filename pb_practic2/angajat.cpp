#include <iostream>
#include <string>
#include "angajat.hpp"

Angajat::Angajat(std::string nume, int id) : nume_complet(nume), id_angajat(id)
{
}

void Angajat::AfiseazaDate()
{
    std::cout << "Nume: " << nume_complet << ", id: " << id_angajat << "\n";
}

Programator::Programator(std::string nume, int id, int ore, int plata_per_ora, std::string language) : Angajat(nume, id), ore_lucrate(ore), tarif_orar(plata_per_ora), limbaj_principal(language)
{
}

double Programator::CalculeazaSalariu()
{
    return ore_lucrate * tarif_orar;
}

void Programator::AfiseazaDate()
{
    Angajat::AfiseazaDate();
    std::cout << "Ore lucrate: " << ore_lucrate << ", Plata/ora: " << tarif_orar << ", Limba principala: " << limbaj_principal << "\n";
}

Manager::Manager(std::string nume, int id, double base_salary, double bonus, int nb_projects) : Angajat(nume, id), salariu_baza(base_salary), bonus_per_proiect(bonus), nr_proiecte_coord(nb_projects)
{
}

double Manager::CalculeazaSalariu()
{
    return salariu_baza + (nr_proiecte_coord * bonus_per_proiect);
}