#include <iostream>
#include "film.hpp"

Film::Film(std::string title, unsigned int length, float review_stars) : titlu(title), durata(length), rating(review_stars)
{
}

std::ostream &operator<<(std::ostream &output, const Film &f)
{
    output << "Titlu: " << f.titlu << "; Durata: " << f.durata << "; Rating: " << f.rating << std::endl;
    return output;
}

bool operator<(Film &f1, Film &f2)
{
    return f1.GetRating() < f2.GetRating() ? true : false;
}

bool Film::compare(const Film &f1, const Film &f2)
{
    return f1.rating > f2.rating ? true : false;
}