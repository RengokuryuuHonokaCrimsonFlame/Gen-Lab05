//
// Created by Rod Julien on 24.05.2019.
//

#ifndef GEN_LAB05_NEW_RELEASE_H
#define GEN_LAB05_NEW_RELEASE_H

#include "Movie.h"

class New_Release : public Movie{
public:
    New_Release( const std::string& title )
            : Movie(title)
    {}
    virtual ~New_Release();
    virtual double getBaseAmount() const;
    virtual int getMaxDay() const;
    virtual double getFeePerExpendDay() const;
    virtual bool hasBonus() const;

protected:
    New_Release();
};

inline New_Release::New_Release() {}

inline New_Release::~New_Release() {}

inline double New_Release::getBaseAmount() const{return 0;}
inline int New_Release::getMaxDay() const{return 0;}
inline double New_Release::getFeePerExpendDay() const{return 3;}
inline bool New_Release::hasBonus() const {return true;}

#endif //GEN_LAB05_NEW_RELEASE_H
