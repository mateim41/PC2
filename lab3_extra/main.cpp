#include <iostream>
#include "carte.hpp"
#include "laptop.hpp"

void carte()
{
    Carte c1;
    Carte c2((char *)"Daniel In Arabia", 298);
    Carte c3(c2);
    c3.afisare();
    Carte c4 = std::move(c3);

    c1.afisare();
    c2.afisare();
    c3.afisare();
    c4.afisare();
}

void laptop()
{
    Laptop l1;
    Laptop l2((char *)"Dell", 16);
    Laptop l3(l2);
    Laptop *l4 = &l3;
    Laptop l5(l1);

    l1.afisare();
    l2.afisare();
    l3.afisare();
    l4->afisare();
    l5.afisare();

    l1.changeModel((char *)"Omen");
    l1.changeRAM(8);
    l1.afisare();

    std::cout << l1.comparLaptop(l2) << std::endl;

    // array static
    int n;
    std::cout << "Nr laptopuri: ";
    std::cin >> n;

    Laptop v[n];
    for (int i = 0; i < n; i++)
        v[i].citire();

    for (int i = 0; i < n; i++)
        v[i].afisare();

    Laptop best = memorieMax(v, n);
    best.afisare();
}

int main(void)
{
    // carte();
    laptop();

    return EXIT_SUCCESS;
}