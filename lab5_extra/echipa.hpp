#ifndef ECHIPA_HPP
#define ECHIPA_HPP

#include <iostream>
#include <string>

class Jucator
{
private:
	std::string numeJucator;
	double market_price;// in milioane de euro
public:
	static unsigned int nb_players;
	Jucator(std::string nume, double valoare);
	~Jucator();
	friend std::ostream& operator<<(std::ostream& output, const Jucator& j);
};

class Echipa
{
private:
	std::string nume_echipa;
	Jucator** jucatori;
	unsigned int nr_jucatori;
public:
	Echipa(std::string team_name, unsigned int nrJucatori);
	~Echipa();
	void adaugaJucator(Jucator* j, unsigned int poz);
	friend std::ostream& operator<<(std::ostream& output, const Echipa& e);
};

#endif // !ECHIPA_HPP
