#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include "figura.hpp"

int main()
{
    // std::vector<Figura *> figuri;
    // Figura *f1 = new Cerc("Rosu", 2, 3, 1);
    // Figura *f2 = new Cerc("Verde", -1, 0, 2);
    // Figura *f3 = new Patrat("Negru", -2, 4, 3.09);
    // Figura *f4 = new Patrat("Magenta", -2, -1, 2.14);
    // figuri.push_back(f1);
    // figuri.push_back(f2);
    // figuri.push_back(f3);
    // figuri.push_back(f4);

    // double ArieMax = 0;
    // Figura *p;
    // for (std::vector<Figura *>::iterator i = figuri.begin(); i != figuri.end(); i++)
    // {
    //     (*i)->afisare();
    //     std::cout << "Arie = " << (*i)->arie() << "\n";
    //     if ((*i)->arie() > ArieMax)
    //     {
    //         ArieMax = (*i)->arie();
    //         p = *i;
    //     }
    // }
    // std::cout << "\nObiectul cu aria maxima este:\n";
    // p->afisare();
    // std::cout << "Arie = " << p->arie() << "\n";

    std::vector<Figura *> fig;
    Figura *f1 = new Triunghi("Gray", 2, 3, 0, 0, 5, 0);
    Figura *f2 = new Patrat("Rosu", 4, 5, 2.69);
    Figura *f3 = new Cerc("Albastru", 5, 7, 4);
    fig.push_back(f1);
    fig.push_back(f2);
    fig.push_back(f3);
    double perimetruMax = 0;
    Figura *fig_p_max;
    for (std::vector<Figura *>::iterator i = fig.begin(); i != fig.end(); i++)
    {
        if ((*i)->perimetru() > perimetruMax)
        {
            perimetruMax = (*i)->perimetru();
            fig_p_max = (*i);
        }
    }
    std::cout << "Perimetrul maxim este: " << perimetruMax << "\n";
    fig_p_max->afisare();
    std::cout << "\n";

    for (std::vector<Figura *>::iterator i = fig.begin(); i != fig.end(); i++)
    {
        (*i)->afisare();
        std::cout << (*i)->arie() << "\n";
    }
    std::cout << "\n";

    std::sort(fig.begin(), fig.end(), compareFiguri);
    for (std::vector<Figura *>::iterator i = fig.begin(); i != fig.end(); i++)
    {
        (*i)->afisare();
        std::cout << (*i)->arie() << "\n";
    }
    std::cout << "\n";

    Triunghi *fig1 = dynamic_cast<Triunghi *>(f1);
    if (fig1 != nullptr)
        std::cout << fig1->semiperimetru() << "\n";
    
    delete f1;
    delete f2;
    delete f3;
    // delete f4;

    return EXIT_SUCCESS;
}
// std::vector<Animal> v[10];
// e un array de 10 elemente de vector de Animale
// v[0] este un vector<Animal>
// v[1] este un vector<Animal>