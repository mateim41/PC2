#ifndef TEMPLATEFCT_HPP
#define TEMPLATEFCT_HPP

template <typename T>
int nrAparitii(T *v, int nrElem, T x)
{
    int nr = 0;
    for (int i = 0; i < nrElem; i++)
    {
        if (v[i] == x)
        {
            nr++;
        }
    }
    return nr;
}

#endif