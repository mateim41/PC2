#ifndef PLANTA_HPP
#define PLANTA_HPP

#include <string>
class Planta
{
private:
    std::string denumire;
    u_int varsta;

public:
    Planta(std::string name = "undefined", u_int age = 0);
    virtual ~Planta() = default;
    virtual void afisare();
};

#endif