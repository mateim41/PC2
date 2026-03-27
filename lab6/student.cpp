#include <iostream>
#include <string>
#include <algorithm>
#include "student.hpp"

StudentAC::StudentAC() : nume("0"), nota(0)
{
}

StudentAC::StudentAC(std::string nume, int nota) : nume(nume), nota(nota)
{
}

std::ostream &operator<<(std::ostream &output, const StudentAC &s)
{
    output << "Nume: " << s.nume << ", Nota = " << s.nota << std::endl;
    return output;
}

bool StudentAC::compare(const StudentAC &s1, const StudentAC &s2)
{
    return s1.nota > s2.nota ? true : false;
}

void StudentAC::modificareNota(int nouaNota)
{
    this->nota = nouaNota;
}

void afisareStudenti(const std::vector<StudentAC> &s)
{
    for (std::vector<StudentAC>::const_iterator i = s.begin(); i != s.end(); i++)
    {
        std::cout << *i;
    }
}

std::vector<StudentAC> transfVector(StudentAC *s, int nrStudenti)
{
    // std::vector<StudentAC> student(s, s + nrStudenti);
    // std::copy(s, s + nrStudenti, studenti.begin());
    return std::vector<StudentAC>(s, s + nrStudenti);
}

bool operator<(StudentAC &s1, StudentAC &s2)
{
    return s1.getNota() < s2.getNota() ? true : false;
}