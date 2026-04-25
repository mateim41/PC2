#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "laptop.hpp"
#include "dispozitiv.hpp"
#include "laptopgaming.hpp"
#include "robot.hpp"
// in caz ca te uiti la pb_robot (robot.hpp, robot.cpp)
// mi o venit mie in cap sa fac anumiti constructori(copiere, mutare), destructori
// si o trebuit sa declar ca default o gramade de chestii, printre care si
// operator= de copiere si de mutare
// de aceeea codul e foarte intortocheat

void pb_dispozitiv()
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
}

void pb_robot()
{
    Robot r1;
    Robot r2("robot1", 2013);
    std::cout << r1 << r2;

    std::cout << "Nr roboti industriali: " << RobotIndustrial::getNrRobotiIndustriali() << "\n\n";
    RobotIndustrial ri1("robot_industrial1", 2020, 50);
    RobotIndustrial *ri2 = new RobotIndustrial(ri1);
    ri1.afisare();
    ri2->afisare();
    std::cout << "Nr roboti industriali: " << RobotIndustrial::getNrRobotiIndustriali() << "\n";
    if (ri1 > (*ri2))
        std::cout << "Primul robot poate sa care mai mult decat al doilea\n";
    else
        std::cout << "Al doilea robot poate sa care mai mult decat al doilea\n";
    // nu mai supraincarc operatorul > si ==
    delete ri2;
    std::cout << "Nr roboti industriali: " << RobotIndustrial::getNrRobotiIndustriali() << "\n\n\n";

    std::vector<RobotAsamblare> robotiA;
    robotiA.push_back(RobotAsamblare("robotA1", 2015, 52.25, 100, 16));
    robotiA.push_back(RobotAsamblare("robotA2", 2014, 60.50, 80, 24));
    robotiA.push_back(RobotAsamblare("robotA3", 2020, 75, 120, 10));
    int productieZilnica = 0;
    for (auto i = robotiA.begin(); i != robotiA.end(); i++)
        productieZilnica += (*i).calculeazaProductieZilnica();
    std::cout << "Productia zilnica a fabricii: " << productieZilnica << "\n";
    for (auto &i : robotiA)
    {
        i.afisare();
        std::cout << "\n";
    }
    std::cout << "\n";
    std::sort(robotiA.begin(), robotiA.end(), comparRobotAsamblare);
    for (std::vector<RobotAsamblare>::iterator i = robotiA.begin(); i != robotiA.end(); i++)
    {
        (*i).afisare();
        std::cout << "\n";
    }
    std::cout << "\n";

    std::vector<std::unique_ptr<Robot>> roboti;
    roboti.push_back(std::make_unique<Robot>("Robot1", 2010));
    roboti.push_back(std::make_unique<RobotIndustrial>("Robot2", 2016, 57.25));
    roboti.push_back(std::make_unique<RobotAsamblare>("Robot3", 2020, 60.50, 100, 20));
    roboti.push_back(std::make_unique<RobotIndustrial>("Robot4", 2021, 25.5));
    for (auto i = roboti.begin(); i != roboti.end(); i++)
    {
        (*i)->afisare();
        std::cout << "\n";
    }
    std::cout << "\n";

    std::vector<Robot *> vRoboti;
    Robot *robot1 = new Robot("Robot1", 2010);
    Robot *robot2 = new RobotIndustrial("Robot2", 2016, 57.25);
    Robot *robot3 = new RobotAsamblare("Robot3", 2020, 60.50, 100, 20);
    Robot *robot4 = new RobotIndustrial("Robot4", 2021, 25.5);
    vRoboti.push_back(robot1);
    vRoboti.push_back(robot2);
    vRoboti.push_back(robot3);
    vRoboti.push_back(robot4);
    RobotAsamblare *robot_cautat; // caut robotAsamblare pentru a calcula productia anuala
                                  // presupunem ca anul are 365 de zile
    int productieAnuala = 0;
    for (int i = 0; i < vRoboti.size(); i++)
    {
        robot_cautat = dynamic_cast<RobotAsamblare *>(vRoboti[i]);
        if (robot_cautat != nullptr)
        {
            productieAnuala += robot_cautat->calculeazaProductieZilnica() * 365;
        }
    }
    std::cout << "Productia anuala a robotilor de asamblare este: " << productieAnuala << "\n";
    delete robot1;
    delete robot2;
    delete robot3;
    delete robot4;
}

int main()
{
    pb_robot();

    return EXIT_SUCCESS;
}