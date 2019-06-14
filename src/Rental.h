// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"
#include "New_Release.h"
#include "Childrens.h"
#include <sstream>

class Rental {
public:
    Rental( Movie& movie, int daysRented );
    virtual ~Rental();
    virtual int getDaysRented() const;
    virtual const Movie * getMovie() const;
    virtual bool addBonusForATwoDayNewReleaseRental() const;
    virtual void showFiguresForThisRental(std::ostringstream& result, double amount) const;

private:
    Movie * _movie;
    int _daysRented;
};

inline Rental::
Rental( Movie& movie, int daysRented )
        : _movie( &movie )
        , _daysRented( daysRented ) {}

inline Rental::
~Rental(){}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const Movie * Rental::
getMovie() const { return _movie; }

inline bool Rental::
addBonusForATwoDayNewReleaseRental() const{
    return  _movie->hasBonus() && getDaysRented() > 1;
}

inline void Rental::
showFiguresForThisRental(std::ostringstream &result, double amount) const {
    result << "\t" + _movie->getTitle() << "\t" << amount << "\n";
}

#endif // RENTAL_H