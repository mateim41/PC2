#include <iostream>
#include <cmath>
#include "complex.hpp"

Complex::Complex(int r, int i) : re(r), im(i)
{
    // std::cout << "constructor cu parametri" << std::endl;
}

Complex::Complex(const Complex &c) : re(c.re), im(c.im)
{
    // std::cout << "constructor de copiere" << std::endl;
}

Complex::Complex(Complex &&c) : re(c.re), im(c.im)
{
    // std::cout << "Constructor de mutare" << std::endl;
    c.re = 0;
    c.im = 0;
}

Complex::~Complex()
{
    // std::cout << "destructor" << std::endl;
}

void Complex::citire()
{
    std::cin >> re >> im;
}

void Complex::show()
{
    std::cout << re << " + " << im << "i" << std::endl;
}

// Complex Complex::operator+(Complex &b)
// {
//     Complex c;
//     c.re = this->re + b.re;
//     c.im = this->im + b.im;
//     return c;
// }

// modulul unui nr complex cu o valoare stanga
double operator~(Complex &z)
{
    std::cout << "stanga" << std::endl;

    return sqrt(z.getRe() * z.getRe() + z.getIm() * z.getIm());
}

// modulul unui nr complex cu o valoare dreapta
double operator~(Complex &&z)
{
    std::cout << "dreapta" << std::endl;
    return sqrt(z.getRe() * z.getRe() + z.getIm() * z.getIm());
}

Complex operator+(Complex &a, Complex &b)
{
    return Complex(a.getRe() + b.getRe(), a.getIm() + b.getIm());
}

Complex operator-(Complex &a, Complex &b)
{
    return Complex(a.getRe() - b.getRe(), a.getIm() - b.getIm());
}

// (3 + 4i)(5 + 6i) = 15 + 18i + 20i + 24i^2 =  15 -24 + 38i
Complex operator*(Complex &a, Complex &b)
{
    return Complex(a.getRe() * b.getRe() - a.getIm() * b.getIm(), a.getRe() * b.getIm() + a.getIm() * b.getRe());
}

bool operator==(Complex &a, Complex &b)
{
    if (a.getRe() == b.getRe() && a.getIm() == b.getIm())
        return true;
    else
        return false;
}