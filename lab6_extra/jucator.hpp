#ifndef JUCATOR_HPP
#define JUCATOR_HPP

#include <iostream>
#include <string>
#include <vector>

class Jucator
{
private:
    std::string nume;
    int numarTricou;

public:
    Jucator(std::string name = "0", int nb_on_shirt = 0);
    int getNumar() { return numarTricou; };

    friend std::ostream &operator<<(std::ostream &output, const Jucator &j);
    friend bool operator==(const Jucator &j1, const Jucator &j2);
};
void elimJucator(std::vector<Jucator> &j);
bool compareJucator(Jucator &j1, Jucator &j2);

#endif