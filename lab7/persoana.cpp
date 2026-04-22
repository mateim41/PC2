#include <iostream>
#include <string>
#include <algorithm>
#include "persoana.hpp"

Persoana::Persoana(std::string nume, std::string adresa, int varsta) : m_sNume(nume), m_sAdresa(adresa), m_iVarsta(varsta)
{
    std::cout << "constructor Persoana\n";
}

void Persoana::schimbareAdresa(std::string adresaNoua)
{
    this->m_sAdresa = adresaNoua;
}

int Persoana::getVarsta()
{
    return m_iVarsta;
}

Student::Student(std::string nume, std::string adresa, int varsta, int AnStudiu, int NotaP2) : Persoana(nume, adresa, varsta), m_iAnStudiu(AnStudiu), m_iNotaP2(NotaP2)
{
    std::cout << "contructor Student\n";
}

void Student::inscriereAnStudiu(int anStudiuNou)
{
    m_iAnStudiu = anStudiuNou;
}

int Student::getNota()
{
    return m_iNotaP2;
}

void Student::schimbaNota(int notaNoua)
{
    m_iNotaP2 = notaNoua;
}

void Student::afisareStudent()
{
    std::cout << "An studiu: " << m_iAnStudiu << ", Nota P2: " << m_iNotaP2 << std::endl;
}

Student Student::operator>(const Student &s2) const
{
    return this->m_iNotaP2 > s2.m_iNotaP2 ? *this : s2;
}

Angajat::Angajat(double salariu) : m_dSalariu(salariu)
{
    std::cout << "constructor Angajat\n";
}

double Angajat::getSalariu()
{
    return m_dSalariu;
}

Profesor::Profesor(std::string nume, std::string adresa, int varsta, double salariu, int gradDidactic, std::string s_gradDidactic) : Persoana(nume, adresa, varsta), Angajat(salariu), m_iGradDidactic(gradDidactic), m_sGradDidactic(s_gradDidactic)
{
    std::cout << "constructor Profesor\n";
}

void Profesor::addStudent(Student s)
{
    m_studenti.push_back(s);
}

void Profesor::acordaNota(int poz, int nota)
{
    m_studenti[poz].schimbaNota(nota);
}

void Profesor::afiseazaStudenti()
{
    for (std::vector<Student>::iterator i = m_studenti.begin(); i != m_studenti.end(); i++)
        (*i).afisareStudent();
}

bool compareStudent(Student &s1, Student &s2)
{
    return s1.getNota() > s2.getNota() ? true : false;
}

void Profesor::sortareStudenti()
{
    std::sort(m_studenti.begin(), m_studenti.end(), compareStudent);
}

std::ostream &operator<<(std::ostream &output, const Profesor &p)
{
    output << p.m_sNume << " " << p.m_iVarsta << " " << p.m_sAdresa << " " << p.m_sGradDidactic << std::endl;
    return output;
}

StudentMaster::StudentMaster(std::string nume, std::string adresa, int varsta, int anStudiu, int notaP2, std::string numeDizertatie) : Student(nume, adresa, varsta, anStudiu, notaP2), m_sNumeDizertatie(numeDizertatie)
{
    std::cout << "constructor StudentMaster\n";
}

StudentMaster::~StudentMaster()
{
    std::cout << "destructor StudentMaster\n";
}