#ifndef AUTOTURISM_HPP
#define AUTOTURISM_HPP

class Autoturism
{
private:
    char *culoare;
    unsigned int an_fabricatie;

public:
    Autoturism();
    Autoturism(char *colour, unsigned int ReleaseDate);
    Autoturism(const Autoturism &a);
    Autoturism(Autoturism &&a);
    ~Autoturism();

    void citire();
    void afisare();
    void changeColour(char *new_colour);
    void changeAnFabricatie(unsigned int newAn);
    bool comparAutoturism(Autoturism &a);
    
    static Autoturism celMaiNou(Autoturism *array,int NrMasini);
};

#endif