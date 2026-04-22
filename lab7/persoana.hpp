#ifndef PERSOANA_HPP
#define PERSOANA_HPP

#include <iostream>
#include <string>
#include <vector>

class Persoana
{
protected:
    std::string m_sNume;
    std::string m_sAdresa;
    int m_iVarsta;

public:
    Persoana(std::string nume = "undefined", std::string adresa = "undefined", int varsta = 0);
    void schimbareAdresa(std::string adresaNoua);
    int getVarsta();
};

class Student : public Persoana
{
protected:
    int m_iAnStudiu, m_iNotaP2;

public:
    Student(std::string nume = "undefined", std::string adresa = "undefined", int varsta = 0, int AnStudiu = 0, int NotaP2 = 0);
    void inscriereAnStudiu(int anStudiuNou);
    int getNota();
    void schimbaNota(int notaNoua);
    void afisareStudent();

    Student operator>(const Student &s2) const;
};

class Angajat
{
protected:
    double m_dSalariu;

public:
    Angajat(double salariu = 0);
    double getSalariu();
};

class Profesor : public Persoana, public Angajat
{
private:
    int m_iGradDidactic;
    std::string m_sGradDidactic;
    std::vector<Student> m_studenti;

public:
    Profesor(std::string nume = "undefined", std::string adresa = "undefined", int varsta = 0, double salariu = 0, int gradDidactic = 0, std::string s_gradDidactic = "undefined");
    void addStudent(Student s);
    void acordaNota(int poz, int nota);
    void afiseazaStudenti();
    void sortareStudenti();
    friend std::ostream &operator<<(std::ostream &output, const Profesor &p);
};
bool compareStudent(Student &s1, Student &s2);

class StudentMaster : public Student
{
private:
    std::string m_sNumeDizertatie;

public:
    StudentMaster(std::string nume = "0", std::string adresa = "0", int varsta = 0, int anStudiu = 0, int notaP2 = 0, std::string numeDizertatie = "0");
    ~StudentMaster();
};

#endif