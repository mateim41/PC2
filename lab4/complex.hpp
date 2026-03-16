#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
private:
    int re, im;

public:
    Complex(int r = 0, int i = 0);
    Complex(const Complex &c);
    Complex(Complex &&c);
    ~Complex();

    int getRe() { return re; }
    int getIm() { return im; }
    void show();
    // Complex operator+(Complex &b);
};
Complex operator+(Complex &a, Complex &b);
Complex operator-(Complex &a, Complex &b);
Complex operator*(Complex &a, Complex &b);
double operator~(Complex &z);
double operator~(Complex &&z);

#endif