#ifndef PB5_HPP
#define PB5_HPP

// folosim numai date de tip POD
template <typename T>
void swap(T &a, T &b)
{
    T aux = a;
    a = b;
    b = aux;
}

// sortam descrescator
template <typename T>
void sortare(T *v, int nrElem)
{
    for (int i = 0; i < nrElem - 1; i++)
    {
        for (int j = i + 1; j < nrElem; j++)
            if (v[i] < v[j])
                swap(v[i], v[j]);
    }
}

#endif
