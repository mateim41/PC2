#ifndef PERSONAJ_HPP
#define PERSONAJ_HPP

#include <iostream>
#include <string>
#include <vector>

class Personaj
{
protected:
    std::string nume;
    int viata, nivel;

public:
    Personaj(std::string name = "0", int hp = 0, int lvl = 0);
    ~Personaj();
    void schimbaNivel(int nouNivel);
    int getViata();
    friend std::ostream &operator<<(std::ostream &output, const Personaj &p);
};

class Magician : public Personaj
{
private:
    int putereMagica, mana;

public:
    Magician(std::string name, int hp, int lvl, int ap, int mana);
    ~Magician();
    Magician(const Magician &m);
    Personaj getPersonaj() const;
    int getPutereMagica() const;
    int getMana() const;
    void mediteaza();
    void schimbaPutereMagica(int nouPutere);
    Magician &operator+=(int bonusAP);
    Magician comparaNivelMag(const Magician &m2) const;
    friend bool comparMagician(const Magician &m1, const Magician &m2);
};
void afisareProfilMagician(const Magician &m);

class LiderBreasla : public Personaj
{
private:
    std::string numeBreasla;
    std::vector<Magician> membriBreasla;

public:
    LiderBreasla(std::string name, int hp, int lvl, std::string breasla);
    ~LiderBreasla();
    void addMagician(const Magician &m);
    void antreneazaMagician(int poz, int bonusAP);
    friend std::ostream &operator<<(std::ostream &output, const LiderBreasla &l);
    void afiseazaBreasla() const;
    void sortareBreasla();
};

class ArhiMagician : public Magician
{
private:
    std::string titluLegendar;

public:
    ArhiMagician(std::string name, int hp, int lvl, int ap, int mana, std::string legendary_title);
    ArhiMagician(const ArhiMagician &am);
    ~ArhiMagician();
    void afisareProfilArhiMagician();
};

#endif