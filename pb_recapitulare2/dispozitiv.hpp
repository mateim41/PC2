#ifndef DISPOZITIV_HPP
#define DISPOZITIV_HPP

#include <string>

class Dispozitiv
{
private:
    std::string producator;
    u_int anFabricatie;

public:
    Dispozitiv(std::string manufacturer = "undefined", u_int year = 0);
    virtual ~Dispozitiv() = default;
    virtual void afisare();
};

#endif