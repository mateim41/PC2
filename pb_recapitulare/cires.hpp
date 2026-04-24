#ifndef CIRES_HPP
#define CIRES_HPP

#include "pom.hpp"

class Cires : public Pom
{
private:
    double nrKg, pretPerKg;

public:
    Cires(std::string name = "undefined", u_int age = 0, double height = 0, double kg = 0, double price = 0);
    ~Cires() override = default;
    double get_nrKg() const;
    double recolta();
    void afisare();
};
bool comparCires(const Cires &c1, const Cires &c2); // ordonez descresc dupa nr de kg

#endif