#include <iostream>
#include "pb1.h"

void pb1::afisare(int *v, int nrElem, bool ordineAfisare)
{
    if (ordineAfisare == 0)
    {
        for (int i = 0; i < nrElem; i++)
            std::cout << v[i] << " ";
        std::cout << std::endl;
    }
    else
        for (int i = nrElem - 1; i >= 0; i--)
            std::cout << v[i] << " ";
    std::cout << std::endl;
}