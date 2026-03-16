#include <iostream>
#include "arraySimplu.hpp"

arraySimplu::arraySimplu(int nrElem)
{
    nrElemente = nrElem;
    array = new int[nrElemente];
}
arraySimplu::arraySimplu(const arraySimplu &tablouDeCopiat) 
{
    
}
arraySimplu::~arraySimplu() {}
void arraySimplu::setValoareElem(int poz, int val) {}