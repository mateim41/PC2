#ifndef FRACTIE_HPP
#define FRACTIE_HPP

class Fractie
{
private:
    int numarator, numitor;
    void simplifica();

public:
    Fractie(int top = 0, int bottom = 1);
    Fractie(const Fractie &F);
    Fractie(Fractie &&F);
    ~Fractie();

    void citire();
    Fractie operator+(const Fractie &b) const;//nici obiectul pt care apelam fct nu se modifica <=> const final
    Fractie operator*(const Fractie &b) const;
    bool operator==(const Fractie &b) const;
    Fractie operator~();
    void operator!();
};

#endif