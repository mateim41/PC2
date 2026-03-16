#ifndef CARTE_HPP
#define CARTE_HPP

class Carte
{
private:
    char *titlu;
    unsigned int nr_pagini;

public:
    Carte();
    Carte(char *titlu, unsigned int nr_pagini);
    Carte(const Carte &c);
    Carte(Carte &&c);
    ~Carte();

    void citire();
    void afisare();
    void changeNrPage(int nr_pagini);
    void comparCarte(Carte &c);
};

#endif