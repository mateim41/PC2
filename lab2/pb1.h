// parametrii impliciti trb sa se afle la finalul listei de parametri ai functiei
// int afisare(int a, int b = 0, int c) <- nu functioneaza

#ifndef PB1_H
#define PB1_H

namespace pb1
{
    // daca ordineAfisare = 0 => afisez in ordine normala
    //                    = 1 => afisez in ordine inversa
    void afisare(int *v, int nrElem, bool ordineAfisare = 0);
}

#endif