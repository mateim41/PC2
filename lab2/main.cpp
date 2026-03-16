#include <iostream>
#include "pb1.h"
#include "pb2.h"
#include "pb3.h"
#include "dreptunghi.h"
#include "punct.h"

void pb1main()
{
    int v[100];
    int n;
    std::cout << "Nr elemente: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    pb1::afisare(v, n);
    pb1::afisare(v, n, true);
}

void pb2main()
{
    int *v;
    int n;
    std::cout << "Nr elemente: ";
    std::cin >> n;
    if (pb2::citire(v, n) == 0)
    {
        std::cout << "Nu s-a putut citi vectorul" << std::endl;
    }
    pb2::afisare(v, n);
    delete[] v;
}

void pb3main()
{
    Student *s;
    int nrStudenti;
    pb3::citire(s, nrStudenti);
    std::cout << std::endl;
    pb3::afisare(s, nrStudenti);
    // sortam crescator
    pb3::sortare(s, nrStudenti);
    pb3::afisare(s, nrStudenti);
    // sortam descrescator
    pb3::sortare(s, nrStudenti, 1);
    pb3::afisare(s, nrStudenti);

    std::cout << "Media generale a studentilor " << pb3::medieGenerala(s, nrStudenti) << std::endl;
    delete[] s;
}

void pb4main()
{
    Dreptunghi dr1;
    int l, L;
    std::cout << "Lungimea si latimea ";
    std::cin >> L >> l;
    dr1.setLungime(L);
    dr1.setLatime(l);
    std::cout << dr1.Aria() << std::endl;
}

void pb5main()
{
    Punct A, B;
    std::cout << "Primul punct: ";
    A.citire();
    std::cout << std::endl;
    std::cout << "Al doilea punct: ";
    B.citire();
    std::cout << std::endl
              << A.distantaOrigine() << " " << B.distantaOrigine() << std::endl;
    // if (A.comparPct(B, A.distantaOrigine()))
    //     std::cout << "Punctul B este mai departe de origine decat A" << std::endl;
    // else
    //     std::cout << "Punctul A este mai departe de origine decat B" << std::endl;
    if (Punct::comparPct(A, B))
        std::cout << "Punctul A este mai departe de origine decat B" << std::endl;
    else
        std::cout << "Punctul A este mai aproape de origine decat B" << std::endl;
}

void pb6main()
{
    Punct D;
    D.afisare();
    Punct E(2);
    E.afisare();
    Punct C(2, 3);
    C.afisare();
}

void pb7main()
{
    Punct *array_pct;
    int nr_pct;
    std::cout << "Numarul de puncte: ";
    std::cin >> nr_pct;
    array_pct = new Punct[nr_pct];
    for (int i = 0; i < nr_pct; i++)
    {
        array_pct[i].citire();
    }
    Punct A = Punct::distMaxima(array_pct, nr_pct);
    A.afisare();
    delete[] array_pct;
}

void pb8main()
{
    Punct *array_pct;
    int nr_pct;
    std::cout << "Nr de puncte: ";
    std::cin >> nr_pct;
    array_pct = new Punct[nr_pct];
    for (int i = 0; i < nr_pct; i++)
    {
        array_pct[i].citire();
    }
    bool r = Punct::potFormaTriunghi(array_pct, nr_pct);
    std::cout << r << std::endl;

    delete[] array_pct;
}

int main()
{
    // pb1main();
    // pb2main();
    // pb3main();
    // pb4main();
    // pb5main();
    // pb6main(); - completez clasa punct cu un constructor fara argumente si unul cu argumente
    // pb7main();
    pb8main();

    return EXIT_SUCCESS;
}