#ifndef COMPANIE_HPP
#define COMPANIE_HPP

class Angajat
{
private:
    unsigned int vechimeMunca;

public:
    Angajat(unsigned int vm = 0);
    ~Angajat();
    unsigned int GetVechime();
};

class Departament
{
private:
    char *denumire;
    int nrAngajati;

public:
    Departament() = delete;
    Departament(char *name, int nbEmployees);
    ~Departament();

    void citireDepartament();
    void afisareDepartament();
};

class Companie
{
public:
    Angajat *arrayAngajati[2];
    Departament *arrayDepartamente[2];
    int nbEmployees = 5;

public:
    void addDepartament(Departament *d, unsigned int poz);
    void addAngajat(Angajat *a, unsigned int poz);
    void AfisareAngajati();
    void AfisareDepartamente();
};

#endif