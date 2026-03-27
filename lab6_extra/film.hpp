#ifndef FILM_HPP
#define FILM_HPP

#include <iostream>
#include <string>

class Film
{
private:
    std::string titlu;
    unsigned int durata;
    float rating;

public:
    Film(std::string title = "0", unsigned int length = 0, float review_stars = 0);

    friend std::ostream &operator<<(std::ostream &output, const Film &f);
    float GetRating() { return rating; };
    void setRating(float new_rating) { rating = new_rating; };

    static bool compare(const Film &f1, const Film &f2);
};
bool operator<(Film &f1, Film &f2);

#endif