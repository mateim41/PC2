#include <iostream>

void citireVector(int *v, const size_t &nr_elem);
int &replaceValMin(int *v, const size_t i);

int main(void)
{
    int v[100];
    size_t n;
    std::cout << "Numarul de elemente: ";
    std::cin >> n;
    citireVector(v, n);
    int min = v[0], indice = 0;
    // valoarea minima din vector
    for (int i = 1; i < n; i++)
    {
        if (*(v + i) < min)
        {
            min = *(v + i);
            indice = i;
        }
    }
    replaceValMin(v, indice) = 0; // pot face asta, deoarece fct este o referinta la stanga
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

void citireVector(int *v, const size_t &nr_elem)
{
    for (size_t i = 0; i < nr_elem; i++)
    {
        // std::cin >> (v + i); - da eroare
        // nu merge, deoarece cin nu cere sa citeasca adresa de memorie
        std::cin >> v[i];
    }
}
int &replaceValMin(int *v, const size_t i)
{
    return v[i];
}