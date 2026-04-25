#pragma once

#include <iostream>
#include <string>

class Robot
{
protected:
    std::string numeCod;
    unsigned int anProductie;

public:
    Robot(std::string cod = "0", unsigned int ProductionYear = 0);
    virtual ~Robot() = default;
    virtual void afisare();
    Robot(const Robot &r) = default;
    Robot(Robot &&r) = default;
    Robot &operator=(const Robot &r) = default;
    Robot &operator=(Robot &&r) = default;
    friend std::istream &operator>>(std::istream &input, Robot &r);
    friend std::ostream &operator<<(std::ostream &output, const Robot &r);
};

class RobotIndustrial : public Robot
{
private:
    double sarcinaMaximaKg;
    inline static int nrTotalRobotiIndustriali = 0;

public:
    RobotIndustrial(std::string cod = "0", unsigned int ProductionYear = 0, double sarcinaKg = 0);
    ~RobotIndustrial();
    RobotIndustrial(const RobotIndustrial &ri);
    RobotIndustrial(RobotIndustrial &&ri);
    RobotIndustrial &operator=(const RobotIndustrial &ri) = default;
    RobotIndustrial &operator=(RobotIndustrial &&ri) = default;
    void afisare();
    static int getNrRobotiIndustriali();
    bool operator>(const RobotIndustrial &ri2) const;
};

class RobotAsamblare : public RobotIndustrial
{
private:
    int PiesePeOra;
    int OreFunctionareZilnica;

public:
    RobotAsamblare(std::string cod = "0", unsigned int ProductionYear = 0, double sarcinaKg = 0, int piese_pe_ora = 0, int ore_functionare_daily = 0);
    ~RobotAsamblare() = default;
    RobotAsamblare(const RobotAsamblare &ra);
    RobotAsamblare(RobotAsamblare &&ra);
    RobotAsamblare &operator=(const RobotAsamblare &ra) = default;
    RobotAsamblare &operator=(RobotAsamblare &&ra) = default;
    void afisare();
    int calculeazaProductieZilnica() const;
};
bool comparRobotAsamblare(const RobotAsamblare &ra1, const RobotAsamblare &ra2);