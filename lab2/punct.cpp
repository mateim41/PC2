#include <iostream>
#include <cmath>
#include "punct.h"

// Punct::Punct()
// {
//     std::cout << "S-a apelat constructorul fara parametri" << std::endl;
// }
// Punct::Punct(int abscisa, int ordonata)
// {
//     x = abscisa;
//     y = ordonata;
//     std::cout << "S-a apelat constructorul cu parametri" << std::endl;
// }

// combinam cei doi constructori intr-unul
Punct::Punct(double abscisa, double ordonata)
{
    std::cout << "S-a apelat constructorul" << std::endl;
    x = abscisa;
    y = ordonata;
}
Punct::~Punct()
{
    std::cout << "S-a apelat destructorul" << std::endl;
}
void Punct::citire()
{
    std::cin >> x >> y;
}
void Punct::afisare()
{
    std::cout << x << " " << y << std::endl;
}
double Punct::distantaOrigine()
{
    return sqrt(x * x + y * y);
}
int Punct::comparPct(Punct A, double distpct)
{
    double dist1 = A.distantaOrigine();
    if (dist1 < distpct)
        return 0;
    else
        return 1;
}
/*
    Daca punctul A este mai aproape de origine decat B => true
    altfel                                             => false
*/
bool Punct::comparPct(Punct A, Punct B)
{
    double dist1 = A.distantaOrigine();
    double dist2 = B.distantaOrigine();
    if (dist1 > dist2)
        return true;
    else
        return false;
}
// distanta maxima a unui pct fata de origine
Punct Punct::distMaxima(Punct *array, int nr_pct)
{
    double distMax = 0;
    Punct A;
    for (int i = 0; i < nr_pct; i++)
    {
        double temp = array[i].distantaOrigine();
        if (temp > distMax)
        {
            distMax = temp;
            A = array[i];
        }
    }
    return A;
}
double Punct::distPct(Punct &A, Punct &B)
{
    return sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}
// formula lui Heron
double Arie(double &a, double &b, double &c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
bool Punct::potFormaTriunghi(Punct *array, int nr_pct)
{
    for (int i = 0; i < nr_pct - 2; i++)
    {
        Punct A = array[i];
        Punct B = array[i + 1];
        // laturile vor fi notate cu a, b, c
        for (int j = i + 2; j < nr_pct; j++)
        {
            Punct C = array[j];
            double a = Punct::distPct(B, C);
            double b = Punct::distPct(A, C), c = Punct::distPct(A, B);
            double arie = Arie(a, b, c);
            // consideram sqrt(3) = 1.73205 pentru a putea introduce o latura sqrt(3) in terminal
            double arie_ifEchilat = (a * a * 1.73205) / 4;
            if (abs(arie_ifEchilat - arie) < 0.00001)
            {
                std::cout << "Trei pct din array pot forma un triunghi echilateral" << std::endl;
                return true;
            }
            else if (a + b > c)
            {
                std::cout << "Trei pct din array pot forma un triunghi oarecare" << std::endl;
                return true;
            }
        }
    }
    return false;
}