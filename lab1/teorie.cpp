#include <iostream>
using namespace std;

int main(void)
{
    int a = 20;
    cout << &a; // afisez adresa lui a
    a + 1;      // valoarea dreapta - nu pot gasi in memorie a+1
    int &b = a; // creez un alias
    b = 24;
    cout << &b; // e tot adresa lui a

    return EXIT_SUCCESS;
}