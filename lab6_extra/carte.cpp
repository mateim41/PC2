#include <iostream>
#include <string>
#include "carte.hpp"

Carte::Carte(std::string titlu, int an_lansare) : nume(titlu), an(an_lansare)
{
}

Carte::Carte(const Carte &c) : nume(c.nume), an(c.an), writer(c.writer)
{
}

std::ostream &operator<<(std::ostream &output, const Carte &c)
{
    output << "Titlu: " << c.nume << ", an lansare: " << c.an << std::endl;
    return output;
}

void Carte::addAutor(Autor *a)
{
    this->writer = a;
}