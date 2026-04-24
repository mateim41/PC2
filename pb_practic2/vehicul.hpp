#ifndef VEHICUL_HPP
#define VEHICUL_HPP

#include <iostream>
#include <string>

class Vehicul
{
protected:
    std::string producator;

public:
    Vehicul(std::string producer = "0");
    virtual double calculeazaImpozit() = 0;
    virtual void afisare() = 0;
};

class Autoturism : public Vehicul
{
private:
    int capacitate_cilindrica;

public:
    Autoturism(std::string producer, int capacitate);
    double calculeazaImpozit();
    void afisare();
};

class Camion : public Vehicul
{
private:
    double tonaj;

public:
    Camion(std::string producer, double weight);
    double calculeazaImpozit();
    double AplicaReducereFlota(double impozit);
    void afisare();
};

class Motocicleta : public Vehicul
{
private:
    bool are_atas;

public:
    double calculeazaImpozit();
    void afisare();
};

#endif