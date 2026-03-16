#ifndef ARRAYSIMPLU_HPP
#define ARRAYSIMPLU_HPP

class arraySimplu
{
private:
    int nrElemente;
    int *array;

public:
    arraySimplu() = delete;
    arraySimplu(int nrElem);
    arraySimplu(const arraySimplu &tablouDeCopiat);
    ~arraySimplu();
    void setValoareElem(int poz, int val);
};

#endif