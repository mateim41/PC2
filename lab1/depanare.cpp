#include <iostream>

int determinaMaxim(int a[], unsigned int dim)
{
    int maxim = a[0];
    for (unsigned int i = 1; i < dim; i++)
    {
        if (a[i] > maxim)
        {
            maxim = a[i];
        }
    }
    return maxim;
}

int main()
{
    int a[] = {1, 5, 7, 2, 8, 3, 4};
    int maxim;
    maxim = determinaMaxim(a, sizeof(a) / sizeof(int));
    std::cout << "Maximul este: " << maxim << std::endl;

    return EXIT_SUCCESS;
}
