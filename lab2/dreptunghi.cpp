#include <iostream>
#include "dreptunghi.h"

void Dreptunghi::setLungime(int lung)
{
    lungime = lung;
}
void Dreptunghi::setLatime(int lat)
{
    latime = lat;
}
int Dreptunghi::Aria()
{
    return lungime * latime;
}