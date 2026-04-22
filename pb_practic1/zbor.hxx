#ifndef ZBOR_HXX
#define ZBOR_HXX

#include <iostream>
#include <string>
#include <vector>

class Zbor //: public Pilot
{
private:
    std::string destinatie;
    unsigned int numarPasageri;
    float pretBilet;

public:
    /// @brief
    /// @param dest destinatie
    /// @param nb_passangers numar pasageri
    /// @param price pret bilet
    Zbor(std::string dest = "undefined", unsigned int nb_passangers = 0, float price = 0.f);
    friend std::ostream &operator<<(std::ostream &output, const Zbor &z);
    float getPret() const { return pretBilet; };
    void setPret(float newPret) { pretBilet = newPret; };
    bool operator>(const Zbor &z2) const;
};
bool comp(const Zbor &z1, const Zbor &z2);

class Pilot
{
protected:
    std::string nume;
    int oreZbor;

public:
    Pilot(std::string name, int ore);
    Pilot(const Pilot &p);
    Pilot(Pilot &&p);
    ~Pilot() { std::cout << "destructor pilot\n"; };
    std::string getName() { return nume; };
    friend std::ostream &operator<<(std::ostream &output, const Pilot &p);
};

class CompanieAeriana //: public Pilot
{
private:
    std::vector<Pilot *> piloti;

public:
    ~CompanieAeriana() { std::cout << "destructor CompanieAeriana\n"; };
    void addPilot(Pilot *p);
    void addEchipaPiloti(std::vector<Pilot> p);
    void firePilot(std::string id); // id - nume pilot
    void afisareCompanie();
};

#endif