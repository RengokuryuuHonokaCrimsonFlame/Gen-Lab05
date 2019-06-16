//
// Created by Rod Julien on 24.05.2019.
//

#ifndef GEN_LAB05_NEWRELEASE_H
#define GEN_LAB05_NEWRELEASE_H

#include "Movie.h"

class NewRelease : public Movie{
public:
    explicit NewRelease( const std::string& title )
            : Movie(title)
    {}
    virtual ~NewRelease();
    virtual double getBaseAmount() const;
    virtual int getMaxDay() const;
    virtual double getFeePerExpendDay() const;
    virtual bool hasBonus() const;

protected:
    NewRelease();
};

inline NewRelease::NewRelease() = default;

inline NewRelease::~NewRelease() = default;

inline double NewRelease::getBaseAmount() const{return 0;}
inline int NewRelease::getMaxDay() const{return 0;}
inline double NewRelease::getFeePerExpendDay() const{return 3;}
inline bool NewRelease::hasBonus() const {return true;}

#endif //GEN_LAB05_NEWRELEASE_H
