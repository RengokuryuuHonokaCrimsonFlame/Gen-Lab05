// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

class Movie {
public:
    explicit Movie( const std::string& title );
    virtual ~Movie();
    virtual std::string getTitle() const;
    virtual double getBaseAmount() const;
    virtual int getMaxDay() const;
    virtual double getFeePerExpendDay() const;
    virtual bool hasBonus() const;

private:
    std::string _title;

protected:
    Movie();
};

inline Movie::
Movie( const std::string& title )
        : _title( title )
{}

inline Movie::Movie() = default;

inline Movie::~Movie()= default;

inline std::string Movie::getTitle() const { return _title; }
inline double Movie::getBaseAmount() const{return 2;}
inline int Movie::getMaxDay() const{return 2;}
inline double Movie::getFeePerExpendDay() const{return 1.5;}
inline bool Movie::hasBonus() const {return false;}

#endif // MOVIE_H