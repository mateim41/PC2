#include <iostream>
using namespace std;

int &functie(int a[], int i)
{
    return a[i];
}
int main()
{
    int myArray[] = {0, 1, 2, 3, 4, 5};
    functie(myArray, 2) = 0;
    for (int i = 0; i < 6; i++)
        cout << myArray[i] << " ";
    return 0;
}