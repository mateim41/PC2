#ifndef LAPTOP_HPP
#define LAPTOP_HPP

class Laptop
{
private:
    char *model;
    unsigned int memorie_ram;

public:
    Laptop();
    Laptop(char *product_name, unsigned int memorie);
    Laptop(const Laptop &l);
    Laptop(Laptop &&l);
    ~Laptop();

    void citire();
    void afisare();
    void changeModel(char *new_model);
    void changeRAM(unsigned int ram);
    bool comparLaptop(Laptop &l2);
};
Laptop memorieMax(Laptop *array, unsigned int nr_laptopuri);

#endif