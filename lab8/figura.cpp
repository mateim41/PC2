#include <iostream>
#include <string>
#include <cmath>
#include "figura.hpp"

Figura::Figura(std::string colour) : culoare(colour)
{
}

// Figura::~Figura()
// {
//     std::cout << "destructor Figura\n";
// }

Cerc::Cerc(std::string colour, int x, int y, int r) : Figura(colour)
{
    // std::cout << "constructor Cerc\n";
    this->x = x;
    this->y = y;
    this->r = r;
}

// Cerc::~Cerc()
// {
//     // std::cout << "destructor cerc\n";
// }

double Cerc::perimetru()
{
    return 2 * 3.14159 * r;
}

void Cerc::afisare()
{
    std::cout << "Cerc de centru (" << x << "," << y << ") si raza = " << r << "\n";
}

double Cerc::arie()
{
    return 3.14159 * r * r;
}

// Dreptunghi::Dreptunghi(int x1, int y1, int x2, int y2)
// {
//     this->x1 = x1;
//     this->y1 = y1;
//     this->x2 = x2;
//     this->y2 = y2;
// }

// double Dreptunghi::arie()
// {
//     return abs((x1 - x2) * (y1 - y2));
// }

// void Dreptunghi::afisare()
// {
//     std::cout << "Dreptunghi delimitat de dreptele x = " << x1 << ", x = " << x2 << ", y = " << y1 << ", y = " << y2 << "\n";
// }

Patrat::Patrat(std::string colour, int i_x, int i_y, double lat) : Figura(colour)
{
    // std::cout << "constructor Patrat\n";
    x = i_x;
    y = i_y;
    latura = lat;
}

// Patrat::~Patrat()
// {
//     // std::cout << "destructor Patrat\n";
// }

double Patrat::perimetru()
{
    return 4 * latura;
}

double Patrat::arie()
{
    return latura * latura;
}

void Patrat::afisare()
{
    std::cout << "Patrat de latura: " << latura << " si colt stanga jos: (" << x << "," << y << ")\n";
}

Triunghi::Triunghi(std::string colour, int x1, int y1, int x2, int y2, int x3, int y3) : Figura(colour), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3)
{
}

double Triunghi::semiperimetru()
{
    double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double b = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    double c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    return (a + b + c) / 2;
}

double Triunghi::perimetru()
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) +
           sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2)) +
           sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
}

double Triunghi::arie()
{
    double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double b = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    double c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double p = semiperimetru();
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triunghi::afisare()
{
    std::cout << "Triunghi de varfuri: " << "(" << x1 << "," << y1 << "), " << "(" << x2 << "," << y2 << "), " << "(" << x3 << "," << y3 << ")\n";
}

bool compareFiguri(Figura *f1, Figura *f2)
{
    return f1->arie() < f2->arie() ? true : false;
}
