#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <memory>
#include "planta.hpp"
#include "pom.hpp"
#include "cires.hpp"

int main()
{
    Planta p1;
    Planta p2("Zambila", 2);
    p1.afisare();
    p2.afisare();
    std::cout << "\n";

    Pom po1;
    Pom po2("Mar", 25, 5.7);
    po1.afisare();
    po2.afisare();
    po1.setInaltime(6.9);
    if (po1 < po2)
        std::cout << "Inaltimea primului pom este mai mica decat celui de-al doilea\n";
    else
        std::cout << "Inaltimea primului pom este mai mare decat celui de-al doilea\n";
    Pom po3(po2);
    po3.afisare();
    std::cout << "\n";

    std::vector<Cires> v_cires;
    v_cires.push_back(Cires("cires1", 12, 5.2, 10.5, 20.50));
    v_cires.push_back(Cires("cires2", 15, 6.9, 15.8, 18.99));
    v_cires.push_back(Cires("cires3", 20, 8.5, 31.269, 16.80));
    double valRecoltaTotal = 0;
    for (std::vector<Cires>::iterator i = v_cires.begin(); i != v_cires.end(); i++)
    {
        valRecoltaTotal += (*i).recolta();
        (*i).afisare();
    }
    std::cout << std::setprecision(9) << valRecoltaTotal << "\n\n\n";
    std::sort(v_cires.begin(), v_cires.end(), comparCires);
    for (std::vector<Cires>::iterator i = v_cires.begin(); i != v_cires.end(); i++)
    {
        (*i).afisare();
    }
    std::cout << "\n\n";

    std::vector<Planta *> plante;
    Planta *planta1 = new Planta("lalea", 1);
    Planta *planta2 = new Pom("Mar", 6, 4.9);
    Planta *planta3 = new Cires("cires4", 9, 7, 14, 20);
    plante.push_back(planta1);
    plante.push_back(planta2);
    plante.push_back(planta3);
    for (int i = 0; i < plante.size(); i++)
    {
        plante[i]->afisare();
    }

    delete planta1;
    delete planta2;
    delete planta3;

    // am comentat vectorul de pointeri la Planta pentru a putea exemplifica
    // utilizarea unui smart pointer; voi repeta aceeasi pasi ca si mai sus
    // avantajul este ca nu ma ocup de managementul memoriei
    std::vector<std::unique_ptr<Planta>> plante1;
    plante1.push_back(std::make_unique<Planta>("lalea", 1));
    plante1.push_back(std::make_unique<Pom>("Mar", 6, 4.9));
    plante1.push_back(std::make_unique<Cires>("cires4", 9, 7, 14, 20));
    for (std::vector<std::unique_ptr<Planta>>::iterator i = plante1.begin(); i != plante1.end(); i++)
        (**i).afisare();
    std::cout << '\n';
    // unique_ptr se ocupa automat de dealocarea memoriei
    // daca vreau sa declar inafara push_back pointerii
    // pot folosi shared_ptr

    return EXIT_SUCCESS;
}