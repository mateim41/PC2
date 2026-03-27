#ifndef CARTE_HPP
#define CARTE_HPP

#include <iostream>
#include <string>
#include "autor.hpp"

class Carte
{
private:
    std::string nume;
    int an;
    Autor *writer;

public:
    Carte() = delete;
    Carte(std::string titlu, int an_lansare);
    Carte(const Carte &c);

    void addAutor(Autor *a);
    Autor GetAutor() { return *this->writer; };
    friend std::ostream &operator<<(std::ostream &output, const Carte &c);
};

#endif