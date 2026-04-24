#pragma once

#include "laptop.hpp"

class LaptopGaming : public Laptop
{
private:
    int numarJocuri;
    double pretMediuPerJoc;

public:
    LaptopGaming(std::string manufacturer = "undefined", u_int year = 0, double weight = 0, int nb_games = 0, double medium_price = 0);
    ~LaptopGaming() = default;
    void afisare() override;
    double val_estimata_colectie();
    bool operator<(const LaptopGaming &l2) const; // comparam pretMediuPerJoc
};