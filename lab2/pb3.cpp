#include <iostream>
#include "pb3.h"

void pb3::citire(Student *&s, int &nrElem)
{
    try
    {
        std::cout << "Nr studenti: ";
        std::cin >> nrElem;
        s = new Student[nrElem];
        std::cout << "Se vor citi pe rand anStudiu si medieNote" << std::endl;
        for (int i = 0; i < nrElem; i++)
        {
            std::cin >> s[i].anStudiu >> s[i].medieNote;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Eroare alocare";
        exit(EXIT_FAILURE);
    }
}
void pb3::afisare(Student *s, int nrElem)
{
    for (int i = 0; i < nrElem; i++)
    {
        std::cout << s[i].anStudiu << " " << s[i].medieNote << std::endl;
    }
    std::cout << std::endl;
}
void pb3::sortare(Student *s, int nrElem, bool ordine)
{
    if (ordine == 0)
    {
        for (int i = 0; i < nrElem - 1; i++)
        {
            for (int j = i + 1; j < nrElem; j++)
            {
                if (s[i].medieNote > s[j].medieNote)
                {
                    Student aux = s[i];
                    s[i] = s[j];
                    s[j] = aux;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < nrElem - 1; i++)
        {
            for (int j = i + 1; j < nrElem; j++)
            {
                if (s[i].medieNote < s[j].medieNote)
                {
                    Student aux = s[i];
                    s[i] = s[j];
                    s[j] = aux;
                }
            }
        }
    }
}
double pb3::medieGenerala(Student *s, int nrElem)
{
    double medie_gen = 0;
    for (int i = 0; i < nrElem; i++)
    {
        medie_gen += s[i].medieNote;
    }
    return medie_gen / nrElem;
}