#include <iostream>
#include <string>
#include "baterie.hpp"
#include "echipa.hpp"

// compozitie
void pb1main()
{
	SmartPhone *t = new SmartPhone("Oppo", 5000);
	std::cout << *t;
	std::string modelTelefon = model_tel(*t);
	for (std::string::iterator iterator_sir = modelTelefon.begin(); iterator_sir != modelTelefon.end(); iterator_sir++)
		std::cout << *iterator_sir << " ";
	std::cout << std::endl;

	delete t;
}

// exemplu agregare
void pb2main()
{
	Jucator *j1 = new Jucator("Alex", 1.25);
	Jucator *j2 = new Jucator("Denis", 0.75);
	Jucator *j3 = new Jucator("Ionut", 2.789);
	std::cout << Jucator::nb_players << std::endl;

	Echipa *e = new Echipa("TUIASI Football Team", Jucator::nb_players);
	e->adaugaJucator(j1, 0);
	e->adaugaJucator(j2, 1);
	e->adaugaJucator(j3, 2);
	std::cout << *e;
	delete e;

	delete j1;
	j1 = nullptr;
	delete j2;
	j2 = nullptr;
	delete j3;
	j3 = nullptr;
}

int main()
{
	// pb1main();
	pb2main();

	return EXIT_SUCCESS;
}