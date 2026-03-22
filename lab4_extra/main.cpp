#include <iostream>
#include "fractie.hpp"
#include "complex.hpp"
#include "templateFct.hpp"
#include "inventar.hpp"
#include "timp.hpp"
#include "pbFiltrare.hpp"

void fractie_main()
{
    Fractie f1(2, 3), f2(5, 7);
    !f1;
    !f2;

    !(f1 + f2);
    !(f1 * f2);
    std::cout << (f1 == f2) << std::endl;
    Fractie inv_f1(~f1);
    !inv_f1;
}

void pb2_templateFct()
{
    double v[] = {1.23, 5.45, 11.9283, 69.12567, 24.12, 5.45, 5.45, 1.69420, 5.45};
    int nr1 = sizeof(v) / sizeof(double);
    std::cout << nrAparitii<double>(v, nr1, 5.45) << std::endl;

    int v2[] = {1, 5, 1, 1, 1, 9, 11, 16, 189, 275, 0, 0, 0, 0};
    int nr2 = sizeof(v2) / sizeof(int);
    std::cout << nrAparitii<int>(v2, nr2, 1) << "\n";

    Complex *v3 = new Complex[4];
    for (int i = 0; i < 4; i++)
        v3[i].citire();
    std::cout << nrAparitii<Complex>(v3, 4, Complex(2, 5)) << "\n";

    delete[] v3;
}

void inventar_main()
{
    Inventar<int> I(5);
    I.citire();

    I += 5;
    I.afisare();
    std::cout << I[2] << std::endl;

    Inventar<int> I2(3);
    I2.citire();

    (I - I2).afisare();
}

void Filtrare()
{
    int *v;
    int n;
    std::cout << "Nr elem: ";
    std::cin >> n;
    v = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    int m = 0;
    int *arr = ExtrageMaiMari<int>(v, n, 2, m);
    for (int i = 0; i < m; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    int nr;
    std::cout << "Nr elem vector timp: ";
    std::cin >> nr;
    Timp *t = new Timp[nr];
    for (int i = 0; i < nr; i++)
        std::cin >> t[i];

    int nrNou = 0;
    Timp *t2 = ExtrageMaiMari<Timp>(t, nr, Timp(10, 15, 8), nrNou);
    for (int i = 0; i < nrNou; i++)
        std::cout << t2[i];

    delete[] v;
    delete[] arr;
    delete[] t;
    delete[] t2;
}

int main()
{
    // fractie_main();
    // pb2_templateFct();
    // inventar_main();
    Filtrare();

    return EXIT_SUCCESS;
}