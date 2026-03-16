#include <iostream>
#include <cmath>
#include "matrice.hpp"

// void Matrice::afisareElem(int idx_i, int idx_j)
// {
//     std::cout << elemente[idx_i][idx_j] << " ";
// }

Matrice::Matrice(int n, int m) : nrL(n), nrC(m)
{
    // std::cout << "constructor cu parametri" << std::endl;
}

Matrice::Matrice(const Matrice &a) : nrL(a.nrL), nrC(a.nrC)
{
    // std::cout << "constructor de copiere" << std::endl;
    for (int i = 0; i < nrL; i++)
    {
        for (int j = 0; j < nrC; j++)
        {
            this->elemente[i][j] = a.elemente[i][j];
        }
    }
}

Matrice::~Matrice()
{
    // std::cout << "destructor" << std::endl;
}

void Matrice::citire()
{
    // std::cout << "Nr linii: ";
    // std::cin >> nrL;
    // std::cout << "Nr coloane ";
    // std::cin >> nrC;
    for (int i = 0; i < nrL; i++)
    {
        for (int j = 0; j < nrC; j++)
        {
            std::cin >> elemente[i][j];
        }
    }
}

void Matrice::afisare()
{
    for (int i = 0; i < nrL; i++)
    {
        for (int j = 0; j < nrC; j++)
        {
            std::cout << elemente[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int Matrice::get_nrL()
{
    return nrL;
}
int Matrice::get_nrC()
{
    return nrC;
}
// x - scalarul adaugat
void Matrice::changeElem(int idx_i, int idx_j, int x)
{
    this->elemente[idx_i][idx_j] += x;
}

Matrice Matrice::operator+(Matrice &b)
{
    if (nrL == b.nrL && nrC == b.nrC)
    {
        Matrice m(nrL, nrC);
        for (int i = 0; i < nrL; i++)
        {
            for (int j = 0; j < nrC; j++)
            {
                m.elemente[i][j] = this->elemente[i][j] + b.elemente[i][j];
            }
        }
        return m;
    }
    else
    {
        std::cout << "Matricele nu se pot aduna" << std::endl;
        return 1;
    }
}

Matrice Matrice::operator-(Matrice &b)
{
    if (nrL == b.nrL && nrC == b.nrC)
    {
        Matrice m(nrL, nrC);
        for (int i = 0; i < nrL; i++)
        {
            for (int j = 0; j < nrC; j++)
            {
                m.elemente[i][j] = this->elemente[i][j] - b.elemente[i][j];
            }
        }
        return m;
    }
    else
    {
        std::cout << "Matricele nu se pot scadea" << std::endl;
        return 1;
    }
}
/*
    1 2 * 5 6 = 1 * 5 + 2 * 7, 1 * 6 + 2 * 8 = 19 22
    3 4   7 8   3 * 5 + 4 * 7, 3 * 6 + 4 * 8   43 50
*/
Matrice Matrice::operator*(Matrice &b)
{
    if (nrC == b.nrL)
    {
        Matrice m(nrL, b.nrC);
        for (int i = 0; i < nrL; i++)
        {
            int k = 0;
            for (int k = 0; k < b.nrC; k++)
            {
                for (int j = 0; j < b.nrC; j++)
                {
                    m.elemente[i][k] += this->elemente[i][j] * b.elemente[j][k];
                }
            }
        }
        return m;
    }
    else
    {
        std::cout << "Matricele nu se pot inmulti" << std::endl;
        return 1;
    }
}

// returnam un logical matrix care contine 1 daca elem sunt egale si 0 altfel
Matrice Matrice::operator==(Matrice &b)
{
    if (nrL == b.nrL && nrC == b.nrC)
    {
        Matrice m(nrL, nrC);
        for (int i = 0; i < nrL; i++)
        {
            for (int j = 0; j < nrC; j++)
            {
                if (this->elemente[i][j] == b.elemente[i][j])
                    m.elemente[i][j] = 1;
                else
                    m.elemente[i][j] = 0;
            }
        }
        return m;
    }
    else
    {
        std::cout << "Matricele nu pot fi comparate" << std::endl;
        return 1;
    }
}

/*
    1 2 3 4 5
    5 6 7 5 6
    9 9 9 7 6
*/

// inversarea elementelor fata de diag principala
void Matrice::operator~()
{
    int k = std::min(nrL, nrC);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i == j)
                break;
            else
            {
                int aux = elemente[i][j];
                elemente[i][j] = elemente[j][i];
                elemente[j][i] = aux;
            }
        }
    }
}

// ++ post-fixat
Matrice Matrice::operator++(int)
{
    Matrice temp = *this;
    for (int i = 0; i < nrL; i++)
    {
        for (int j = 0; j < nrC; j++)
        {
            if (i == j)
                this->changeElem(i, j, 1);
        }
    }
    return temp;
}

// ++ pre-fixat
Matrice &Matrice::operator++()
{
    for (int i = 0; i < nrL; i++)
    {
        for (int j = 0; j < nrC; j++)
        {
            if (i == j)
                this->changeElem(i, j, 1);
        }
    }
    return *this;
}

// returnez elementul de pe linia x/nrC si coloana x % nrC
int Matrice::operator()(int x, int y)
{
    return this->elemente[x][y];
}

Matrice operator+(Matrice &a, int x)
{
    int n = a.get_nrL();
    int m = a.get_nrC();
    Matrice M(a);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            M.changeElem(i, j, x);
        }
    }
    return M;
}

Matrice operator+(int x, Matrice &a)
{
    int n = a.get_nrL();
    int m = a.get_nrC();
    Matrice M(a);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            M.changeElem(i, j, x);
        }
    }
    return M;
}
