#ifndef DRONA_HPP
#define DRONA_HPP

#include <iostream>
#include <string>
#include <vector>

class Baterie
{
private:
    int capacitate_mAh;
    double sanatate_procent;

public:
    Baterie(int capacitate = 0, double sanatate = 0); // 0 < sanatate < 1 - procent
    ~Baterie();
    friend std::ostream &operator<<(std::ostream &output, const Baterie &b);
    int get_capacitatemAh() { return capacitate_mAh; };
    double get_sanatate_procent() { return sanatate_procent; };
};

class Drona
{
private:
    std::string model;
    Baterie *baterie_interna;

public:
    Drona(std::string model, int fn_capacitate, double fn_procent);
    ~Drona();
};

class OperatorDrona
{
private:
    std::string nume;
    int numar_zboruri;

public:
    OperatorDrona(std::string name = "0", int nb_flights = 0);
    std::string getName() { return nume; };
    int get_nbFlights() { return numar_zboruri; };
    friend std::ostream &operator<<(std::ostream &output, const OperatorDrona &op);
};
void eliminaIncepatori(std::vector<OperatorDrona> &v);

class EchipaLivrare
{
private:
    std::string nume_echipa;
    std::vector<OperatorDrona *> v;

public:
    EchipaLivrare(std::string team_name);
    ~EchipaLivrare();
    std::string getName() { return nume_echipa; };
    friend std::ostream &operator<<(std::ostream &output, const EchipaLivrare &e);
    void addOperator(OperatorDrona *op);
    void concediazaOperator(std::string nume);
};

#endif