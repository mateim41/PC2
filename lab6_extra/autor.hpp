#ifndef AUTOR_HPP
#define AUTOR_HPP

#include <iostream>
#include <string>

class Autor
{
private:
    std::string nume;
    int an_nastere;

public:
    Autor(std::string name = "0", int BirthYear = 0);
    friend std::ostream &operator<<(std::ostream &output, const Autor &a);
};

#endif