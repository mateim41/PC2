#ifndef PBFILTRARE_HPP
#define PBFILTRARE_HPP

template <typename T>
T *ExtrageMaiMari(const T *array, const int nrElem, T prag, int &nrElemVectorNou)
{
    for (int i = 0; i < nrElem; i++)
    {
        if (array[i] > prag)
            nrElemVectorNou++;
    }
    T *arrNou = new T[nrElemVectorNou];
    int k = 0;
    for (int i = 0; i < nrElem; i++)
    {
        if (array[i] > prag)
        {
            arrNou[k] = array[i];
            k++;
        }
    }
    return arrNou;
}

#endif