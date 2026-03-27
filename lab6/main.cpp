#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "student.hpp"

int nrLitereMari(const std::string &A)
{
    int cnt = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (isupper(A[i]))
            cnt++;
    }
    return cnt;
}
int nrCifre(const std::string &A)
{
    int cnt = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (isdigit(A[i]))
            cnt++;
    }
    return cnt;
}
void pb1main()
{
    std::string A("Ana are mere si prune si portocale si STRUGURI Si ManCARe");
    int nr_upper = nrLitereMari(A);
    std::cout << nr_upper << "\n";

    std::string B("Pb 1238 informatica este gresita; error code 404");
    int nr_digit = nrCifre(B);
    std::cout << nr_digit << "\n";
}

void pb2main()
{
    std::vector<StudentAC> s;
    s.push_back(StudentAC("Vladoi", 10));
    s.push_back(StudentAC("Bogdan", 6));
    s.push_back(StudentAC("Estera", 8));
    s.push_back(StudentAC("Matei", 2));
    afisareStudenti(s);

    StudentAC *a = new StudentAC[3];
    a[0] = StudentAC("Vlad", 7);
    a[1] = StudentAC("Matei", 10);
    a[2] = StudentAC("Ioana", 8);

    std::vector<StudentAC> b = transfVector(a, 3);
    afisareStudenti(b);

    delete[] a;
    a = nullptr;

    std::sort(s.begin(), s.end());
    afisareStudenti(s);

    std::sort(s.begin(), s.end(), StudentAC::compare);
    afisareStudenti(s);
}

int main()
{
    // pb1main();
    pb2main();

    return EXIT_SUCCESS;
}