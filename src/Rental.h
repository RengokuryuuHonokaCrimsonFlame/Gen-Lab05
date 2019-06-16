// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"
#include "NewRelease.h"
#include "Childrens.h"
#include <sstream>

class Rental {
public:
    Rental( Movie& movie, int daysRented );
    virtual ~Rental();
    virtual int getDaysRented() const;
    virtual double determineAmountsForEachLine() const;
    //virtual const Movie * getMovie() const; //Ne sert plus a rien.
    virtual bool addBonusForATwoDayNewReleaseRental() const;
    virtual std::string getMovieName() const;

protected:
    Rental();

private:
    Movie * _movie{};
    int _daysRented{};
};

inline Rental::
Rental( Movie& movie, int daysRented )
        : _movie( &movie )
        , _daysRented( daysRented ) {}

inline Rental::Rental() = default;

inline Rental::~Rental()= default;

inline int Rental::getDaysRented() const { return _daysRented; }

//inline const Movie * Rental::getMovie() const { return _movie; }

inline double Rental::determineAmountsForEachLine() const {
    double result = _movie->getBaseAmount();
    if(_daysRented > _movie->getMaxDay()){
        result += (_daysRented - _movie->getMaxDay()) * _movie->getFeePerExpendDay();
    }
    return result;
}

inline bool Rental::addBonusForATwoDayNewReleaseRental() const{
    return  _movie->hasBonus() && getDaysRented() > 1;
}

inline std::string Rental::getMovieName() const{
    return _movie->getTitle();
}

#endif // RENTAL_H