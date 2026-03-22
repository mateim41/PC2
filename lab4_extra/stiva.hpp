#ifndef STIVA_HPP
#define STIVA_HPP

#include <iostream>

template <typename T>
class Stiva
{
private:
    T *stv;
    int capacitate;
    int varf;

public:
    Stiva();
    Stiva(int stocare, int nrElem);
    Stiva(const Stiva &s);
    Stiva(Stiva &&s);
    ~Stiva();

    friend std::istream &operator>>(std::istream &input, Stiva &s);
    friend std::ostream &operator<<(std::ostream &stream, const Stiva &s);
    Stiva &operator=(const Stiva &s);
    Stiva &operator=(Stiva &&s);
    Stiva &operator++();
    Stiva operator++(int);
    Stiva &operator--();
    Stiva operator--(int);
    Stiva &operator+=(T element);
    Stiva &operator~();
};

template <typename T>
inline std::istream &operator>>(std::istream &input, Stiva<T> &s)
{
    input >> s.capacitate >> s.varf;
    s.stv = new T[s.capacitate];
    for (int i = 0; i < s.varf; i++)
    {
        input >> s.stv[i];
    }
    return input;
}

template <typename T>
inline std::ostream &operator<<(std::ostream &stream, const Stiva<T> &s)
{
    for (int i = 0; i < s.varf; i++)
    {
        stream << s.stv[i] << "\n";
    }
    return stream;
}



#endif