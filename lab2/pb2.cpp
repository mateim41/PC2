#include <iostream>
#include "pb2.h"

bool pb2::citire(int *&v, int nrElem)
{
    try
    {
        v = new int[nrElem];
        for (int i = 0; i < nrElem; i++)
        {
            std::cin >> v[i];
        }
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}
void pb2::afisare(int *v, int nrElem)
{
    for (int i = 0; i < nrElem; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}