#include <iostream>

class Punct
{
private:
    int x = 0, y = 0;

public:
    static int a;
    friend std::ostream &operator<<(std::ostream &output, const Punct &p);

    static void f()
    {
        a += 2;
    }
};

std::ostream &operator<<(std::ostream &output, const Punct &p)
{
    output << "(" << p.x << ", " << p.y << ")" << std::endl;
    return output;
}
int Punct::a = 2;

class Angajat
{
    unsigned int vechimeMunca;

public:
    Angajat(unsigned int vm = 0) : vechimeMunca(vm)
    {
        std::cout << "Constructor Angajat" << std::endl;
    }
    ~Angajat()
    {
        std::cout << "Destructor Angajat " << vechimeMunca << std::endl;
    }
    unsigned int GetVechime()
    {
        return vechimeMunca;
    }
};
class Companie
{
    Angajat *arrayAngajati[2];

public:
    void addAngajat(Angajat *a, unsigned int poz)
    {
        arrayAngajati[poz] = a;
    }
    void AfisareAngajati()
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            std::cout << arrayAngajati[i]->GetVechime() << " ";
        }
        std::cout << std::endl;
    }
};

// int main()
// {
//     // Punct p;
//     // std::cout << p;
//     // std::cout << Punct::a << std::endl;
//     // p.a += 2;
//     // std::cout << Punct::a << std::endl;

//     // Punct::f();
//     // std::cout << Punct::a << std::endl;

//     Angajat *a1 = new Angajat(2);
//     Angajat *a2 = new Angajat(5);

//     Companie *c1 = new Companie[2];
//     c1->addAngajat(a1, 0);
//     c1->addAngajat(a2, 1);
//     // delete a1;
//     // a1 = 0;
//     // delete a2;
//     // a2 = 0;
//     c1->AfisareAngajati();
//     delete[] c1;

//     c1->AfisareAngajati();

//     return EXIT_SUCCESS;
// }