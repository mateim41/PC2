#include <iostream>
#include "personaj.hpp"

int main()
{
    std::vector<ArhiMagician> v;
    ArhiMagician a1("Darius", 7290, 120, 587, 2340, "The inescapable");
    ArhiMagician a2("Diana", 8792, 100, 900, 1500, "The OneShot");
    ArhiMagician a3("Aurelion Sol", 7999, 780, 7800, 21879, "The Star Forger");
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(a3);

    int max_hp = 0;
    std::vector<ArhiMagician>::iterator celMaiPuternic;
    for (std::vector<ArhiMagician>::iterator i = v.begin(); i != v.end(); i++)
    {
        (*i).afisareProfilArhiMagician();
        if ((*i).getViata() > max_hp)
        {
            max_hp = (*i).getViata();
            celMaiPuternic = i;
        }
    }
    std::cout << std::endl;
    (*celMaiPuternic).afisareProfilArhiMagician();

    return EXIT_SUCCESS;
}