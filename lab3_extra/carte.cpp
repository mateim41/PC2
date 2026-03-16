#include <iostream>
#include <cstring>
#include "carte.hpp"

Carte::Carte() : nr_pagini(0), titlu(nullptr)
{
    std::cout << "constructor implicit" << std::endl;
}

Carte::Carte(char *titlu, unsigned int nr_pagini) : nr_pagini(nr_pagini), titlu(new char[strlen(titlu) + 1])
{
    std::cout << "constructor cu parametri" << std::endl;
    strcpy(this->titlu, titlu);
}

Carte::Carte(const Carte &c) : nr_pagini(c.nr_pagini), titlu(new char[strlen(c.titlu) + 1])
{
    std::cout << "constructor de copiere" << std::endl;
    strcpy(titlu, c.titlu);
}

Carte::Carte(Carte &&c) : nr_pagini(c.nr_pagini), titlu(c.titlu)
{
    std::cout << "constructor de mutare" << std::endl;
    c.nr_pagini = 0;
    c.titlu = nullptr;
}

Carte::~Carte()
{
    std::cout << "destructor" << std::endl;
    delete[] titlu;
}

void Carte::citire()
{
    char buffer[256];
    std::cout << "Titlu: ";
    std::cin >> buffer;

    delete[] titlu;
    titlu = new char[strlen(buffer) + 1];
    strcpy(titlu, buffer);

    std::cout << "Nr pagini: ";
    std::cin >> nr_pagini;
}

void Carte::afisare()
{
    if (titlu != nullptr)
        std::cout << "Titlu = " << titlu << ", Nr pagini = " << nr_pagini << std::endl;
    else
        std::cout << "Titlu necunoscut, nr_pagini = " << nr_pagini << std::endl;
}

void Carte::changeNrPage(int nrPag)
{
    nr_pagini = nrPag;
}

void Carte::comparCarte(Carte &c)
{
    if (nr_pagini > c.nr_pagini)
        std::cout << "Cartea curenta este mai groasa" << std::endl;
    else if (nr_pagini < c.nr_pagini)
        std::cout << "Cartea curenta este mai subtire" << std::endl;
    else
        std::cout << "Ambele carti au aceeasi grosime" << std::endl;
}