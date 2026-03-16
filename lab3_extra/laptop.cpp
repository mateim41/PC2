#include <iostream>
#include <cstring>
#include "laptop.hpp"

Laptop::Laptop() : memorie_ram(0), model(nullptr)
{
    std::cout << "constructor implicit" << std::endl;
}

Laptop::Laptop(char *product_name, unsigned int memorie) : model(new char[strlen(product_name) + 1]), memorie_ram(memorie)
{
    std::cout << "constructor cu parametri" << std::endl;
    strcpy(model, product_name);
}

Laptop::Laptop(const Laptop &l) : memorie_ram(l.memorie_ram)
{
    std::cout << "constructor de copiere" << std::endl;
    if (l.model != nullptr)
    {
        model = new char[strlen(l.model) + 1];
        strcpy(model, l.model);
    }
    else
        model = nullptr;
}

Laptop::Laptop(Laptop &&l) : memorie_ram(l.memorie_ram), model(l.model)
{
    std::cout << "constructor de mutare" << std::endl;
    l.memorie_ram = 0;
    l.model = nullptr;
}

Laptop::~Laptop()
{
    std::cout << "destructor" << std::endl;
    delete[] model;
}

void Laptop::citire()
{
    char buffer[256];
    std::cout << "Model: ";
    std::cin >> buffer;

    delete[] model;
    model = new char[strlen(buffer) + 1];
    strcpy(model, buffer);

    std::cin >> memorie_ram;
}

void Laptop::afisare()
{
    if (model != nullptr)
        std::cout << "Model = " << model << ", Memorie RAM = " << memorie_ram << std::endl;
    else
        std::cout << "Model necunoscut, memorie RAM = " << memorie_ram << std::endl;
}

void Laptop::changeModel(char *new_model)
{
    delete[] model;
    model = new char[strlen(new_model) + 1];
    strcpy(model, new_model);
}

void Laptop::changeRAM(unsigned int ram)
{
    memorie_ram = ram;
}

// daca memoria obiectului pentru care apelam fct > memoria laptopului cu care comparam
// return true; else return false
bool Laptop::comparLaptop(Laptop &l2)
{
    return memorie_ram > l2.memorie_ram ? true : false;
}

Laptop memorieMax(Laptop *array, unsigned int nr_laptopuri)
{
    int idx = 0;
    for (int i = 1; i < nr_laptopuri; i++)
    {
        if (array[idx].comparLaptop(array[i]) == false)
        {
            idx = i;
        }
    }
    return array[idx];
}