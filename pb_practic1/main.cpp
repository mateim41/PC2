#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "jocvideo.hpp"

int main()
{
	JocVideo j1;
	JocVideo j2("League of Legends", 2009, 4.3f);
	std::cout << j1 << j2;

	std::cout << j2.Get_Recenzii() << std::endl;
	j1.Set_Recenzii(3.2f);
	std::cout << j1.Get_Recenzii() << std::endl;

	if (j1 < j2)
		std::cout << "Jocul j1 are recenzii mai slabe decat jocul j2\n";
	else
		std::cout << "Jocul j1 are recenzii mai bune decat jocul j2\n";

	Jucator juc1("Daniel", 15);
	Jucator juc2(juc1);
	std::cout << juc1 << juc2 << std::endl;

	EchipaEsports* e1 = new EchipaEsports(3);
	Jucator* a = new Jucator("Matei", 20);
	Jucator* b = new Jucator("Vlad", 25);
	Jucator* c = new Jucator("Caramitru", 30);

	e1->addJucator(a, 0);
	e1->addJucator(b, 1);
	e1->addJucator(c, 2);
	std::cout << "Echipa esports:\n" << *e1 << std::endl;

	delete e1;
	e1 = nullptr;

	// am distrus echipa, dar inca pot lucra cu jucatorii
	// deci am demonstrat procesul de agregare
	std::cout << "Jucatori:\n" << *a << *b << *c << std::endl;

	std::vector<JocVideo> v;
	v.push_back(JocVideo("Tarkov", 2013, 3.5f));
	v.push_back(JocVideo("World of Tanks", 2009, 4.0f));
	v.push_back(JocVideo("Assassin's Creed Shadows", 2024, 4.2f));
	for (std::vector<JocVideo>::iterator i = v.begin(); i != v.end(); i++)
		std::cout << *i;
	std::cout << std::endl;

	std::sort(v.begin(), v.end(), compare_an);
	for (std::vector<JocVideo>::iterator i = v.begin(); i != v.end(); i++)
		std::cout << *i;
	std::cout << std::endl;

	delete a;
	a = nullptr;
	delete b;
	b = nullptr;
	delete c;
	c = nullptr;
	return EXIT_SUCCESS;
}