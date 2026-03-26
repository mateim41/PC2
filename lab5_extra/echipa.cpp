#include <iostream>
#include <string>
#include "echipa.hpp"

unsigned int Jucator::nb_players = 0;
Jucator::Jucator(std::string nume, double valoare) :numeJucator(nume), market_price(valoare)
{
	std::cout << "constructor Jucator" << std::endl;
	Jucator::nb_players++;
}

Jucator::~Jucator()
{
	std::cout << "destructor Jucator" << std::endl;
	Jucator::nb_players--;
}

std::ostream& operator<<(std::ostream& output, const Jucator& j)
{
	output << "Nume: " << j.numeJucator << ", valoare = " << j.market_price << std::endl;
	return output;
}


Echipa::Echipa(std::string team_name, unsigned int nrJucatori) :nume_echipa(team_name), jucatori(new Jucator* [nrJucatori]), nr_jucatori(nrJucatori)
{
	std::cout << "constructor Echipa" << std::endl;
}

Echipa::~Echipa()
{
	std::cout << "destructor Echipa" << std::endl;
	delete[] jucatori;
}

void Echipa::adaugaJucator(Jucator* j, unsigned int poz)
{
	this->jucatori[poz] = j;
}

std::ostream& operator<<(std::ostream& output, const Echipa& e)
{
	output << "Nume echipa: " << e.nume_echipa << std::endl;
	for (unsigned int i = 0; i < e.nr_jucatori; i++)
		if (e.jucatori[i] != nullptr)
			output << *e.jucatori[i];
	output << std::endl;
	return output;
}