#ifndef MATRICE_HPP
#define MATRICE_HPP

class Matrice
{
private:
    int elemente[10][10]{};
    int nrL, nrC;

public:
    Matrice(int n = 0, int m = 0);
    Matrice(const Matrice &a);
    ~Matrice();

    int get_nrL();
    int get_nrC();
    void changeElem(int idx_i, int idx_j, int x);
    void citire();
    void afisare();
    void afisareElem(int idx_i, int idx_j);
    Matrice operator+(Matrice &b);
    Matrice operator-(Matrice &b);
    Matrice operator*(Matrice &b);
    Matrice operator==(Matrice &b); // returnez un logical array ca in MatLab
    void operator~();
    Matrice operator++(int);
    Matrice &operator++();
    int operator()(int x, int y);
};
// template <typename T> Matrice operator+(Matrice &a, T x);
// template <typename T> Matrice operator+(T x, Matrice &a);
// trb sa declar template pt fiecare fct globala in parte

Matrice operator+(Matrice &a, int x);
Matrice operator+(int x, Matrice &a);

#endif