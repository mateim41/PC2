#ifndef FIGURA_HPP
#define FIGURA_HPP

#include <string>

class Figura
{
protected:
    std::string culoare;

public:
    Figura(std::string colour);
    virtual ~Figura() {}
    virtual double arie() = 0;
    virtual double perimetru() = 0;
    virtual void afisare() = 0;
};
bool compareFiguri(Figura *f1, Figura *f2);

class Patrat : public Figura
{
private:
    int x, y; // coordonatele coltului din stanga jos
    double latura;

public:
    Patrat(std::string colour, int i_x, int i_y, double lat);
    // ~Patrat();
    double perimetru();
    double arie();
    void afisare();
};

class Cerc : public Figura
{
private:
    int x, y, r;

public:
    Cerc(std::string colour, int x, int y, int r);
    // ~Cerc();
    double perimetru();
    double arie();
    void afisare();
};

class Triunghi : public Figura
{
private:
    int x1, y1, x2, y2, x3, y3;

public:
    Triunghi(std::string colour, int x1, int y1, int x2, int y2, int x3, int y3);
    double semiperimetru();
    double perimetru();
    double arie();
    void afisare();
};

// class Dreptunghi : public Figura
// {
// private:
//     int x1, y1;
//     int x2, y2;

// public:
//     Dreptunghi(int x1, int y1, int x2, int y2);
//     double arie();
//     void afisare();
// };

#endif