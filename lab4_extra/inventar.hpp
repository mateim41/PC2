#ifndef INVENTAR_HPP
#define INVENTAR_HPP

#include <algorithm>

template <typename T>
class Inventar
{
private:
    int nr;
    T *array;

public:
    Inventar();
    Inventar(int nr_prod);
    Inventar(const Inventar &I);
    Inventar(Inventar &&I);
    ~Inventar();

    void citire();
    void afisare();
    Inventar &operator+=(const T &x);
    T operator[](int idx);
    Inventar operator-(Inventar &I2);
};

template <typename T>
inline Inventar<T>::Inventar() : nr(0), array(nullptr)
{
}

template <typename T>
inline Inventar<T>::Inventar(int nr_prod) : nr(nr_prod), array(new T[nr_prod])
{
}

template <typename T>
inline Inventar<T>::Inventar(const Inventar &I) : nr(I.nr), array(new T[I.nr])
{
    std::copy(I.array, I.array + I.nr, this->array);
}

template <typename T>
inline Inventar<T>::Inventar(Inventar &&I) : nr(I.nr), array(I.array)
{
    I.nr = 0;
    I.array = nullptr;
}

template <typename T>
inline Inventar<T>::~Inventar()
{
    delete[] array;
}

template <typename T>
void Inventar<T>::citire()
{
    for (int i = 0; i < nr; i++)
        std::cin >> array[i];
}

template <typename T>
void Inventar<T>::afisare()
{
    for (int i = 0; i < nr; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

// inserez un element nou la finalul vectorului
template <typename T>
Inventar<T> &Inventar<T>::operator+=(const T &x)
{
    T *array = new T[nr + 1];
    std::copy(this->array, this->array + nr, array);
    array[nr] = x;
    nr++;

    delete[] this->array;
    this->array = array;
    array = nullptr;
    return *this;
}

template <typename T>
T Inventar<T>::operator[](int idx)
{
    return array[idx];
}

// elementele care sunt in primul si nu sunt in al doilea
template <typename T>
Inventar<T> Inventar<T>::operator-(Inventar &I2)
{
    int idx = 0;
    T *v = new T[this->nr];
    for (int i = 0; i < this->nr; i++)
    {
        bool ok = true;
        for (int j = 0; j < I2.nr; j++)
        {
            if (this->array[i] == I2.array[j])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            v[idx] = this->array[i];
            idx++;
        }
    }
    Inventar<T> rez(idx);
    std::copy(v, v + idx, rez.array);
    delete[] v;

    return rez;
}

#endif