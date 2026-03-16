#include <iostream>
using namespace std;

struct student
{
    unsigned int varsta;
    unsigned int clasa; // 1-12
    char nume[100];
};
int operatie(int a, int b)
{
    return a * b;
}
float operatie(float u, float v)
{
    return u / v;
}
/*
    daca rulam doar cu int si double nu se intampla nimic, programul
    ruleaza normal, float este transformat in double cand apelam functia
    (nu exista pierdere de precizie)
*/
double operatie(double u, double v)
{
    return u / v;
}
/*
    daca rulam doar cu functiile int si float primim eroare, compilatorul
    cauta o functie operatie pentru variabilele de tip double, insa, deoarece
    ambele functii (int si float) prezinta pierdere de precizie => nu se ruleaza
    codul
*/
double operatie(student s)
{
    return (double)s.varsta / s.clasa;
}

int main()
{
    int x = 7, y = 2;
    float n = 2.45f, m = 6.9f;
    double z = 11.3, t = 12.6;
    student s{.varsta = 18, .clasa = 10, .nume = "Darius"};
    cout << operatie(x, y) << endl;
    cout << operatie(n, m) << endl;
    cout << operatie(z, t) << endl;
    cout << operatie(s) << endl;
    return 0;
}
