#include <iostream>
#include <string>
#include <algorithm>
#include "personaj.hpp"

Personaj::Personaj(std::string name, int hp, int lvl) : nume(name), viata(hp), nivel(lvl)
{
    // std::cout << "constructor personaj\n";
}

Personaj::~Personaj()
{
    // std::cout << "destructor personaj" << std::endl;
}

void Personaj::schimbaNivel(int nouNivel)
{
    nivel = nouNivel;
}

int Personaj::getViata()
{
    return viata;
}

std::ostream &operator<<(std::ostream &output, const Personaj &p)
{
    output << "Nume: " << p.nume << " Viata: " << p.viata << " Nivel: " << p.nivel << std::endl;
    return output;
}

Magician::Magician(std::string name, int hp, int lvl, int ap, int mana) : Personaj(name, hp, lvl), putereMagica(ap), mana(mana)
{
    // std::cout << "constructor magician" << std::endl;
}

Magician::~Magician()
{
    // std::cout << "destructor magician" << std::endl;
}

Magician::Magician(const Magician &m) : Personaj(m)
{
    // std::cout << "constructor copiere magician\n";
    putereMagica = m.putereMagica;
    mana = m.mana;
}

Personaj Magician::getPersonaj() const
{
    return *this;
}
int Magician::getPutereMagica() const
{
    return putereMagica;
}
int Magician::getMana() const
{
    return mana;
}

void Magician::mediteaza()
{
    putereMagica += 50;
}

void Magician::schimbaPutereMagica(int nouPutere)
{
    putereMagica = nouPutere;
}

Magician &Magician::operator+=(int bonusAP)
{
    putereMagica += bonusAP;
    return *this;
}

Magician Magician::comparaNivelMag(const Magician &m2) const
{
    return nivel > m2.nivel ? *this : m2;
}

bool comparMagician(const Magician &m1, const Magician &m2)
{
    return m1.putereMagica > m2.putereMagica ? true : false;
}

void afisareProfilMagician(const Magician &m)
{
    std::cout << m << "PutereMagica: " << m.getPutereMagica() << " Mana: " << m.getMana() << std::endl;
}

LiderBreasla::LiderBreasla(std::string name, int hp, int lvl, std::string breasla) : Personaj(name, hp, lvl), numeBreasla(breasla)
{
    // std::cout << "constructor LiderBreasla\n";
}

LiderBreasla::~LiderBreasla()
{
    // std::cout << "destructor LiderBreasla" << std::endl;
}

void LiderBreasla::addMagician(const Magician &m)
{
    membriBreasla.push_back(Magician(m));
}

void LiderBreasla::antreneazaMagician(int poz, int bonusAP)
{
    membriBreasla[poz] += bonusAP;
}

void LiderBreasla::afiseazaBreasla() const
{
    for (std::vector<Magician>::const_iterator i = membriBreasla.begin(); i != membriBreasla.end(); i++)
    {
        afisareProfilMagician(*i);
    }
}

void LiderBreasla::sortareBreasla()
{
    std::sort(membriBreasla.begin(), membriBreasla.end(), comparMagician);
}

ArhiMagician::ArhiMagician(std::string name, int hp, int lvl, int ap, int mana, std::string legendary_title) : Magician(name, hp, lvl, ap, mana), titluLegendar(legendary_title)
{
    // std::cout << "constructor ArhiMagician\n";
}

ArhiMagician::ArhiMagician(const ArhiMagician &am) : Magician(am), titluLegendar(am.titluLegendar)
{
    // std::cout << "constructor copiere ArhiMagician\n";
}

ArhiMagician::~ArhiMagician()
{
    // std::cout << "destructor ArhiMagician\n";
}

void ArhiMagician::afisareProfilArhiMagician()
{
    afisareProfilMagician(*this);
    std::cout << "Titlu Legendar: " << this->titluLegendar << std::endl;
}
