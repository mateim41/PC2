#include <iostream>
#include <string>
#include "autor.hpp"

Autor::Autor(std::string name, int BirthYear) : nume(name), an_nastere(BirthYear)
{
}

std::ostream &operator<<(std::ostream &output, const Autor &a)
{
    output << a.nume << " " << a.an_nastere << std::endl;
    return output;
}
