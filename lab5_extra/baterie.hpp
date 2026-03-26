#ifndef BATERIE_HPP
#define BATERIE_HPP

#include <iostream>
#include <string>

class Baterie
{
private:
	unsigned int capacitate;
public:
	Baterie(unsigned int cap);
	~Baterie();

	friend std::ostream& operator<<(std::ostream& output, const Baterie& b);
	unsigned int GetCapacitate() const { return capacitate; };
};

class SmartPhone
{
private:
	std::string model;
	Baterie* baterie_interna;
public:
	SmartPhone(std::string nume_telefon, unsigned int capacitate_baterie);
	~SmartPhone();

	friend std::ostream& operator<<(std::ostream& output, const SmartPhone& t);
	friend std::string model_tel(SmartPhone& t);
	Baterie getBaterie();
};

#endif // !BATERIE_HPP
