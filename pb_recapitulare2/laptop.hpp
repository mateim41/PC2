#ifndef LAPTOP_HPP
#define LAPTOP_HPP

#include "dispozitiv.hpp"

class Laptop : public Dispozitiv
{
private:
    double greutateKg;

public:
    Laptop(std::string manufacturer = "undefined", u_int year = 0, double weight = 0);
    Laptop(const Laptop &l1);
    ~Laptop() = default;
    void afisare() override;
    friend bool operator>(const Laptop &l1, const Laptop &l2);
};

#endif