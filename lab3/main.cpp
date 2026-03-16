#include <iostream>
#include "complex.hpp"
#include "persoana.hpp"
#include "autoturism.hpp"

// pointerul this <- pointeaza la adresa obiectului curent
// initializarea prin liste se realizeaza in 2 pasi
// altfel initializarea se face in 2 pazi
// variabilele se duc la variabilele default si de-abia dupa se pun val noi
// cout are comportament impredictibil la string-uri din C (referitor la nullptr) =>
// => if(string != nullptr)

void pb1main()
{
    Complex c1(3, 4);
    Complex c2(c1);
    Complex c3 = std::move(c1);
    c1.afisare();
    c2.afisare();
    c3.afisare();

    Complex adunare(c2.aduna(c3));
    adunare.afisare();
}

void pb2main()
{
    Persoana p1((char *)"Pavel", 22);
    p1.afiseaza();

    Persoana p2((char *)"Anca", 43);
    p2.afiseaza();
    std::cout << p1.compara(p2) << std::endl;

    Persoana p3 = std::move(Persoana((char *)"MATEIM", 20));
    p3.afiseaza();
    std::cout << p1.compara(p3) << std::endl;
}

void pb3main()
{
    Autoturism a1;
    Autoturism a2((char *)"Rosie", 1999);
    Autoturism a3 = a2;
    Autoturism *a4 = &a3;
    a1.afisare();
    a2.afisare();
    a3.afisare();
    a4->afisare();

    Autoturism a5 = std::move(Autoturism((char *)"White", 2005));
    a5.afisare();
    std::cout << a5.comparAutoturism(a2) << std::endl;

    Autoturism a6(a3);
    a6.changeColour((char *)"Black and Yellow");
    a6.afisare();

    a5.changeAnFabricatie(2016);
    std::cout << a6.comparAutoturism(a5) << std::endl;

    char n[100];
    std::cin >> n;
    unsigned int an;
    std::cin >> an;
    Autoturism a7(n, an);
    a7.afisare();
    std::cout << a7.comparAutoturism(a5) << std::endl;
}

void pb4main()
{
    int n;
    std::cout << "Nr masini: ";
    std::cin >> n;
    Autoturism arrayMasini[n];
    for (int i = 0; i < n; i++)
        arrayMasini[i].citire();
    for (int i = 0; i < n; i++)
        arrayMasini[i].afisare();
    Autoturism a = Autoturism::celMaiNou(arrayMasini, n);
    a.afisare();
}

int main(void)
{
    // pb1main();
    // pb2main();
    // pb3main();
    pb4main();

    return EXIT_SUCCESS;
}