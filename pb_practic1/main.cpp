#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "jocvideo.hpp"
#include "drona.hpp"
#include "zbor.hxx"

void supraincarcare_op()
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

	EchipaEsports *e1 = new EchipaEsports(3);
	Jucator *a = new Jucator("Matei", 20);
	Jucator *b = new Jucator("Vlad", 25);
	Jucator *c = new Jucator("Caramitru", 30);

	e1->addJucator(a, 0);
	e1->addJucator(b, 1);
	e1->addJucator(c, 2);
	std::cout << "Echipa esports:\n"
			  << *e1 << std::endl;

	delete e1;
	e1 = nullptr;

	// am distrus echipa, dar inca pot lucra cu jucatorii
	// deci am demonstrat procesul de agregare
	std::cout << "Jucatori:\n"
			  << *a << *b << *c << std::endl;

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
}

void pbDrona()
{
	Drona a("Raptor Lake", 4500, 0.9);

	std::vector<OperatorDrona> v(5);
	v[0] = OperatorDrona("Daniel", 15);
	v[1] = OperatorDrona("Matei", 8);
	v[2] = OperatorDrona("Vlad", 20);
	v[3] = OperatorDrona("Daniela", 5);
	v[4] = OperatorDrona("Bianca", 57);
	for (std::vector<OperatorDrona>::iterator i = v.begin(); i != v.end(); i++)
		std::cout << *i;
	std::cout << std::endl;

	eliminaIncepatori(v);
	for (std::vector<OperatorDrona>::iterator i = v.begin(); i != v.end(); i++)
		std::cout << *i;
	std::cout << std::endl;

	{
		EchipaLivrare team("Livratori");
		for (int i = 0; i < v.size(); i++)
			team.addOperator(&v[i]);
		std::cout << team << std::endl;
	}
	// echipa a fost distrusa, dar operatorii mai pot fi folositi
	// deci am demonstrat procedeul de agregare
	for (std::vector<OperatorDrona>::iterator i = v.begin(); i != v.end(); i++)
		std::cout << *i;
	std::cout << std::endl;
}

void pbZbor()
{
	Zbor z1("Maldive", 178, 450.99f);
	Zbor z2;
	std::cout << z1 << z2;

	std::cout << z1.getPret() << " ";
	z2.setPret(169.420f);
	std::cout << z2.getPret() << "\n\n";

	if (z1 > z2)
		std::cout << "Pretul biletului pt zborul 1 este mai mare decat pt zborul 2\n";
	else
		std::cout << "Pretul biletului pt zborul 1 este mai mic decat pt zborul 2\n\n";

	Pilot p1("Ioana", 570);
	Pilot p2(p1);
	std::cout << p1 << p2 << "\n";
	// std::vector<Pilot> v_p;
	// v_p.push_back(p1);
	// v_p.push_back(p2);
	// v_p.push_back(Pilot("Matei", 1200));
	// v_p.push_back(Pilot("Rares", 890));
	// v_p.push_back(Pilot("Daniela", 100));
	Pilot p3("Matei", 1200);
	Pilot p4("Rares", 890);
	Pilot p5("Daniela", 100);

	{
		CompanieAeriana corp;
		corp.addPilot(&p1);
		corp.addPilot(&p2);
		corp.addPilot(&p3);
		corp.addPilot(&p4);
		corp.addPilot(&p5);

		corp.afisareCompanie();
	}
	// compania aeriana a disparut, dar pilotii inca exista si se pot altundeva
	std::cout << p1 << p2 << p3 << p4 << p5 << std::endl;

	std::vector<Zbor> v_z;
	v_z.push_back(Zbor("Paris", 200, 500));
	v_z.push_back(Zbor("Tokyo", 330, 1100));
	v_z.push_back(Zbor("Copenahga", 245, 229.99f));
	v_z.push_back(Zbor("Catalunia", 156, 190.80f));
	v_z.push_back(Zbor("USA", 350, 789.99f));
	for (std::vector<Zbor>::iterator i = v_z.begin(); i != v_z.end(); i++)
		std::cout << *i;
	std::cout << "\n";

	std::sort(v_z.begin(), v_z.end(), comp);
	for (std::vector<Zbor>::iterator i = v_z.begin(); i != v_z.end(); i++)
		std::cout << *i;
	std::cout << "\n";
}

int main()
{
	// supraincarcare_op();
	// pbDrona();
	pbZbor();

	return EXIT_SUCCESS;
}