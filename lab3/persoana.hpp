#ifndef PERSOANA_HPP
#define PERSOANA_HPP

class Persoana
{
    char *nume;
    int varsta;

public:
    Persoana();
    Persoana(char *n, int v);
    Persoana(const Persoana &obiectDeCopiat);
    Persoana(Persoana &&pers);
    ~Persoana();
    void afiseaza();
    bool compara(Persoana p);
};

#endif