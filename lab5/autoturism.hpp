#ifndef AUTOTURISM_HPP
#define AUTOTURISM_HPP

#include <iostream>
#include <string>

class Roata
{
private:
    unsigned int dimensiune; // dimensiunea rotilor
public:
    friend std::istream &operator>>(std::istream &input, Roata &r);
    friend std::ostream &operator<<(std::ostream &output, const Roata &r);
};

class ComponenteElectrice
{
private:
    int nrComponente;
    int *elemente;

public:
    ComponenteElectrice(int nrComp = 0);
    ~ComponenteElectrice();
    friend std::istream &operator>>(std::istream &input, ComponenteElectrice &CE);
    friend std::ostream &operator<<(std::ostream &output, const ComponenteElectrice &CE);
    int Get_nrComp() { return nrComponente; };
    int *Get_elem() { return elemente; };
};

class Autoturism
{
private:
    Roata roti[4];
    ComponenteElectrice *componente;
    unsigned int capacitate; // capacitatea cilindrica
    double consum;

public:
    Autoturism(unsigned int ca = 0, double co = 0);
    ~Autoturism();

    void addComponenteElectrice(ComponenteElectrice *c);
    friend std::istream &operator>>(std::istream &input, Autoturism &a);
    friend std::ostream &operator<<(std::ostream &output, const Autoturism &a);
    static int cnt; // incrementam in constructor, decrementam in destructor
};

#endif