#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
private:
    int re, im;

public:
    Complex();
    Complex(int real, int imaginar);
    Complex(const Complex &obiectDeCopiat);
    Complex(Complex &&nr);
    ~Complex();
    Complex aduna(Complex c2);
    void afisare();
};

#endif