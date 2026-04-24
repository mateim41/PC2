#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <typeinfo>
#include "personaj.hpp"
#include "vehicul.hpp"

void pb_mostenire()
{
    std::vector<ArhiMagician> v;
    ArhiMagician a1("Darius", 7290, 120, 587, 2340, "The inescapable");
    ArhiMagician a2("Diana", 8792, 100, 900, 1500, "The OneShot");
    ArhiMagician a3("Aurelion Sol", 7999, 780, 7800, 21879, "The Star Forger");
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(a3);

    int max_hp = 0;
    std::vector<ArhiMagician>::iterator celMaiPuternic;
    for (std::vector<ArhiMagician>::iterator i = v.begin(); i != v.end(); i++)
    {
        (*i).afisareProfilArhiMagician();
        if ((*i).getViata() > max_hp)
        {
            max_hp = (*i).getViata();
            celMaiPuternic = i;
        }
    }
    std::cout << std::endl;
    (*celMaiPuternic).afisareProfilArhiMagician();
}

void pb_polimorfism()
{
    std::vector<Vehicul *> v;
    Vehicul *a1 = new Autoturism("Volvo", 2300);
    Vehicul *a2 = new Autoturism("Dacia", 1500);
    Vehicul *c1 = new Camion("Scania", 2.2);
    Vehicul *c2 = new Camion("MAN", 2);
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(c1);
    v.push_back(c2);

    double impozitMax = 0;
    Vehicul *p;
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i]->calculeazaImpozit() << " ";
        if (v[i]->calculeazaImpozit() > impozitMax)
        {
            impozitMax = v[i]->calculeazaImpozit();
            p = v[i];
        }
    }
    std::cout << "\nImpozit max: " << impozitMax << "\n";
    p->afisare();

    

    delete a1;
    delete a2;
    delete c1;
    delete c2;
}

int main()
{
    // pb_mostenire();
    pb_polimorfism();

    return EXIT_SUCCESS;
}