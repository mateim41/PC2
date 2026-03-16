#ifndef PB3_H
#define PB3_H

struct Student
{
    int anStudiu;
    double medieNote;
};
namespace pb3
{
    void citire(Student *&s, int &nrElem);
    void afisare(Student *s, int nrElem);
    void sortare(Student *s, int nrElem, bool ordine = 0);
    double medieGenerala(Student *s, int nrElem);
}

#endif