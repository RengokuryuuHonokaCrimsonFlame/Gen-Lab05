//
// Created by Rod Julien on 24.05.2019.
//

#ifndef GEN_LAB05_CHILDRENS_H
#define GEN_LAB05_CHILDRENS_H

#include "Movie.h"

class Children : public Movie{
public:
    explicit Children( const std::string& title)
            : Movie(title)
    {}
    virtual ~Children();
    virtual double getBaseAmount() const;
    virtual int getMaxDay() const;
    virtual double getFeePerExpendDay() const;
    virtual bool hasBonus() const;

protected:
    Children();
};

inline Children::Children()= default;

inline Children::~Children()= default;

inline double Children::getBaseAmount() const{return 1.5;}
inline int Children::getMaxDay() const{return 3;}
inline double Children::getFeePerExpendDay() const{return 1.5;}
inline bool Children::hasBonus() const {return false;}
#endif //GEN_LAB05_CHILDRENS_H
