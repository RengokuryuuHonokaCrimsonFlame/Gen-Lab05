// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"
#include "New_Release.h"
#include "Childrens.h"

class Rental {
public:
    Rental( Movie& movie, int daysRented );

    int getDaysRented() const;
    const Movie * getMovie() const;

private:
    Movie * _movie;
    int _daysRented;
};

inline Rental::
Rental( Movie& movie, int daysRented )
        : _movie( &movie )
        , _daysRented( daysRented ) {}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const Movie * Rental::
getMovie() const { return _movie; }

#endif // RENTAL_H