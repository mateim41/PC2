#ifndef TIMP_HPP
#define TIMP_HPP

#include <iostream>

class Timp
{
private:
    int ore, minute, secunde;
    void normalizeaza();

public:
    /// @brief
    /// @param h ore
    /// @param m minute
    /// @param s secunde
    Timp(int h = 0, int m = 0, int s = 0);

    friend std::istream &operator>>(std::istream &input, Timp &t1);
    friend std::ostream &operator<<(std::ostream &output, Timp &t1);
    Timp operator+(const Timp &t2) const;
    Timp operator+(int x) const; // adaug un nr de secunde
    friend Timp operator+(int x, const Timp &t1);
    bool operator==(const Timp &t1) const;
    bool operator<(const Timp &t1) const;
    Timp &operator++();
    Timp operator++(int);

    Timp operator-(const Timp &t2);
    Timp operator-(int x); // scad un nr de secunde;
    friend Timp operator-(int x, const Timp &t1);
    Timp &operator--();
    Timp operator--(int);
};

#endif