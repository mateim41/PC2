#include <iostream>

void citireArray(int *v, const size_t nr_elem);
void afisareArray(const int *v, const size_t nr_elem);
int main()
{
    int v[100], n;
    std::cout << "Nr elem: ";
    std::cin >> n;
    citireArray(v, n);
    afisareArray(v, n);

    return EXIT_SUCCESS;
}

void citireArray(int *v, const size_t nr_elem)
{
    for (int i = 0; i < nr_elem; i++)
    {
        std::cin >> *(v + i);
    }
}
void afisareArray(const int *v, const size_t nr_elem)
{
    for (int i = 0; i < nr_elem; i++)
    {
        if (i != nr_elem - 1)
            std::cout << *(v + i) << " ";
        else
            std::cout << *(v + i) << std::endl;
    }
}