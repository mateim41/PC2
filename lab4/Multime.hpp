#ifndef MULTIME_HPP
#define MULTIME_HPP

template <typename T>
class Multime
{
private:
    T *elemente; // T elemente[100];
    int nrElem;

public:
    Multime() = delete;
    Multime(int nr);
    Multime(const Multime &M);
    Multime(Multime &&M);
    ~Multime();

    void citire();
    void afisare();
    T operator!();
    Multime operator+(const Multime &B);
};
template <typename T>
T aduna(T &x, T &y);

template <typename T>
Multime<T>::Multime(int nr) : nrElem(nr), elemente(new T[nr]{})
{
    std::cout << "constructor cu parametri" << std::endl;
}

template <typename T>
Multime<T>::Multime(const Multime &M) : nrElem(M.nrElem), elemente(new T[M.nrElem])
{
    std::cout << "constructor de copiere" << std::endl;
    std::copy(M.elemente, M.elemente + M.nrElem, this->elemente);
    /*
        sau
        for(int i = 0;i < nrElem;i++)
        {
            this->elemente[i] = M.elemente[i];
        }
    */
}

template <typename T>
Multime<T>::Multime(Multime &&M) : nrElem(M.nrElem), elemente(M.elemente)
{
    std::cout << "constructor de mutare" << std::endl;
    M.nrElem = 0;
    M.elemente = nullptr;
}

template <typename T>
Multime<T>::~Multime()
{
    std::cout << "destructor" << std::endl;
    // if(elemente) <- nu e necesar, delete[] nullptr e perfect ok in C++
    delete[] elemente;
}

template <typename T>
void Multime<T>::citire()
{
    for (int i = 0; i < nrElem; i++)
        std::cin >> elemente[i];
}

template <typename T>
void Multime<T>::afisare()
{
    for (int i = 0; i < nrElem; i++)
        std::cout << elemente[i] << " ";
    std::cout << "\n\n";
}

// returnam cel mai mare element din multime
template <typename T>
T Multime<T>::operator!()
{
    int max = elemente[0];
    for (int i = 1; i < nrElem; i++)
    {
        if (elemente[i] > max)
        {
            max = elemente[i];
        }
    }
    return max;
}

// presupunem ca putem aduna multimi de dimensiuni diferite
template <typename T>
Multime<T> Multime<T>::operator+(const Multime &B)
{
    int nr = std::max(this->nrElem, B.nrElem);
    int min = std::min(this->nrElem, B.nrElem); // 1 2 3 4 5 6 7 8 9
    Multime<T> M(nr);
    int i;
    for (i = 0; i < min; i++)
    {
        M.elemente[i] += this->elemente[i] + B.elemente[i];
    }
    while (i < this->nrElem)
    {
        M.elemente[i] = this->elemente[i];
        i++;
    }
    while (i < B.nrElem)
    {
        M.elemente[i] = B.elemente[i];
        i++;
    }
    return M;
}

template <typename T>
T aduna(T &x, T &y)
{
    return x + y;
}

#endif
