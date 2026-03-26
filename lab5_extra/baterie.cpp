#include <iostream>
#include <string>
#include "baterie.hpp"

Baterie::Baterie(unsigned int cap) :capacitate(cap)
{
	std::cout << "constructor Baterie" << std::endl;
}

Baterie::~Baterie()
{
	std::cout << "destructor Baterie" << std::endl;
}

SmartPhone::SmartPhone(std::string nume_telefon, unsigned int capacitate_baterie) :model(nume_telefon), baterie_interna(new Baterie(capacitate_baterie))
{
	std::cout << "constructor smartphone" << std::endl;
}

SmartPhone::~SmartPhone()
{
	std::cout << "destructor smartphone" << std::endl;
	delete baterie_interna;
}

std::ostream& operator<<(std::ostream& output, const Baterie& b)
{
	output << b.capacitate << std::endl;
	return output;
}

std::ostream& operator<<(std::ostream& output, const SmartPhone& t)
{
	output << "Model telefon: " << t.model << ", Capacitate baterie = " << t.baterie_interna << std::endl;
	return output;
}

std::string model_tel(SmartPhone& t)
{
	return t.model;
}

Baterie SmartPhone::getBaterie()
{
	return *this->baterie_interna;
}