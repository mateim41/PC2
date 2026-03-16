#include <iostream>
#include <cstring>
#include "autoturism.hpp"

Autoturism::Autoturism() : an_fabricatie(0), culoare(nullptr)
{
    std::cout << "constructor implicit" << std::endl;
    // an_fabricatie = 0;
    // culoare = new char[strlen("NO COLOUR") + 1];
    // strcpy(culoare, "NO COLOUR");
}

Autoturism::Autoturism(char *culoare, unsigned int ReleaseDate) : an_fabricatie(ReleaseDate), culoare(new char[strlen(culoare) + 1])
{
    std::cout << "constructor cu parametri" << std::endl;
    // an_fabricatie = ReleaseDate;
    strcpy(this->culoare, culoare);
}

Autoturism::Autoturism(const Autoturism &a) : an_fabricatie(a.an_fabricatie), culoare(new char[strlen(a.culoare) + 1])
{
    std::cout << "constructor de copiere" << std::endl;
    // an_fabricatie = a.an_fabricatie;
    // culoare = new char[strlen(a.culoare) + 1];
    strcpy(culoare, a.culoare);
}

Autoturism::Autoturism(Autoturism &&a) : an_fabricatie(a.an_fabricatie), culoare(a.culoare)
{
    std::cout << "constructor de mutare" << std::endl;
    // an_fabricatie = a.an_fabricatie;
    // culoare = a.culoare;

    a.culoare = nullptr;
    a.an_fabricatie = 0;
}

Autoturism::~Autoturism()
{
    std::cout << "destructor" << std::endl;
    delete[] culoare;
}

void Autoturism::citire()
{
    std::cout << "Culoare ";
    scanf("%s", culoare);
    /*
        std::string c;
        std::cin >> c;
    */
    std::cout << "An Fabricatie: ";
    std::cin >> an_fabricatie;
}

void Autoturism::afisare()
{
    if (culoare)
        std::cout << "Culoare = " << culoare << ", An Fabricatie = " << an_fabricatie << std::endl;
    else
        std::cout << "Datele nu au fost initializate" << std::endl;
}

void Autoturism::changeColour(char *new_colour)
{
    delete[] culoare;
    culoare = new char[strlen(new_colour) + 1];
    strcpy(culoare, new_colour);
}

void Autoturism::changeAnFabricatie(unsigned int newAn)
{
    an_fabricatie = newAn;
}

bool Autoturism::comparAutoturism(Autoturism &a)
{
    if (an_fabricatie > a.an_fabricatie)
    {
        std::cout << "Model mai nou ";
        return true;
    }
    else
    {
        std::cout << "Model mai vechi ";
        return false;
    }
}

Autoturism Autoturism::celMaiNou(Autoturism *array, int nrMasini)
{
    int cnt = 0;
    int fab = array[0].an_fabricatie;
    // int nr = sizeof(array) / sizeof(Autoturism);
    for (int i = 1; i < nrMasini; i++)
    {
        if (array[i].an_fabricatie > fab)
        {
            cnt = i;
            fab = array[i].an_fabricatie;
        }
    }
    return array[cnt];
}