#include <iostream>

int determinaMaxim(int a[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
int sumaArray(int a[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
    }
    return s;
}
bool nrCautat(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return true;
        }
    }
    return false;
}
bool nrCautat(int a[], int n, double x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return true;
        }
    }
    return false;
}
void schimba(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

int main()
{
    int a[] = {1, 5, 7, 2, 8, 3, 4};
    int maxim;
    maxim = determinaMaxim(a, sizeof(a) / sizeof(int));
    std::cout << "Maximul este: " << maxim << std::endl;
    std::cout << "Suma elementelor este: " << sumaArray(a, sizeof(a) / sizeof(int)) << std::endl;
    double x;

    std::cout << "Numarul cautat este: ";
    std::cin >> x;
    std::cout << nrCautat(a, sizeof(a) / sizeof(int), x) << std::endl;

    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j])
            {
                schimba(a[i], a[j]);
            }
    }

    return EXIT_SUCCESS;
}