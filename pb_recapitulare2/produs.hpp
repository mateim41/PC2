#ifndef PRODUS_HPP
#define PRODUS_HPP

#include <string>

class Produs
{
private:
    std::string denumire;
    unsigned int anAparitie;

public:
    Produs(std::string nume = "0", unsigned int releaseYear = 0);
    virtual ~Produs() = default;
    virtual void afisare();
};

class Electrocasnic : public Produs
{
private:
    double greutateKg;

public:
    Electrocasnic(std::string nume = "0", unsigned int releaseYear = 0, double greutate = 0);
    Electrocasnic(const Electrocasnic &e);
    void afisare() override;
    bool operator>(const Electrocasnic &e) const;
};

class Televizor : public Electrocasnic
{
private:
    double diagonala, pretPerInch;

public:
    Televizor(std::string nume = "0", unsigned int releaseYear = 0, double greutate = 0, double dim = 0, double pricePerInch = 0);
    void afisare() override;
    double valEstimata() const;
    bool operator<(const Televizor &t) const; // compar pretPerInch
};
bool comparTV(const Televizor &t1, const Televizor &t2); // compar val TV pt a sorta descresc

#endif