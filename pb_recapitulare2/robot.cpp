#include <iostream>
#include <algorithm>
#include "robot.hpp"

Robot::Robot(std::string cod, unsigned int ProductionYear) : numeCod(cod), anProductie(ProductionYear)
{
}

void Robot::afisare()
{
    std::cout << "Cod: " << numeCod << ", anProductie: " << anProductie << "\n";
}

/// @brief
/// @param input read numeCod then anProductie
/// @return
std::istream &operator>>(std::istream &input, Robot &r)
{
    input >> r.numeCod >> r.anProductie;
    return input;
}

std::ostream &operator<<(std::ostream &output, const Robot &r)
{
    output << "Cod: " << r.numeCod << ", anProductie: " << r.anProductie << "\n";
    return output;
}

// int RobotIndustrial::nrTotalRobotiIndustriali = 0;
RobotIndustrial::RobotIndustrial(std::string cod, unsigned int ProductionYear, double sarcinaKg) : Robot(cod, ProductionYear), sarcinaMaximaKg(sarcinaKg)
{
    RobotIndustrial::nrTotalRobotiIndustriali++;
}

RobotIndustrial::~RobotIndustrial()
{
    RobotIndustrial::nrTotalRobotiIndustriali--;
}

RobotIndustrial::RobotIndustrial(const RobotIndustrial &ri) : Robot(ri), sarcinaMaximaKg(ri.sarcinaMaximaKg)
{
    RobotIndustrial::nrTotalRobotiIndustriali++;
}

RobotIndustrial::RobotIndustrial(RobotIndustrial &&ri) : Robot(std::move(ri)), sarcinaMaximaKg(ri.sarcinaMaximaKg)
{
    ri.sarcinaMaximaKg = 0;
    RobotIndustrial::nrTotalRobotiIndustriali--;
}

void RobotIndustrial::afisare()
{
    Robot::afisare();
    std::cout << "Sarcina maxima kg: " << sarcinaMaximaKg << "\n";
}

int RobotIndustrial::getNrRobotiIndustriali()
{
    return nrTotalRobotiIndustriali;
}

bool RobotIndustrial::operator>(const RobotIndustrial &ri2) const
{
    return this->sarcinaMaximaKg > ri2.sarcinaMaximaKg;
}

RobotAsamblare::RobotAsamblare(std::string cod, unsigned int ProductionYear, double sarcinaKg, int piese_pe_ora, int ore_functionare_daily) : RobotIndustrial(cod, ProductionYear, sarcinaKg), PiesePeOra(piese_pe_ora), OreFunctionareZilnica(ore_functionare_daily)
{
}

RobotAsamblare::RobotAsamblare(const RobotAsamblare &ra) : RobotIndustrial(ra)
{
    PiesePeOra = ra.PiesePeOra;
    OreFunctionareZilnica = ra.OreFunctionareZilnica;
}

RobotAsamblare::RobotAsamblare(RobotAsamblare &&ra) : RobotIndustrial(std::move(ra)), PiesePeOra(ra.PiesePeOra), OreFunctionareZilnica(ra.OreFunctionareZilnica)
{
    ra.PiesePeOra = 0;
    ra.OreFunctionareZilnica = 0;
}

void RobotAsamblare::afisare()
{
    RobotIndustrial::afisare();
    std::cout << "Piese pe ora: " << PiesePeOra << ", ore de functionare: " << OreFunctionareZilnica << "\n";
}

int RobotAsamblare::calculeazaProductieZilnica() const
{
    return OreFunctionareZilnica * PiesePeOra;
}

bool comparRobotAsamblare(const RobotAsamblare &ra1, const RobotAsamblare &ra2)
{
    return ra1.calculeazaProductieZilnica() > ra2.calculeazaProductieZilnica() ? true : false;
}
