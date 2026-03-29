#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include "film.hpp"
#include "carte.hpp"
#include "autor.hpp"
#include "produsit.hpp"
#include "jucator.hpp"

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

// ex_1 gemini
int nrVocale(std::string sir)
{
    int cnt = 0;
    for (std::string::iterator i = sir.begin(); i != sir.end(); i++)
        if (strchr("aeiou", *i))
            cnt += 1;
    return cnt;
}
int nrSpatii(std::string sir)
{
    int cnt = 0;
    for (int i = 0; i < sir.length(); i++)
    {
        if (isspace(sir[i]))
            cnt++;
    }
    return cnt;
}
// !ex_1 gemini

void pb1_gemini()
{
    std::string text("I love coding in C++ !");
    int nb_vowels = nrVocale(text);
    int nb_spaces = nrSpatii(text);
    std::cout << "Nr vocale = " << nb_vowels << "\nNr spatii = " << nb_spaces << std::endl;
}

void pb2_gemini()
{
    ProdusIT p1("Telefon", 1900);
    std::cout << p1;
    p1.aplicaReducere(0.357);
    std::cout << p1 << std::endl;

    ProdusIT *p = new ProdusIT[5];
    p[0] = ProdusIT("Masina de spalat vase", 2500);
    p[1] = ProdusIT("Masina de spalat rufe", 3000);
    p[2] = ProdusIT("Masina", 49980.756);
    p[3] = ProdusIT("Termostat", 120.15);
    p[4] = ProdusIT("Centrala de apartament", 7000);
    for (int i = 0; i < 5; i++)
        std::cout << p[i];
    std::cout << std::endl;

    std::vector<ProdusIT> vector_p = transf_in_Vector(p, 5);
    afisareProduse(vector_p);

    std::sort(vector_p.begin(), vector_p.end());
    afisareProduse(vector_p);

    delete[] p;
}

void pb3_gemini()
{
    Jucator j1("Daniel", 23);
    std::cout << j1 << std::endl;

    std::vector<Jucator> v_j;
    v_j.push_back(j1);
    v_j.push_back(Jucator("Matei", 25));
    v_j.push_back(Jucator("Anca", 52));
    v_j.push_back(Jucator("Vlad", 67));
    v_j.push_back(Jucator("Rares", 12));
    v_j.push_back(Jucator("Musiala", 13));

    for (std::vector<Jucator>::iterator i = v_j.begin(); i != v_j.end(); i++)
        std::cout << *i;
    std::cout << std::endl;

    elimJucator(v_j);

    std::sort(v_j.begin(), v_j.end(), compareJucator);
    for (std::vector<Jucator>::iterator i = v_j.begin(); i != v_j.end(); i++)
        std::cout << *i;
}

int main()
{
    // pb6_extra();
    // pb1_gemini();
    // pb2_gemini();
    pb3_gemini();

    return EXIT_SUCCESS;
}