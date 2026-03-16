#include <iostream>
#include "complex.hpp"
#include "matrice.hpp"
#include "pb3.hpp"
#include "Multime.hpp"
#include "pb5.hpp"

// daca primul element este o clasa pot face operatorul in interiorul clasei
void pb1main()
{
    Complex c1(2, 3), c2(4, 5);
    Complex c3 = c1 + c2;
    c3.show();

    double modul = ~Complex(3, 4);
    double modul1 = ~c1;
}

void pb2main()
{
    Matrice A(3, 2), B(2, 3);
    A.citire();
    B.citire();

    Matrice C = A + B;
    C.afisare();
    std::cout << std::endl;
    Matrice D = A - B;
    D.afisare();
    std::cout << std::endl;

    Matrice E = A * B;
    E.afisare();
    std::cout << std::endl;

    Matrice Compar = A == B;
    Compar.afisare();
    std::cout << std::endl;

    Matrice F = 2 + A;
    F.afisare();
    std::cout << std::endl;

    Matrice G = B + 3;
    G.afisare();
    std::cout << std::endl;

    Matrice M = A++;
    M.afisare();
    std::cout << std::endl;
    A.afisare();
    std::cout << std::endl;

    Matrice N = ++A;
    N.afisare();
    std::cout << std::endl;
    A.afisare();
    std::cout << std::endl;

    ~A;
    A.afisare();
    std::cout << std::endl;

    // Fie x = 5
    int x = 5;
    std::cout << A(x / A.get_nrC(), x % A.get_nrC()) << std::endl;
}

void pb3main()
{
    double x = 7.29, y = 9.69420;
    std::cout << adunare<double>(x, y) << std::endl;

    Complex c1(4, 5), c2(6, 9);
    adunare<Complex>(c1, c2).show();

    Matrice A(2, 2), B(2, 3);
    A.citire();
    B.citire();
    adunare<Matrice>(A, B).afisare();
    std::cout << "\n";
}

void pb4main()
{
    Multime<int> a(5), b(3);
    a.citire();
    b.citire();
    (a + b).afisare();

    std::cout << a.operator!() << "\n";

    Multime<double> c(3), d(4);
    c.citire();
    d.citire();

    auto m = aduna<Multime<double>>(c, d);
    m.afisare();
}

void pb5main()
{
    int *array;
    int nr;
    std::cout << "Nr elem: ";
    std::cin >> nr;
    array = new int[nr];

    for (int i = 0; i < nr; i++)
        std::cin >> array[i];
    sortare<int>(array, nr);
    for (int i = 0; i < nr; i++)
        std::cout << array[i] << " ";
    std::cout << "\n\n";

    float arr2[] = {2.3f, 5.9f, -4.69f, 9.89f};
    sortare<float>(arr2, sizeof(arr2) / sizeof(float));
    for (int i = 0; i < sizeof(arr2) / sizeof(float); i++)
        std::cout << arr2[i] << " ";
    std::cout << "\n\n";

    double arr3[] = {4.98, 2.812, 0.2452, 9.8274, 12.69420};
    sortare<double>(arr3, sizeof(arr3) / sizeof(double));
    for (int i = 0; i < sizeof(arr3) / sizeof(double); i++)
        std::cout << arr3[i] << " ";
    std::cout << "\n\n";
    
    delete[] array;
}

int main()
{
    // pb1main();
    // pb2main();
    // pb3main();
    // pb4main();
    pb5main();

    return EXIT_SUCCESS;
}