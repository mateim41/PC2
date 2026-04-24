#ifndef POM_HPP
#define POM_HPP

#include "planta.hpp"

class Pom : public Planta
{
private:
    double inaltime;

public:
    Pom(std::string name = "undefined", u_int age = 0, double height = 0);
    ~Pom() override = default;
    Pom(const Pom &p);
    void setInaltime(double h);
    void afisare();
    bool operator<(const Pom &p);
};

#endif