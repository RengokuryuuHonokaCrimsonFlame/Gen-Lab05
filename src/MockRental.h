//
// Created by Rod Julien on 14.06.2019.
//

#ifndef GEN_LAB05_MOCKRENTAL_H
#define GEN_LAB05_MOCKRENTAL_H

#include "Rental.h"
class MockRental : public Rental{
public:
    MOCK_CONST_METHOD1(getDaysRented, int());
    MOCK_CONST_METHOD3(getMovie, const Movie*());
    MOCK_CONST_METHOD2(addBonusForATwoDayNewReleaseRental, bool());
    MOCK_CONST_METHOD4(showFiguresForThisRental, void (std::ostringstream& result, double amount));
};
#endif //GEN_LAB05_MOCKRENTAL_H
