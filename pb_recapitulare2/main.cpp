#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "laptop.hpp"
#include "dispozitiv.hpp"
#include "laptopgaming.hpp"

int main()
{
    Dispozitiv d1;
    Dispozitiv d2("Samsung", 2026);
    d1.afisare();
    d2.afisare();
    std::cout << "\n";

    Laptop l1;
    Laptop l2("HP Omen", 2024, 2.5);
    l1.afisare();
    l2.afisare();
    if (l1 > l2)
        std::cout << "Primul laptop este mai greu decat al doilea\n";
    else
        std::cout << "Al doilea laptop este mai greu decat primul\n";
    Laptop l3(l2);
    l3.afisare();
    std::cout << "\n";

    std::vector<LaptopGaming> v_lgaming;
    LaptopGaming laptop1("Lenovo", 2019, 2, 10, 52.99);
    LaptopGaming laptop2("Asus", 2022, 1.5, 5, 69.99);
    LaptopGaming laptop3("MSI", 2025, 2.35, 20, 41);
    v_lgaming.push_back(laptop1);
    v_lgaming.push_back(laptop2);
    v_lgaming.push_back(laptop3);
    double valColectieTot = 0;
    for (std::vector<LaptopGaming>::iterator i = v_lgaming.begin(); i != v_lgaming.end(); i++)
    {
        valColectieTot += (*i).val_estimata_colectie();
        (*i).afisare();
        std::cout << "\n";
    }
    // for (auto &i : v_lgaming)
    // {
    //     valColectieTot += i.val_estimata_colectie();
    //     i.afisare();
    //     std::cout << "\n";
    // }
    std::cout << "Pret colectie: " << valColectieTot << "\n\n\n";
    std::sort(v_lgaming.begin(), v_lgaming.end()); // ordonam crescator dupa pretul mediu per joc
    for (std::vector<LaptopGaming>::iterator i = v_lgaming.begin(); i != v_lgaming.end(); i++)
    {
        (*i).afisare();
        std::cout << "\n";
    }
    std::cout << "\n";

    // am ales sa fac un vector de unique_ptr in loc de vector<Dispozitiv*>
    // pentru a demonstra si utilizarea unui smart pointer
    // de asemenea, datorita unique_ptr nu mai trb sa ma ocup eu de dealocarea memoriei
    std::vector<std::unique_ptr<Dispozitiv>> dispozitive;
    dispozitive.push_back(std::make_unique<Laptop>("HP Omen", 2024, 2.5));
    dispozitive.push_back(std::make_unique<Dispozitiv>("Apple", 2025));
    dispozitive.push_back(std::make_unique<LaptopGaming>("Lenovo", 2026, 2.2, 24, 62.46));
    // for (auto i = dispozitive.begin(); i != dispozitive.end(); i++)
    // {
    //     (**i).afisare();
    //     std::cout << "\n";
    // }
    for (const auto &i : dispozitive)
    {
        (*i).afisare();
        std::cout << "\n";
    }
    std::cout << "\n";
    /*
        std::string a("Matei");
        std::string b("Daniel");
        bool r = a < b;
        int r1 = a > b;
        std::cout << r << " " << r1 << "\n";
        daca r1 = 0 => a se afla inaintea lui b in alfabet
        daca f1 = 1 => a se afla in alfabet dupa b (compar litera cu litera);
    */
    return EXIT_SUCCESS;
}