#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "film.hpp"
#include "carte.hpp"
#include "autor.hpp"

void pb6_extra()
{
    Film f1;
    Film f2("Dune", 3, 4.83f);
    std::cout << f1 << f2;

    std::cout << f2.GetRating() << std::endl;
    f2.setRating(4.95f);
    std::cout << "New rating = " << f2.GetRating() << std::endl;
    std::cout << (f1 < f2) << std::endl;

    Carte *c1 = new Carte("Povestea familiei Heike", 1950);
    Autor *a = new Autor("Eiji Yoshikawa", 1892);
    c1->addAutor(a);
    Carte *c2 = new Carte(*c1);
    std::cout << *c1 << *c2;

    std::cout << c1->GetAutor();
    std::cout << c2->GetAutor();

    delete c1;
    c1 = nullptr;
    delete c2;
    c2 = nullptr;

    std::cout << *a;
    // am distrus obiectele de tip Carte c1, c2 si inca putem lucra cu autorul
    // deci am folosit agregarea
    delete a;
    a = nullptr;

    std::vector<Film> array_filme(3);
    array_filme[0] = Film("Dune", 3, 4.95f);
    array_filme[1] = Film("Bubble", 2, 3.5f);
    array_filme[2] = Film("Demon Slayer", 1, 4.01f);

    for (std::vector<Film>::iterator i = array_filme.begin(); i != array_filme.end(); i++)
        std::cout << *i;
    std::cout << std::endl;

    std::sort(array_filme.begin(), array_filme.end(), Film::compare);
    for (std::vector<Film>::iterator i = array_filme.begin(); i != array_filme.end(); i++)
        std::cout << *i;
}

int main()
{
    pb6_extra();

    return EXIT_SUCCESS;
}