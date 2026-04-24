#ifndef ANGAJAT_HPP
#define ANGAJAT_HPP

#include <iostream>
#include <string>

class Angajat
{
protected:
    std::string nume_complet;
    int id_angajat;

public:
    Angajat(std::string nume, int id);
    virtual double CalculeazaSalariu() = 0;
    virtual void AfiseazaDate();
    friend std::ostream &operator<<(std::ostream &output, const Angajat &a);
};

class Programator : public Angajat
{
private:
    int ore_lucrate;
    double tarif_orar;
    std::string limbaj_principal;

public:
    Programator(std::string nume, int id, int ore, int plata_per_ora, std::string language);
    double CalculeazaSalariu();
    void AfiseazaDate();
};

class Manager : public Angajat
{
private:
    double salariu_baza, bonus_per_proiect;
    int nr_proiecte_coord;

public:
    Manager(std::string nume, int id, double base_salary, double bonus, int nb_projects);
    double CalculeazaSalariu();
    void AfiseazaDate();
};

#endif