#include <iostream>
#include "fractie.hpp"

void Fractie::simplifica()
{
    int min = std::min(numarator, numitor);
    for (int d = 2; d <= min; d++)
    {
        while (numarator % d == 0 && numitor % d == 0)
        {
            numarator /= d;
            numitor /= d;
        }
    }
}

Fractie::Fractie(int top, int bottom) : numarator(top), numitor(bottom)
{
    // std::cout << "constructor cu parametri impliciti" << std::endl;
}

Fractie::Fractie(const Fractie &F) : numarator(F.numarator), numitor(F.numitor)
{
    // std::cout << "constructor de copiere" << std::endl;
}

Fractie::Fractie(Fractie &&F) : numarator(F.numarator), numitor(F.numitor)
{
    // std::cout << "constructor de mutare" << std::endl;
    F.numarator = 0;
    F.numitor = 1;
}

Fractie::~Fractie()
{
    // std::cout << "destructor" << std::endl;
}

// adunarea a doua fractii + simplificare
Fractie Fractie::operator+(const Fractie &b) const
{
    Fractie rez(numarator * b.numitor + b.numarator * numitor, numarator * numitor);
    rez.simplifica();
    return rez;
}

// inmultirea a doua fractii + simplificare
Fractie Fractie::operator*(const Fractie &b) const
{
    Fractie rez(numarator * b.numarator, numitor * b.numitor);
    rez.simplifica();
    return rez;
}

// verificarea egalitatii intre doua fractii
bool Fractie::operator==(const Fractie &b) const
{
    return (numarator == b.numarator && numitor == b.numitor) ? true : false;
}

// inversul fractiei
Fractie Fractie::operator~()
{
    return Fractie(this->numitor, this->numarator);
}

// afisare sub format numa / numi
void Fractie::operator!()
{
    std::cout << numarator << "/" << numitor << std::endl;
}
