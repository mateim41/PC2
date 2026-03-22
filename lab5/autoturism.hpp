#ifndef AUTOTURISM_HPP
#define AUTOTURISM_HPP

#include <iostream>

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
    
};

class Autoturism
{
private:
    Roata roti[4];
    unsigned int capacitate; // capacitatea cilindrica
    double consum;

public:
    Autoturism(unsigned int ca = 0, double co = 0);
    ~Autoturism();

    friend std::istream &operator>>(std::istream &input, Autoturism &a);
    friend std::ostream &operator<<(std::ostream &output, const Autoturism &a);
    static int cnt; // incrementam in constructor, decrementam in destructor
};

#endif