#ifndef PUNCT_H
#define PUNCT_H

class Punct
{
private:
    double x, y;

public:
    // Punct();
    // Punct(int absica, int ordonata = 0);
    Punct(double absica = 0, double ordonata = 0);
    ~Punct();
    void citire();
    void afisare();
    double distantaOrigine();
    int comparPct(Punct A, double distpct);

    static bool comparPct(Punct A, Punct B);
    static Punct distMaxima(Punct *array, int nr_pct);
    static bool potFormaTriunghi(Punct *array, int nr_pct);
    static double distPct(Punct &A, Punct &B);
};

#endif