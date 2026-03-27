#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>

class StudentAC
{
private:
    std::string nume;
    int nota;

public:
    StudentAC();
    StudentAC(std::string nume, int nota);
    void modificareNota(int nouaNota);

    friend std::ostream &operator<<(std::ostream &output, const StudentAC &s);
    static bool compare(const StudentAC &s1, const StudentAC &s2);

    std::string getNume() { return nume; };
    int getNota() { return nota; };
};
std::vector<StudentAC> transfVector(StudentAC *s, int nrStudenti);
void afisareStudenti(const std::vector<StudentAC> &s); // iau un vector de studenti si afisez informatiile la fiecare
bool operator<( StudentAC &s1, StudentAC &s2);

#endif