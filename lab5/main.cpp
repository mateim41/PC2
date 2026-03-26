#include <iostream>
#include "autoturism.hpp"
#include "companie.hpp"

void pb12main()
{
    Autoturism a1;
    Autoturism a2;
    std::cin >> a1 >> a2;
    std::cout << a1 << a2;
}

void pb3main()
{
    Angajat *a1 = new Angajat(2);
    Angajat *a2 = new Angajat(5);

    Departament *d1 = new Departament((char *)"HR", 10);
    Departament *d2 = new Departament((char *)"IT", 36);

    Companie *c1 = new Companie;
    c1->addAngajat(a1, 0);
    c1->addAngajat(a2, 1);
    c1->addDepartament(d1, 0);
    c1->addDepartament(d2, 1);
    c1->AfisareAngajati();
    c1->AfisareDepartamente();

    delete c1;
    c1 = nullptr;
    // inca pot accesa arrayDepartamente ???? why
    std::cout << (c1->arrayDepartamente[0] == d1);

    delete a1;
    std::cout << (c1->arrayDepartamente[0] == d1);
    a1 = 0;
    delete a2;
    std::cout << (c1->arrayDepartamente[0] == d1);
    a2 = 0;
    delete d1;
    d1 = 0;
    delete d2;
    d2 = 0;
}

void pb4main()
{
    ComponenteElectrice comp(5);
    std::cin >> comp;

    Autoturism *a1 = new Autoturism(1600, 6.2);
    std::cin >> *a1;
    a1->addComponenteElectrice(&comp);
    std::cout << *a1;

    std::cout << comp;
}

int main()
{
    // pb12main();
    // pb3main();
    pb4main();

    return EXIT_SUCCESS;
}