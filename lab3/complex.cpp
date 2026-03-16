#include <iostream>
#include "complex.hpp"

Complex::Complex()
{
    std::cout << "S-a apelat constructorul Complex::Complex()" << std::endl;
}
Complex::Complex(int real, int imaginar) : re(real), im(imaginar)
{
    std::cout << "S-a apelat constructorul Complex::Complex(int real, int imaginar)" << std::endl;
}
Complex::Complex(const Complex &obiectDeCopiat) : re(obiectDeCopiat.re), im(obiectDeCopiat.im)
{
    std::cout << "S-a apelat constructorul de copiere" << std::endl;
}
Complex::Complex(Complex &&nr) : re(nr.re), im(nr.im)
{
    std::cout << "S-a apelat constructoul de mutare" << std::endl;
    nr.re = 0;
    nr.im = 0;
}
Complex::~Complex()
{
    std::cout << "S-a apelat destructorul" << std::endl;
}
Complex Complex::aduna(Complex c2)
{
    Complex rez;
    rez.re = re + c2.re;
    rez.im = im + c2.im;
    return rez;
}
void Complex::afisare()
{
    std::cout << "(" << re << " + " << im << "i)" << std::endl;
}