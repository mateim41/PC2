#include <iostream>
#include "persoana.hpp"

int main()
{
    Profesor p1("Ion", "Pacurari 50", 50, 3488.12, 2, "Grad 2");
    std::cout << p1;

    Student s1("Matei", "Iasi", 20, 1, 5);
    Student s2("Vlad", "Iasi", 20, 1, 9);
    Student s3("Estera", "Iasi", 21, 2, 7);
    Student s4("Bianca", "Iasi", 19, 1, 10);

    Student s5 = s1 > s2;
    s5.afisareStudent();
    std::cout << std::endl;

    p1.addStudent(s1);
    p1.addStudent(s2);
    p1.addStudent(s3);
    p1.addStudent(s4);
    p1.afiseazaStudenti();
    std::cout << "\n";

    p1.sortareStudenti();
    p1.afiseazaStudenti();
    std::cout << "\n";

    p1.acordaNota(0, 10);
    p1.acordaNota(1, 4);
    p1.acordaNota(2, 8);
    p1.afiseazaStudenti();

    std::vector<StudentMaster> m_studentimaster;
    m_studentimaster.push_back(StudentMaster("Matei", "Iasi", 19, 5, 7, "Securitate cibernetica si metode avansate de protectie a datelor"));
    m_studentimaster.push_back(StudentMaster("Daniela", "Vaslui", 20, 5, 10, "AI and its uses in Automatics"));
    m_studentimaster.push_back(StudentMaster("Ioana", "Bucuresti", 21, 5, 5, "Machine Learning and AI"));
    int max = -1;
    for (std::vector<StudentMaster>::iterator i = m_studentimaster.begin(); i != m_studentimaster.end(); i++)
        if ((*i).getNota() > max)
            max = (*i).getNota();
    std::cout << max << std::endl;

    return EXIT_SUCCESS;
}